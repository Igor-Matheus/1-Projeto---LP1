#include "Diretor.h"

Diretor::Diretor(){
    // Inicializa todos os outros atributos
    Funcionarios();

    areaSupervisao = "NaN";
    areaFormacao = "NaN";
}

Diretor::~Diretor(){}

void Diretor::concederAumento(){

}

std::string Diretor::getAreaSupervisao(){
    return areaSupervisao;
}
void Diretor::setAreaSupervisao(std::string aS){
    areaSupervisao = aS;
}

std::string Diretor::getAreaFormacao(){
    return areaFormacao;
}
void Diretor::setAreaFormacao(std::string aF){
    areaFormacao = aF;
}