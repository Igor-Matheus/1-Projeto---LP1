/* ===============================================================
    OBS: a implementação do método modificarFuncionario()
    se encontra em cada um dos ".cpp" de cada classe. Nessa parte,
    "metodoModificar.cpp" está presente somente uma parte da main. 
 ================================================================= */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //para usar o system("CLS")
/*
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"*/

//#include "Funcionarios.h"
#define NUM_LINHAS 100

using namespace std;

void modificarFuncionario(){
    typedef struct {
        int dia;
        int mes;
        int ano;
    } tData;

    tData data;
    string cod, cep, desig, escolha, aux[NUM_LINHAS];
    fstream file;
    int cont = 0;
    string linhaParaMod[NUM_LINHAS], linhaArquivo[NUM_LINHAS], modificacao, inicioCodigo;

    cout << "\n";
    cout << "========================================= Modificar ========================================" << endl;

    cout << "\nQual o codigo do Funcionario?\n";
    cin >> cod;
    inicioCodigo = "EF";

    cout << "\nQual a designacao desse funcionario? (Operador, Gerente, Diretor, Presidente)" << endl;
    cin >> desig;

    cout << "\nO que deseja modificar? (Codigo, Nome, Endereco, Telefone, Data, Designacao, Salario)" << endl;
    cin >> escolha;

    system("cls");    

    if (escolha == "Codigo" || escolha == "codigo"){
        /*
        if (desig == "Gerente" || desig == "gerente"){

        } else if (desig == "Diretor" || desig == "diretor"){

        } else if (desig == "Presidente" || desig == "presidente"){

        } else { */
        cout << "================================= Modificar Codigo ===================================" << endl;
        cout << "\n";

        cout << "Digite o novo codigo (EFXXX): ";
        cin >> modificacao;

        file.open("Empresa - Copia.csv", ios::in);

        if (file.is_open()){

            if (cod.find(inicioCodigo) != string::npos && cod.size() == 5){

                while(getline(file, linhaArquivo[cont])){

                    if (linhaArquivo[cont].find(cod) != string::npos){

                        cout << linhaArquivo[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linhaParaMod[cont] = linhaArquivo[cont];
                        
                        cout << "Linha com codigo apagado: " << linhaParaMod[cont].erase(0, 5) << endl;

                        //linhaParaMod[cont].erase(0, 5);
                        aux[cont] = linhaParaMod[cont];

                        linhaParaMod[cont] = modificacao + aux[cont];
                        
                        cout << "\nLinha modificada: ";
                        cout << linhaParaMod[cont] << endl;

                        cont++;
                    
                    } else {
                        linhaParaMod[cont] = linhaArquivo[cont];
                        cont++;
                    }
                }

            } else {
                cout << "codigo nao encontrado\n";
            }

        } else {
            cout << "Nao foi possivel ler o arquivo" << endl;
        }

        file.close();

        file.open("Empresa - Copia.txt", ios::out /*| ios::app*/);

        for (int i = 0; i < NUM_LINHAS; i++){
            file << linhaParaMod[i] << endl;
        }

        file.close();
    }

    /*
    else if (escolha == "Nome" || escolha == "nome"){

    } else if (escolha == "Endereco" || escolha == "endereco"){

    } else if (escolha == "Telefone" || escolha == "telefone"){

    } else if (escolha == "Data" || escolha == "data"){
        
    } else if (escolha == "Salario" || escolha == "salario"){
        
    } else if (escolha == "Designacao" || escolha == "designacao"){
        
    } */

}

// 1- Operador; 2- Gerente; 3- Diretor; 4- Presidente
int main(){

    modificarFuncionario();

    /*
    Funcionarios funcionario;

    funcionario.modificarFuncionario();*/

    return 0;
}