#include "arma.h"


void desenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B)
{
    glColor3f(R,G,B);

    glBegin(GL_POLYGON);
        glVertex3f(-width/2, 0, 0.0);
        glVertex3f(width/2, 0 , 0.0);
        glVertex3f(width/2,height, 0.0);
        glVertex3f(-width/2,height, 0.0);
    glEnd();

}

void Arma::desenhaArma()
{
    desenhaRect(this->altura,this->largura,1,0,0);
}

Tiro *Arma::atira()
{
    return new Tiro(this->gX,this->gY,this->angulo);
}
