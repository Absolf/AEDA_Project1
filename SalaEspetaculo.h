//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_SALAESPETACULO_H
#define AEDA_PROJETO_SALAESPETACULO_H

#include "Atracao.h"
#include "Time.h"
#include "Date.h"


class SalaEspetaculo : public Atracao {
    bool aderente = false;
public:

    SalaEspetaculo();

    SalaEspetaculo(string nome, int capacidadeMaxima, int lotacao, Address endereco, int id, bool aderente);

    bool isAderente() const;

    SalaEspetaculo &operator=(const SalaEspetaculo &espetaculo);

    void setAderente(bool aderente);

};


class Evento : public SalaEspetaculo {
    string nomeEvento;
    Date data;
    time_t horario;
public:
    Evento();

    Evento(string nome, int capacidadeMaxima, int lotacao, Address endereco, int id, bool aderente, string nomeEvento,
           Date data, time_t horario);

    /*
    const SalaEspetaculo& getSalaEspetaculo() const;
    void setSalaEspetaculo(SalaEspetaculo *salaEspetaculo);
*/
    const string &getNomeEvento() const;

    void setNomeEvento(const string &nomeEvento);

    const Date &getData() const;

    void setData(const Date &data);

    const time_t &getHorario() const;

    void setHorario(const time_t &horario);

    SalaEspetaculo &operator=(const SalaEspetaculo &espetaculo);
};


#endif //AEDA_PROJETO_SALAESPETACULO_H
