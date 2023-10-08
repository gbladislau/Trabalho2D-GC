#ifndef PLAYER_H
#define PLAYER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "arma.h"
#include "personagem.h"

class Player
{
private:
    Personagem* corpo;
    GLfloat thetaGun;
    Arma * arma;
public:
    Player(GLint raioCabeca, int velocidade, GLfloat x,GLfloat y){
        this->corpo = new Personagem(x, y);
        this->corpo->setRaioCabeca(raioCabeca);
        this->corpo->setVelocidade(velocidade);
        this->arma = new Arma(raioCabeca,100);
    }

    void desenhaPlayer();
    void Move(GLfloat dx, GLfloat dy);
    GLint getVelocidade();
    GLfloat getGx();
    GLfloat getGy();
    GLint getRaioCabeca();
};

#endif // !PLAYER_H