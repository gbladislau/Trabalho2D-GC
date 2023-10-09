#ifndef JOGADOR_H
#define JOGADOR_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "arma.h"

class Personagem
{
private:
    GLfloat gX, gY;
    GLfloat thetaPerna;
    GLint raioCabeca = 0;
    GLfloat velocidadeDeMovimento = 1;
    GLfloat R, G, B;
    Arma * arma;
    GLfloat thetaGun;
public:
    Personagem(GLfloat x, GLfloat y,GLint r){
        gX = x;
        gY = y;
        thetaPerna = 0;
        this->raioCabeca = r;
        this->arma = new Arma(this->raioCabeca,100);
    };
    void setRaioCabeca(GLint r){ this->raioCabeca = r;};
    void setVelocidade(GLfloat v){ this->velocidadeDeMovimento = v;};

    void desenhaPernas();

    void Move(GLfloat dx, GLfloat dy);
    
    void desenhaPersonagem();
    GLfloat getVelocidade(){return this->velocidadeDeMovimento;};
    GLfloat getGx(){return this->gX;};
    GLfloat getGy(){return this->gY;};
    GLint getRaioCabeca(){return this->raioCabeca;};
    void setColors(GLfloat R,GLfloat G,GLfloat B);

};



#endif // !JOGADOR_H