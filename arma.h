#ifndef ARMA_H
#define ARMA_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "tiro.h"
#include "point.h"

class Arma
{
private:
    GLfloat angulo = 0;
    GLint altura;
    GLint largura;
    double velocidadeTiro;
    int tiroPorSegundo;
public:
    Arma(GLint raioCabeca, double velocidade){
        this->altura = raioCabeca*3;
        this->largura = raioCabeca/2;
        this->velocidadeTiro = velocidade;
        this->tiroPorSegundo = -1;
    }

    Arma(GLint raioCabeca, double velocidade, int tirosPorSegundo){
        this->altura = raioCabeca*3;
        this->largura = raioCabeca/2;
        this->velocidadeTiro = velocidade;
        this->tiroPorSegundo = tirosPorSegundo;
    }

    GLint getLargura() { return this->largura; }
    GLint getAltura() { return this->altura; }

    GLfloat getAngulo(){return this->angulo;}
    void setAngulo(GLfloat ang){this->angulo = ang;}

    void desenhaArma();

    Tiro *atira(Point2D baseArma, Point2D pontaArma);
    
    void accAngulo(GLfloat dx);

};
#endif // !ARMA_H