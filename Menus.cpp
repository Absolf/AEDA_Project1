//
// Created by laureano on 05/11/19.
//

#include "Menus.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <time.h>


using namespace std;

sistemaCartaoAmigoMuseumPortugal sys;
int numeroUsuario;
string NomeUsuario;

//Variaveis utilizadas para busca e para personalizar tratamento do usuário, mostrando mensagens com nome.

/*
void WriteAllClients(){
    //Apaga o arquivo do cliente
    deleteFileToRewrite("../clientes.txt");
    ofstream clientes("../clientes.txt");

    if(clientes.is_open())
    {
        for (int i = 0; i < sys.c; i++) {
            clientes<<BaseClientes[i].getN_cartao()<< endl;
            clientes<<BaseClientes[i].getNome()<< endl;
            clientes<<BaseClientes[i].getNascimento();
            clientes<<BaseClientes[i].getContacto()<< endl;
            clientes<<BaseClientes[i].getMorada()<< endl;
            clientes<<BaseClientes[i].getFreguesia()<< endl;
            clientes<<BaseClientes[i].getUniversitario()<< endl;
        }
        clientes.close();
    }
}*/

void loadEverything() {

    string line;
    ifstream myfile("../instituicoes.txt");


    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            //  cout << line << '\n';
        }
        myfile.close();

        cout << endl << "DADOS CARREGADOS COM SUCESSO" << endl << endl;
    } else cout << "Unable to open file";

};

void PrintInstituicoes() {
    //Vetor responsável por armazenar temporariamente as linhas de algum arquivo para facilitar a leitura
    vector<string> lines;


    string newline;


    ifstream myfile("../instituicoes.txt");
    if (myfile.is_open()) {

        for (string line; getline(myfile, line);) {

            lines.push_back(line);

        }

        for (int i = 0; i < lines.size(); i++) {


            cout << "ID: ";
            cout << lines[i] << endl;
            i++;
            cout << "Instituicao: ";
            cout << lines[i] << endl;
            i++;
            cout << "Endereco: ";
            cout << lines[i] << endl;
            i++;
            cout << "Aderente: ";
            cout << lines[i] << endl << endl;


        }


        myfile.close();
    }


};

void PrintEventos() {
    //Vetor responsável por armazenar temporariamente as linhas de algum arquivo para facilitar a leitura
    vector<string> lines;

    string newline;
    ifstream myfile("../eventos.txt");
    if (myfile.is_open()) {

        for (string line; getline(myfile, line);) {

            lines.push_back(line);

        }


        for (int i = 0; i < lines.size(); i++) {

            cout << "ID: ";
            cout << lines[i] << endl;
            i++;
            cout << "Evento: ";
            cout << lines[i] << endl;
            i++;
            cout << "Instituição: ";
            cout << lines[i] << endl;
            i++;
            cout << "Localizacao: ";
            cout << lines[i] << endl;
            i++;
            cout << "Aderente: ";
            cout << lines[i] << endl;
            i++;
            i++;
            cout << "Ingressos Disponíveis Agora: ";
            cout << lines[i] << endl;
            i++;
            i++;
            i++;
            cout << "Data e Hora: ";
            cout << lines[i] << endl << endl;
        }


        myfile.close();

        mainMenu();
    }


};

//Recebe como argumento o ID do usuario e faz uma busca para verificar sua existencia e seu nome

int searchForNameById(int usuario) {

    //Vetor responsável por armazenar temporariamente as linhas de algum arquivo para facilitar a leitura
    vector<string> lines;


    string newline;
    ifstream myfile("../clientes.txt");
    if (myfile.is_open()) {

        for (string line; getline(myfile, line);) {

            lines.push_back(line);

        }


        for (int i = 0; i < lines.size(); i++) {


            try {
                if (stoi(lines[i]) == usuario) {
                    NomeUsuario = lines[i + 1]; //Onde estará o nome
                    //Retorna o index, para ser utilizado futuramente para alteracoes do usuario
                    return i;
                } else {
                    NomeUsuario = "N_existe";
                }

            } catch (std::invalid_argument &e) {
                //Caso o numero nao puder ser convertido para inteiro para verificar, este catch impede que o programa seja finalizado.
            };


        }


    }

    myfile.close();
    //Não existe:
    return -1;

}

//Tela inicial quando o programa é aberto, aparece apenas uma vez.
void firstOpen() {
    //Pega o numero de usuario para verificar mensagens importantes como validade do cartão e eventos proximos com desconto!
    cout << "POR FAVOR DIGITE O NÚMERO DE SEU CARTÃO PARA INICIAR" << endl;
    cout << "OU DIGITE 0 PARA FAZER O REGISTRO: " << endl;
    cin >> numeroUsuario;
    if (numeroUsuario == 0) {
        sys.addCliente();
    } else {
        //Procura o usuario para verificar sua existencia e dados
        searchForNameById(numeroUsuario);
    }


    if (NomeUsuario != "N_existe") {

        //Printa a saudação e mensagens
        cout << endl << "**********************" << endl;
        cout << "Olá " << NomeUsuario << ", seja bem vindo!" << endl << endl;
        cout << "MENSAGENS RELEVANTES :" << endl << endl;
        cout << "**********************" << endl;


        mainMenu();

    } else {
        //Não encontrou nenhum usuário com este registro! Pode redirecionar para criar um cartão
        string newHandler;
        cout << endl << endl << endl << endl;
        cout << "ATUALMENTE NÃO EXISTE NENHUM USUÁRIO COM ESTE ID!" << endl;
        cout << "DESEJA FAZER UM REGISTRO? (sim/nao):  ";
        cin >> newHandler;

        if (newHandler != "sim") {

            //encerrar
            cout << endl << "**********************" << endl;
            cout << "PROGRAMA FINALIZADO" << endl;
            cout << "Foi um prazer recebe-lo " << NomeUsuario << "." << endl;
            cout << "**********************" << endl;
            cout << "Por: Gabriel Augusto Rocco e Victor Laureano" << endl;
            exit(0);

        } else {
            //Fazer novo cadastro interativo
            sys.addCliente();
        }
    }
}


void mainMenu() {       //Chama o menu principal

    //ESTE CODIGO ABAIXO ESTA SENDO EXECUTADO NA MAIN, APAGAR DA MAIN E DEIXAR AQUI.
    //CHAMAR APENAS A mainMenu NO MAIN.CPP

    cout << endl << "**********************" << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "**********************" << endl;
    cout << "DIGITE 1 PARA VER INSTITUICOES" << endl;
    cout << "DIGITE 2 PARA BUSCAR INSTITUICOES POR FREGUESIA" << endl;
    cout << "DIGITE 3 PARA VER OS PRÓXIMOS EVENTOS DISPONÍVEIS" << endl;
    cout << "DIGITE 4 PARA BUSCAR EVENTOS POR FREGUESIA" << endl;
    cout << "DIGITE 5 PARA RESERVAR BILHETES" << endl;
    cout << "DIGITE 6 PARA VER DADOS PESSOAIS" << endl;
    cout << "DIGITE x PARA ENTRAR NO MODO DE EDICAO PARA ADMINISTRADORES" << endl;
    cout << "DIGITE 0 PARA ENCERRAR" << endl;
    //  cout << "**********************" << endl;
    // cout << "CASO QUEIRA ABORTAR ALGUMA OPERACAO DIGITE menu A QUALQUER MOMENTO!" << endl;
    cout << "**********************" << endl << endl;
    cout << "OPCAO: ";

    char op;
    cin >> op;
    cin.clear();
    cin.ignore();


    switch (op) {

        default:
            mainMenu();
            break;
        case '1':
            // subMenuSeeAll();
        case '2': {
            sys.updateCliente();
            break;
        }

        case '3':
            PrintEventos();

        case '4':
            cout << "A implementar" << endl;

        case '5':
            cout << "A implementar" << endl;

        case '6':
            cout << "A implementar" << endl;


        case '0':
            //encerrar
            cout << endl << "**********************" << endl;
            cout << "PROGRAMA FINALIZADO" << endl;
            cout << "Foi um prazer recebe-lo " << NomeUsuario << "." << endl;
            cout << "**********************" << endl;
            //cout << "Por: Gabriel Augusto Rocco e Victor Laureano" << endl;
    }
};
