#ifndef ARMA_H
#define ARMA_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "tiro.h"

class Arma
{
private:
    GLfloat gX, gY, angulo = 0;
    GLint altura;
    GLint largura;
    int velocidadeTiro;
    int tiroPorSegundo;
public:
    Arma(GLint raioCabeca, int velocidade){
        this->altura = raioCabeca*3;
        this->largura = raioCabeca/2;
        this->velocidadeTiro = velocidade;
        this->tiroPorSegundo = -1;
    };
    Arma(GLint raioCabeca, int velocidade, int tirosPorSegundo){};

    void desenhaArma();
    GLint getLargura(){return this->largura;};
    Tiro* atira();
    void accAngulo(GLfloat dx);

    GLfloat getAngulo(){return this->angulo;};
};
#endif // !ARMA_H