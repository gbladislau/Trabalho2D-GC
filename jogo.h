#include "tinyxml2.h"
#include "arena.h"
#include <stdio.h>
#include <iostream>

using namespace tinyxml2;
class Jogo
{
private:
    Arena * arena;
public:
    Jogo(/* args */);
    ~Jogo();
    Arena* getArena(){
        return this->arena;
    }
};

Jogo::Jogo()
{
    XMLDocument doc;
    XMLError eResult = doc.LoadFile("configuracoes.xml" );
    if (eResult != XML_SUCCESS) exit(1);

    GLint arenAltura;
    GLint arenaLargura;

    try
    {
        XMLElement * p_root_element = doc.RootElement();
        XMLElement * p_arena = p_root_element->FirstChildElement("arena");
        XMLElement * p_jogador = p_root_element->FirstChildElement("jogador");
        XMLElement * p_inimigo = p_root_element->FirstChildElement("inimigo");
        
        
        arenAltura = p_arena->FindAttribute("altura")->IntValue();
        arenaLargura = p_arena->FindAttribute("largura")->IntValue();
    }
    catch(const std::exception& e)
    {
        std::cout << "ERRO AO LER ARQUIVO configuracoes.xml\nVerifique o arquivo e as tags" << std::endl;
        std::cerr << e.what() << '\n';
    }
    
    std::cout << arenAltura <<" " << arenaLargura<< std::endl;
    
    this->arena = new Arena(arenAltura,arenaLargura);
}

Jogo::~Jogo()
{
    delete arena;
}
