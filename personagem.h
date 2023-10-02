#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

class personagem
{
private:
    GLint raioCabeca;
    GLfloat velocidadeDeMovimento;
    GLint tirosPorSegundo;
    GLint velocidadeTiro;
public:
    personagem(/* args */);
    ~personagem();
};

personagem::personagem(/* args */)
{
}

personagem::~personagem()
{
}
