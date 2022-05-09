#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring.>

using namespace std;

void ExcluirRegistro(){
    string cod, linha;
    fstream file;
    int cont = 0;
    string linhas[100], escolha, teste;

    file.open("Empresa - Copia.csv", ios::in);
    
    cin >> cod;
    
    teste = "EF";
    
    if(file.is_open()){
        if(cod.find(teste) != string::npos && cod.size() == 5){
            while(getline(file, linha)){

                if(linha.find(cod) != string::npos){
                    if((linha.find("presidente") != string::npos) || (linha.find("diretor") != string::npos)){
                        linhas[cont] = linha;
                        cont++;
                        cout << "Registro nao pode ser excluido." << endl;
                    }else{
                        cout << linha << endl;
                        cout << "codigo encontrado\n";
                        cout << "Deseja excluir o registro do Arquivo ?" <<"\n Digite sim ou nao" << endl;
                        cin >> escolha;
                        if(escolha == "nao"){
                            linhas[cont] = linha;
                            cont++;
                        }else if(escolha == "sim"){
                            cout << "O registro foi excluido." << endl;
                        }
                    }
                }else{
                    linhas[cont] = linha;
                    cont++;
                }
            }
        }else{
            cout << "codigo nao encontrado\n";
        }
    }else{
        cout << "arquivo nao foi aberto\n";
    }

    file.close();

    file.open("Empresa - Copia.txt", ios::out);

    for(int i = 0; i<cont; i++){
        file << linhas[i] << endl;
    }

}


int main(){

    ExcluirRegistro();

    return 0;
}
