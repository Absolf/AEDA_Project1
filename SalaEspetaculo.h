//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_SALAESPETACULO_H
#define AEDA_PROJETO_SALAESPETACULO_H
#include "Address.h"
#include "CartaoAmigo.h"
#include "Atracao.h"
#include "Time.h"

class SalaEspetaculo : Atracao{
    bool aderente = false;
public:
    bool isAderente() const;

    void setAderente(bool aderente);

    SalaEspetaculo();
    void venderBilhete();
};

class Evento : public SalaEspetaculo{
    SalaEspetaculo *salaEspetaculo;
    string nome;
    Date data;
    time_t horario;
public:
    Evento(){};
    const SalaEspetaculo& getSalaEspetaculo() const;
    void setSalaEspetaculo(SalaEspetaculo *salaEspetaculo);

    const string &getNome() const;
    void setNome(const string &nome);

    const Date &getData() const;
    void setData(const Date &data);

    const time_t&getHorario() const;
    void setHorario(const time_t &horario);
};


#endif //AEDA_PROJETO_SALAESPETACULO_H
