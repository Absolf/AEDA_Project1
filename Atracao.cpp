//
// Created by laureano on 11/11/19.
//

#include "Atracao.h"

Atracao::Atracao() {}

Atracao::Atracao(string nome, int capacidadeMaxima, int lotacao, Address endereco, int id) : nome(nome),
                                                                                             capacidadeMaxima(
                                                                                                     capacidadeMaxima),
                                                                                             lotacao(lotacao),endereco(endereco),id(id) {};
Atracao::Atracao(const Atracao& at1){
    this->nome = at1.getNome();
    this->capacidadeMaxima = at1.getCapacidadeMaxima();
    this->lotacao = at1.getLotacao();
    this->endereco = at1.endereco;
    this->id = at1.getId();
};

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

const Address &Atracao::getEndereco() const {
    return endereco;
}

void Atracao::setEndereco(const Address &endereco) {
    this->endereco = endereco;
}

int Atracao::getId() const {
    return id;
}

void Atracao::setId(int id) {
    this->id = id;
}

ostream &operator<<(ostream &out, const Atracao &atracao) {
    out << "\nid: " << atracao.id << "\nNome: " << atracao.nome << "\nCapacidade Máxima: " << atracao.capacidadeMaxima
        << "\nLotação: " << atracao.lotacao << "\nEndereco: " << atracao.endereco << endl;
}

Atracao &Atracao::operator=(const Atracao &atracao) {
    this->nome = atracao.nome;
    this->capacidadeMaxima = atracao.capacidadeMaxima;
    this->lotacao = atracao.lotacao;
    this->endereco = atracao.endereco;
    this->id = atracao.id;
}

