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

/*
Cout de endl para limpar console:
void cleanLog(){
    int i = 0;
    while (i!=40) {
        cout << endl;
        i++;
    }

}
*/


//Variaveis utilizadas para busca e para personalizar tratamento do usuário, mostrando mensagens com nome.
int numeroUsuario;
string NomeUsuario;

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
        //Encaminha para fazer um novo cadastro
        novoCadastro();
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
            novoCadastro();
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
            subMenuSeeAll();
        case '2':


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
            exit(0);

    }


};


void subMenuSeeAll() {


    //MOSTRA OS MUSEUS
    PrintInstituicoes();

    cout << "**********************" << endl;
    cout << "DIGITE 1 PARA VOLTAR PARA O MENU PRINCIPAL" << endl;
    cout << "DIGITE 0 PARA ENCERRAR" << endl;
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
            mainMenu();

        case '0':
            //encerrar
            cout << endl << "**********************" << endl;
            cout << "PROGRAMA FINALIZADO" << endl;
            cout << "Foi um prazer recebe-lo " << NomeUsuario << "." << endl;
            cout << "**********************" << endl;
            //cout << "Por: Gabriel Augusto Rocco e Victor Laureano" << endl;
            exit(0);
            break;

    }

}


//Verifica o cartao expira em menos de 30 dias e mostra uma mensagem no inicio! No mesmo local
//em que são mostradas as mensagens de eventos proximos
void verificaValidade(int id) {
    //NECESSITA OVERLOAD DE DATA
}


//Utilizado em qualquer caso que existe um novo usuário que deseja fazer o cadastro para adquirir o cartão.
void novoCadastro() {


    //CRIAR NOVA CLASSE DE CLIENTE AQUI!!!!



    //Responsavel por intermediar a criacao do novo usuario recebendo os dados digitados
    string tempHandler;
    cout << endl << "É um prazer iniciar o seu registro, para prosseguir " << "por favor digite seu nome completo: ";
    cin.ignore();
    getline(cin, tempHandler);
    NomeUsuario = tempHandler;
    cin.clear();
    //cin.ignore();

    //SET NAME DO CLIENTE CRIADO



    cout << endl << "*************************************************************************";
    cout << endl << NomeUsuario << ", ao completar o cadastro você terá entrada gratuita e ilimitada na " << endl
         << "Rede Portuguesa de Museus, com acesso total à 156 museus nacionais, assim como " << endl
         << "descontos exclusivos em eventos. Para dar continuidade vamos precisar de alguns dados: " << endl;
    cout << "*************************************************************************" << endl << endl;
    cout << "Por favor informe a data de nascimento (XX/XX/XXXX): ";
    tempHandler = "";
    getline(cin, tempHandler);
    cin.clear();
    //cin.ignore();

    //SET DATA DE NASCIMENTO
    //INTERESSANTE FAZER CATCH PARA CASO O FORMATO DIGITADO SEJA INVALIDO
    //COMO ALTERNATIVA PODEMOS FAZER 3 CINs, UM PARA DIA, UM PARA MES E UM PARA ANO

    //PRECISAMOS UTILIZAR AQUI O OPERADOR DE DATAS PARA VERIFICAR SE O USUARIO TEM DIREITO AO CARTAO SILVER (+65 anos)

    /*
    if (dataAtual-ClasseDesteCliente.nascimento >= 65 ){
     cout << NomeUsuario << "explicar cartao"

     }
     */

    cout << endl << "Por favor informe o vosso número de telemovel: ";
    tempHandler = "";
    getline(cin, tempHandler);
    cin.clear();
    //cin.ignore();

    //SET CONTATO

    cout << endl << "Por favor informe seu NIF: ";
    tempHandler = "";
    getline(cin, tempHandler);
    cin.clear();
    //cin.ignore();

    //SET NIF

    cout << endl << "Seu cadastro está quase completo, precisamos apenas dos dados de sua Morada!" << endl;
    cout << endl << "Por favor digite a Rua (sem número): ";
    tempHandler = "";
    getline(cin, tempHandler);
    cin.clear();
    //cin.ignore();

    //SET RUA DA MORADA

    cout << endl << "Por favor o número da Morada: ";
    tempHandler = "";
    getline(cin, tempHandler);
    cin.clear();
    //cin.ignore();

    //SET NUMERO DA MORADA

    cout << endl << "Por favor digite o código postal da Morada: ";
    tempHandler = "";
    getline(cin, tempHandler);
    cin.clear();
    //cin.ignore();

    //SET CEP

    cout << endl << "Por favor a Freguesia da Morada: ";
    tempHandler = "";
    getline(cin, tempHandler);
    cin.clear();
    //cin.ignore();

    //SET FREGUESIA

    cout << endl << "Por favor o Distrito da Morada: ";
    tempHandler = "";
    getline(cin, tempHandler);
    cin.clear();
    //cin.ignore();

    //SET DISTRITO





//GERA NUMERO DO CARTAO
    string tempNumCartao;

    //Garante que o random vai gerar numeros diferentes:
    srand(time(NULL));
    tempNumCartao += to_string(rand() % 99999999);

    //SET NUMERO CARTAO


    //AINDA NECESSARIO TRABALHAR TIPO DO CARTAO

    //ADICIONA NOVO CLIENTE PARA O VETOR DE CLIENTES
    //REESCREVE O CONTEUDO DO VETOR NO ARQUIVO DE TEXTO PARA INCLUIR O CLIENTE


    cout << endl << "*************************************************************************" << endl;
    cout << "Parabéns " << NomeUsuario << ", você acaba de completar seu cadastro com sucesso! " << endl;
    cout << "Por favor compareca à qualquer Museu da Rede Portuguesa " << endl
         << "para a emissão do seu cartão, não se esqueca de " << endl;
    cout << "levar um documento com foto e Cartão de estudante caso necessário.";
    cout << endl << endl;
    cout << "AVISO: O número de seu cartão é " << tempNumCartao;
    cout << endl << "*************************************************************************" << endl << endl << endl;




    //Faz a abertura inicial novamente!
    firstOpen();
}
