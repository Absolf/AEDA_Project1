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
    if (idx == -1) {
        cout << "ATUALMENTE NÃO EXISTE NENHUM USUÁRIO COM ESTE CARTÃO!" << endl;
        int aux = readInteger("\n\"DESEJA FAZER UM REGISTRO?\n1 - SIM\n0 - NÃO \n");
        if (aux == 1) {
            sys.addCliente();
            sys.WriteAllClients();
            idx = sys.searchUser(sys.getClientes()[sys.getClientes().size()-1].getN_cartao());
            aux = readInteger("IR PARA GENRENCIAMENTO DE CONTA?\n1 - SIM \n0 - NÃO\n");
            if(aux == 1)
                goto LblMenu;
            else
                leaving();
        } else {
            leaving();
        }
    }
    LblMenu:
        firstMenu(idx);
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
                    Evento *ev = new Evento(sys.getEventos().at(i));
                    b1.setEvento(ev);
                    Cliente *cli = new Cliente(sys.getClientes().at(idx));
                    sys.createTicket(cli,b1,ev);
                    sys.venderBilhete(cli,b1,ev);
                    b1.printBilhete();
                }
            }
        }
        op = readInteger("\n1 - VOLTAR \n0 - ENCERRAR");
    }
    return op;
}

void firstMenu(int &idx){
    cout << endl << "**********************" << endl;
    cout << "Olá " << sys.getClientes().at(idx).getNome() << ", seja bem vindo!" << endl << endl;
    messageSilver(idx);
    cout << endl << endl;
    cout << "**********************" << endl;
    cout << "Dica: Pressione 1 para começar a gerenciar a sua conta! \n";
    int aux = readInteger("\n1 - GERENCIAR CONTA \n0 - SAIR \n");
    while(aux !=0){
        if (aux == 1)
            aux = auxMenu(idx);
    }
    leaving();
}
void leaving(){
    cout << endl << "**********************" << endl;
    cout << "PROGRAMA FINALIZADO" << endl;
    cout << "Foi um prazer recebe-lo." << endl;
    cout << "**********************" << endl;
    cout << "Por: Gabriel Augusto Rocco e Victor Laureano" << endl;
    exit(0);
}

void messageSilver(int idx){
    Cliente *cli = new Cliente(sys.getClientes().at(idx));
    if(sys.getEventos().size() != NULL){

        for(auto it = sys.getEventos().begin(); it != sys.getEventos().end(); it++){
            Evento *ev = new Evento((*it));
            if(cli->temCartao() && cli->getIdade() >=65 && ev->isAderente()){
                Bilhete b1;
                b1.setEvento(ev);
                sys.createTicket(cli,b1,ev);
                b1.setValor(0.0);
                cout << ev->getNomeEvento() << " Acontecerá no dia " << ev->getData().getDateString() << "\n e por seres membro Silver do Cartão Amigo dos Museus de Portugal tens entrada a borla!\n";
                cout << "Bilhetes por " << b1.getValor() << " Euros não podes perder! "<< endl;
            }
        }
    }
}
