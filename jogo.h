#include "tinyxml2.h"
#include "arena.h"
#include <stdio.h>

using namespace tinyxml2;
class jogo
{
private:
    Arena * arena;
public:
    jogo(/* args */);
    ~jogo();
};

jogo::jogo()
{
    XMLDocument doc;
    XMLError eResult = doc.LoadFile("configuracoes.xml" );
    if (eResult != XML_SUCCESS) exit(1);

    XMLElement * p_root_element = doc.RootElement();
    XMLElement * p_arena = p_root_element->FirstChildElement("arena");
    GLint arenAltura = p_arena->FindAttribute("altura")->IntValue();
    GLint arenaLargura = p_arena->FindAttribute("largura")->IntValue();
    //std::cout <<  << std::endl;
}

jogo::~jogo()
{
}
