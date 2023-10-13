#include "barril.h"
#include <iostream>
extern void desenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B);

Barril::Barril(GLfloat x, GLfloat y, GLint altura, GLint largura, GLfloat velocidade, int vida)
{
    this->altura = altura;
    this->largura = largura;
    this->velocidade = velocidade;
    this->vida = (vida);
    this->gX = x;
    this->gY = y;
    this->hasEnemy = bool(rand()%2);
}

void Barril::addInimigo(Inimigo* i){
    this->inimigo = i;
}

void Barril::destroiBarril(){
    delete this->inimigo;
}

void Barril::MoveY(GLfloat timeDelta)
{
    this->gY -= (this->velocidade*timeDelta);
}

void Barril::decVida()
{
    this->vida--;
}

void Barril::desenhaBarril()
{
    glPushMatrix();
        glTranslatef(this->gX,this->gY,0);
        //std::cout << "DESENHA"<< std::endl;
        desenhaRect(-this->altura,this->largura,0.78,0.549,0.055);
    glPopMatrix();
}

bool Barril::isValido(GLfloat yLimit)
{
    return (yLimit < this->gY) && (this->vida > 0);
}
