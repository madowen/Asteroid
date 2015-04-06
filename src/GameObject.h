//
//  GameObject.h
//  Asteroid
//
//  Created by Alex Catalán on 6/4/15.
//  Copyright (c) 2015 MaDLabs. All rights reserved.
//

#ifndef __Asteroid__GameObject__
#define __Asteroid__GameObject__

#include <stdio.h>
#include "includes.h"

class GameObject{
public:
    int type;
    int rotate;
    int accelerate;

    GameObject(int type);
    void render();
    void update(float dt);
    void setPosition(Vector3 p);
    Vector3 getPosition();
    void setVelocity(Vector3 v);
    void setModel(Matrix44* m);
    Matrix44* getModel();
private:
    Matrix44 *model;
    float speedRotation;
    float speedAcceleration;
    Vector3 velocity;
};
#endif /* defined(__Asteroid__GameObject__) */
