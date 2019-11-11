//
// Created by laureano on 11/11/19.
//

#include "Atracao.h"

const string &Atracao::getNome() const {
    return nome;
}

void Atracao::setNome(const string &nome) {
    Atracao::nome = nome;
}

int Atracao::getCapacidadeMaxima() const {
    return capacidadeMaxima;
}

void Atracao::setCapacidadeMaxima(int capacidadeMaxima) {
    Atracao::capacidadeMaxima = capacidadeMaxima;
}

int Atracao::getLotacao() const {
    return lotacao;
}

void Atracao::setLotacao(int lotacao) {
    Atracao::lotacao = lotacao;
}

const Address &Atracao::getEndereco() const {
    return endereco;
}

void Atracao::setEndereco(const Address &endereco) {
    Atracao::endereco = endereco;
}

int Atracao::getId() const {
    return id;
}

void Atracao::setId(int id) {
    Atracao::id = id;
}

void Atracao::venderBilhete() {
    this->lotacao++;
}
