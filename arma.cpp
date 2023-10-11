#include "arma.h"
#include "math.h"

extern void desenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B);

void Arma::desenhaArma()
{
    glRotatef(this->angulo,0,0,1);
    desenhaRect(this->altura,this->largura,1,0,0);
}

Tiro *Arma::atira()
{
    return new Tiro(this->gX,this->gY,this->angulo);
}

void Arma::accAngulo(GLfloat dx)
{
    this->angulo -= dx;
    if (this->angulo > 30) this->angulo = 30;
    if (this->angulo < -30) this->angulo = -30;
}
