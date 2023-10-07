#ifndef JOGO_H
#define JOGO_H

#include "tinyxml2.h"
#include "arena.h"
#include "player.h"
#include <stdio.h>
#include <iostream>

using namespace tinyxml2;

class Jogo
{
private:
    Arena * arena;
    int numeroMax;
    int contadorDestruidos = 0;
    Player * jogador;

public:
    Jogo();
    Arena* getArena(){
        return this->arena;
    }
    void incContador(){
        this->contadorDestruidos++;
    }
    bool isGameDone(){
        return this->contadorDestruidos >= this->numeroMax;
    }
};

#endif // !JOGO_H