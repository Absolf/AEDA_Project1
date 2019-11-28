//
// Created by laureano on 08/11/19.
//

#include "SalaEspetaculo.h"

SalaEspetaculo::SalaEspetaculo() {};

SalaEspetaculo::SalaEspetaculo(string nome, int capacidadeMaxima, Address endereco, int id, bool aderente)
        :
        nome(nome), capacidadeMaxima(capacidadeMaxima), endereco(endereco), id(id),
        aderente(aderente) {};

SalaEspetaculo::SalaEspetaculo(const SalaEspetaculo &s1) {
    this->nome = s1.getNome();
    this->capacidadeMaxima = s1.getCapacidadeMaxima();
    this->endereco = s1.getEndereco();
    this->id = s1.getId();
    this->aderente = s1.isAderente();
}

bool SalaEspetaculo::isAderente() const {
    return aderente;
}

void SalaEspetaculo::setAderente(bool aderente) {
    this->aderente = aderente;
}

SalaEspetaculo &SalaEspetaculo::operator=(const SalaEspetaculo &espetaculo) {
    this->nome = espetaculo.nome;
    this->capacidadeMaxima = espetaculo.capacidadeMaxima;
    this->endereco = espetaculo.endereco;
    this->id = espetaculo.id;
    this->aderente = espetaculo.aderente;
}

ostream &operator<<(ostream &out, const SalaEspetaculo &espetaculo) {
    out << espetaculo.nome << endl << espetaculo.capacidadeMaxima << endl
        << espetaculo.endereco << endl << espetaculo.id << endl << espetaculo.aderente << endl;
    return out;
}

const string &SalaEspetaculo::getNome() const {
    return nome;
}

void SalaEspetaculo::setNome(const string &nome) {
    this->nome = nome;
}

int SalaEspetaculo::getCapacidadeMaxima() const {
    return capacidadeMaxima;
}

void SalaEspetaculo::setCapacidadeMaxima(int capacidadeMaxima) {
    this->capacidadeMaxima = capacidadeMaxima;
}

const Address &SalaEspetaculo::getEndereco() const {
    return endereco;
}

void SalaEspetaculo::setEndereco(const Address &endereco) {
    SalaEspetaculo::endereco = endereco;
}

int SalaEspetaculo::getId() const {
    return id;
}

void SalaEspetaculo::setId(int id) {
    SalaEspetaculo::id = id;
}

bool SalaEspetaculo::operator<(const SalaEspetaculo &s1) {
    return this->id < s1.getId();
}

// --------------------------------Evento

Evento::Evento() : SalaEspetaculo() {
    this->lotacao = 0;
};


Evento::Evento(string nome, int capacidadeMaxima, Address endereco, int id, bool aderente,
               string nomeEvento, int lotacao, Date data, Time horario)
        : SalaEspetaculo(nome, capacidadeMaxima, endereco, id, aderente), nomeEvento(nomeEvento), lotacao(lotacao),
          data(data), horario(horario) {};

const string &Evento::getNomeEvento() const {
    return nomeEvento;
}

void Evento::setNomeEvento(const string &nomeEvento) {
    this->nomeEvento = nomeEvento;
}

const Date Evento::getData() const {
    return data;
}

void Evento::setData(const Date &data) {
    this->data = data;
}

const Time Evento::getHorario() const {
    return horario;
}

void Evento::setHorario(const Time &horario) {
    this->horario = horario;
}

int Evento::getLotacao() const {
    return lotacao;
}

void Evento::setLotacao(const int &lotacao) {
    this->lotacao = lotacao;
}

Evento::Evento(const Evento &ev) {
    this->nome = ev.getNome();
    this->capacidadeMaxima = ev.getCapacidadeMaxima();
    this->endereco = ev.getEndereco();
    this->id = ev.getId();
    this->aderente = ev.isAderente();
    this->nomeEvento = ev.getNomeEvento();
    this->lotacao = ev.getLotacao();
    this->data = ev.getData();
    this->horario = ev.getHorario();
}

Evento::Evento(const SalaEspetaculo &s1) {
    this->nome = s1.getNome();
    this->capacidadeMaxima = s1.getCapacidadeMaxima();
    this->endereco = s1.getEndereco();
    this->id = s1.getId();
    this->aderente = s1.isAderente();
    this->lotacao = 0;
}

Evento Evento::operator=(const Evento &ev) {
    return Evento(this->nome = ev.getNome(), this->capacidadeMaxima = ev.getCapacidadeMaxima(),
                  this->endereco = ev.getEndereco(), this->id = ev.getId(),
                  this->aderente = ev.isAderente(), this->nomeEvento = ev.getNomeEvento(),
                  this->lotacao = ev.getLotacao(), this->data = ev.getData(), this->horario = ev.getHorario());
}

ostream &operator<<(ostream &out, const Evento &evento) {
    out  << evento.nome << endl << evento.nomeEvento << endl<< evento.lotacao << endl << evento.data << endl << evento.horario << endl;
    return out;
}

bool Evento::operator<(const Evento &e1) {
    return this->data < e1.getData();
}


