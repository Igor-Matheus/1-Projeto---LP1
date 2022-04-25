#include <iostream>
#include <string>
#include <fstream>
#include "Funcionarios.h"

using namespace std;

Funcionarios::Funcionarios(){
    codigo = "NaN";
    nome = "NaN";
    data = "NaN";
    endereco = "NaN";
    salario = 0;
    telefone = "NaN";
    designacao = "NaN";
}

Funcionarios::Funcionarios(string codigo, string nome, string data,
string endereco, double salario, string telefone, string designacao){

    this -> codigo = codigo;
    this -> nome = nome;
    this -> data = data;
    this -> endereco = endereco;
    this -> salario = salario;
    this -> telefone = telefone;
    this -> designacao = designacao;

}

Funcionarios::~Funcionarios(){}

string Funcionarios::getCodigo(){
    return codigo;
}

string Funcionarios::getNome(){
    return nome;
}

string Funcionarios::getData(){
    return data;
}

string Funcionarios::getEndereco(){
    return endereco;
}

string Funcionarios::getTelefone(){
    return telefone;
}

string Funcionarios::getDesignacao(){
    return designacao;
}

double Funcionarios::getSalario(){
    return salario;
}

/*================================================================================================*/

void Funcionarios::criarArquivo(){
    arquivo.open("Empresa.csv", ios::in);

    if(!arquivo.is_open()){
        arquivo.open("Empresa.csv", ios::out);
    }

    arquivo.close();
}

void Funcionarios::lerArquivo(){
    arquivo.open("Empresa.csv", ios::in);

    int i = 0;
    if(arquivo.is_open()){

        while(getline(arquivo, linhas[i])){
            cout << linhas[i] << endl;
            i++;
        }

        arquivo.close();

    } else {
        cout << "Nao foi possivel ler o arquivo" << endl;
    }
}

string Funcionarios::retornaEndereco(string cep){
    int i;

    string linhasAPI[12];

    fstream arquivoAPI;
    
    string CEP = cep;
    string url = "http://viacep.com.br/ws/" + CEP +"/json/";
    string comando = "wget " + url;

    system(comando.c_str());

    system("cls");

    arquivoAPI.open("index.html", ios::in);

    i = 0;
    while(getline(arquivoAPI, linhasAPI[i])){
        i++;
    }

    arquivoAPI.close();

    if(linhasAPI[2] == "}"){
        system("del index.html");
        cout << "endereco nao encontrado" << endl;
        return "Nan";
    }

    system("del index.html");

    linhasAPI[2].erase(0, 17);
    int count = 0;
    while(1){
        for(i = 0; i < 50; i++){
            if(linhasAPI[2][i] == '"'){
                linhasAPI[2].erase(i, 2);
                count = 1;
                break;
            }
        }
        if(count = 1){
            break;
        }
    }

    linhasAPI[4].erase(0, 13);
    count = 0;
    while(1){
        for(i = 0; i < 50; i++){
            if(linhasAPI[4][i] == '"'){
                linhasAPI[4].erase(i, 2);
                count = 1;
                break;
            }
        }
        if(count = 1){
            break;
        }
    }

    linhasAPI[5].erase(0, 17);
    count = 0;
    while(1){
        for(i = 0; i < 50; i++){
            if(linhasAPI[5][i] == '"'){
                linhasAPI[5].erase(i, 2);
                count = 1;
                break;
            }
        }
        if(count = 1){
            break;
        }
    }

    linhasAPI[6].erase(0, 9);
    count = 0;
    while(1){
        for(i = 0; i < 50; i++){
            if(linhasAPI[6][i] == '"'){
                linhasAPI[6].erase(i, 2);
                count = 1;
                break;
            }
        }
        if(count = 1){
            break;
        }
    }

    return "Logradouro: " + linhasAPI[2] + " - " "Bairro: " + linhasAPI[4] + " - " + "Cidade: " + linhasAPI[5] + " - " + "UF: " + linhasAPI[6];

}

void Funcionarios::addFuncionario(){
    typedef struct{
        int dia;
        int mes;
        int ano;
    } Data;

    Data data;

    string nome, aux, codigo, cod, telefone, designacao, endereco, cep, numero, areaS[2], areaF[2], formacao;

    string Nan("Nan"), logradouro, bairro, cidade, uf, linha[NUM_LINHAS], line, dia, mes, ano;

    char yn;
    int i, c, desig, li = 0;
    float salario;

    criarArquivo();
    lerArquivo();

    cout << "deseja adicionar funcionario? [s/n]" << endl;
    cin >> yn;
    getchar();

    system("cls");

    while(yn == 'S' || yn == 's'){
        while(1){
            c = 1;
            while(1){
                cout << "digite o codigo: ";
                getline(cin, cod);
                system("cls");

                if(cod.length() == 3){
                    codigo = cod;
                    break;
                }
                else if(cod.length() == 2){
                    codigo = "0" + cod;
                    break;
                }
                else if(cod.length() == 1){
                    codigo = "00" + cod;
                    break;
                }
                else{
                    cout << "codigo maior do que o esperado" << endl;
                    continue;
                }
            }

            for(i = 1; i < NUM_LINHAS; i++){
                if(linhas[i] != ""){
                    aux = linhas[i];
                    aux.erase(3, aux.length());
                }

                if(aux == codigo){
                    cout << "codigo invalido, tente novamente" << endl;
                    c = 0;
                    break;
                }
            }
            if(c == 1){
                break;
            }
        }

        cout << "digite o nome: ";
        getline(cin, nome);

        system("cls");

        cout << "poderia informar seu CEP? [s/n]: ";
        cin >> yn;
        getchar();

        system("cls");
        while(1){
            if(yn == 'S' || yn == 's'){
                cout << "digite seu CEP: ";
                getline(cin, cep);

                if(cep.length() > 8 || cep.length() < 8){
                    cout << "CEP invalido" << endl;
                    continue;
                }
                else{
                    endereco = retornaEndereco(cep);
                    break;
                }
            }
            else{
                break;
            }
        }
        
        if(endereco == "Nan" || yn == 'N' || yn == 'n'){
            endereco.clear();
            cep.clear();
            cout << "informe o logradouro: ";
            getline(cin, logradouro);
            cout << "informe o bairro: ";
            getline(cin, bairro);
            cout << "informe a cidade: ";
            getline(cin, cidade);
            cout << "informe a Uf: ";
            getline(cin, uf);

            endereco = "Logradouro: " + logradouro + " - " "Bairro: " + bairro + " - " + "Cidade: " + cidade + " - " + "UF: " + uf;            
        }

        cout << "digite o numero da casa: ";
        getline(cin, numero);

        endereco = endereco + " - numero: " + numero;
        system("cls");

        cout << "telefone - formato: (00) 0000-0000: ";
        getline(cin, telefone);

        system("cls");
        while(1){
            cout << "data que ingressou na empresa:\n";
            cout << "dia: ";
            cin >> data.dia;
            cout << "mes: ";
            cin >> data.mes;
            cout << "ano: ";
            cin >> data.ano;
            
            
            if(to_string(data.dia).length() == 1){
                dia = "0" + to_string(data.dia);
            }
            else if(to_string(data.dia).length() == 2){
                dia = to_string(data.dia);
            }
            if(to_string(data.mes).length() == 1){
                mes = "0" + to_string(data.mes);
            }
            else if(to_string(data.mes).length() == 2){
                mes = to_string(data.mes);
            }
            if(to_string(data.ano).length() == 2){
                ano = "19" + to_string(data.ano);
            }
            else if(to_string(data.ano).length() == 4){
                ano = to_string(data.ano);
            }
            else{
                ano = "0";
            }


            if(stoi(mes) < 1 || stoi(mes) > 12){
                system("cls");
                cout << "data invalida" << endl;
                continue;
            }
            
            if(stoi(ano) < 1000 || stoi(ano) > 2022){
                system("cls");
                cout << "data invalida" << endl;
                continue;
            }

            if(stoi(mes)){
                if(stoi(mes) == 2){
                    if(data.dia <= 28 && data.dia > 1){
                        break;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;
                        continue;
                    }
                }
                if(stoi(mes) == 1 || stoi(mes) == 3|| stoi(mes) == 5 || stoi(mes) == 7 || stoi(mes) == 8 || stoi(mes) == 10 || stoi(mes) == 12){
                    if(stoi(dia) <= 31 && stoi(dia) > 1){
                        break;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;
                        continue;
                    }
                }
                else{
                    if(stoi(dia) <= 30 && stoi(dia) > 1){
                        break;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;
                        continue;
                    }
                }
            }
        }
        system("cls");

        c = 1;
        while(1){
            cout << "Escolha a designacao:\n";
            cout << "(1) Operador\n";
            cout << "(2) Gerente\n";
            cout << "(3) Diretor\n";
            cout << "(4) Presidente\n";

            cin >> desig;
            getchar();

            switch (desig){
            case 1:
                designacao = "Operador";
                c = 0;
                break;
            case 2:
                designacao = "Gerente";
                c = 0;
                break;
            case 3:
                designacao = "Diretor";
                c = 0;
                break;
            case 4:
                designacao = "Presidente";
                c = 0;
                break;
            default:
                cout << "Inválido! Tente novamente\n";
                break;
            }

            if(c == 0){
                break;
            }
        }

        system("cls");

        if(designacao == "gerente" || designacao == "Gerente"){
            cout << "informe a area de supervisão: ";
            getline(cin, areaS[0]);
            system("cls");
        }
        else if(designacao == "diretor" || designacao == "Diretor"){
            cout << "informe a area de supervisão: ";
            getline(cin, areaS[1]);
            system("cls");
            cout << "informe a area de formacao: ";
            getline(cin, areaF[0]);
            system("cls");
        }
        else if(designacao == "presidente" || designacao == "Presidente"){
            cout << "informe a area de formacao: ";
            getline(cin, areaF[1]);
            system("cls");
            cout << "informa a formacao academica maxima: ";
            getline(cin, formacao);
            system("cls");
        }

        cout << "salario: ";
        cin >> salario;
        getchar();

        line = codigo + "," + nome + "," + endereco + "," + telefone + "," + dia + "/" + mes +"/" + ano + "," + designacao + "," + "R$" + to_string(salario).erase(to_string(salario).size()-4, 4) ;
        if(designacao == "gerente" || designacao == "Gerente"){
            linha[li] = line + "," + areaS[0] + "," + Nan + "," + Nan + "\n";
        }
        else if(designacao == "diretor" || designacao == "Diretor"){
            linha[li] = line + "," + areaS[1] + "," + areaF[0] + "," + Nan + "\n";
        }
        else if(designacao == "presidente" || designacao == "Presidente"){
            linha[li] = line + "," + Nan + "," + areaF[1] + "," + formacao + "\n";
        }
        else{
            linha[li] = line + "," + Nan + "," + Nan + "," + Nan + "\n";
        }

        system("cls");

        cout << "Cadastro realizado!" << endl;

        cout << "Deseja adicionar outro funcionario? [s/n]" << endl;
        cin >> yn;
        getchar();

        li++;
    }

    arquivo.open("Empresa.csv", ios::out | ios::app);
    for(li = 0; li < 100; li++){
        arquivo << linha[li];
    }
    arquivo.close();

}


void Funcionarios::excluirFuncionario(){

}

void Funcionarios::modificarFuncionario(){
    /*
    string codigo, nome, end, telefone, data, designacao, salario;
    string resposta1, resposta2, flag[NUM_LINHAS];
    int numDesignacao;
    int contador = 0;
    string linha, linhaParaModificar, modificacao; //a modificacao dependerá do que foi escolhido na resposta2
    */

    typedef struct{
        int dia;
        int mes;
        int ano;
    } Data;

    Data data;

    string nome, aux, codigo, cod, telefone, designacao, endereco, cep, numero, areaS[2], areaF[2], formacao;

    string Nan("Nan"), logradouro, bairro, cidade, uf, linha[NUM_LINHAS], line, dia, mes, ano;

    char yn;
    int i, c, desig, li = 0;
    float salario;
    
    criarArquivo();
    lerArquivo();

    cout << "========================================= Modificar ========================================" << endl;

    cout << "Qual o codigo?" << endl;
    cin >> cod;

   
}

void Funcionarios::concederAumento(){

}
void Funcionarios::calculaFolhaSalarial(){

}

int Funcionarios::diasTrabalhados(){

}
double Funcionarios::horasExtras(){

}

void Funcionarios::imprimeFolhaSalarial(){

}
void Funcionarios::imprimeFolhaSalarialEmpresa(){
    
}




