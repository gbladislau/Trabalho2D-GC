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
    Personagem corpo;
    GLfloat thetaGun;
    Arma * arma;
public:
    Player(GLint raioCabeca, int velocidade ){
        corpo.setRaioCabeca(raioCabeca);
        corpo.setVelocidade(velocidade);
        this->arma = new Arma(raioCabeca,100);
    }

    void desenhaPlayer(GLfloat x, GLfloat y, GLfloat thetaGun);
};


#endif // !PLAYER_H