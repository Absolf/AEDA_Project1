//
// Created by Gabriel Rocco on 23/10/2019.
//

#ifndef AEDA_PROJETO_CARTAO_AMIGO_H
#define AEDA_PROJETO_CARTAO_AMIGO_H
#endif //AEDA_PROJETO_CARTAO_AMIGO_H

#import <string>
#import <vector>
using namespace std;












class Hora {
private:
    int hora;
    int minutos;


};


class Date {
private:
    int dia;
    int mes;
    int ano;

public:
    string TransformaData();
    Date(int dia, int mes, int ano);



};



class Local{
private:
    string rua;
    int cep;

};


class Instituicao{
private:
    Local localizacao;
    bool aderente;


};


class Cliente {
private:
    int tipo_assinatura; //Guarda a informação do tipo da assinatura: 1.Cartão Amigo Uni 2.Cartão amigo Silver 3.Cartão amigo individual
    float valor_assinatura; //1. 32.4e 2. 30e 3. 54.9e Não foi colocada como const pois a assinatura pode ser alterada
    string nome;
    Date nascimento;
    Local morada; //Necessário criar classe para melhor extrair informaçoes da morada do cliente visto que precisaremos comparar com o local do evento para fornecer bilhetes gratuitos para o cartão Silver
    int contacto;
    Date aquisicao_cartao;
    int nif;



public:



};



class Evento{
private:
    bool aceita_desconto_cartao_amigo; //Apenas eventos selecionados possuem desconto
    Local localizacao; //Para comparar com a loc. do usuario -> bilhetes gratuitos para Silver
    int bilhetes_totais;
    int bilhetes_reservados;
    int bilhetes_disponiveis;
    int porcentagem_disponivel;
    Instituicao inst;




};

class Gestao {
private:
    //Vetor que armazena os clientes
    vector<Cliente> clientes_amigo_uni;
    vector<Cliente> clientes_amigo_silver;
    vector<Cliente> clientes_amigo_individual;


public:
    /*Vai criar uma nova classe de cliente e após isso adicionar para
o vetor de clientes*/
    void AddCliente();


/*Avisa membros Silver de eventos na proximidade caso faltando menos de
8h para o evento ainda nao tenham sido vendidos no minimo 50% do total
de ingressos. Recebe o evento em questão e o vetor de clientes Silver*/
    void avisar_membros_Silver(Evento evento, vector<Cliente>);


    void removerCliente(int identificacao);

    void procuraCliente(int identificacao);

    void trocarPlano_Cliente(int identificacao);


};













