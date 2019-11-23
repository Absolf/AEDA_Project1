//
// Created by laureano on 02/11/19.
//

#ifndef AEDA_PROJETO_CARTAOAMIGO_H
#define AEDA_PROJETO_CARTAOAMIGO_H

#include "Date.h"
#include "Address.h"
#include "SalaEspetaculo.h"
#include <vector>


class CartaoAmigo {
protected:
    Date nascimento;
    string nome;
    Address morada;
    string contacto;
    string n_cartao;
    Date dataAcquisition;
public:
    CartaoAmigo();

    CartaoAmigo(Date dataAcquisition, Date nascimento, string nome, Address morada, string contacto, string n_cartao)
            : dataAcquisition(dataAcquisition), nascimento(nascimento), nome(nome), morada(morada), contacto(contacto),
              n_cartao(n_cartao) {};

    virtual float getAnuidade() const;

    const Date &getDataAcquisition() const;

    void setDataAcquisition(const Date &dataAcquisition);

    const Date &getNascimento() const;

    void setNascimento(const Date &nascimento);

    const string &getNome() const;

    void setNome(const string &nome);

    const Address &getMorada() const;

    void setMorada(const Address &morada);

    const string &getContacto() const;

    void setContacto(const string &contacto);

    const string &getN_cartao() const;

    void set_Ncartao(const string &n_cartao);

    CartaoAmigo operator=(CartaoAmigo &);

    friend ostream &operator<<(ostream &out, const CartaoAmigo &cliente);


};

class CartaoAmigoUni : public CartaoAmigo {
    float anuidade;
public:
    CartaoAmigoUni() {};

    CartaoAmigoUni(Date dataAcquisition, Date nascimento, string nome, Address morada, string contacto, string n_cartao,
                   float anuidade);

    float getAnuidade() const;

    CartaoAmigoUni operator=(CartaoAmigoUni &);

    friend ostream &operator<<(ostream &out, const CartaoAmigoUni &cliente);

};

class CartaoAmigoSilver : public CartaoAmigo {
    float anuidade;
public:
    CartaoAmigoSilver() {};

    CartaoAmigoSilver(Date dataAcquisition, Date nascimento, string nome, Address morada, string contacto,
                      string n_cartao,
                      float anuidade);

    float getAnuidade() const;

    CartaoAmigoSilver operator=(CartaoAmigoSilver &);

    friend ostream &operator<<(ostream &out, const CartaoAmigoSilver &cliente);
};

class CartaoAmigoIndi : public CartaoAmigo {
    float anuidade;
public:
    CartaoAmigoIndi() {};

    CartaoAmigoIndi(Date dataAcquisition, Date nascimento, string nome, Address morada, string contacto,
                    string n_cartao,
                    float anuidade);

    float getAnuidade() const;

    CartaoAmigoIndi operator=(CartaoAmigoIndi &);

    friend ostream &operator<<(ostream &out, const CartaoAmigoIndi &cliente);

};


#endif //AEDA_PROJETO_CARTAOAMIGO_H
