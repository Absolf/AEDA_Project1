//
// Created by laureano on 08/11/19.
//

#include "SalaEspetaculo.h"

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
const SalaEspetaculo& Evento::getSalaEspetaculo() const {
    return *salaEspetaculo;
}

void Evento::setSalaEspetaculo(SalaEspetaculo *salaEspetaculo) {
    this->salaEspetaculo = salaEspetaculo;
}

const string &Evento::getNome() const {
    return nome;
}

void Evento::setNome(const string &nome) {
    this->nome = nome;
}

const Date & Evento::getData() const {
    return data;
}

void Evento::setData(const Date &data) {
    this->data = data;
}

const time_t & Evento::getHorario() const {
    return horario;
}

void Evento::setHorario(const time_t &horario) {
    this->horario = horario;
}



