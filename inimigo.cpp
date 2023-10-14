#include "inimigo.h"

void Inimigo::desenhaInimigo()
{
    this->corpo->desenhaPersonagem();
}

void Inimigo::Move(GLfloat dx, GLfloat dy)
{
    this->corpo->Move(dx,dy);
}

GLint Inimigo::getVelocidade()
{
    return this->corpo->getVelocidade();
}

GLfloat Inimigo::getGx()
{
    return this->corpo->getGx();
}

GLfloat Inimigo::getGy()
{
    return this->corpo->getGy();
}

GLint Inimigo::getRaioCabeca(){
    return this->corpo->getRaioCabeca();
}

void Inimigo::changeArmaDirection(GLfloat dx)
{
    this->corpo->getArma()->accAngulo(dx);
}

Tiro *Inimigo::atira()
{
    return this->corpo->atira();
}
