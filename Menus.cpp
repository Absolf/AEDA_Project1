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

//Recebe como argumento o nº do cartão do usuario e faz uma busca para verificar sua existencia e seu nome

int searchForNameById(int usuario, int &index, string &NomeUsuario) {

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
                    index = i;
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
    index = -1;
}

//Tela inicial quando o programa é aberto, aparece apenas uma vez.
void firstOpen() {
    sys.loadClients();
    //Pega o numero de usuario para verificar mensagens importantes como validade do cartão e eventos proximos com desconto!
    cout << "POR FAVOR DIGITE O NÚMERO DE SEU CARTÃO PARA INICIAR" << endl;
    cout << "OU DIGITE 0 PARA FAZER O REGISTRO: " << endl;
    cin >> numeroUsuario;
    if (numeroUsuario == 0) {
        sys.addCliente();
    } else {
        //Procura o usuario para verificar sua existencia e dados
        searchForNameById(numeroUsuario, index, NomeUsuario);
    }

    if (NomeUsuario != "N_existe") {
        //Printa a saudação e mensagens
        cout << endl << "**********************" << endl;
        cout << "Olá " << NomeUsuario << ", seja bem vindo!" << endl << endl;

        cout << "MENSAGENS RELEVANTES :" << endl << endl;
        cout << "**********************" << endl;
        mainMenu();
    }else {
        //Não encontrou nenhum usuário com este registro! Pode redirecionar para criar um cartão
        string newHandler;
        cout << endl << endl << endl << endl;
        cout << "ATUALMENTE NÃO EXISTE NENHUM USUÁRIO COM ESTE ID!" << endl;
        newHandler = readString("DESEJA FAZER UM REGISTRO? (sim/nao):  ");

       if(newHandler == "sim") {
            sys.addCliente();
        }else {
            //encerrar
            cout << endl << "**********************" << endl;
            cout << "PROGRAMA FINALIZADO" << endl;
            cout << "Foi um prazer recebe-lo " << NomeUsuario << "." << endl;
            cout << "**********************" << endl;
            cout << "Por: Gabriel Augusto Rocco e Victor Laureano" << endl;
            exit(0);
        }
    }
}


void mainMenu(string &NomeUsuario) {       //Chama o menu principal
    vector<string> menu = {"VER SALAS DE ESPETÁCULO", "BUSCAR EVENTOS POR FREGUESIA", "PRÓXIMOS EVENTOS DISPONÍVEIS", "COMPRAR BILHETES","DADOS PESSOAIS", "MODO EDIÇÃO (ADM)"};
    cout << endl << "**********************" << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "**********************" << endl;
    int op = readOptions(menu);
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

        case '4':/*
            for(size_t i = 0; i < sys.getClientes().size() ; i++){
                if(sys.getClientes().at(i).getCartao().getN_cartao() == to_string(numeroUsuario)){
                    cout << "Para qual evento gostaria de comprar seu bilhete ?\n";
                    string eventName;
                    getline(cin, eventName);
                    for(size_t j = 0; j < sys.getEventos().size(); j++){
                        if(eventName == sys.getEventos().at(j).getNomeEvento()){
                            sys.venderBilhete()
                        }
                    }

                }
            }
*/
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
