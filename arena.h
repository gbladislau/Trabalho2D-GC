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
public:
    Arena(GLint altura, GLint largura);
    ~Arena();
    int getLargura(){
        return this->largura;
    }
    int getAltura(){
        return this->altura;
    }
};

Arena::Arena(GLint altura, GLint largura)
{
    this->altura = altura;
    this->largura = largura;
}

Arena::~Arena()
{
}
