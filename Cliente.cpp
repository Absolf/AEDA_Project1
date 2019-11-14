//
// Created by laureano on 10/11/19.
//

#include "Cliente.h"

Cliente::Cliente() {}

const string &Cliente::getNif() const {
    return nif;
}

void Cliente::setNif(const string &nif) {
    this->nif = nif;
}

const Date &Cliente::getNascimento() const {
    return nascimento;
}

void Cliente::setNascimento(const Date &nascimento) {
    this->nascimento = nascimento;
}

const string &Cliente::getNome() const {
    return nome;
}

void Cliente::setNome(const string &nome) {
    this->nome = nome;
}

const string &Cliente::getMorada() const {
    return morada;
}

void Cliente::setMorada(const string &morada) {
    this->morada = morada;
}

const string &Cliente::getContacto() const {
    return contacto;
}

void Cliente::setContacto(const string &contacto) {
    this->contacto = contacto;
}

bool Cliente::temCartao() {

    if (this->cartao)
        return (this->cartao);
    else {
        cout << "Name: '" << this->cartao->getNome() << "' " << endl;
        return false;
    }

}

const bool &Cliente::getUniversitario() const {
    return universitario;
}

void Cliente::setUniversitario(const bool &universitario) {
    this->universitario = universitario;
}

const CartaoAmigo &Cliente::getCartao() const {
    return *cartao;
}

void Cliente::setCartao(CartaoAmigo *cartao) {
    this->cartao = cartao;
}

void Cliente::addBilhete(Bilhete *b) {
    bilhetes.push_back(b);
}

void Cliente::aderirCartao() {
    Date acq;
    acq.actualDate();
    if ((acq.getYear() - getNascimento().getYear()) > 65)
        cartao = new CartaoAmigoSilver();
    else if ((universitario) && (acq.getYear() - nascimento.getYear()) <= 65)
        cartao = new CartaoAmigoUni();
    else
        cartao = new CartaoAmigoIndi();
    cartao->setDataAcquisition(acq);
    cartao->setNome(nome);
    cartao->setNascimento(nascimento);
    cartao->setContacto(contacto);
    cartao->setMorada(morada);
    cartao->setNif(nif);
}

const vector<Bilhete *> &Cliente::getBilhetes() const {
    return bilhetes;
}

void Cliente::setBilhetes(const vector<Bilhete *> bilhetes) {
    Cliente::bilhetes = bilhetes;
}


void Cliente::printCliente() {
    cout << " Apresentando função printCliente() \n------------Cliente------------- \n";
    cout << "Nome: " << this->getNome() << endl;
    cout << "Data de Nascimento: " << this->getNascimento();
    cout << "Nif: " << this->getNif() << endl;
    cout << "Contacto Telemóvel: " << this->getContacto() << endl;
    cout << "Morada: " << this->getMorada() << endl;
    cout << "É membro de universidade? ";
    if (getUniversitario())
        cout << " Sim" << endl;
    else
        cout << "Não" << endl;
    for (int i = 0; i < this->getBilhetes().size(); i++) {
        cout << endl;
        this->getBilhetes()[i]->printBilhete();
        cout << endl;
    }
}