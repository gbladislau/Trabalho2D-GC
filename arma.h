#ifndef ARMA_H
#define ARMA_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Arma
{
private:
    GLint altura;
    GLint largura;
    int velocidadeTiro;
    int tiroPorSegundo;
public:
    Arma(GLint raioCabeça, int velocidade){};
    Arma(GLint raioCabeça, int velocidade, int tirosPorSegundo){};
};
#endif // !ARMA_H