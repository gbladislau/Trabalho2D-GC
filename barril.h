#ifndef BARRIL_H
#define BARRIL_H


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include "inimigo.h"

class Barril
{
private:
    GLfloat gX,gY;
    GLint altura;
    GLint largura;
    GLfloat velocidade;
    int vida;
    bool enemy;
    Inimigo* inimigo = NULL;
public:
    //void ImprimeVida(GLfloat x, GLfloat y);
    Barril(GLfloat x, GLfloat y, GLint altura, GLint largura, GLfloat velocidade, int vida);
    GLfloat getX(){return this->gX;}
    GLfloat getY(){return this->gY;}
    GLint getAltura(){return this->altura;}
    GLint getLargura(){return this->largura;}
    bool hasEnemy(){return this->enemy;}
    Inimigo* getInimigo(){return this->inimigo;}
    void addInimigo(Inimigo *i);
    void MoveY(GLfloat timeDelta);
    void destroiBarril();
    void ImprimeVida();
    void decVida();
    void desenhaBarril();
    bool isValido(GLfloat yLimit);
};

#endif // !BARRIL_H