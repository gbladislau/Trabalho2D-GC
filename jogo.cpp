#include "jogo.h"
#include <stdexcept>


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


Jogo::Jogo()
{
    XMLDocument doc;
    XMLError eResult = doc.LoadFile("configuracoes.xml" );
    if (eResult != XML_SUCCESS) exit(1);

    struct configData config;

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

    try
    {
        XMLElement * p_root_element = doc.RootElement();
        XMLElement * p_arena = p_root_element->FirstChildElement("arena");
        XMLElement * p_jogador = p_root_element->FirstChildElement("jogador");
        XMLElement * p_inimigo = p_root_element->FirstChildElement("inimigo");
        XMLElement * p_barril = p_root_element->FirstChildElement("barril");

        if (p_arena== 0 || p_jogador == 0|| p_inimigo==0 ||p_barril==0) 
            throw std::runtime_error("tags faltando");

        // ARENA
        if(p_arena->Attribute("altura") && p_arena->Attribute("largura")){
            config.arenAltura = p_arena->FindAttribute("altura")->IntValue();
            config.arenaLargura = p_arena->FindAttribute("largura")->IntValue();
        }else throw std::runtime_error("\natributos altura e ou largura faltando (arena)");
        try
        {
            if(p_arena->Attribute("R") && p_arena->Attribute("G")&&  p_arena->Attribute("B")){
                p_arena->FindAttribute("R");
                p_arena->FindAttribute("G");
                p_arena->FindAttribute("B");
            }else throw std::runtime_error("\natributos R G B faltando (arena)" );
        }
        catch(const std::runtime_error& e) {
            std::cerr << "Cores Faltando usando padrão " << e.what() << std::endl;
        }

        //JOGADOR
        if(p_jogador->Attribute("raioCabeca")&&p_jogador->Attribute("velocidade")){
            config.raioCabecaJogador = p_jogador->FindAttribute("raioCabeçaJogador")->IntValue();
            config.velocidadeJogador = p_jogador->FindAttribute("velocidade")->IntValue();
        }else throw std::runtime_error("\natributos raioCabeca e ou velocidade faltando (jogador)");

    }
    catch(const std::runtime_error& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        exit(1);
    }
    
    std::cout << config.arenAltura <<" " << config.arenaLargura<< std::endl;
    
    this->arena = new Arena(config.arenAltura,config.arenaLargura,config.arenaR,config.arenaG,config.arenaB);
    this->jogador = new Player(config.raioCabecaJogador, config.velocidadeJogador);
}
