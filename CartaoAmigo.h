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
    Address morada;
    string contacto;
    float valorAssinatura;
    string nif;
public:
    CartaoAmigo();
    CartaoAmigo(Date dataAcquisition, Date nascimento, string nome, Address morada, string contacto, float valorAssinatura): dataAcquisition(dataAcquisition), nascimento(nascimento),
                                                                                                                                          nome(nome), morada(morada), contacto(contacto), valorAssinatura(valorAssinatura) {};
    float getValorAssinatura() const;
    void setValorAssinatura(float &valorAssinatura);

    const Date &getDataAcquisition() const;
    void setDataAcquisition(const Date &dataAcquisition);

    const Date &getNascimento() const;
    void setNascimento(const Date &nascimento);

    const string &getNome() const;
    void setNome(const string &nome);
/**
 *
 * @return
 */
    const Address &getMorada() const;
    void setMorada(const Address &morada);

    const string &getContacto() const;
    void setContacto(const string &contacto);

    void emitirCartao();

    float darDescontoMuseu();
    float darDescontoEvento();

    friend ostream &operator<<(ostream &out, const CartaoAmigo &cliente);


};

class CartaoAmigoUni : public  CartaoAmigo{
public:
    CartaoAmigoUni();
    void emitirCartao();
    float getValorAssinatura() const;

};

class CartaoAmigoSilver : public CartaoAmigo {
public:
    CartaoAmigoSilver();
    void emitirCartao();
    float getValorAssinatura() const;
    /*Avisa membros Silver de eventos na proximidade caso faltando menos de
8h para o evento ainda nao tenham sido vendidos no minimo 50% do total
de ingressos. Recebe o evento em questão e o vetor de clientes Silver*/
    //void avisarMembrosSilver(Evento evento1 , vector<CartaoAmigo> &v);

};

class CartaoAmigoIndi : public CartaoAmigo {
public:
    CartaoAmigoIndi();
    void emitirCartao();
    float getValorAssinatura() const;

};


#endif //AEDA_PROJETO_CARTAOAMIGO_H
