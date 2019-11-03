//
// Created by laureano on 02/11/19.
//

#ifndef AEDA_PROJETO_CARTAOAMIGO_H
#define AEDA_PROJETO_CARTAOAMIGO_H
#include "cartao_amigo.h"
#include "Date.h"

class CartaoAmigo {
    Cliente *clientes;
    Date validade;
    Date dataAcquisition;
    Date nascimento;
    string nome;
    Local morada;
    string contacto;
    float valorAssinatura;
public:
    virtual float getValorAssinatura() const;

    void setValorAssinatura(float valorAssinatura);

    const Date &getValidade() const;

    void setValidade(const Date &validade);

    const Date &getDataAcquisition() const;

    void setDataAcquisition(const Date &dataAcquisition);

    const Date &getNascimento() const;

    void setNascimento(const Date &nascimento);

    const string &getNome() const;

    void setNome(const string &nome);

    const Local &getMorada() const;

    void setMorada(const Local &morada);

    const string &getContacto() const;

    void setContacto(const string &contacto);

    CartaoAmigo(Date validade, Date dataAcquisition, Date nascimento, string nome, Local morada, string contacto);
    void addClient();
    virtual void emitirCartao();
};

class CartaoAmigoUni : public  CartaoAmigo{
public:
    CartaoAmigoUni()
    void emitirCartao();
    float getValorAssinatura() const;

};

class CartaoAmigoSilver : public CartaoAmigo {
public:
    void emitirCartao();
    float getValorAssinatura() const;

};

class CartaoAmigoIndi : public CartaoAmigo {
public:
    void emitirCartao();
    float getValorAssinatura() const;

};


#endif //AEDA_PROJETO_CARTAOAMIGO_H
