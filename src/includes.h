
#ifndef INCLUDES_H
#define INCLUDES_H

#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

//SDL
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


#ifdef __APPLE__
#define glGenVertexArrays glGenVertexArraysAPPLE
#define glBindVertexArrays glBindVertexArraysAPPLE
#define glBindVertexArray glBindVertexArrayAPPLE
#define glDeleteVertexArrays glDeleteVertexArraysAPPLE
#endif

#include "framework.h"
#include "glfw3.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_CAPTION "MaDsteroids"
#define UNIT_SIZE 30

#define PLAYER 0
#define SMALL_ASTEROID 1
#define MEDIUM_ASTEROID 2
#define BIG_ASTEROID 3
#define BULLET 4

#define MAX_VEL_ASTEROID 0.25
#define VEL_BULLET 0.3

#define KEY_SPACE 32
#define KEY_ESC 27

using namespace std;
#endif