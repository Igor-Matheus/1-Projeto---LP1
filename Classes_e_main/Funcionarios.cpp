#include "Funcionario.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

Funcionario::Funcionario(){

}

void Funcionario::criarArquivo(){
    arquivo.open("./csv/Empresa.csv", ios::in);

    if(!arquivo.is_open()){
        arquivo.open("./csv/Empresa.csv", ios::out);
    }

    arquivo.close();
}

void Funcionario::lerArquivo(){
    arquivo.open("./csv/Empresa.csv", ios::in);

    int i = 0;
    if(arquivo.is_open()){
        while(getline(arquivo, linhas[i])){
            i++;
        }
        arquivo.close();
    }
    else{
        cout << "nao foi possivel ler o arquivo" << endl;
    }
}

void Funcionario::exibirArquivo(){
    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            cout << linhas[i] << endl;
        }
    }
}

void Funcionario::separadorColuna(string colPresent[], int del[]){
    for(int i = 1, j = 0; i < 100; i++, j++){
        if(linhas[i] != ""){
            colPresent[i] = linhas[i];
            colPresent[i].erase(0, del[j]);
            colPresent[i].erase(colPresent[i].find(','));
        }
        else{
            break;
        }
        // cout << colPresent[i] << endl;
    }
}

void Funcionario::colunas(){
    int del[100] = {0};

    criarArquivo();
    lerArquivo();

    for(int i = 1; i < 100; i++){
        if(linhas[i] != ""){
            codigo[i] = linhas[i];
            codigo[i].erase(3, codigo[i].length());
        }
        else{
            break;
        }
        // cout << codigo[i] << endl;
    }
    for(int i = 1, j = 0; i < 100; i++, j++){
        del[j] += codigo[i].size() + 1;
    }
    separadorColuna(nome, del);
    
    for(int i = 1, j = 0; i < 100; i++, j++){
        del[j] += nome[i].size() + 1;
    }
    separadorColuna(end, del);

    for(int i = 1, j = 0; i < 100; i++, j++){
        del[j] += end[i].size() + 1;
    }
    separadorColuna(telefone, del);

    for(int i = 1, j = 0; i < 100; i++, j++){
        del[j] += telefone[i].size() + 1;
    }
    separadorColuna(data, del);
    for(int i = 1, j = 0; i < 100; i++, j++){
        del[j] += data[i].size() + 1;
    }
    separadorColuna(desig, del);
    for(int i = 1, j = 0; i < 100; i++, j++){
        del[j] += desig[i].size() + 1;
    }
    separadorColuna(salario, del);
    for(int i = 1, j = 0; i < 100; i++, j++){
        del[j] += salario[i].size() + 1;
    }
    separadorColuna(sup, del);
    for(int i = 1, j = 0; i < 100; i++, j++){
        del[j] += sup[i].size() + 1;
    }
    separadorColuna(acad, del);
    
    for(int i = 1, j = 0; i < 100; i++, j++){
        del[j] += acad[i].length() +1;
        if(linhas[i] != ""){
            formacao[i] = linhas[i];
            formacao[i].erase(0, del[j]);
        }
        else{
            break;
        }
        // cout << formacao[i] << endl; 
    }
}

string Funcionario::forEndereco(string api[], int line, int tam){
    api[line].erase(0, tam);
    int count = 0;
    while(1){
        for(int i = 0; i < 50; i++){
            if(api[line][i] == '"'){
                api[line].erase(i, 2);
                count = 1;
                break;
            }
        }
        if(count = 1){
            break;
        }
    }
    return api[line];
}

string Funcionario::retornaEndereco(string cep){
    int i;
    int count = 0;
    string logradouro;
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

    return "Logradouro: " + forEndereco(linhasAPI, 2, 17) + " - " "Bairro: " + forEndereco(linhasAPI, 4, 13) + " - " + "Cidade: " + forEndereco(linhasAPI, 5, 17) + " - " + "UF: " + forEndereco(linhasAPI, 6, 9);

}

void Funcionario::addFuncionario(){
    typedef struct{
        int dia;
        int mes;
        int ano;
    } Data;

    Data data;
    string nome, aux, codigo, cod, telefone, designacao, endereco, cep, numero, areaS[2], areaF[2], formacao;
    string Nan("Nan"), logradouro, bairro, cidade, uf, linha[100], line, dia, mes, ano;
    string yn;
    int i, c, desig, li = 0;
    float salario;

    criarArquivo();
    lerArquivo();
    exibirArquivo();

    while(1){
        cout << "deseja adicionar funcionario? [s/n]" << endl;
        cin >> yn;
        getchar();
        if(yn == "S" || yn == "s" ||yn == "N" || yn == "n"){
            break;
        }
        else if(yn.length() > 1){
            continue;
        }
        else{
            continue;
        }
        system("cls");
    }
    system("cls");

    while(yn == "S" || yn == "s"){
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

            for(i = 1; i < 100; i++){
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

        while(1){
            cout << "poderia informar seu CEP? [s/n]: ";
            cin >> yn;
            getchar();
            if(yn == "S" || yn == "s" ||yn == "N" || yn == "n"){
                break;
            }
            else if(yn.length() > 1){
                continue;
            }
            else{
                continue;
            } 
            system("cls");
        }
        system("cls");

        while(1){
            if(yn == "S" || yn == "s"){
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
        
        if(endereco == "Nan" || yn == "N" || yn == "n"){
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

        if(designacao == "Gerente"){
            cout << "informe a area de supervisão: ";
            getline(cin, areaS[0]);
            system("cls");
        }
        else if(designacao == "Diretor"){
            cout << "informe a area de supervisão: ";
            getline(cin, areaS[1]);
            system("cls");
            cout << "informe a area de formacao: ";
            getline(cin, areaF[0]);
            system("cls");
        }
        else if(designacao == "Presidente"){
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

        line = codigo + "," + nome + "," + endereco + "," + telefone + "," + dia + "/" + mes +"/" + ano + "," + designacao + "," + to_string(salario).erase(to_string(salario).size()-4, 4) ;
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

    arquivo.open("./csv/Empresa.csv", ios::out | ios::app);
    for(li = 0; li < 100; li++){
        arquivo << linha[li];
    }
    arquivo.close();

}

/* ======================================  Excluir funcionário =============================================*/
void Funcionario::excluirFuncionario(){
    string cod, linha;
    fstream file;
    int cont = 0;
    string linhas[NUM_LINHAS], escolha, teste;

    file.open("Empresa - Copia.csv", ios::in);
    
    cin >> cod;
    
    teste = "EF";
    
    if (file.is_open()){
        if (cod.find(teste) != string::npos && cod.size() == 5){

            while(getline(file, linha)){

                if (linha.find(cod) != string::npos){

                    if ((linha.find("presidente") != string::npos) || (linha.find("diretor") != string::npos)){
                        linhas[cont] = linha;
                        cont++;
                        cout << "Registro nao pode ser excluido." << endl;
                    } else {
                        cout << linha << endl;
                        cout << "codigo encontrado\n";
                        cout << "Deseja excluir o registro do Arquivo ?" <<"\n Digite sim ou nao" << endl;
                        cin >> escolha;
                        if (escolha == "nao"){
                            linhas[cont] = linha;
                            cont++;
                        } else if (escolha == "sim"){
                            cout << "O registro foi excluido." << endl;
                        }
                    }
                } else {
                    linhas[cont] = linha;
                    cont++;
                }
            }

        } else {
            cout << "codigo nao encontrado\n";
        }

    } else {
        cout << "arquivo nao foi aberto\n";
    }

    file.close();

    file.open("Empresa - Copia.txt", ios::out);

    for (int i = 0; i < cont; i++){
        file << linhas[i] << endl;
    }
}
/* =========================================================================================================*/

/* ======================================  Para as modificações =============================================*/
void Funcionario::modificaCodigo(string cod){
    //fstream file;
    int cont = 0;
    string linha[NUM_LINHAS], modificacao;
    
    colunas();

    cout << "================================= Modificar Codigo ===================================" << endl;
    cout << "\n";

    cout << "Digite o novo codigo: ";
    cin >> modificacao;

    system("cls");

    arquivo.open("./csv/Empresa.csv", ios::in);

    if (arquivo.is_open()){

        //if (cod.find("EF") != string::npos && cod.size() == 5){   

        while(getline(arquivo, linhas[NUM_LINHAS])){
            if (codigo[cont].find(cod) != string::npos){

                cout << linhas[cont] << endl;
                cout << "\tcodigo encontrado\n";
                
                linha[cont] = linhas[cont];

                linha[cont] = modificacao + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 
    
                cout << linha[cont] << endl;

                cont++;
                    
            } else {
                linha[cont] = linhas[cont];
                cont++;
            }    
        }

    } else {
        cout <<  "Nao foi possivel ler o arquivo" << endl;
    }   

    arquivo.close();

    arquivo.open("./csv/Empresa.csv", ios::out);

    for (int i = 0; i < cont; i++){
        arquivo << linha[i] << endl;
    }

    arquivo.close();   
}        

void Funcionario::modificaNome(string cod){
    //fstream file;
    int cont = 0;
    string linha[NUM_LINHAS], modificacao;

    colunas();
    
    cout << "================================= Modificar Nome ===================================" << endl;
    cout << "\n";

    cout << "Digite o novo nome: ";
    getline(cin, modificacao);

    system("cls");

    arquivo.open("./csv/Empresa.csv", ios::in);

    if (arquivo.is_open()){

        //if (cod.find("EF") != string::npos && cod.size() == 5){   

        while(getline(arquivo, linhas[NUM_LINHAS])){
            if (codigo[cont].find(cod) != string::npos){

                cout << linhas[cont] << endl;
                cout << "\tcodigo encontrado\n";
                
                linha[cont] = linhas[cont];

                linha[cont] = codigo[cont] + "," + modificacao + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 
    
                cout << linha[cont] << endl;

                cont++;
                    
            } else {
                linha[cont] = linhas[cont];
                cont++;
            }
        }

    } else {
        cout <<  "Nao foi possivel ler o arquivo" << endl;
    }   

    arquivo.close();

    arquivo.open("./csv/Empresa.csv", ios::out);

    for (int i = 0; i < cont; i++){
        arquivo << linha[i] << endl;
    }

    arquivo.close();   
}        

void Funcionario::modificaEndereco(string cod){
    //fstream file;
    int cont = 0;
    string linha[NUM_LINHAS];
    string modificacao, endereco, logradouro, bairro, cidade, uf, numero;

    colunas();
    
    cout << "================================= Modificar Endereco ===================================" << endl;
    cout << "\n";

    cout << "Digite o novo endereco:\n\n";
    cout << "Logradouro: ";
    getline(cin, logradouro);

    cout << "Bairro: ";
    getline(cin, bairro);

    cout << "Cidade: ";
    getline(cin, cidade);

    cout << "UF: ";
    getline(cin, uf); 

    cout << "Numero: ";
    getline(cin, numero);

    endereco = "Logradouro: " + logradouro + " - " + "Bairro: " + bairro + " - "
    + "Cidade: " + cidade + " - " + "UF: " + uf + " - " + "numero: " + numero;

    modificacao = endereco;

    system("cls");
    
    arquivo.open("./csv/Empresa.csv", ios::in);

    if (arquivo.is_open()){

        //if (cod.find("EF") != string::npos && cod.size() == 5){   

        while(getline(arquivo, linhas[NUM_LINHAS])){
            if (codigo[cont].find(cod) != string::npos){

                cout << linhas[cont] << endl;
                cout << "\tcodigo encontrado\n";
                
                linha[cont] = linhas[cont];

                linha[cont] = codigo[cont] + "," + nome[cont] + "," + modificacao + "," + telefone[cont] + "," + data[cont]
                + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 
    
                cout << linha[cont] << endl;

                cont++;
                    
            } else {
                linha[cont] = linhas[cont];
                cont++;
            }
        }

    } else {
        cout <<  "Nao foi possivel ler o arquivo" << endl;
    }   

    arquivo.close();

    arquivo.open("./csv/Empresa.csv", ios::out);

    for (int i = 0; i < cont; i++){
        arquivo << linha[i] << endl;
    }

    arquivo.close();   
}        

void Funcionario::modificaTelefone(string cod){
    //fstream file;
    int cont = 0;
    string linha[NUM_LINHAS], modificacao;

    colunas();
    
    cout << "================================= Modificar Telefone ===================================" << endl;
    cout << "\n";

    cout << "Digite o novo telefone - formato: (00) 0000-0000: ";
    getline(cin, modificacao);
    //cin.ignore(); // ou getchar?

    system("cls");

    arquivo.open("./csv/Empresa.csv", ios::in);

    if (arquivo.is_open()){

        //if (cod.find("EF") != string::npos && cod.size() == 5){   

        while(getline(arquivo, linhas[NUM_LINHAS])){
            if (codigo[cont].find(cod) != string::npos){

                cout << linhas[cont] << endl;
                cout << "\tcodigo encontrado\n";
                
                linha[cont] = linhas[cont];

                linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + modificacao + "," + data[cont]
                + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 
    
                cout << linha[cont] << endl;

                cont++;
                    
            } else {
                linha[cont] = linhas[cont];
                cont++;
            }
        }

    } else {
        cout <<  "Nao foi possivel ler o arquivo" << endl;
    }   

    arquivo.close();

    arquivo.open("./csv/Empresa.csv", ios::out);

    for (int i = 0; i < cont; i++){
        arquivo << linha[i] << endl;
    }

    arquivo.close();   
}

void Funcionario::modificaData(string cod){
    //fstream file;
    int cont = 0;
    string linha[NUM_LINHAS], modificacao; 

    colunas();
    
    cout << "================================= Modificar Data de Ingresso ===================================" << endl;
    cout << "\n";

    cout << "Digite a nova data - formato: 00/00/00: ";
    getline(cin, modificacao);
    //cin.ignore(); // ou getchar?

    system("cls");

    arquivo.open("./csv/Empresa.csv", ios::in);

    if (arquivo.is_open()){

        //if (cod.find("EF") != string::npos && cod.size() == 5){   

        while(getline(arquivo, linhas[NUM_LINHAS])){
            if (codigo[cont].find(cod) != string::npos){

                cout << linhas[cont] << endl;
                cout << "\tcodigo encontrado\n";
                
                linha[cont] = linhas[cont];

                linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                + modificacao + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + ","
                + formacao[cont]; 
    
                cout << linha[cont] << endl;

                cont++;
                    
            } else {
                linha[cont] = linhas[cont];
                cont++;
            }
        }

    } else {
        cout <<  "Nao foi possivel ler o arquivo" << endl;
    }   

    arquivo.close();

    arquivo.open("./csv/Empresa.csv", ios::out);

    for (int i = 0; i < cont; i++){
        arquivo << linha[i] << endl;
    }

    arquivo.close(); 
}

void Funcionario::modificaSalario(string cod){
    //fstream file;
    int cont = 0;
    string linha[NUM_LINHAS], modificacao;
    
    colunas();
    
    cout << "================================= Modificar Salario ===================================" << endl;
    cout << "\n";

    cout << "Digite o novo salario: ";
    getline(cin, modificacao);
    //cin.ignore(); // ou getchar?

    system("cls");

    arquivo.open("./csv/Empresa.csv", ios::in);

    if (arquivo.is_open()){

        //if (cod.find("EF") != string::npos && cod.size() == 5){   

        while(getline(arquivo, linhas[NUM_LINHAS])){
            if (codigo[cont].find(cod) != string::npos){

                cout << linhas[cont] << endl;
                cout << "\tcodigo encontrado\n";
                
                linha[cont] = linhas[cont];

                linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                + "," + desig[cont] + "," + modificacao + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 
    
                cout << linha[cont] << endl;

                cont++;
                    
            } else {
                linha[cont] = linhas[cont];
                cont++;
            }
        }

    } else {
        cout <<  "Nao foi possivel ler o arquivo" << endl;
    }   

    arquivo.close();

    arquivo.open("./csv/Empresa.csv", ios::out);

    for (int i = 0; i < cont; i++){
        arquivo << linha[i] << endl;
    }

    arquivo.close();   
}

void Funcionario::modDesigParaOperador(string cod){
    int cont = 0;
    string linha[NUM_LINHAS];
    string modificacao = "Operador";

    colunas();

    arquivo.open("./csv/Empresa.csv", ios::in);

    if (arquivo.is_open()){

        while(getline(arquivo, linhas[NUM_LINHAS])){
            if (codigo[cont].find(cod) != string::npos){

                cout << linhas[cont] << endl;
                cout << "\tcodigo encontrado\n";
                
                linha[cont] = linhas[cont];

                linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + "Nan" + "," + "Nan"; 
    
                cout << linha[cont] << endl;

                cont++;
                    
            } else {
                linha[cont] = linhas[cont];
                cont++;
            }
        }
                
    } else {
        cout <<  "Nao foi possivel ler o arquivo" << endl;
    }   

    arquivo.close();

    arquivo.open("./csv/Empresa.csv", ios::out);

    for (int i = 0; i < cont; i++){
        arquivo << linha[i] << endl;
    }

    arquivo.close();
}
    
void Funcionario::modDesigDeGerente(string cod){
    int cont;
    string linha[NUM_LINHAS];
    string modificacao, areaS, areaF, formacaoMax;

    colunas();

    while(1){
        cont = 0; // Corrigir isso para os outros métodos também.

        cout << "Digite a nova designacao - (Operador, Diretor ou Presidente?): ";
        getline(cin, modificacao);
        //cin.ignore(); // ou getchar?

        if (modificacao == "Operador" || modificacao == "operador"){
            
            modDesigParaOperador(cod);
            break;

        } else if (modificacao == "Diretor" || modificacao == "diretor"){
            
            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            system("cls");

            arquivo.open("./csv/Empresa.csv", ios::in);

            if (arquivo.is_open()){

             //if (cod.find("EF") != string::npos && cod.size() == 5){   

                while(getline(arquivo, linhas[NUM_LINHAS])){
                    if (codigo[cont].find(cod) != string::npos){

                        cout << linhas[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linha[cont] = linhas[cont];

                        linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                        + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + "," + formacao[cont]; 
    
                        cout << linha[cont] << endl;

                        cont++;
                    
                    } else {
                        linha[cont] = linhas[cont];
                        cont++;
                    }
                }

            } else {
                cout <<  "Nao foi possivel ler o arquivo" << endl;
            }   

            arquivo.close();

            arquivo.open("./csv/Empresa.csv", ios::out);

            for (int i = 0; i < cont; i++){
                arquivo << linha[i] << endl;
            }

            arquivo.close(); 

            break;
        
        } else if (modificacao == "Presidente" || modificacao == "presidente"){

            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            cout << "\nQual a formacao maxima? ";
            getline(cin, formacaoMax);

            system("cls");

            arquivo.open("./csv/Empresa.csv", ios::in);

            if (arquivo.is_open()){

             //if (cod.find("EF") != string::npos && cod.size() == 5){   

                while(getline(arquivo, linhas[NUM_LINHAS])){
                    if (codigo[cont].find(cod) != string::npos){

                        cout << linhas[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linha[cont] = linhas[cont];

                        linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                        + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + areaF + "," + formacaoMax; 
    
                        cout << linha[cont] << endl;

                        cont++;
                    
                    } else {
                        linha[cont] = linhas[cont];
                        cont++;
                    }
                }

            } else {
                cout <<  "Nao foi possivel ler o arquivo" << endl;
            }   

            arquivo.close();

            arquivo.open("./csv/Empresa.csv", ios::out);

            for (int i = 0; i < cont; i++){
                arquivo << linha[i] << endl;
            }

            arquivo.close(); 

            break;

        } else {
            system("cls");
            cout << "Resposta invalida, tente novamente.";
            system("cls");

            continue;
        }
    }
}

void Funcionario::modDesigDeOperador(string cod){
    int cont = 0;
    string linha[NUM_LINHAS];
    string modificacao, areaS, areaF, formacaoMax;

    colunas();

    while(1){
        cont = 0;

        cout << "Digite a nova designacao - (Gerente, Diretor ou Presidente?): ";
        getline(cin, modificacao);
        //cin.ignore(); // ou getchar?

        if (modificacao == "Gerente" || modificacao == "gerente"){

            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            system("cls");

            arquivo.open("./csv/Empresa.csv", ios::in);

            if (arquivo.is_open()){

             //if (cod.find("EF") != string::npos && cod.size() == 5){   

                while(getline(arquivo, linhas[NUM_LINHAS])){
                    if (codigo[cont].find(cod) != string::npos){

                        cout << linhas[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linha[cont] = linhas[cont];

                        linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                        + "," + modificacao + "," + salario[cont] + "," + areaS + "," + acad[cont] + "," + formacao[cont]; 
    
                        cout << linha[cont] << endl;

                        cont++;
                    
                    } else {
                        linha[cont] = linhas[cont];
                        cont++;
                    }
                }

            } else {
                cout <<  "Nao foi possivel ler o arquivo" << endl;
            }   

            arquivo.close();

            arquivo.open("./csv/Empresa.csv", ios::out);

            for (int i = 0; i < cont; i++){
                arquivo << linha[i] << endl;
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Diretor" || modificacao == "diretor"){

            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            system("cls");

            arquivo.open("./csv/Empresa.csv", ios::in);

            if (arquivo.is_open()){

             //if (cod.find("EF") != string::npos && cod.size() == 5){   

                while(getline(arquivo, linhas[NUM_LINHAS])){
                    if (codigo[cont].find(cod) != string::npos){

                        cout << linhas[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linha[cont] = linhas[cont];

                        linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                        + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + "," + formacao[cont]; 
    
                        cout << linha[cont] << endl;

                        cont++;
                    
                    } else {
                        linha[cont] = linhas[cont];
                        cont++;
                    }
                }

            } else {
                cout <<  "Nao foi possivel ler o arquivo" << endl;
            }   

            arquivo.close();

            arquivo.open("./csv/Empresa.csv", ios::out);

            for (int i = 0; i < cont; i++){
                arquivo << linha[i] << endl;
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Presidente" || "presidente"){
            
            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            cout << "\nQual a formacao maxima? ";
            getline(cin, formacaoMax);

            system("cls");

            arquivo.open("./csv/Empresa.csv", ios::in);

            if (arquivo.is_open()){

             //if (cod.find("EF") != string::npos && cod.size() == 5){   

                while(getline(arquivo, linhas[NUM_LINHAS])){
                    if (codigo[cont].find(cod) != string::npos){

                        cout << linhas[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linha[cont] = linhas[cont];

                        linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                        + "," + modificacao + "," + salario[cont] + "," + sup[cont] + "," + areaF + "," + formacaoMax; 
    
                        cout << linha[cont] << endl;

                        cont++;
                    
                    } else {
                        linha[cont] = linhas[cont];
                        cont++;
                    }
                }

            } else {
                cout <<  "Nao foi possivel ler o arquivo" << endl;
            }   

            arquivo.close();

            arquivo.open("./csv/Empresa.csv", ios::out);

            for (int i = 0; i < cont; i++){
                arquivo << linha[i] << endl;
            }

            arquivo.close(); 

            break;

        } else {
            system("cls");
            cout << "Resposta invalida, tente novamente.";
            system("cls");

            continue;        
        }
    }

}

void Funcionario::modDesigDeDiretor(string cod){
    int cont;
    string linha[NUM_LINHAS];
    string modificacao, areaS, areaF, formacaoMax;

    colunas();

    while(1){
        cont = 0;

        cout << "Digite a nova designacao - (Operador, Gerente ou Presidente?): ";
        getline(cin, modificacao);
        //cin.ignore(); // ou getchar?

        if (modificacao == "Operador" || "operador"){
            
            modDesigParaOperador(cod);
            break;

        } else if (modificacao == "Gerente" || modificacao == "gerente"){

            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            system("cls");

            arquivo.open("./csv/Empresa.csv", ios::in);

            if (arquivo.is_open()){

             //if (cod.find("EF") != string::npos && cod.size() == 5){   

                while(getline(arquivo, linhas[NUM_LINHAS])){
                    if (codigo[cont].find(cod) != string::npos){

                        cout << linhas[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linha[cont] = linhas[cont];

                        linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                        + "," + modificacao + "," + salario[cont] + "," + areaS + "," + "Nan" + "," + formacao[cont]; 
    
                        cout << linha[cont] << endl;

                        cont++;
                    
                    } else {
                        linha[cont] = linhas[cont];
                        cont++;
                    }
                }

            } else {
                cout <<  "Nao foi possivel ler o arquivo" << endl;
            }   

            arquivo.close();

            arquivo.open("./csv/Empresa.csv", ios::out);

            for (int i = 0; i < cont; i++){
                arquivo << linha[i] << endl;
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Presidente" || "presidente"){
            
            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            cout << "\nQual a formacao maxima? ";
            getline(cin, formacaoMax);

            system("cls");

            arquivo.open("./csv/Empresa.csv", ios::in);

            if (arquivo.is_open()){

             //if (cod.find("EF") != string::npos && cod.size() == 5){   

                while(getline(arquivo, linhas[NUM_LINHAS])){
                    if (codigo[cont].find(cod) != string::npos){

                        cout << linhas[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linha[cont] = linhas[cont];

                        linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                        + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + areaF + "," + formacaoMax; 
    
                        cout << linha[cont] << endl;

                        cont++;
                    
                    } else {
                        linha[cont] = linhas[cont];
                        cont++;
                    }
                }

            } else {
                cout <<  "Nao foi possivel ler o arquivo" << endl;
            }   

            arquivo.close();

            arquivo.open("./csv/Empresa.csv", ios::out);

            for (int i = 0; i < cont; i++){
                arquivo << linha[i] << endl;
            }

            arquivo.close(); 

            break;

        } else {
            system("cls");
            cout << "Resposta invalida, tente novamente.";
            system("cls");

            continue;        
        }
    }

}

void Funcionario::modDesigDePresidente(string cod){
    int cont;
    string linha[NUM_LINHAS];
    string modificacao, areaS, areaF, formacaoMax;

    colunas();

    while(1){
        cont = 0;

        cout << "Digite a nova designacao - (Operador, Gerente ou Diretor?): ";
        getline(cin, modificacao);
        //cin.ignore(); // ou getchar?

        if (modificacao == "Operador" || "operador"){
            
            modDesigParaOperador(cod);
            break;

        } else if (modificacao == "Gerente" || modificacao == "gerente"){

            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            system("cls");

            arquivo.open("./csv/Empresa.csv", ios::in);

            if (arquivo.is_open()){

             //if (cod.find("EF") != string::npos && cod.size() == 5){   

                while(getline(arquivo, linhas[NUM_LINHAS])){
                    if (codigo[cont].find(cod) != string::npos){

                        cout << linhas[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linha[cont] = linhas[cont];

                        linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                        + "," + modificacao + "," + salario[cont] + "," + areaS + "," + "Nan" + "," + "Nan"; 
    
                        cout << linha[cont] << endl;

                        cont++;
                    
                    } else {
                        linha[cont] = linhas[cont];
                        cont++;
                    }
                }

            } else {
                cout <<  "Nao foi possivel ler o arquivo" << endl;
            }   

            arquivo.close();

            arquivo.open("./csv/Empresa.csv", ios::out);

            for (int i = 0; i < cont; i++){
                arquivo << linha[i] << endl;
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Diretor" || "diretor"){
            
            cout << "\nQual a area de supervisao?";
            getline(cin, areaS);

            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            system("cls");

            arquivo.open("./csv/Empresa.csv", ios::in);

            if (arquivo.is_open()){

             //if (cod.find("EF") != string::npos && cod.size() == 5){   

                while(getline(arquivo, linhas[NUM_LINHAS])){
                    if (codigo[cont].find(cod) != string::npos){

                        cout << linhas[cont] << endl;
                        cout << "codigo encontrado\n";
                
                        linha[cont] = linhas[cont];

                        linha[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
                        + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + "," + "Nan"; 
    
                        cout << linha[cont] << endl;

                        cont++;
                    
                    } else {
                        linha[cont] = linhas[cont];
                        cont++;
                    }
                }

            } else {
                cout <<  "Nao foi possivel ler o arquivo" << endl;
            }   

            arquivo.close();

            arquivo.open("./csv/Empresa.csv", ios::out);

            for (int i = 0; i < cont; i++){
                arquivo << linha[i] << endl;
            }

            arquivo.close(); 

            break;

        } else {
            system("cls");
            cout << "Resposta invalida, tente novamente.";
            system("cls");

            continue;        
        }
    }
}

void Funcionario::modificaDesignacao(string cod){
    int desigAtual;
    
    cout << "================================= Modificar Designacao ===================================" << endl;
    cout << "\n";

    cout << "Informe a designacao atual - [1] Operador, [2] Gerente, [3] Diretor, [4] Presidente : \n";
    cin >> desigAtual;
    
    getchar();

    system("cls");

    switch (desigAtual){
        case 1:
            modDesigDeOperador(cod);
            break;
        
        case 2:
            modDesigDeGerente(cod); 
            break;

        case 3:
            modDesigDeDiretor(cod); 
            break;

        case 4:
            modDesigDePresidente(cod); 
            break;
    }
}

// Lembrar do cont = 0 no início dos while, se for o caso de tiver cont.
void Funcionario::modificarFuncionario(){
    string cod;
    int desig, escolha = 0, i = 0;

    while(1){
        cout << "========================================= Modificar ========================================" << endl;

        // Tentar tratar se o código já existe ou não aqui
        cout << "\nQual o codigo do Funcionario?\n";

        getline(cin, cod);

        system("cls");

        if(cod.length() == 3){
            break;
        }
            
        else if(cod.length() < 3){
            cout << "codigo menor do que o esperado" << endl;
            system("cls");
            continue;
        }
                
        else{
            cout << "codigo maior do que o esperado" << endl;
            system("cls");
            continue;
        }
    }

    //Precisa de outro laço aqui? tentar tratar a possibilidade de uma escolha inválida
    cout << "O que deseja modificar?" << endl;
    cout << "[1] Codigo\n";
    cout << "[2] Nome\n";
    cout << "[3] Endereco\n"; 
    cout << "[4] Telefone\n";
    cout << "[5] Data\n";
    cout << "[6] Salario\n";
    cout << "[7] Designacao\n\n";

    cin >> escolha;
    getchar();
   
    system("cls");

    switch (escolha){
        case 1:
            modificaCodigo(cod);
            break;
        
        case 2:
            modificaNome(cod);
            break;
        
        case 3:
            modificaEndereco(cod);
            break;
        
        case 4:
            modificaTelefone(cod);
            break;

        case 5:
            modificaData(cod);
            break;
        
        case 6:
            modificaSalario(cod);
            break;
        
        case 7:
            modificaDesignacao(cod);
            break;
    }

}
/* ==========================================================================================================*/

/* ======================================  Outros métodos =============================================*/

void Funcionario::concederAumento(){

}
void Funcionario::calculaFolhaSalarial(){

}

int Funcionario::diasTrabalhados(){

}
double Funcionario::horasExtras(){

}

void Funcionario::imprimeFolhaSalarial(){

}
void Funcionario::imprimeFolhaSalarialEmpresa(){
    
}

// Destrutor
Funcionario::~Funcionario(){

}
