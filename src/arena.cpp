#include "arena.h"


Arena::Arena(GLint altura, GLint largura, GLdouble R, GLdouble G, GLdouble B)
{
    this->altura = altura;
    this->largura = largura;
    this->color[0] = R;
    this->color[1] = G;
    this->color[2] = B;
}   
