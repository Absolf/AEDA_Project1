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
            idx = sys.searchUser(sys.getClientes()[sys.getClientes().size() - 1].getN_cartao());
            aux = readInteger("IR PARA GENRENCIAMENTO DE CONTA?\n1 - SIM \n0 - NÃO\n");
            if (aux == 1)
                goto LblMenu;
            else
                sys.sortClients();
                sys.WriteAllClients();
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
    Cliente *cli = new Cliente(sys.getClientes().at(idx));
    Bilhete b1;
    while (op != 0) {
        op = readOptions(menu);
        if (op == 1) {
            sys.comprarBilhete(cli, b1);
        }
        if (op == 2) {
            sys.updateCliente(sys.getClientes()[idx].getN_cartao());

        }
        op = readInteger("\n1 - VOLTAR \n0 - ENCERRAR");
    }
    sys.sortClients();
    sys.WriteAllClients();
    sys.sortEventos();
    sys.WriteAllEventos();
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
    vector<string> evOpt = sys.eventosGratuitosSilver(idx);
    if(evOpt.size()!=0) {
        if(evOpt.size() >1) {
            cout << "\nOlá" << sys.getClientes()[idx].getNome() << " faltam menos de 8 horas para que " << evOpt.size()
                 << " eventos ocorram no seu Distrito são eles:\n";
            for (size_t i = 0; i < evOpt.size(); i++) {
                cout << evOpt[i] << endl;
            }
            cout << "E por seres membro Silver do Cartão Amigo dos Museus de Portugal tens entrada a borla!\n";
            cout << "Proceda para o gerenciamento da sua conta caso queira reservar seu lugar!\n";

        }else{
            cout << "Olá" << sys.getClientes()[idx].getNome() <<" faltam menos de 8 horas para que o evento "<< evOpt[0] << " ocorra no seu Distrito e por seres membro Silver do Cartão Amigo dos Museus de Portugal tens entrada a borla!\n";
            cout << "Proceda para o gerenciamento da sua conta caso queira reservar seu lugar!\n";
        }
    }
}

int AdminMode() {
    cout << endl << "**********************" << endl;
    cout << "MODO ADMINISTRADOR" << endl;
    cout << "**********************" << endl;
    int op = 1;
    while (op != 0) {
        adminStart:
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
                }
            }
            goto adminStart;
        }
        if (op == 2) {
            while (op != 0) {
                eventosAdm:
                op = readOptions(
                        {"ADICIONAR NOVA EVENTO", "EDITAR EVENTO", "EXCLUIR EVENTOS", "VER EVENTOS DISPONÍVEIS"});
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
                }
            }
            goto adminStart;
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
                }
            }
            goto adminStart;
        }

                cout << "GOSTARIA DE REINICIAR O SISTEMA?\n";
                op = readOptions({"SIM", "NÃO"});
                if (op == 1) {
                    return op;
                } else if (op == 2) {
                    leaving();
                } else if (op == 0) {
                }

    }
    return op;
}