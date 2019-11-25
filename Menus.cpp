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

/*
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
*/

void loadBilhetes(){

}



void mainMenu() {       //Chama o menu principal
    sys.loadClients();
    sys.loadSalaEspetaculos();
    sys.loadEventos();
    string card;
    int idx = 0;
    //Pega o numero de usuario para verificar mensagens importantes como validade do cartão e eventos proximos com desconto!
    card = readString("POR FAVOR DIGITE O NÚMERO DE SEU CARTÃO PARA INICIAR \n:");
    idx = sys.searchUser(card);
    if (idx == 0) {
        cout << "ATUALMENTE NÃO EXISTE NENHUM USUÁRIO COM ESTE CARTÃO!" << endl;
        string newHandler = readString("DESEJA FAZER UM REGISTRO? (sim/nao):  ");
        if (newHandler == "sim") {
            sys.addCliente();
            sys.WriteAllClients();
        } else {
            //encerrar
            cout << endl << "**********************" << endl;
            cout << "PROGRAMA FINALIZADO" << endl;
            cout << "Foi um prazer recebe-lo " << sys.getClientes().at(idx).getNome() << "." << endl;
            cout << "**********************" << endl;
            cout << "Por: Gabriel Augusto Rocco e Victor Laureano" << endl;
            exit(0);
        }
    }
    cout << endl << "**********************" << endl;
    cout << "Olá " << sys.getClientes().at(idx).getNome() << ", seja bem vindo!" << endl << endl;
    cout << "MENSAGENS RELEVANTES :" << endl << endl;
    cout << "**********************" << endl;
    cout << "Pressione 1 para começar a gerenciar a sua conta! \n";
    int aux = readInteger("\n1 - GERENCIAR CONTA \n0 - SAIR \n");
    if(aux == 1) {
        aux = auxMenu(idx);
    }else {
        cout << endl << "**********************" << endl;
        cout << "PROGRAMA FINALIZADO" << endl;
        cout << "Foi um prazer recebe-lo " << endl;
        cout << "**********************" << endl;
        cout << "Por: Gabriel Augusto Rocco e Victor Laureano" << endl;
        sys.WriteAllClients();
        exit(0);
    }
};

int auxMenu(int idx){
    vector<string> menu = {"COMPRAR BILHETE", "ATUALIZAR INFORMAÇÕES"};
    int op = 1;
    while (op != 0) {
        op = readOptions(menu);
        if (op == 1) {
            vector<string> eventos = {};
            for(auto it = sys.getEventos().begin(); it != sys.getEventos().end(); it++){
                string opt = (*it).getNomeEvento() + " - " + (*it).getData().getDateString();
                eventos.push_back(opt);
            }
            op = readOptions((eventos));
            for(int i = 0; i < eventos.size(); i++){
                if(op-1 == i){
                    Bilhete b1;
                    b1.setValor(120.0);
                    b1.setEvento(sys.getEventos().at(i));
                    sys.venderBilhete(const_cast<Cliente *>(&sys.getClientes()[idx]), &b1,
                                      const_cast<Evento *>(&sys.getEventos().at(i)));

                    b1.printBilhete();

                }
            }

        }
        if (op == 2) {
            sys.updateCliente(sys.getClientes().at(idx).getCartao().getN_cartao());
        }
        if (op == 3) {
            sys.updateSalaEspetaculo();
        }
        if (op == 4) {/*
            Bilhete bil;
            bil.setValor(10.0);
            Evento *event(sys.getEventos()[idx]);
            bil.setEvento(event);
            */
        }
        if (op == 6) {

        }
        op = readInteger("\n1 - VOLTAR \n0 - ENCERRAR");
    }
    return op;
}
