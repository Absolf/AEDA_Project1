//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_SALAESPETACULO_H
#define AEDA_PROJETO_SALAESPETACULO_H
#include "Address.h"
#include "CartaoAmigo.h"

class SalaEspetaculo {
    string nome;
    int capacidadeMaxima;
    int lotacao;
    Address localizacao; //Para comparar com a loc. do usuario -> bilhetes gratuitos para Silver
    int id;
public:
    SalaEspetaculo();
    virtual void sellTicket();

};


class Evento : public SalaEspetaculo {
    bool aceitaDescontoCartaoAmigo; //Apenas eventos selecionados possuem desconto
    Address localizacao;
public:

    Evento(){};
    bool getAceitaDescontoCartaoAmigo() const;

    void setAceitaDescontoCartaoAmigo(bool aceitaDescontoCartaoAmigo);

    void sellTicket();
    void porcentagemOcupada();
    void makeReserva();
};


#endif //AEDA_PROJETO_SALAESPETACULO_H
