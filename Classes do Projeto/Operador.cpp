#include <iostream>
#include <fstream>
#include "Operador.h"

Operador::Operador(){

    // Inicializa todos os outros atributos
    Funcionarios();
}

Operador::~Operador(){}

void Operador::Modificar(int numDesignacao){
    string linhas[NUM_LINHAS];
    string flag[NUM_LINHAS];
    fstream arquivo;

    arquivo.open("Empresa.csv", ios::in);

    if (arquivo.is_open()){

        for (int i = 0; i < NUM_LINHAS; i++){
            getline(arquivo, linhas[i]);

            //flag
            flag[i] = linhas[i];

            cout << linhas[i] << endl;
        }

        //teste do flag ======================
        cout << "\n\n";
        for (int i = 0; i < NUM_LINHAS; i++){
            cout << flag[i] << endl;
        }
        // ===================================

        arquivo.close();

    } else {
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
}

void Operador::concederAumento(){
    
}