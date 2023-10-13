#include "barril.h"
#include <iostream>
#include <cstring>
extern void desenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B);


void Barril::ImprimeVida()
{   
    static void *font = GLUT_BITMAP_HELVETICA_12;
    glPushMatrix();
        static char str[1000];
        glColor3f(1.0, 1.0, 1.0);
        // Cria a string a ser impressa
        char *tmpStr;
        sprintf(str, "%d", this->vida);
        tmpStr = str;
        
        // Define a posicao onde vai comecar a imprimir
        glRasterPos2f(0, 0);
        // Imprime um caractere por vez
        
        while (*tmpStr)
        {
            glutBitmapCharacter(font, *tmpStr);
            tmpStr++;
        }
    glPopMatrix();
}


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
        glTranslatef(this->largura/2 ,-this->altura/2,0);
        glTranslatef(int(-10*(log10(this->vida)+1)) - 2,0,0);
        this->ImprimeVida();
    glPopMatrix();
}

bool Barril::isValido(GLfloat yLimit)
{
    return (yLimit < this->gY) && (this->vida > 0);
}
