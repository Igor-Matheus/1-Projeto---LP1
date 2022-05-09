#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <iostream>
#include <string>
#include <fstream>

#define NUM_LINHAS 100

using namespace std;

//Quais seriam os métodos virtuais ou virtuais puros?
class Funcionario{
    public:
        Funcionario();
        
        //Destrutor
        virtual ~Funcionario();

        void addFuncionario();
        void criarArquivo();
        void lerArquivo();
        void exibirArquivo();

        //Usando a API
        string retornaEndereco(string cep);
        string forEndereco(string api[], int line, int tam);

        void separadorColuna(string colunaAtual[], int del[]);
        void colunas();

        /*======================================= Para as modificações ===============================================*/
        //ou virtual void?
        void modificarFuncionario();

        void modificaCodigo(string cod);
        void modificaNome(string cod);
        void modificaEndereco(string cod);
        void modificaTelefone(string cod);
        void modificaData(string cod);
        void modificaSalario(string cod);

        void modificaDesignacao(string cod);
        void modDesigDeOperador(string cod);
        void modDesigDeGerente(string cod);
        void modDesigDeDiretor(string cod);
        void modDesigDePresidente(string cod);
        void modDesigParaOperador(string cod);
        
        /*============================================================================================================*/

        void excluirFuncionario();
        
        virtual void concederAumento();
        void calculaFolhaSalarial();

        int diasTrabalhados();
        double horasExtras();

        void imprimeFolhaSalarial();
        void imprimeFolhaSalarialEmpresa();

        /*
        string getCodigo();
        string getNome();
        string getData();
        string getEndereco();
        string getTelefone();
        string getDesignacao();
        double getSalario();
        */

    protected: 
        fstream arquivo;
        string linhas[NUM_LINHAS];

        string codigo[5], nome[100], end[150], telefone[15], data[15];
        string desig[30], salario[50], sup[100], acad[100], formacao[100];
};

#endif