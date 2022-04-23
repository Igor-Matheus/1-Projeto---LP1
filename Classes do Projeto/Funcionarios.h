#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <string>

#define NUM_LINHAS 6

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
        void Adicionar();
        void Excluir();
        virtual void Modificar();

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
        string codigo;
        string nome;
        string data;
        string endereco;
        double salario;
        string telefone;
        string designacao;
};

#endif