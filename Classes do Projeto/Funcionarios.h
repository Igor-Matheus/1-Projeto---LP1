#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <string>

using namespace std;

class Funcionarios{
    public:
        Funcionarios();

        //Para não precisar fazer os sets
        Funcionarios(string nome, string data, string endereco,
        double salario, string telefone, string designacao);
        
        //Destrutor
        virtual ~Funcionarios();

        //Quais seriam virtuais ou virtuais puros?
        void Adicionar();
        void Excluir();
        void Modificar();

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
        string nome;
        string data;
        string endereco;
        double salario;
        string telefone;
        string designacao;
};

#endif