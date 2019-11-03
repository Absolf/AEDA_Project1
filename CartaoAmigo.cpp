//
// Created by laureano on 02/11/19.
//

#include "CartaoAmigo.h"
#include "Date.h"
const Date &CartaoAmigo::getValidade() const {
    return validade;
}

void CartaoAmigo::setValidade(const Date &validade) {
    this->validade = dataAcquisition;
    this->validade.setYear(this->validade.getYear() +1);

}

const Date &CartaoAmigo::getDataAcquisition() const {
    return dataAcquisition;
}

void CartaoAmigo::setDataAcquisition(const Date &dataAcquisition) {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    Date today(aTime->tm_mday, aTime->tm_mon, aTime->tm_year+1900);
    this->dataAcquisition = today;
}

const Date &CartaoAmigo::getNascimento() const {
    return nascimento;
}

void CartaoAmigo::setNascimento(const Date &nascimento) {
    this->nascimento = nascimento;
}

const string &CartaoAmigo::getNome() const {
    return nome;
}

void CartaoAmigo::setNome(const string &nome) {
    this->nome = nome;
}

const Local &CartaoAmigo::getMorada() const {
    return morada;
}

void CartaoAmigo::setMorada(const Local &morada) {
    this->morada = morada;
}

const string &CartaoAmigo::getContacto() const {
    return contacto;
}

void CartaoAmigo::setContacto(const string &contacto) {
    this->contacto = contacto;
}

float CartaoAmigo::getValorAssinatura() const {
    return valorAssinatura;
}

void CartaoAmigo::setValorAssinatura(float &valorAssinatura) {
    this->valorAssinatura = valorAssinatura;
}

ostream &operator<<(ostream &out, const CartaoAmigo &cliente){
    out << cliente.getValorAssinatura() <<endl
    << cliente.getNome() <<endl
    //out << this->getMorada() <<endl
    << cliente.getContacto()<<endl
    << cliente.getNascimento() <<endl
    << cliente.getDataAcquisition() << "\n validade: " << cliente.getValidade() <<endl;
    return out;

}
void CartaoAmigo::emitirCartao() {
    cout << this->getNome();
    cout << this->getNascimento();
    //cout << this->morada;
    cout << this->getContacto();
    cout << this->getDataAcquisition();
}

//----------- Cartão Amigo Uni ----------
CartaoAmigoUni::CartaoAmigoUni() {
}

float CartaoAmigoUni::getValorAssinatura() const {
    return 32.45;
}

//-----Cartão Amigo Silver -------------
CartaoAmigoSilver::CartaoAmigoSilver() {}

float CartaoAmigoSilver::getValorAssinatura() const {
    return 30.0;
}

//---------- Cartão Amigo Indi -------------
CartaoAmigoIndi::CartaoAmigoIndi(){}

float CartaoAmigoIndi::getValorAssinatura() const {
    return 54.90;
}


