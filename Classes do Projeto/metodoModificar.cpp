/* ===============================================================
    OBS: a implementação do método Modificar(int numDesignacao)
    se encontra em cada um dos ".cpp" de cada classe. Nessa parte,
    "metodoModificar.cpp" está presente somente uma parte da main,
    com chamada do método junto com interações com o usuário. 
 ================================================================= */

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"


#define NUM_LINHAS 6

using namespace std;

int main(){
    // 1- Operador; 2- Gerente; 3- Diretor; 4- Presidente

/*
    string linhas[NUM_LINHAS];
    string flag[NUM_LINHAS];
    string codigo;
    int numDesignacao;
    int contador = 0;
    fstream arquivo;
    arquivo.open("Empresa.csv", ios::in);

    if (arquivo.is_open()){

        for (int i = 0; i < NUM_LINHAS; i++){
            getline(arquivo, linhas[i]);

            //flag
            flag[i] = linhas[i];
            contador++;
            cout << linhas[i] << endl;
        }

        arquivo.close();

    } else {
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }

    cout << "\n";
    cout << "\n";

    for (int i = 0; i < NUM_LINHAS; i++){
        cout << flag[i] << endl;
    }
*/

    return 0;
}