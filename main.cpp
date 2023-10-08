#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "jogo.h"

#define INC_KEY 1
#define INC_KEYIDLE 0.2


Jogo jogo = Jogo();

// Key status
int keyStatus[256];

// Window & Viewing dimensions
const GLint Width = jogo.getArena()->getLargura();
const GLint Height = jogo.getArena()->getAltura();

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    jogo.getPlayer()->desenhaPlayer();

    glBegin(GL_LINES);
        glVertex3f(-Height/2.0,0,0)
    glEnd();


    glutSwapBuffers(); // Desenha the new frame of the game.
}

void keyPress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
    case 'd':
    case 'D':
    case 'w':
    case 'W':
    case 's':
    case 'S':
        keyStatus[(int)key] = 1; // Using keyStatus trick
        break;
    case 27:
        exit(0);
    }
    glutPostRedisplay();
}

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

bool isDentroDaArena(GLfloat dx,GLfloat dy,Player*p){
    GLint raioCabeca = p->getRaioCabeca();
    GLfloat gX = p->getGx();
    GLfloat gY = p->getGy();
    
    bool ladodir = gX + dx + (raioCabeca) <= Width/2.0;
    bool ladoesq = -Width/2.0 <= gX + dx - (raioCabeca);
    bool emcima = gY + dy + (raioCabeca) <= 0;
    bool embaixo = -Height/2.0 <= gY + dy - (raioCabeca); 

    return ladodir&&ladoesq&&emcima&&embaixo;
}


void idle(void)
{
    static GLdouble previousTime = glutGet(GLUT_ELAPSED_TIME);
    GLdouble currentTime, timeDiference;
    // Pega o tempo que passou do inicio da aplicacao
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    // Calcula o tempo decorrido desde de a ultima frame.
    timeDiference = currentTime - previousTime;
    // Atualiza o tempo do ultimo frame ocorrido
    previousTime = currentTime;

    Player* p = jogo.getPlayer();
    GLfloat inc =  jogo.getPlayer()->getVelocidade()*timeDiference*INC_KEYIDLE;

    if (keyStatus[(int)('a')])
    {
        if(isDentroDaArena(-inc,0,p))
            p->Move((-inc) ,0);
    }
    if (keyStatus[(int)('d')])
    {
        if(isDentroDaArena(inc,0,p))
            p->Move(inc ,0);
    }
    if (keyStatus[(int)('s')])
    {
        if(isDentroDaArena(0,-inc,p))
            p->Move(0,(-inc) );
    }
    if (keyStatus[(int)('w')])
    {
        if(isDentroDaArena(0,inc,p))
            p->Move(0,inc );
    }


    glutPostRedisplay();
}


void init()
{
    // The color the windows will redraw. Its done to erase the previous frame.
    ResetKeyStatus();

    // Get colors for background
    GLdouble* background_c = jogo.getArena()->getColor();
    // No opacity(alpha).
    glClearColor(background_c[0], background_c[1], background_c[2], 1.0f); 

    glMatrixMode(GL_PROJECTION);  // Select the projection matrix
    
    glOrtho(-(Width / 2),  // X coordinate of left edge
            (Width  / 2),   // X coordinate of right edge
            -(Height  / 2), // Y coordinate of bottom edge
            (Height / 2),  // Y coordinate of top edge
            -1,                 // Z coordinate of the “near” plane
            1);                 // Z coordinate of the “far” plane
    
    glMatrixMode(GL_MODELVIEW);   // Select the projection matrix
    glLoadIdentity();
}


int main(int argc, char *argv[])
{
 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Create the window.
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Trabalho 2D");

    // Define callbacks.
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(keyPress);
    glutIdleFunc(idle);
    glutKeyboardUpFunc(keyup);

    init();

    glutMainLoop();
    
    return 0;
}
