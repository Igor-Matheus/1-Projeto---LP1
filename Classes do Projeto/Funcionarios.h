#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <iostream>
#include <string>
#include <fstream>

#define NUM_LINHAS 100

using namespace std;

class Funcionarios{
    public:
        Funcionarios();

        //Para não precisar fazer os sets
        Funcionarios(string codigo, string nome, string data,
        string endereco, double salario, string telefone, string designacao);
        
        //Destrutor
        virtual ~Funcionarios();

        //Quais seriam virtuais ou virtuais puros?
        void addFuncionario();
        void criarArquivo();
        void lerArquivo();

        //Usando a API
        string retornaEndereco(string cep);

        //ou virtual void?
        void modificarFuncionario();
        void excluirFuncionario();
        
        string getCodigo();
        string getNome();
        string getData();
        string getEndereco();
        string getTelefone();
        string getDesignacao();
        double getSalario();

        virtual void concederAumento();
        void calculaFolhaSalarial();

        int diasTrabalhados();
        double horasExtras();

        void imprimeFolhaSalarial();
        void imprimeFolhaSalarialEmpresa();

    protected: //ou é melhor private?
        fstream arquivo;
        string linhas[NUM_LINHAS];

        string codigo;
        string nome;
        string data;
        string endereco;
        double salario;
        string telefone;
        string designacao;
};

#endif