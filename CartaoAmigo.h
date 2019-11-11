//
// Created by laureano on 02/11/19.
//

#ifndef AEDA_PROJETO_CARTAOAMIGO_H
#define AEDA_PROJETO_CARTAOAMIGO_H
#include "Date.h"
#include "Address.h"
#include "SalaEspetaculo.h"
#include <vector>


class CartaoAmigo{
    Date dataAcquisition;
    Date nascimento;
    string nome;
    string morada;
    string contacto;
    string nif;
public:
    CartaoAmigo();
    CartaoAmigo(Date dataAcquisition, Date nascimento, string nome, string morada, string contacto, string nif): dataAcquisition(dataAcquisition), nascimento(nascimento),
                                                                                                                                          nome(nome), morada(morada), contacto(contacto), nif(nif){};
    virtual float getAnuidade() const;
    const Date &getDataAcquisition() const;
    void setDataAcquisition(const Date &dataAcquisition);

    const Date &getNascimento() const;
    void setNascimento(const Date &nascimento);

    const string &getNome() const;
    void setNome(const string &nome);

    const string &getMorada() const;
    void setMorada(const string &morada);

    const string &getContacto() const;
    void setContacto(const string &contacto);

    const string &getNif() const;

    void setNif(const string &nif);
    CartaoAmigo operator=(const CartaoAmigo&);
    friend ostream &operator<<(ostream &out, const CartaoAmigo &cliente);


};

class CartaoAmigoUni : public  CartaoAmigo{
    float anuidade;
public:
    CartaoAmigoUni(){};
    CartaoAmigoUni(Date dataAcquisition, Date nascimento, string nome, string morada, string contacto, string nif, float anuidade);
    CartaoAmigoUni operator=(const CartaoAmigo&);
    float getAnuidade() const;

};

class CartaoAmigoSilver : public CartaoAmigo {
    float anuidade;
public:
    CartaoAmigoSilver(){};
    CartaoAmigoSilver(Date dataAcquisition, Date nascimento, string nome, string morada, string contacto, string nif, float anuidade);
    CartaoAmigoSilver operator=(const CartaoAmigo&);
    float getAnuidade() const;
};

class CartaoAmigoIndi : public CartaoAmigo {
    float anuidade;
public:
    CartaoAmigoIndi(){};
    CartaoAmigoIndi(Date dataAcquisition, Date nascimento, string nome, string morada, string contacto, string nif, float anuidade);
    CartaoAmigoSilver operator=(const CartaoAmigo&);
    float getAnuidade() const;

};


#endif //AEDA_PROJETO_CARTAOAMIGO_H
