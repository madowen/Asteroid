//
//  Game.h
//  Asteroid
//
//  Created by Alex Catalán on 5/4/15.
//  Copyright (c) 2015 MaDLabs. All rights reserved.
//

#ifndef __Asteroid__Game__
#define __Asteroid__Game__

#include <stdio.h>
#include "includes.h"
#include "GameObject.h"
#include <vector>

class Game{
public:
    Game();
    void update(float dt);
    void display();
    void reshape(int w, int h);
    void onKeydown (unsigned char key, int x, int y);
    void onKeyup(unsigned char key, int x, int y);
private:
    long last_time = 0;
    long last_shoot = 0;
    GameObject *player;
    vector<GameObject*> asteroids;
    vector<GameObject*> bullets;
    GameObject* newGameObject(int type);
    void shoot();
};

#endif /* defined(__Asteroid__Game__) */
