#include "player.h"

void Player::desenhaPlayer()
{
    this->corpo->desenhaPersonagem();
}

void Player::Move(GLfloat dx, GLfloat dy)
{
    this->corpo->Move(dx,dy);
}

GLint Player::getVelocidade()
{
    return this->corpo->getVelocidade();
}

GLfloat Player::getGx()
{
    return this->corpo->getGx();
}

GLfloat Player::getGy()
{
    return this->corpo->getGy();
}

GLint Player::getRaioCabeca(){
    return this->corpo->getRaioCabeca();
}

void Player::changeArmaDirection(GLfloat dx)
{
    this->corpo->getArma()->accAngulo(dx);
}

Tiro *Player::atira()
{
    return this->corpo->atira();
}
