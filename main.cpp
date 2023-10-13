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

// Window & Viewwing dimensions
const GLint Width = jogo.getArena()->getLargura();
const GLint Height = jogo.getArena()->getAltura();

int destruidos = 0;
static char str[1000];
void *font = GLUT_BITMAP_9_BY_15;
void ImprimePlacar(GLfloat x, GLfloat y)
{
    glColor3f(1.0, 1.0, 1.0);
    // Cria a string a ser impressa
    char *tmpStr;
    sprintf(str, "Barris destruidos: %d", destruidos);
    // Define a posicao onde vai comecar a imprimir
    glRasterPos2f(x, y);
    // Imprime um caractere por vez
    tmpStr = str;
    while (*tmpStr)
    {
        glutBitmapCharacter(font, *tmpStr);
        tmpStr++;
    }
}

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    jogo.getPlayer()->desenhaPlayer();

    glColor3f(1,1,1);

    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(-Width/2.0,0,0);
        glVertex3f(Width/2,0,0);
    glEnd();
    // std::cout << "[";
    for( Barril* barril : jogo.barril_list){
        barril->desenhaBarril();
        // std::cout <<  barril << ", ";
        // glPointSize(10);
        // glBegin(GL_POINTS);
        //     glVertex3f(barril->getX(), barril->getY(),0);
        // glEnd();
    }
    // std::cout << "]" << std::endl;


    // std::cout << "[";
    for (Tiro* tiro : jogo.tirosDoPlayer){
        tiro->Desenha();
        // std::cout << tiro ;
    }
    // std::cout << "]" << std::endl;


    for (Tiro* tiro : jogo.tirosDosInimigos){
        tiro->Desenha();
    }
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
        keyStatus[(int)tolower(key)] = 1; // Using keyStatus trick
        break;
    case 27:
        exit(0);
    }
    glutPostRedisplay();
}

void keyup(unsigned char key, int x, int y)
{
    keyStatus[(int)(tolower(key))] = 0;
    glutPostRedisplay();
}

void ResetKeyStatus()
{
    int i;
    // Initialize keyStatus
    for (i = 0; i < 256; i++)
        keyStatus[i] = 0;
}

bool colidiuComBarril(GLfloat barrilX, GLfloat barrilY, GLfloat tiroX, GLfloat tiroY, GLfloat raioTiro, GLfloat alturaB, GLfloat larguraB){
    bool emcima, embaixo, direita, esquerda;
    emcima = tiroY-raioTiro <= barrilY + (alturaB/2.0);
    embaixo = tiroY+raioTiro >= barrilY - (alturaB/2.0);
    direita = tiroX-raioTiro <= barrilX + (larguraB/2.0);
    esquerda = tiroX+raioTiro >= barrilX - (larguraB/2.0);
    return emcima && embaixo && direita && esquerda;
}

void idle(void)
{
    static GLdouble previousTime = glutGet(GLUT_ELAPSED_TIME);
    struct configData config = jogo.getConfig();
    static GLfloat deltaTimerBarril = config.segParaSairBarril;

    GLdouble currentTime, timeDiference;
    // Pega o tempo que passou do inicio da aplicacao
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    // Calcula o tempo decorrido desde de a ultima frame.
    timeDiference = currentTime - previousTime;
    // Atualiza o tempo do ultimo frame ocorrido
    previousTime = currentTime;
    
    deltaTimerBarril += timeDiference;

    Player* p = jogo.getPlayer();
    GLfloat inc =  jogo.getPlayer()->getVelocidade()*timeDiference*INC_KEYIDLE;

    GLfloat p_raioCabeca = p->getRaioCabeca();
    GLfloat p_gX = p->getGx();
    GLfloat p_gY = p->getGy();
    // MOVE PLAYER
    if (keyStatus[(int)('a')]||keyStatus[(int)('A')])
    {
        bool ladoesq = -Width/2.0 <= p_gX - inc - (p_raioCabeca);
        if(!ladoesq){
            inc = -(-Width/2.0 - (p_gX-p_raioCabeca));
        }    
        p->Move(-(inc),0);

    }
    if (keyStatus[(int)('d')]||keyStatus[(int)('D')])
    {
        bool ladodir = p_gX + inc + (p_raioCabeca) <= Width/2.0;
        if(!ladodir){
            inc = (Width/2.0 - (p_gX+p_raioCabeca));
        }    
        p->Move((inc),0);
    }
    if (keyStatus[(int)('s')]||keyStatus[(int)('S')])
    {
        bool embaixo = -Height/2.0 <= p_gY - inc - (p_raioCabeca);
        if(!embaixo){
            inc = -(-Height/2.0 - (p_gY-p_raioCabeca));
        }    
        p->Move(0,-inc);
    }
    if (keyStatus[(int)('w')]||keyStatus[(int)('W')])
    {
        bool emcima = p_gY + inc + (p_raioCabeca) <= 0;
         if(!emcima){
            inc = (0 - (p_gY + p_raioCabeca));
        }    
        p->Move(0,inc);
    }

    // Cria Barril
    if( deltaTimerBarril >= config.segParaSairBarril){
        deltaTimerBarril = 0.0;
        GLint lower = (-Width/2 + config.larguraBarril/2);
        GLint upper = (Width/2 - config.larguraBarril/2);

        GLint xBarril = (rand() % (upper - lower + 1)) + lower; 
        //cout << "CRIA BARRIl: " << xBarril << " " << Height/2 << endl;
        jogo.barril_list.push_back(new Barril( xBarril, Height/2,
                                                config.alturaBarril,
                                                config.larguraBarril,
                                                config.velocidadeBarril,
                                                config.numeroTirosBarril));
    }


    // MOVE TODOS OS TIROS PLAYER
    for (auto it_tiro = jogo.tirosDoPlayer.rbegin(); it_tiro != jogo.tirosDoPlayer.rend(); ++it_tiro){
        Tiro* tiro = *it_tiro;
        if(tiro->Valido(Width/2,Height/2)) 
            tiro->Move(timeDiference);
        else{
            jogo.tirosDoPlayer.remove(tiro); // Remove elemento
            delete tiro;
        }
    }

    // MOVE TODOS OS TIROS Inimigos
    for (auto it_tiro = jogo.tirosDosInimigos.rbegin(); it_tiro != jogo.tirosDosInimigos.rend(); ++it_tiro){
        Tiro* tiro = *it_tiro;
        if(tiro->Valido(Width/2,Height/2)) 
            tiro->Move(timeDiference);
        else{
            jogo.tirosDosInimigos.remove(tiro); // Remove elemento
            delete tiro;
        }
    }

    // Move Barril e Checa se tiro bateu nele
    for (auto it = jogo.barril_list.rbegin(); it != jogo.barril_list.rend(); ++it) {
        Barril* barril = *it;
        
        GLfloat barrilX, barrilY;
        barrilX = barril->getX();
        barrilY = barril->getY();

        //  TIRO checa SE BATEU NO BARRIL
        for (auto it_tiro = jogo.tirosDoPlayer.rbegin(); it_tiro != jogo.tirosDoPlayer.rend(); ++it_tiro){
            Tiro* tiro = *it_tiro;
           
            GLfloat tiroX, tiroY;
            tiro->GetPos(tiroX,tiroY);

            if (colidiuComBarril(barrilX,barrilY,tiroX,tiroY,tiro->getRaio(),barril->getAltura(),barril->getLargura())){
                barril->decVida();
                jogo.tirosDoPlayer.remove(tiro); // Remove elemento
                delete tiro;
            }
        }
        // checa se barril é valido (se morreu no for anterior ou passou da arena)
        if (barril->isValido(-Height/2))
            barril->MoveY(timeDiference);
        else {
            jogo.barril_list.remove(barril); // Remove elemento
            delete barril;
        }
    }

    // Move tiros do Inimigo e verifica se colidiu com player

    // Checa se tiros do player são válidos

    glutPostRedisplay();
}



void passiveMotion(int x, int y){
    static Point2D previousMousePosition = Point2D(x,y);

    GLfloat dx = (x - previousMousePosition.getX())*0.2; 
    previousMousePosition.setX(x);

    jogo.getPlayer()->changeArmaDirection(dx);

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
void cleanMemory(){
    for (auto it = jogo.barril_list.rbegin(); it != jogo.barril_list.rend(); ++it) {
        Barril* barril = *it;
        jogo.barril_list.remove(barril); // Remove the element
    }

    for (auto it = jogo.tirosDoPlayer.rbegin(); it != jogo.tirosDoPlayer.rend(); ++it) {
        Tiro* tiro = *it;
        jogo.tirosDoPlayer.remove(tiro); // Remove the element
    }
    
     for (auto it = jogo.tirosDosInimigos.rbegin(); it != jogo.tirosDosInimigos.rend(); ++it) {
        Tiro* tiro = *it;
        jogo.tirosDosInimigos.remove(tiro); // Remove the element
    }
    std::cout << "Limpeza de memória feita" << std::endl;
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
        jogo.tirosDoPlayer.push_back(jogo.getPlayer()->atira());
    }
    glutPostRedisplay();
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
    glutMouseFunc(mouse);
    atexit(cleanMemory);
    init();

    glutMainLoop();

    
    
    return 0;
}
