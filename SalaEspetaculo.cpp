//
// Created by laureano on 08/11/19.
//

#include "SalaEspetaculo.h"

SalaEspetaculo::SalaEspetaculo() : Atracao() {};

SalaEspetaculo::SalaEspetaculo(string nome, int capacidadeMaxima, int lotacao, string endereco, int id, bool aderente) :
        Atracao(nome, capacidadeMaxima, lotacao, endereco, id), aderente(aderente) {};


bool SalaEspetaculo::isAderente() const {
    return aderente;
}

void SalaEspetaculo::setAderente(bool aderente) {
    this->aderente = aderente;
}

void SalaEspetaculo::venderBilhete() {
    Atracao::venderBilhete();
}


// --------------------------------Evento

Evento::Evento() : SalaEspetaculo() {};

Evento::Evento(string nome, int capacidadeMaxima, int lotacao, string endereco, int id, bool aderente,
               string nomeEvento, Date data, time_t horario) :
        SalaEspetaculo(nome, capacidadeMaxima, lotacao, endereco, id, aderente), nomeEvento(nomeEvento), data(data),
        horario(horario) {};

/*
const SalaEspetaculo& Evento::getSalaEspetaculo() const {
    return *salaEspetaculo;
}

void Evento::setSalaEspetaculo(SalaEspetaculo *salaEspetaculo) {
    this->salaEspetaculo = salaEspetaculo;
}*/

const string &Evento::getNomeEvento() const {
    return nomeEvento;
}

void Evento::setNomeEvento(const string &nomeEvento) {
    this->nomeEvento = nomeEvento;
}

const Date &Evento::getData() const {
    return data;
}

void Evento::setData(const Date &data) {
    this->data = data;
}

const time_t &Evento::getHorario() const {
    return horario;
}

void Evento::setHorario(const time_t &horario) {
    this->horario = horario;
}



