#include "Game.h"

Game* game = NULL;


void reshape(int w, int h){
    game->reshape(w,h);
}

void display(){
    game->display();
}

void onKeydown(unsigned char key, int x, int y){
    game->onKeydown(key,x,y);
}

void onKeyup(unsigned char key, int x, int y){
    game->onKeyup(key,x,y);
}

void init(){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); //Double buffering, RGBA colour space, Depth buffer (displays things in the correct order, things don't overlap in the wrong order)
    
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("MaDsteroids");
    
    glClearColor(0.2, 0.0, 0.0, 0.0); //Write your openGL set-up commands
    glutReshapeFunc(reshape); //Sets the function that wants to be called when the form is resized
    glutDisplayFunc(display); //the tick function that gets called as fast as it can to update the graphics
    glutIdleFunc(display); //Constantly recall the display function
    glutKeyboardFunc(onKeydown);
    glutKeyboardUpFunc(onKeyup);
    
}

int main (int argc, char **argv)
{
    game = new Game();
    
    glutInit(&argc, argv);
    init();
    glutMainLoop(); //Starts the glut tick loop cycle

    return 0;
}