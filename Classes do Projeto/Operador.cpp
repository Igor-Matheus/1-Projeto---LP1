#include <iostream>
#include <fstream>
#include "Operador.h"

Operador::Operador(){

    // Inicializa todos os outros atributos
    Funcionarios();
}

Operador::~Operador(){}

void Operador::Modificar(){
    string linhas[NUM_LINHAS];
    string flag[NUM_LINHAS];
    string resposta1, resposta2;
    fstream arquivo;

    arquivo.open("Empresa.csv", ios::in);

    if (arquivo.is_open()){

        for (int i = 0; i < NUM_LINHAS; i++){
            getline(arquivo, linhas[i]);

            //flag
            flag[i] = linhas[i];
        }

        cout << "========================================= Modificar ========================================" << endl;

        cout << "Qual o código?" << endl;
        cin >> resposta1;

        cout << "O que deseja modificar? (codigo, nome, end, telefone, data de ingresso, designacao, salario)" << endl;
        cin >> resposta2;

        /*
        if (resposta == "designacao"){

        }
        */

        /*
        for (int i = 0; i < NUM_LINHAS; i++){
            

            
            flag[i] = linhas[i];

            cout << linhas[i] << endl;
        }
        */

        arquivo.close();

    } else {
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
}

void Operador::concederAumento(){
    
}