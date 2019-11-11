//
// Created by laureano on 11/11/19.
//

#include "Atracao.h"
Atracao::Atracao() {}


Atracao::Atracao(string nome, int capacidadeMaxima, int lotacao, string endereco, int id) : nome(nome), capacidadeMaxima(capacidadeMaxima), lotacao(lotacao), endereco(endereco), id(id) {};

const string &Atracao::getNome() const {
    return nome;
}

void Atracao::setNome(const string &nome) {
    this->nome = nome;
}

int Atracao::getCapacidadeMaxima() const {
    return capacidadeMaxima;
}

void Atracao::setCapacidadeMaxima(int capacidadeMaxima) {
    this->capacidadeMaxima = capacidadeMaxima;
}

const int Atracao::getLotacao() const {
    return lotacao;
}

void Atracao::setLotacao(const int &lotacao) {
    this->lotacao = lotacao;
}

const string &Atracao::getEndereco() const {
    return endereco;
}

void Atracao::setEndereco(const string &endereco) {
    this->endereco = endereco;
}

int Atracao::getId() const {
    return id;
}

void Atracao::setId(int id) {
    this->id = id;
}

void Atracao::venderBilhete() {
    this->lotacao++;
}
