#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "jogo.h"
#include "point.h"

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

    glColor3f(1,1,1);
    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex3f(-Height/2.0,0,0);
        glVertex3f(Height/2,0,0);
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

    GLfloat p_raioCabeca = p->getRaioCabeca();
    GLfloat p_gX = p->getGx();
    GLfloat p_gY = p->getGy();

    if (keyStatus[(int)('a')])
    {
        bool ladoesq = -Width/2.0 <= p_gX - inc - (p_raioCabeca);
        if(!ladoesq){
            inc = -(-Width/2.0 - (p_gX-p_raioCabeca));
        }    
        p->Move(-(inc),0);

    }
    if (keyStatus[(int)('d')])
    {
        bool ladodir = p_gX + inc + (p_raioCabeca) <= Width/2.0;
        if(!ladodir){
            inc = (Width/2.0 - (p_gX+p_raioCabeca));
        }    
        p->Move((inc),0);
    }
    if (keyStatus[(int)('s')])
    {
        bool embaixo = -Height/2.0 <= p_gY - inc - (p_raioCabeca);
        if(!embaixo){
            inc = -(-Height/2.0 - (p_gY-p_raioCabeca));
        }    
        p->Move(0,-inc);
    }
    if (keyStatus[(int)('w')])
    {
        bool emcima = p_gY + inc + (p_raioCabeca) <= 0;
         if(!emcima){
            inc = (0 - (p_gY + p_raioCabeca));
        }    
        p->Move(0,inc);
    }


    glutPostRedisplay();
}

Point2D previousMousePosition = Point2D();

void passiveMotion(int x, int y){
    printf("%f, %f",x,y);
    Point2D p = Point2D(x,y);

    jogo.getPlayer()->changeArmaDirection(p);

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
            -Height,                 // Z coordinate of the “near” plane
            Height);                 // Z coordinate of the “far” plane
    
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
    glutPassiveMotionFunc(passiveMotion);

    init();

    glutMainLoop();
    
    return 0;
}
