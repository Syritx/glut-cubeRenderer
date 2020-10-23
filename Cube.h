#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include <GLUT/GLUT.h>

class Square {
public:
    void render(GLdouble size) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        
        glVertex2f( size,  size);
        glVertex2f( size, -size);
        glVertex2f(-size, -size);
        glVertex2f(-size,  size);
        
        glEnd();
    }
};

class Cube {
private:
    int zOffset = -0;
    
public:
    void render(GLdouble size) {
        glBegin(GL_QUADS);
        
        glColor3f(1.0, 1.0, 1.0);
        // front
        glColor3f(1.0, 0, 0);
        glVertex3d(-1*size, 1*size, -1*size+zOffset);
        glVertex3d( 1*size, 1*size, -1*size+zOffset);
        glVertex3d( 1*size,-1*size, -1*size+zOffset);
        glVertex3d(-1*size,-1*size, -1*size+zOffset);
        
        // back
        glColor3f(0, 1.0, 0);
        glVertex3d(-1*size, 1*size,  1*size+zOffset);
        glVertex3d( 1*size, 1*size,  1*size+zOffset);
        glVertex3d( 1*size,-1*size,  1*size+zOffset);
        glVertex3d(-1*size,-1*size,  1*size+zOffset);
        
        // left
        glColor3f(0, 0, 1.0);
        glVertex3d(-1*size, 1*size, -1*size+zOffset);
        glVertex3d(-1*size, 1*size,  1*size+zOffset);
        glVertex3d(-1*size,-1*size,  1*size+zOffset);
        glVertex3d(-1*size,-1*size, -1*size+zOffset);
        
        // right
        glColor3f(1.0, 0.5, 0);
        glVertex3d( 1*size, 1*size, -1*size+zOffset);
        glVertex3d( 1*size, 1*size,  1*size+zOffset);
        glVertex3d( 1*size,-1*size,  1*size+zOffset);
        glVertex3d( 1*size,-1*size, -1*size+zOffset);
        
        // top
        glColor3f(1.0, 1.0, 1.0);
        glVertex3d(-1*size, 1*size, -1*size+zOffset);
        glVertex3d( 1*size, 1*size, -1*size+zOffset);
        glVertex3d( 1*size, 1*size,  1*size+zOffset);
        glVertex3d(-1*size, 1*size,  1*size+zOffset);
        
        // bottom
        glColor3f(1.0, 1.0, 0);
        glVertex3d(-1*size,-1*size, -1*size+zOffset);
        glVertex3d( 1*size,-1*size, -1*size+zOffset);
        glVertex3d( 1*size,-1*size,  1*size+zOffset);
        glVertex3d(-1*size,-1*size,  1*size+zOffset);
        
        glEnd();
        glFlush();
    }
};
