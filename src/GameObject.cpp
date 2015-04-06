//
//  GameObject.cpp
//  Asteroid
//
//  Created by Alex Catalán on 6/4/15.
//  Copyright (c) 2015 MaDLabs. All rights reserved.
//

#include "GameObject.h"

GameObject::GameObject(int type){
    this->speedRotation = 100;
    this->speedAcceleration = 0.2;
    this->accelerate = 0;
    this->rotate = 0;
    this->velocity = Vector3(0,0,0);
    this->model = new Matrix44();
    this->type = type;
    if (this->type != PLAYER && this->type != BULLET)
        this->model->scale(Vector3(this->type,this->type,this->type));
}

void GameObject::render(){
    glPushMatrix();
    this->model->set();
    glColor3f(1.0f, 1.0f, 1.0f);
    if (this->type == PLAYER){
        glBegin(GL_LINE_LOOP);
            glVertex3f(0.8f, -1.0f, 0.0f);
            glVertex3f(0.0f, -0.3f, 0.0f);
            glVertex3f(-0.8f, -1.0f, 0.0f);
            glVertex3f(0.0f, 1.0f, 0.0f);
        glEnd();
        if (this->accelerate){
            glBegin(GL_LINE_STRIP);
                glVertex3f(-0.4f, -0.6f, 0.0f);
                glVertex3f(0.0f, -0.9f, 0.0f);
                glVertex3f(0.4f, -0.6f, 0.0f);
            glEnd();
        }
    }else if (this->type <= BIG_ASTEROID){
        glBegin(GL_LINE_LOOP);
            glVertex3f(-1.0f, -0.3f, 0.0f);
            glVertex3f(-0.5f, 0.0f, 0.0f);
            glVertex3f(-1.0f, 0.3f, 0.0f);
            glVertex3f(-0.5f, 1.0f, 0.0f);
            glVertex3f(0.0f, 0.6f, 0.0f);
            glVertex3f(0.4f, 0.9f, 0.0f);
            glVertex3f(1.0f, 0.4f, 0.0f);
            glVertex3f(1.0f, -0.2f, 0.0f);
            glVertex3f(0.2f, -1.0f, 0.0f);
            glVertex3f(-0.3f, -1.0f, 0.0f);
        glEnd();
   
    }else{
        glBegin(GL_LINE_STRIP);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, -0.5f, 0.0f);
        glEnd();

    }
    glPopMatrix();
}

void GameObject::update(float dt){
    // if accelerating, then rise velocity
    this->velocity = this->velocity + this->model->topVector() * this->accelerate * this->speedAcceleration * dt;

    this->model->traslate(this->velocity.x,this->velocity.y,this->velocity.z);
    this->model->rotateLocal(this->speedRotation * this->rotate * DEG2RAD*dt,Vector3(0,0,1));

    // control if GO is out of bounds
    if (abs(this->model->m[12]) >= UNIT_SIZE+1) this->model->m[12] = -this->model->m[12];
    if (abs(this->model->m[13]) >= UNIT_SIZE+1) this->model->m[13] = -this->model->m[13];
    
}

void GameObject::setPosition(Vector3 p){
    this->model->m[12] = p.x;
    this->model->m[13] = p.y;
    this->model->m[14] = p.z;
}
Vector3 GameObject::getPosition(){
    return Vector3(this->model->m[12], this->model->m[13] ,this->model->m[14]);
}
void GameObject::setVelocity(Vector3 v){
    this->velocity = v;
}

void GameObject::setModel(Matrix44* m){
    this->model = m;
}

Matrix44* GameObject::getModel(){
    return this->model;
}

