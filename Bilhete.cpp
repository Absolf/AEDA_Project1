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

void Bilhete::setEvento(Evento *evento) {
    this->evento = evento;
}
