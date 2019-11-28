//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_SALAESPETACULO_H
#define AEDA_PROJETO_SALAESPETACULO_H

#include "Atracao.h"
#include "Time.h"
#include "Date.h"


class SalaEspetaculo {
protected:
    int capacidadeMaxima;
    Address endereco;
    int id;
    bool aderente = false;
    string nome;
public:
    const string &getNome() const;

    void setNome(const string &nome);

    int getCapacidadeMaxima() const;

    void setCapacidadeMaxima(int capacidadeMaxima);

    const Address &getEndereco() const;

    void setEndereco(const Address &endereco);

    int getId() const;

    void setId(int id);

    SalaEspetaculo();

    SalaEspetaculo(string nome, int capacidadeMaxima, Address endereco, int id, bool aderente);

    SalaEspetaculo(const SalaEspetaculo &s1);


    bool isAderente() const;

    SalaEspetaculo &operator=(const SalaEspetaculo &espetaculo);

    void setAderente(bool aderente);

    friend ostream &operator<<(ostream &out, const SalaEspetaculo &espetaculo);

    bool operator<(const SalaEspetaculo &s1);

};


class Evento : public SalaEspetaculo {
    string nomeEvento;
    int lotacao;
    Date data;
    Time horario;
public:
    Evento();

    Evento(string nome, int capacidadeMaxima, Address endereco, int id, bool aderente, string nomeEvento, int lotacao,
           Date data, Time horario);

    Evento(const Evento &e1);

    Evento(const SalaEspetaculo &s1);

    int getLotacao() const;

    void setLotacao(const int &lotacao);

    /*
    const SalaEspetaculo& getSalaEspetaculo() const;
    void setSalaEspetaculo(SalaEspetaculo *salaEspetaculo);
*/
    const string &getNomeEvento() const;

    void setNomeEvento(const string &nomeEvento);

    const Date getData() const;

    void setData(const Date &data);

    const Time getHorario() const;

    void setHorario(const Time &horario);

    Evento operator=(const Evento &ev);

    bool operator<(const Evento &e1);

    friend ostream &operator<<(ostream &out, const Evento &evento);
};


#endif //AEDA_PROJETO_SALAESPETACULO_H
