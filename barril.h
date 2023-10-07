#ifndef BARRIL_H
#define BARRIL_H


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

class barril
{
private:
    GLint altura;
    GLint largura;
    GLfloat velocidade;
    int numeroTiros;
public:
    barril();
};

barril::barril()
{
}

#endif // !BARRIL_H