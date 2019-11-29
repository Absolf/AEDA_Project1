//
// Created by laureano on 10/11/19.
//

#ifndef AEDA_PROJETO_CLIENTE_H
#define AEDA_PROJETO_CLIENTE_H
using namespace std;

#import "CartaoAmigo.h"
#include "Bilhete.h"

class Cliente {
    Date nascimento;
    string nome;
    Address morada;
    string contacto;
    string n_cartao;
    CartaoAmigo *cartao;
    //string eventos;
public:
    const string &getEventos() const;

    void setEventos(const string &eventos);

private:
    bool universitario = false;
    vector<Bilhete *> bilhetes = {};
public:
    const vector<Bilhete *> &getBilhetes() const;

    void setBilhetes(Bilhete *bilhete);

    Cliente();

    Cliente(const Cliente &cli);

    const Date &getNascimento() const;

    void setNascimento(const Date &nascimento);

    const string &getNome() const;

    void setNome(const string &nome);

    const Address &getMorada() const;

    void setMorada(const Address &morada);

    const string &getContacto() const;

    void setContacto(const string &contacto);

    const bool &getUniversitario() const;

    void setUniversitario(const bool &universitario);

    const CartaoAmigo &getCartao() const;

    void clientsEvents(string line, vector<int> &aux);

    void setCartao(CartaoAmigo *cartao);

    bool temCartao();

    void printCliente();

    const string &getN_cartao() const;

    void setN_cartao(const string &N_cartao);

    void addBilhete(Bilhete &b);

    void aderirCartao();

    int getIdade();

    bool operator<(const Cliente &c1);

    friend ostream &operator<<(ostream &out, Cliente &cli);
};


#endif //AEDA_PROJETO_CLIENTE_H
