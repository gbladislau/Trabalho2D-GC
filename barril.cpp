#include "barril.h"
extern void desenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B);

Barril::Barril(GLfloat x, GLfloat y, GLint altura, GLint largura, GLfloat velocidade, int vida): 
                altura(altura), largura(largura), velocidade(velocidade), vida(vida)
{
    this->gX = gX;
    this->gY = gY;
    this->hasEnemy = bool(rand()%2);
}

void Barril::addInimigo(Inimigo* i){
    this->inimigo = i;
}

void Barril::destroiBarril(){
    delete this->inimigo;
}

void Barril::Move()
{
    this->gY -= this->velocidade;
}

void Barril::decVida()
{
    this->vida--;
}

void Barril::desenhaBarril()
{
    glPushMatrix();
        glTranslatef(this->gX,this->gY,0);
        desenhaRect(this->altura,this->largura,0.78,0.549,0.055);
    glPopMatrix();
}
