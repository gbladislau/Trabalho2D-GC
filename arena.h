#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

class Arena
{
private:
    GLint altura;
    GLint largura;
    GLdouble color[3];
public:
    Arena(GLint altura, GLint largura, GLdouble R, GLdouble G, GLdouble B);
    ~Arena();
    int getLargura(){
        return this->largura;
    }
    int getAltura(){
        return this->altura;
    }
    GLdouble* getColor(){
        return this->color;
    }
};
