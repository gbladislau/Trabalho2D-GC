#ifndef TIRO_H
#define	TIRO_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#define radiusTiro 5

class Tiro {
    GLfloat gXInit; 
    GLfloat gYInit; 
    GLfloat gX; 
    GLfloat gY; 
    GLfloat gDirectionAng;
    GLfloat gVel;
    GLfloat raioTiro;
private:
    void DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B);
    void DesenhaTiro(GLfloat x, GLfloat y);
public:
    Tiro(GLfloat x, GLfloat y, GLfloat directionAng, GLfloat velocidade){
        gXInit = x; 
        gYInit = y; 
        gX = x; 
        gY = y; 
        gDirectionAng = directionAng; 
        gVel = velocidade;
        raioTiro = radiusTiro;
    };

    void Desenha(){ 
        // std::cout << gX<< gY << std::endl;
        DesenhaTiro(gX, gY);
    };

    void Move(GLdouble timedif);

    bool Valido(GLfloat distMaxX, GLfloat distMaxY);

    void GetPos(GLfloat &xOut, GLfloat &yOut){
        xOut = gX;
        yOut = gY;
    };

    GLfloat getRaio(){return this->raioTiro;};
};

#endif	/* TIRO_H */

