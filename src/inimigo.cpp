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

void Inimigo::apontaParaJogador(Point2D posicaoJogador)
{
    GLfloat angulo;
    Point2D base = this->corpo->getBaseArma();
    
    angulo = (posicaoJogador.AngleBeetwen(this->corpo->getBaseArma(),posicaoJogador)*180/M_PI) - 270;
    // std::cout << angulo +360 << std::endl;

    if (angulo+360 > 30) angulo = 30;
    if (angulo +360<  -30) angulo = -30;
    this->corpo->getArma()->setAngulo(angulo);
}

Tiro *Inimigo::atira()
{
    return this->corpo->atira();
}
