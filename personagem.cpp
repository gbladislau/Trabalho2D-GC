#include "personagem.h"
#include "point.h"

void desenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
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

void Personagem::desenhaPersonagem()
{
    glLoadIdentity();
    glPushMatrix();
        // se move para posição
        glTranslatef(this->gX,this->gY,0);

        //Pernas
        desenhaPernas();
        
        // Cabeça
        desenhaCirc(this->raioCabeca,this->R,this->G,this->B);    

        //Arma
        glPushMatrix();
            glTranslatef(this->raioCabeca+(this->arma->getLargura()/2)+1,-this->raioCabeca,0);           
            this->arma->desenhaArma();
        glPopMatrix();
    glPopMatrix();
}

void Personagem::setColors(GLfloat R, GLfloat G, GLfloat B)
{
    this->R = R;
    this->G = G;
    this->B = B;
}


void desenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B)
{
    glColor3f(R,G,B);

    glBegin(GL_POLYGON);
        glVertex3f(-width/2.0, 0, 0.0);
        glVertex3f(width/2.0, 0 , 0.0);
        glVertex3f(width/2.0,height, 0.0);
        glVertex3f(-width/2.0,height, 0.0);
    glEnd();

}


void Personagem::desenhaPernas(){
    glPushMatrix();
        glPushMatrix();
            //esq
            glRotatef(this->thetaPerna,1,0,0);
            glTranslatef(-(this->raioCabeca/8)*3,0,0);
            desenhaRect(this->raioCabeca*2,this->raioCabeca/2,0,0,0);
        glPopMatrix();

        glPushMatrix();
            // dir
            glRotatef(this->thetaPerna,1,0,0);
            glTranslatef(+(this->raioCabeca/8)*3,0,0);
            desenhaRect(-this->raioCabeca*2,this->raioCabeca/2,0,0,0);
        glPopMatrix();
    glPopMatrix();
}


void Personagem::Move(GLfloat dx, GLfloat dy)
{ 
    
    this->gX += dx;
    this->gY += dy;
    this->thetaPerna -= (dy/(this->raioCabeca)) *(180/M_PI);
}
