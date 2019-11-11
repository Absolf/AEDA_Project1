//
// Created by laureano on 05/11/19.
//

#include "Menus.h"
#include "sistemaCartaoAmigoMuseus.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

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

            cout << "Preenchendo um evento "<< endl;
            Date eventDate("2020/11/21");
            time_t timer;
            struct tm aTime;
            aTime.tm_hour;
            Evento *evento = new Evento("Espaço alfa", 20 , 19, "Rua de São Brás0", 0 , true, "TomorrowLand",eventDate,aTime.tm_hour);
            cout << "Lotacão evento depois de criado: " << evento->getLotacao() << endl;

            cout << "Associando um evento a um bilhete" << endl;
            Bilhete bi;
            bi.setValor(25.5);
            cout << "Foi atribuido manualmente um valor pro bilhete" << endl;
            bi.setEvento(evento);
            sistemaCartaoAmigoMuseumPortugal obj;
            cout << "Preenchendo um cliente" << endl;
            Cliente teste;

            teste.setNif("213123123");
            teste.setNome(("victor"));
            teste.setContacto("935550893");
            teste.setMorada("testando");
            Date nascimento("1995/11/21");
            teste.setNascimento(nascimento);
            teste.setUniversitario(true);
            teste.aderirCartao();
            cout << "Com as informações do cliente, foi gerado um cartao" << endl;
            obj.venderBilhete(&teste,&bi, evento);
            teste.printCliente();

            //--- Segundo teste
            Cliente teste2;
            teste2.setNif("5468789");
            teste2.setNome(("Edu"));
            teste2.setContacto("6665558");
            teste2.setMorada("FEUP");
            Date nascimento2("1998/11/21");
            teste2.setNascimento(nascimento2);
            teste2.setUniversitario(true);
            teste2.aderirCartao();
            obj.venderBilhete(&teste2, &bi, evento);
            teste2.printCliente();
            break;



        }
        case '3':

            break;


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
