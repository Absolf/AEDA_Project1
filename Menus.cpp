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


sistemaCartao sys;

void mainMenu() {       //Chama o menu principal
    start:
    sys.loadClients();
    sys.loadSalaEspetaculos();
    sys.loadEventos();
    string card;
    int idx = 0;
    //Pega o numero de usuario para verificar mensagens importantes como validade do cartão e eventos proximos com desconto!
    card = readString("POR FAVOR DIGITE O NÚMERO DE SEU CARTÃO PARA INICIAR \n:");
    idx = sys.searchUser(card);

    if (card == "12345678") {
        admin:
        card = readString("DIGITE A PASSWORD: ");
        if (card == "147") {
            int op = 1;
            while (op != 0) {
                op = AdminMode();
            }
            goto start;
        } else {
            idx = readInteger("SENHA PARA O ADMINISTRADOR ESTÁ ERRADA! \n1 - TENTAR NOVAMENTE\n0 - INSERIR CARTÃO");
            if (idx == 1) {
                goto admin;
            } else
                goto start;
        }
    } else if (idx == -1) {
        cout << "ATUALMENTE NÃO EXISTE NENHUM USUÁRIO COM ESTE CARTÃO!" << endl;
        int aux = readInteger("\n\"DESEJA FAZER UM REGISTRO?\n1 - SIM\n0 - NÃO \n");
        if (aux == 1) {
            sys.addCliente();
            sys.sortClients();
            sys.WriteAllClients();
            idx = sys.searchUser(sys.getClientes()[sys.getClientes().size() - 1].getN_cartao());
            aux = readInteger("IR PARA GENRENCIAMENTO DE CONTA?\n1 - SIM \n0 - NÃO\n");
            if (aux == 1)
                goto LblMenu;
            else
                leaving();
        } else
            leaving();
    }
    LblMenu:
    firstMenu(idx);
};

int auxMenu(int idx) {
    vector<string> menu = {"COMPRAR BILHETE", "ATUALIZAR INFORMAÇÕES"};
    int op = 1;
    while (op != 0) {
        op = readOptions(menu);
        if (op == 1) {
            cout << "Eventos disponíveis:\n";
            vector<string> eventos = {};
            for (auto it = sys.getEventos().begin(); it != sys.getEventos().end(); it++) {
                string opt = (*it).getNomeEvento() + " - " + (*it).getData().getDateString();
                eventos.push_back(opt);
            }
            op = readOptions((eventos));
            for (int i = 0; i < eventos.size(); i++) {
                if (op - 1 == i) {
                    Bilhete b1;
                    Evento *ev = new Evento(sys.getEventos().at(i));
                    b1.setEvento(ev);
                    Cliente *cli = new Cliente(sys.getClientes().at(idx));
                    sys.createTicket(cli, b1, ev);
                    b1.printBilhete();
                    sys.venderBilhete(cli, b1, ev);
                    b1.printBilhete();
                }
            }
            sys.sortSalas();
            sys.WriteAllSalas();
        }
        if (op == 2) {
            sys.updateCliente(sys.getClientes()[idx].getN_cartao());
            sys.sortClients();
            sys.WriteAllClients();
        }
        op = readInteger("\n1 - VOLTAR \n0 - ENCERRAR");
    }
    return op;
}

void firstMenu(int &idx) {
    cout << endl << "**********************" << endl;
    cout << "Olá " << sys.getClientes().at(idx).getNome() << ", seja bem vindo!" << endl << endl;
    messageSilver(idx);
    cout << endl << endl;
    cout << "**********************" << endl;
    cout << "Dica: Pressione 1 para começar a gerenciar a sua conta! \n";
    int aux = readInteger("\n1 - GERENCIAR CONTA \n0 - SAIR \n");
    while (aux != 0) {
        if (aux == 1)
            aux = auxMenu(idx);
    }
    leaving();
}

void leaving() {
    cout << endl << "**********************" << endl;
    cout << "PROGRAMA FINALIZADO" << endl;
    cout << "Foi um prazer recebe-lo." << endl;
    cout << "**********************" << endl;
    cout << "Por: Gabriel Augusto Rocco e Victor Laureano" << endl;
    exit(0);
}

void messageSilver(int idx) {
    Cliente *cli = new Cliente(sys.getClientes().at(idx));
    if (sys.getEventos().size() != 0) {

        for (auto it = sys.getEventos().begin(); it != sys.getEventos().end(); it++) {
            Evento *ev = new Evento((*it));
            if (cli->temCartao() && cli->getIdade() >= 65 && ev->isAderente()) {
                Bilhete b1;
                b1.setEvento(ev);
                sys.createTicket(cli, b1, ev);
                b1.setValor(0.0);
                cout << ev->getNomeEvento() << " Acontecerá no dia " << ev->getData().getDateString()
                     << "\n e por seres membro Silver do Cartão Amigo dos Museus de Portugal tens entrada a borla!\n";
                cout << "Bilhetes por " << b1.getValor() << " Euros não podes perder! " << endl;
            }
        }
    }
}

int AdminMode() {
    cout << endl << "**********************" << endl;
    cout << "MODO ADMINISTRADOR" << endl;
    cout << "**********************" << endl;
    int op = 1;
    adminStart:
    while (op != 0) {

        op = readOptions({"SALAS DE ESPETACULO", "EVENTOS", "CLIENTES"});
        if (op == 1) {
            while (op != 0) {
                salasAdm:
                op = readOptions(
                        {"ADICIONAR NOVA SALA DE ESPETACULO", "EDITAR SALA DE ESPETACULO", "EXCLUIR SALA DE ESPETACULO",
                         "VER SALAS DE ESPETACULO"});
                if (op == 1) {
                    sys.addSalaEspetaculo();
                    sys.sortSalas();
                    sys.WriteAllSalas();
                    goto salasAdm;
                }
                if (op == 2) {
                    sys.updateSalaEspetaculo();
                    sys.sortSalas();
                    sys.WriteAllSalas();
                    goto salasAdm;
                }
                if (op == 3) {
                    sys.deleteSalaEspetaculo();
                    sys.sortSalas();
                    sys.WriteAllSalas();
                    goto salasAdm;
                }
                if (op == 4) {
                    op = readOptions({"TODAS AS SALAS DE ESPETACULO", "SALA DE ESPETÁCULO ESPECÍFICA"});
                    if (op == 1) {
                        sys.readSalaEspetaculo();
                    }
                    if (op == 2) {
                        sys.readSala();
                    }
                    goto salasAdm;
                } else
                    goto adminStart;
            }
        }
        if (op == 2) {
            while (op != 0) {
                eventosAdm:
                op = readOptions(
                        {"ADICIONAR NOVA EVENTO", "EDITAR EVENTO", "EXCLUIR EVENTOS",
                         "VER EVENTOS DISPONÍVEIS"});
                if (op == 1) {
                    sys.addEvento();
                    sys.sortEventos();
                    sys.WriteAllEventos();
                    goto eventosAdm;
                }
                if (op == 2) {/*
                    sys.updateEvento();
                    sys.sortEventos();
                    sys.WriteAllEventos();*/
                    goto eventosAdm;
                }
                if (op == 3) {/*
                    sys.deleteEvento();
                    sys.sortEventos();
                    sys.WriteAllEventos();*/
                    goto eventosAdm;
                }
                if (op == 4) {/*
                    op = readOptions({"TODAS AS SALAS DE ESPETACULO", "SALA DE ESPETÁCULO ESPECÍFICA"});
                    if (op == 1) {
                        sys.readSalaEspetaculo();
                    }
                    if (op == 2) {
                        sys.readSala();
                    }*/
                    goto eventosAdm;
                } else
                    goto adminStart;

            }
        }
        if (op == 3) {
            while (op != 0) {
                clientesAdm:
                op = readOptions({"ADICIONAR NOVO CLIENTE", "EDITAR INFORMAÇÕES GERAIS", "EXCLUIR CLIENTE",
                                  "VER DADOS CLIENTES"});
                if (op == 1) {
                    sys.addCliente();
                    sys.sortClients();
                    sys.WriteAllClients();
                    goto clientesAdm;
                }
                if (op == 2) {
                    sys.updateClienteAdm();
                    sys.sortClients();
                    sys.WriteAllClients();
                    goto clientesAdm;
                }
                if (op == 3) {
                    sys.deleteCliente();
                    sys.sortClients();
                    sys.WriteAllClients();
                    goto clientesAdm;
                }
                if (op == 4) {
                    op = readOptions({"TODOS CLIENTES", "CLIENTE ESPECÍFICO"});
                    if (op == 1) {
                        sys.readClients();
                    }
                    if (op == 2) {
                        sys.readClient();
                    }
                    goto clientesAdm;
                } else
                    goto adminStart;
            }
        }
        cout << "GOSTARIA DE REINICIAR O SISTEMA?\n";
        op = readOptions({"SIM", "NÃO"});
        if (op==1) {
            return op;
        }
        else if(op == 2 || op==0){
            leaving();
        }

    }
    return op;
}