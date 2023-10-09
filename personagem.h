#ifndef JOGADOR_H
#define JOGADOR_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

class Personagem
{
private:
    GLfloat gX, gY;
    GLfloat thetaPerna;
    GLint raioCabeca = 0;
    GLfloat velocidadeDeMovimento = 1;
    GLfloat R, G, B;
public:
    Personagem(GLfloat x, GLfloat y){
        gX = x;
        gY = y;
        thetaPerna = 0;
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