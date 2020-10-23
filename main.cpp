#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include <GLUT/GLUT.h>

#include "Cube.h"

// FUNCTIONS
void display();
void init();
void resize(int, int);
void timer(int a);
void render();

Cube cube;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(720, 720);
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("Hello");
    glutReshapeFunc(resize);
    glutIdleFunc(render);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}

void render() {
    cube.render(1);
    glutSwapBuffers();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(50, -160.0, 160.0, 0);
    
    glFlush();
}

void init() {
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    glutPostRedisplay();
}

void resize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(20, width/height, .1, 2000);
    glOrtho(-10, 10, -10, 10, .1, 2000);
    glMatrixMode(GL_MODELVIEW);
}
