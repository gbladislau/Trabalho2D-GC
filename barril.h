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
    Barril(GLfloat x, GLfloat y, GLint altura, GLint largura, GLfloat velocidade, int vida);
    void addInimigo(Inimigo *i);
    void destroiBarril();
    void Move();
    void decVida();
    void desenhaBarril();
};

#endif // !BARRIL_H