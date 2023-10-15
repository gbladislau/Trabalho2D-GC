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
    GLfloat segParaSairBarril;
    GLdouble arenaR =0 , arenaG = 0, arenaB = 1;

    GLint raioCabecaJogador;
    GLfloat velocidadeJogador;
    GLfloat velocidadeTiroJogador;

    GLint raioCabecaInimigo;
    int tirosPorSegundo;
    GLfloat velocidadeTiro;
    GLfloat velocidadeTiroInimigo;

    GLint alturaBarril;
    GLint larguraBarril;
    GLint numeroTirosBarril;
    GLint nParaGanhar;
    GLfloat velocidadeBarril;

    bool semBarril = false;
    bool semInimigo = false;
    bool desativaColisao = false;
};


class Jogo
{
private:
    Arena * arena;
    Player * jogador;
    struct configData config;

public:
    int contadorDestruidos = 0;
    list <Barril*> barril_list;
    list <Tiro*> tirosDosInimigos;
    list <Tiro*> tirosDoPlayer;
    bool gameOver_lose = false;

    void readConfigFile(char* path);
    Jogo();
    Arena* getArena(){
        return this->arena;
    }
    void incContador(){
        this->contadorDestruidos++;
    }
    bool isGameDone(){
        return this->contadorDestruidos >= this->config.nParaGanhar;
    }
    Player* getPlayer(){
        return this->jogador;
    }
    configData getConfig(){return this->config;};
    void cleanMemoryPlayereArena();
};

#endif // !JOGO_H