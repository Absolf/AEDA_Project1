//
// Created by Gabriel Rocco on 23/10/2019.
//

#ifndef AEDA_PROJETO_CARTAO_AMIGO_H
#define AEDA_PROJETO_CARTAO_AMIGO_H


#import <string>
#import <vector>
#import <iostream>
#import "Date.h"
using namespace std;


class Hora {
    int hora;
    int minutos;
public:
    int getHora() const;

    void setHora(int hora);

    int getMinutos() const;

    void setMinutos(int minutos);

};


class Local{
    string rua;
    int cep;
public:
    const string &getRua() const;

    void setRua(const string &rua);

    int getCep() const;

    void setCep(int cep);
};

class Instituicao{
    Local localizacao;
    bool aderente;
public:
    const Local &getLocalizacao() const;

    void setLocalizacao(const Local &localizacao);

    bool isAderente() const;

    void setAderente(bool aderente);

};


class Cliente {
    int tipo_assinatura; //Guarda a informação do tipo da assinatura: 1.Cartão Amigo Uni 2.Cartão amigo Silver 3.Cartão amigo individual
    string nome;
    Date nascimento;
    Local morada; //Necessário criar classe para melhor extrair informaçoes da morada do cliente visto que precisaremos comparar com o local do evento para fornecer bilhetes gratuitos para o cartão Silver
    int contacto;
    Date aquisicao_cartao;
    int nif;
public:
    int getTipoAssinatura() const;

    void setTipoAssinatura(int tipoAssinatura);

    virtual float getValorAssinatura() const;

    virtual void setValorAssinatura(float valorAssinatura);

    const string &getNome() const;

    void setNome(const string &nome);

    const Date &getNascimento() const;

    void setNascimento(const Date &nascimento);

    const Local &getMorada() const;

    void setMorada(const Local &morada);

    int getContacto() const;

    void setContacto(int contacto);

    const Date &getAquisicaoCartao() const;

    void setAquisicaoCartao(const Date &aquisicaoCartao);

    int getNif() const;

    void setNif(int nif);


};


class Evento{
    bool aceita_desconto_cartao_amigo; //Apenas eventos selecionados possuem desconto
    Local localizacao; //Para comparar com a loc. do usuario -> bilhetes gratuitos para Silver
    int bilhetes_totais;
    int bilhetes_reservados;
    int bilhetes_disponiveis;
    int porcentagem_disponivel;
public:
    bool isAceitaDescontoCartaoAmigo() const;

    void setAceitaDescontoCartaoAmigo(bool aceitaDescontoCartaoAmigo);

    const Local &getLocalizacao() const;

    void setLocalizacao(const Local &localizacao);

    int getBilhetesTotais() const;

    void setBilhetesTotais(int bilhetesTotais);

    int getBilhetesReservados() const;

    void setBilhetesReservados(int bilhetesReservados);

    int getBilhetesDisponiveis() const;

    void setBilhetesDisponiveis(int bilhetesDisponiveis);

    int getPorcentagemDisponivel() const;

    void setPorcentagemDisponivel(int porcentagemDisponivel);

};

class Gestao {
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



#endif //AEDA_PROJETO_CARTAO_AMIGO_H









