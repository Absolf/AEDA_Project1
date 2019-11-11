//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_SALAESPETACULO_H
#define AEDA_PROJETO_SALAESPETACULO_H
#include "Address.h"
#include "Atracao.h"
#include "Time.h"


class SalaEspetaculo : public Atracao{
    bool aderente = false;
public:

    SalaEspetaculo();
    SalaEspetaculo(string nome, int capacidadeMaxima, int lotacao, string endereco, int id, bool aderente);
    bool isAderente() const;

    void setAderente(bool aderente);
    void venderBilhete();
};

class Evento : public SalaEspetaculo{
    string nomeEvento;
    Date data;
    time_t horario;
public:
    Evento();
    Evento(string nome, int capacidadeMaxima, int lotacao, string endereco, int id, bool aderente, string nomeEvento, Date data, time_t horario);
    /*
    const SalaEspetaculo& getSalaEspetaculo() const;
    void setSalaEspetaculo(SalaEspetaculo *salaEspetaculo);
*/
    const string &getNomeEvento() const;
    void setNomeEvento(const string &nomeEvento);

    const Date &getData() const;
    void setData(const Date &data);

    const time_t&getHorario() const;
    void setHorario(const time_t &horario);
};


#endif //AEDA_PROJETO_SALAESPETACULO_H
