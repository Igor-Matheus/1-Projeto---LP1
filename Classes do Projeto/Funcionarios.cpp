#include "Funcionarios.h"

Funcionarios::Funcionarios(){
    nome = "NaN";
    data = "NaN";
    endereco = "NaN";
    salario = 0;
    telefone = "NaN";
    designacao = "NaN";
}

Funcionarios::Funcionarios(string nome, string data, string endereco,
double salario, string telefone, string designacao){

    this -> nome = nome;
    this -> data = data;
    this -> endereco = endereco;
    this -> salario = salario;
    this -> telefone = telefone;
    this -> designacao = designacao;

}

Funcionarios::~Funcionarios(){}

string Funcionarios::getNome(){
    return nome;
}

string Funcionarios::getData(){
    return data;
}

string Funcionarios::getEndereco(){
    return endereco;
}

string Funcionarios::getTelefone(){
    return telefone;
}

string Funcionarios::getDesignacao(){
    return designacao;
}

double Funcionarios::getSalario(){
    return salario;
}

void Funcionarios::Adicionar(){

}
void Funcionarios::Excluir(){

}
void Funcionarios::Modificar(){

}

void Funcionarios::concederAumento(){

}
void Funcionarios::calculaFolhaSalarial(){

}

int Funcionarios::diasTrabalhados(){

}
double Funcionarios::horasExtras(){

}

void Funcionarios::imprimeFolhaSalarial(){

}
void Funcionarios::imprimeFolhaSalarialEmpresa(){
    
}




