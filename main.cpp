#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "jogo.h"

Jogo jogo = Jogo();

// Key status
int keyStatus[256];

void keyup(unsigned char key, int x, int y)
{
    keyStatus[(int)(key)] = 0;
    glutPostRedisplay();
}

void ResetKeyStatus()
{
    int i;
    // Initialize keyStatus
    for (i = 0; i < 256; i++)
        keyStatus[i] = 0;
}

void init()
{
    ResetKeyStatus();
    // The color the windows will redraw. Its done to erase the previous frame.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black, no opacity(alpha).

    glMatrixMode(GL_PROJECTION);  // Select the projection matrix
    
    glOrtho(-(jogo.getArena()->getLargura() / 2),  // X coordinate of left edge
            (jogo.getArena()->getLargura()  / 2),   // X coordinate of right edge
            -(jogo.getArena()->getAltura()  / 2), // Y coordinate of bottom edge
            (jogo.getArena()->getAltura() / 2),  // Y coordinate of top edge
            -1,                 // Z coordinate of the “near” plane
            1);                 // Z coordinate of the “far” plane
    
    glMatrixMode(GL_MODELVIEW);   // Select the projection matrix
    glLoadIdentity();
}


int main(int argc, char const *argv[])
{
    
    
    return 0;
}
