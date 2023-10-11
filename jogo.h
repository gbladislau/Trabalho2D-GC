#ifndef JOGO_H
#define JOGO_H

#include "tinyxml2.h"
#include <stdio.h>
#include <iostream>
#include <list>
#include "arena.h"
#include "player.h"
#include "barril.h"

using namespace tinyxml2;
using namespace std;


struct configData
{
    GLint arenAltura;
    GLint arenaLargura;
    GLdouble arenaR =0 , arenaG = 0, arenaB = 1;

    GLint raioCabecaJogador;
    int velocidadeJogador;

    GLint raioCabecaInimigo;
    int tirosPorSegundo;
    int velocidadeTiro;

    GLint alturaBarril;
    GLint larguraBarril;
    GLint numeroTirosBarril;
    GLint nParaGanhar;
    GLint velocidadeBarril;
};


class Jogo
{
private:
    Arena * arena;
    int numeroMax;
    int contadorDestruidos = 0;
    Player * jogador;
    struct configData config;

public:
    list <Barril*> barril_list;
    list <Tiro*> tirosDosInimigos;
    list <Tiro*> tirosDoPlayer;

    void readConfigFile(char* path);
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
    Player* getPlayer(){
        return this->jogador;
    }
};

#endif // !JOGO_H