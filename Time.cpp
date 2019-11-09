//
// Created by laureano on 08/11/19.
//

#include "Time.h"

int Time::getHora() const {
    return hora;
}

void Time::setHora(int hora) {
    this->hora = hora;
}

int Time::getMinutos() const {
    return minutos;
}

void Time::setMinutos(int minutos) {
    this->minutos = minutos;
}

int Time::getSegundos() const {
    return segundos;
}

void Time::setSegundos(int segundos) {
    this->segundos = segundos;
}
