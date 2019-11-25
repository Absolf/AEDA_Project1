//
// Created by laureano on 11/11/19.
//

#include "Bilhete.h"

float Bilhete::getValor() const {
    return valor;
}

void Bilhete::setValor(float valor) {
    Bilhete::valor = valor;
}

const Evento &Bilhete::getEvento() const {
    return *evento;
}

void Bilhete::setEvento(Evento evento) {
    this->evento = &evento;
}

void Bilhete::printBilhete() {
    cout << " Apresentando função printBilhete() \n------------Bilhete------------- \n";
    cout << "Sala de Espetáculo: " << evento->getNome() << endl;
    cout << "Evento: " << evento->getNomeEvento() << endl;
    cout << "Valor: $" << this->valor << endl;
    cout << "Data: " << evento->getData() << endl;
//    cout << "Horário: " << evento->getHorario();
    cout << "Lotacao: " << evento->getLotacao() << endl;
}

ostream &operator<<(ostream &out, const Bilhete &bilhete) {
    //cout << " Apresentando função printBilhete() \n------------Bilhete------------- \n";
    cout << "Sala de Espetáculo: " << bilhete.evento->getNome() << endl;
    cout << "Evento: " << bilhete.evento->getNomeEvento() << endl;
    cout << "Valor: $" << bilhete.valor << endl;
    cout << "Data: " << bilhete.evento->getData() << endl;
    cout << bilhete.evento->getCapacidadeMaxima();
    cout <<  bilhete.evento->getEndereco();
    //cout << "Horário: " << bilhete.evento->getHorario();
}

void teste() {
    Bilhete bilhete;
    cout << bilhete;
}