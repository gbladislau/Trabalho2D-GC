#include "arma.h"
#include "math.h"
#include <iostream>

extern void desenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B);

void Arma::desenhaArma()
{
    glRotatef(this->angulo,0,0,1);
    desenhaRect(this->altura,this->largura,1,0,0);
}

Tiro *Arma::atira(Point2D baseArma, Point2D pontaArma)
{
    GLfloat angulo = baseArma.AngleBeetwen(baseArma,pontaArma);
    // std::cout << baseArma.getX() << baseArma.getY() << angulo <<this->velocidadeTiro << std::endl;
    return new Tiro(pontaArma.getX(),pontaArma.getY(),angulo,this->velocidadeTiro);
}

void Arma::accAngulo(GLfloat dx)
{
    this->angulo -= dx;
    if (this->angulo > 30) this->angulo = 30;
    if (this->angulo < -30) this->angulo = -30;
}
