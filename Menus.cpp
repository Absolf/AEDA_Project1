//
// Created by laureano on 05/11/19.
//

#include "Menus.h"
#include "CartaoAmigo.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void loadEverything(){

    string line;
    ifstream myfile ("../1instituicoes.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }
        myfile.close();

        cout << endl << "DADOS CARREGADOS COM SUCESSO" << endl << endl;
    }

    else cout << "Unable to open file";

};




void PrintInstituicoes(){
    string newline;
    ifstream myfile ("../instituicoes.txt");
    if (myfile.is_open())
    {

        vector<string> lines;
        for(string line; getline( myfile, line ); )
        {

            lines.push_back(line);


        }

        for (int i = 0; i<lines.size(); i++){

            cout << "ID: ";
            cout << lines[i]  << endl;
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

        mainMenu();
    }


};








void mainMenu() {



    //ESTE CODIGO ABAIXO ESTA SENDO EXECUTADO NA MAIN, APAGAR DA MAIN E DEIXAR AQUI.
    //CHAMAR APENAS A mainMenu NO MAIN.CPP

    cout << endl << "**********************" << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "**********************" << endl;
    cout << "DIGITE 1 PARA VER INSTITUICOES" << endl;
    cout << "DIGITE 2 PARA BUSCAR INSTITUICOES POR FREGUESIA" << endl;
    cout << "DIGITE 3 PARA VER OS PRÓXIMOS EVENTOS DISPONÍVEIS" << endl;
    cout << "DIGITE 4 PARA BUSCAR EVENTOS POR FREGUESIA" << endl;
    cout << "DIGITE 5 RESERVAR BILHETES" << endl;
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
        case '1': {
            subMenuSeeAll();
            break;
        }
        case '2':{
            CartaoAmigo teste;
            teste.emitirCartao();
            break;
        }
        case '3':


        case '0':
            //encerrar
            cout << endl << "**********************" << endl;
            cout << "PROGRAMA FINALIZADO" << endl;
            cout << "**********************" << endl;
            cout << "Por: Gabriel Augusto Rocco e Victor Laureano" << endl;
            exit(0);
            break;

    }



};



void subMenuSeeAll() {
    PrintInstituicoes();



}
