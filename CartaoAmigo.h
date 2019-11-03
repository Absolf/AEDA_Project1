//
// Created by laureano on 02/11/19.
//

#ifndef AEDA_PROJETO_CARTAOAMIGO_H
#define AEDA_PROJETO_CARTAOAMIGO_H
#include "cartao_amigo.h"
#include "Date.h"

class CartaoAmigo{
    Date validade;
    Date dataAcquisition;
    Date nascimento;
    string nome;
    Local morada;
    string contacto;
    float valorAssinatura;
public:
    CartaoAmigo(){};
    CartaoAmigo(Date validade, Date dataAcquisition, Date nascimento, string nome, Local morada, string contacto, float valorAssinatura): validade(validade), dataAcquisition(dataAcquisition), nascimento(nascimento),
                                                                                                                                          nome(nome), morada(morada), contacto(contacto), valorAssinatura(valorAssinatura) {};
    float getValorAssinatura() const;
    void setValorAssinatura(float &valorAssinatura);

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

    void addClient();
    void emitirCartao();
    friend ostream &operator<<(ostream &out, const CartaoAmigo &cliente);

};

class CartaoAmigoUni : public  CartaoAmigo{
public:
    CartaoAmigoUni();
    void emitirCartao(Cliente &cliente);
    float getValorAssinatura() const;

};

class CartaoAmigoSilver : public CartaoAmigo {
public:
    CartaoAmigoSilver();
    void emitirCartao(Cliente &cliente);
    float getValorAssinatura() const;
};

class CartaoAmigoIndi : public CartaoAmigo {
public:
    CartaoAmigoIndi();
    void emitirCartao();
    float getValorAssinatura() const;

};


#endif //AEDA_PROJETO_CARTAOAMIGO_H
