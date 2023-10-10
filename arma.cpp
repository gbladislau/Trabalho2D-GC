#include "arma.h"
#include "math.h"

extern void desenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B);

void Arma::desenhaArma()
{
    desenhaRect(this->altura,this->largura,1,0,0);
}

Tiro *Arma::atira()
{
    return new Tiro(this->gX,this->gY,this->angulo);
}

void Arma::setAngulo(GLint dx)
{
    this->angulo -= (dx/(this->altura)) *(180/M_PI);
}
