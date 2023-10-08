#include "personagem.h"
#include "point.h"


void Personagem::desenhaPersonagem()
{
    glLoadIdentity();
    glPushMatrix();
        // se move para posição
        glTranslatef(this->gX,this->gY,0);

        // Cabeça
        desenhaCirc(this->raioCabeca,this->R,this->G,this->B);

        //Pernas
        desenhaPernas();

    
    glPopMatrix();
}

void Personagem::desenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B)
{
    glColor3f(R,G,B);

    glBegin(GL_POLYGON);
        glVertex3f(-width/2, 0, 0.0);
        glVertex3f(width/2, 0 , 0.0);
        glVertex3f(width/2,height, 0.0);
        glVertex3f(-width/2,height, 0.0);
    glEnd();

}

void Personagem::desenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
    glPushMatrix();
        glColor3f(R,G,B);
        glPointSize(1);
        
        int qntdPoints = 360/1;
        Point2D *point = new Point2D(0,0);

        glBegin(GL_POLYGON);

            for (int p = 0; p < qntdPoints; p++){
                point->Translate(0,radius);
                glVertex3f(point->getX(),point->getY(),0);   
                point->RotateZ(1);
                point->Translate(0,-radius);
            }
            
        glEnd();     
      
    glPopMatrix();   
    delete point;
}
void Personagem::desenhaPernas(){
    glPushMatrix();
        //esq
        glTranslatef(-(this->raioCabeca/8)*3,0,0);
        desenhaRect(this->raioCabeca/3,this->raioCabeca/4,0,0,0);

        //0
        glTranslatef(+(this->raioCabeca/8)*3,0,0);

        // dir
        glTranslatef(+(this->raioCabeca/8)*3,0,0);
        desenhaRect(this->raioCabeca/3,this->raioCabeca/4,0,0,0);
    glPopMatrix();
}


void Personagem::Move(GLfloat dx, GLfloat dy)
{ 
    
    this->gX += dx;
    this->gY += dy;
    this->thetaPerna -= (dy/(this->raioCabeca/3*2)) *(180/M_PI);
}

// void Personagem::MoveEmX(GLfloat dx)
// {
//     this->gX += dx;
//     this->thetaPerna -= (dx/(this->raioCabeca/3*2)) *(180/M_PI);
// }