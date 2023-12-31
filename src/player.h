#ifndef PLAYER_H
#define PLAYER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "arma.h"
#include "personagem.h"
#include "point.h"

class Player
{
private:
    Personagem* corpo;
public:
    Player(GLint raioCabeca, GLfloat velocidade, GLfloat x,GLfloat y, GLfloat velocidadeTiro){
        this->corpo = new Personagem(x, y,raioCabeca,velocidadeTiro);
        this->corpo->setVelocidade(velocidade);
        this->corpo->setColors(0,1,0);

    }

    void desenhaPlayer();
    void Move(GLfloat dx, GLfloat dy);
    GLint getVelocidade();
    GLfloat getGx();
    GLfloat getGy();
    GLint getRaioCabeca();
    void changeArmaDirection(GLfloat dx);
    Tiro* atira();
    void clearMemoryPersonagem(){
        this->corpo->clearMemoryArma();
        delete this->corpo;
    }
};

#endif // !PLAYER_H