//
// Created by laureano on 10/11/19.
//

#include "Cliente.h"

Cliente::Cliente() {}

const string &Cliente::getN_cartao() const {
    return n_cartao;
}

void Cliente::setN_cartao(const string &n_cartao) {
    this->n_cartao = n_cartao;
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

const Address &Cliente::getMorada() const {
    return morada;
}

void Cliente::setMorada(const Address &morada) {
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

void Cliente::addBilhete(Bilhete &b) {
    bilhetes.push_back(&b);
}

void Cliente::aderirCartao() {
    Date acq;
    acq.actualDate();
    if ((acq.getYear() - this->nascimento.getYear()) > 65)
        cartao = new CartaoAmigoSilver();
    else if ((universitario) && (acq.getYear() - this->nascimento.getYear()) <= 65)
        cartao = new CartaoAmigoUni();
    else
        cartao = new CartaoAmigoIndi();
    cartao->setDataAcquisition(acq);
    cartao->setNome(nome);
    cartao->set_Ncartao(n_cartao);
    cartao->setNascimento(nascimento);
    cartao->setContacto(contacto);
    cartao->setMorada(morada);
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
    cout << "Numero do Cartao: " << n_cartao << endl;
    cout << "Data de Nascimento: " << this->getNascimento() << endl;
    cout << "Contacto Telemóvel: " << this->getContacto() << endl;
    cout << "Morada: " << this->getMorada();
    cout << "É membro de universidade? ";
    if (getUniversitario())
        cout << " Sim" << endl;
    else
        cout << "Não" << endl;
    if (this->getBilhetes().size() != 0) {
        for (int i = 0; i < this->getBilhetes().size(); i++) {
            cout << endl;
            this->getBilhetes()[i]->printBilhete();
            cout << endl;
        }
    }
}

ostream &operator<<(ostream &out, Cliente &cli) {
    out << cli.getN_cartao() << endl;
    out << cli.getNome() << endl;
    out << cli.getNascimento() << endl;
    out << cli.getCartao().getDataAcquisition() <<endl;
    out << cli.getContacto() << endl;
    out << cli.getMorada()<< endl;
    out << cli.getUniversitario() << endl;
    return out;
}