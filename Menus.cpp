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
int searchUser(string card) {
    for(size_t i = 0; i < sys.getClientes().size(); i++){
        if (card == sys.getClientes().at(i).getN_cartao()){
            return i;
        }
    }
    return 0;
}

//Tela inicial quando o programa é aberto, aparece apenas uma vez.
void loadClients() {
    vector<string> lines;
    string newline;
    ifstream myfile("../clientes.txt");
    if (myfile.is_open()) {
        for (string line; getline(myfile, line);) {
            lines.push_back(line);
        }
        for (int i = 0; i < lines.size(); i++) {
            Cliente user;

            user.setN_cartao(lines[i]);
            i++;
            user.setNome(lines[i]);
            i++;
            Date tempNascimento;
            tempNascimento.setDateString(lines[i]);
            user.setNascimento(tempNascimento);
            i++;
            Date oldDate;
            oldDate.setDateString(lines[i]);
            i++;
            user.setContacto(lines[i]);
            i++;
            user.setMorada(lines[i]);
            i++;
            if (lines[i] == "1") {
                user.setUniversitario(true);
            } else {
                user.setUniversitario(false);
            }
            user.aderirCartao();
            CartaoAmigo *novo = const_cast<CartaoAmigo *>(&(user.getCartao()));
            novo->setDataAcquisition(oldDate);
            user.setCartao(novo);
            sys.setClientes(user);
            cout << user;
            cout.clear();
        }
        myfile.close();
        cout << endl << "DADOS CARREGADOS COM SUCESSO" << endl << endl;
    } else {
        cout << endl << "PROBLEMA NO CARREGAMENTO DE BASE DE DADOS" << endl << endl;
    }
};




void mainMenu() {       //Chama o menu principal
    loadClients();
    string card;
    int idx = 0;
    //Pega o numero de usuario para verificar mensagens importantes como validade do cartão e eventos proximos com desconto!
    card = readString("POR FAVOR DIGITE O NÚMERO DE SEU CARTÃO PARA INICIAR \n:");
    idx = searchUser(card);
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
    vector<string> menu = {"VER SALAS DE ESPETÁCULO", "BUSCAR EVENTOS POR FREGUESIA",
                           "PRÓXIMOS EVENTOS DISPONÍVEIS",
                           "COMPRAR BILHETES", "DADOS PESSOAIS", "MODO EDIÇÃO (ADM)"};
    int op = 1;
    while (op != 0) {
        op = readOptions(menu);
        if (op == 1) {
        }
        if (op == 2) {
        }
        if (op == 3) {
        }
        if (op == 4) {/* // comprar bilhetes
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
        }
        if (op == 6) {
            sys.updateCliente(sys.getClientes().at(idx).getCartao().getN_cartao());
        }
        op = readInteger("\n1 - VOLTAR \n0 - ENCERRAR");
    }
    return op;
}
