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
    GLint gX, gY;
    GLfloat thetaPerna;
    GLint raioCabeca = 0;
    GLfloat velocidadeDeMovimento = 1;
    GLfloat R, G, B;
public:
    Personagem(GLint x, GLint y){
        gX = x;
        gY = y;
        thetaPerna = 0;
    };
    void setRaioCabeca(GLint r){ this->raioCabeca = r;};
    void setVelocidade(GLfloat v){ this->velocidadeDeMovimento = v;};

    void desenhaRect(  GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B);

    void desenhaCirc(  GLint radius, GLfloat R,  GLfloat G, GLfloat B);

    void desenhaPernas();

    void Move(GLfloat dx, GLfloat dy);
    
    void desenhaPersonagem();

};



#endif // !JOGADOR_H