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
    Player(GLint raioCabeca, int velocidade, GLfloat x,GLfloat y){
        this->corpo = new Personagem(x, y,raioCabeca);
        this->corpo->setVelocidade(velocidade);
        this->corpo->setColors(0,1,0);

    }

    void desenhaPlayer();
    void Move(GLfloat dx, GLfloat dy);
    GLint getVelocidade();
    GLfloat getGx();
    GLfloat getGy();
    GLint getRaioCabeca();
    void changeArmaDirection(Point2D new_pos);
};

#endif // !PLAYER_H