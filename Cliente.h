//
// Created by laureano on 10/11/19.
//

#ifndef AEDA_PROJETO_CLIENTE_H
#define AEDA_PROJETO_CLIENTE_H
using namespace std;
#import <string>
#import "Date.h"
#import "CartaoAmigo.h"
#include "Bilhete.h"

class Cliente {
    Date nascimento;
    string nome;
    string morada;
    string contacto;
    string nif;
    CartaoAmigo *cartao;
    bool universitario = false;
    vector<Bilhete* > bilhetes;
public:
    const vector<Bilhete*> & getBilhetes() const;
    void setBilhetes(const vector<Bilhete* > bilhetes);

    Cliente();
    const Date &getNascimento() const;
    void setNascimento(const Date &nascimento);

    const string &getNome() const;
    void setNome(const string &nome);

    const string &getMorada() const;
    void setMorada(const string &morada);

    const string &getContacto() const;
    void setContacto(const string &contacto);

    const bool &getUniversitario() const;
    void setUniversitario(const bool &universitario);

    const CartaoAmigo& getCartao() const;
    void setCartao(CartaoAmigo *cartao);

    bool temCartao();
    void printCliente();
    const string &getNif() const;
    void setNif(const string &nif);
    void addBilhete(Bilhete *b);
    void aderirCartao();
};


#endif //AEDA_PROJETO_CLIENTE_H
