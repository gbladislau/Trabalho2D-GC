#ifndef INIMIGO_H
#define INIMIGO_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "personagem.h"
class Inimigo
{
private:
    Personagem * corpo;
    GLfloat deltaTiro = 0.0;
public:

    Inimigo(GLint raioCabeca, int velocidade, int tirosPorSegundo,
            GLfloat velocidadeTiro,GLfloat x,GLfloat y){
                
        this->corpo = new Personagem(x, y,raioCabeca,velocidadeTiro,tirosPorSegundo);
        this->corpo->setVelocidade(velocidade);
        this->corpo->setColors(0.7,0.3,0);
    }

    void desenhaInimigo();
    void Move(GLfloat dx, GLfloat dy);
    GLint getVelocidade();
    GLfloat getGx();
    GLfloat getGy();
    GLint getRaioCabeca();
    void changeArmaDirection(GLfloat dx);
    void apontaParaJogador(Point2D posicaoJogador);
    Tiro *atira();
    void accDeltaTiro(GLfloat timediff){this->deltaTiro+= timediff;}
    GLfloat getDeltaTiro(){return this->deltaTiro;}
    void clearMemoryPersonagem(){
        this->corpo->clearMemoryArma();
        delete this->corpo;
    }
};

#endif // !INIMIGO_H