/* ===============================================================
    OBS: a implementação do método Modificar(int numDesignacao)
    se encontra em cada um dos ".cpp" de cada classe. Nessa parte,
    "metodoModificar.cpp" está presente somente uma parte da main,
    com chamada do método junto com interações com o usuário. 
 ================================================================= */

#include <iostream>
#include <string>
#include <fstream>
//#include "Operador.h"
//#include "Gerente.h"
//#include "Diretor.h"
//#include "Presidente.h"


//Primeiro, testando como se fosse uma função na main, e não usando classses e métodos
#define NUM_LINHAS 6

void ModificaInformacoes(){
    
}

using namespace std;

int main(){
    // 1- Operador; 2- Gerente; 3- Diretor; 4- Presidente

    string linhas[NUM_LINHAS];
    string flag[NUM_LINHAS];
    string codigo;
    int numDesignacao;
    fstream arquivo;

    arquivo.open("Empresa.csv", ios::in);


    // Conferindo se a leitura deu certo
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



    return 0;
}