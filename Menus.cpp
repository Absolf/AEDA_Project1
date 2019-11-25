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
                cout << (*it) << endl;
                string opt = (*it).getNomeEvento() + " - " + (*it).getData().getDateString();
                eventos.push_back(opt);
            }
            op = readOptions((eventos));
            for(int i = 0; i < eventos.size(); i++){
                if(op-1 == i){
                    Bilhete b1;
                    Evento *ev = new Evento(sys.getEventos().at(i));
                    b1.setEvento(ev);
                    Cliente *cli = new Cliente(sys.getClientes().at(idx));
                    sys.createTicket(cli,b1,ev);
                    sys.venderBilhete(cli,b1,ev);
                    b1.printBilhete();
                    cout << sys.getEventos()[i].getLotacao() << endl;
                    cout << ev->getLotacao() << endl;

                    sys.readSalaEspetaculo();
                }
            }
        }
        op = readInteger("\n1 - VOLTAR \n0 - ENCERRAR");
    }
    return op;
}
