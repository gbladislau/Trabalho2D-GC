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
    bool hasEnemy;
    Inimigo* inimigo;
public:
    //void ImprimeVida(GLfloat x, GLfloat y);
    void ImprimeVida();
    Barril(GLfloat x, GLfloat y, GLint altura, GLint largura, GLfloat velocidade, int vida);
    void addInimigo(Inimigo *i);
    void destroiBarril();
    void MoveY(GLfloat timeDelta);
    void decVida();
    void desenhaBarril();
    GLfloat getX(){return this->gX;};
    GLfloat getY(){return this->gY;};
    GLint getAltura(){return this->altura;};
    GLint getLargura(){return this->largura;};
    bool isValido(GLfloat yLimit);
};

#endif // !BARRIL_H