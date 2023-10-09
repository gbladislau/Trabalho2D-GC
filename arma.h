#ifndef ARMA_H
#define ARMA_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "tiro.h"

class Arma
{
private:
    GLfloat gX, gY, angulo;
    GLint altura;
    GLint largura;
    int velocidadeTiro;
    int tiroPorSegundo;
public:
    Arma(GLint raioCabeca, int velocidade){};
    Arma(GLint raioCabeca, int velocidade, int tirosPorSegundo){};

    void desenhaArma();
    Tiro* atira();
};
#endif // !ARMA_H