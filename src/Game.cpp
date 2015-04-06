//
//  Game.cpp
//  Asteroid
//
//  Created by Alex Catalán on 5/4/15.
//  Copyright (c) 2015 MaDLabs. All rights reserved.
//

#include "Game.h"

Game::Game() {
    /* initialize random seed: */
    srand (time(NULL));
    
    this->player = newGameObject(PLAYER);
    
    vector<GameObject*>::iterator it;
    
    for (int i = 0; i < 5; i++) {
        this->asteroids.push_back(newGameObject(BIG_ASTEROID));
    }
    

    
}

void Game::update(float dt){
    this->player->update(dt);
    vector<GameObject*>::iterator it;
    for (it=this->asteroids.begin(); it<this->asteroids.end(); it++)
        (*it)->update(dt);
    for (it=this->bullets.begin(); it<this->bullets.end(); it++)
        (*it)->update(dt);
   
}

void Game::display() {
    //OpenGL functions to draw a basic triangle
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    this->player->render();
    vector<GameObject*>::iterator it;
    for (it=this->asteroids.begin(); it<this->asteroids.end(); it++)
        (*it)->render();
    for (it=this->bullets.begin(); it<this->bullets.end(); it++)
        (*it)->render();
    
    glutSwapBuffers(); //Swaps the double-buffer
    
    //update logic
    double elapsed_time = (SDL_GetTicks() - this->last_time) * 0.001; //0.001 converts from milliseconds to seconds
    this->last_time = SDL_GetTicks();
    this->update(elapsed_time);
}

void Game::reshape(int w, int h){
    glutReshapeWindow( WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-UNIT_SIZE, UNIT_SIZE, -UNIT_SIZE, UNIT_SIZE, 0, 1);
    glMatrixMode(GL_MODELVIEW);
}

void Game::onKeydown (unsigned char key, int x, int y){
    if (key == 'a' || key == 'A') this->player->rotate = -1;
    if (key == 'd' || key == 'D') this->player->rotate = 1;
    if (key == 'w' || key == 'W') this->player->accelerate = 1;
    if (key == KEY_SPACE) this->shoot();
    if (key == KEY_ESC) exit(1);
    cout << (int)key << endl;
}
void Game::onKeyup(unsigned char key, int x, int y){
    if (key == 'a' || key == 'A') this->player->rotate = 0;
    if (key == 'd' || key == 'D') this->player->rotate = 0;
    if (key == 'w' || key == 'W') this->player->accelerate = 0;
}

GameObject* Game::newGameObject(int type){
    GameObject *obj = new GameObject(type);
    if (type == PLAYER){
        // PLAYER //
        // new player starts at 0,0, with no rotation.
    }else if (type <= BIG_ASTEROID){
        // ASTEROID //
        // random initial position
        obj->setPosition(Vector3(rand()%UNIT_SIZE-UNIT_SIZE/2.0f,
                                 rand()%UNIT_SIZE-UNIT_SIZE/2.0f,
                                 0.0f));
        // random initial velocity
        float rx = -MAX_VEL_ASTEROID + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MAX_VEL_ASTEROID+MAX_VEL_ASTEROID)));
        float ry = -MAX_VEL_ASTEROID + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MAX_VEL_ASTEROID+MAX_VEL_ASTEROID)));
        
        obj->setVelocity(Vector3(rx,ry,0.0f));
    }else{
        // BULLET //
        // same position and rotation as player
        Matrix44 *m = new Matrix44(*this->player->getModel());
        obj->setModel(m);
        // position = a unit forward (bullets are shot from the front not the inside the spaceship)
        Vector3 newPos = obj->getPosition();
        Vector3 forward = this->player->getModel()->topVector();
        newPos = newPos + forward;
        obj->setPosition(newPos);
        // bullet velocity with forward direction
        forward = forward * VEL_BULLET;
        obj->setVelocity(forward);
    }
    return obj;
}

void Game::shoot(){
    this->bullets.push_back(this->newGameObject(BULLET));
}
