#include "jogo.h"
#include <stdexcept>

void Jogo::readConfigFile(char* path){
    XMLDocument doc;
    XMLError eResult = doc.LoadFile(path);
    if (eResult != XML_SUCCESS) exit(1);

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
            this->config.arenAltura = p_arena->FindAttribute("altura")->IntValue();
            this->config.arenaLargura = p_arena->FindAttribute("largura")->IntValue();
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
            config.raioCabecaJogador = p_jogador->FindAttribute("raioCabeca")->IntValue();
            config.velocidadeJogador = p_jogador->FindAttribute("velocidade")->IntValue();
        }else throw std::runtime_error("\natributos raioCabeca e ou velocidade faltando (jogador)");

        //BARRIL
        if( p_barril->Attribute("largura") && p_barril->Attribute("altura")          && 
            p_barril->Attribute("numeroTiros") && p_barril->Attribute("nParaGanhar") &&
            p_barril->Attribute("velocidade") )
        {
            config.alturaBarril = p_barril->FindAttribute("altura")->IntValue();
            config.larguraBarril = p_barril->FindAttribute("largura")->IntValue();
            config.numeroTirosBarril = p_barril->FindAttribute("numeroTiros")->IntValue();
            config.nParaGanhar = p_barril->FindAttribute("nParaGanhar")->IntValue();
            config.velocidadeBarril = p_barril->FindAttribute("velocidade")->DoubleValue();
            if(p_barril->Attribute("segParaSair")) config.segParaSairBarril = p_barril->FindAttribute("segParaSair")->IntValue();
            else config.segParaSairBarril = 1200;
        }else throw std::runtime_error("\natributos relacionados a barril faltando");
        
    }
    catch(const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    
}

Jogo::Jogo()
{
    char path[20]= "./configuracoes.xml";
    this->readConfigFile(path);
    
    std::cout <<"Criando arena de altura e largura: " <<config.arenAltura <<" " << config.arenaLargura<< std::endl;
    
    this->arena = new Arena(config.arenAltura,config.arenaLargura,config.arenaR,config.arenaG,config.arenaB);
    this->jogador = new Player(config.raioCabecaJogador, config.velocidadeJogador,0,(-config.arenAltura/2.0)+config.raioCabecaJogador);
}
