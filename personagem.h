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
    GLint raioCabeca = 0;
    GLfloat velocidadeDeMovimento = 1;
    GLfloat R, G, B;
public:
    Personagem(){};
    void setRaioCabeca(GLint r){ this->raioCabeca = r;};
    void setVelocidade(GLfloat v){ this->velocidadeDeMovimento = v;};

    void desenhaRect(  GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B);

    void desenhaCirc(  GLint radius, GLfloat R,  GLfloat G, GLfloat B);

    void desenhaPersonagem(GLint x, GLint y);

};



#endif // !JOGADOR_H