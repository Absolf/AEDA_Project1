//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_TIME_H
#define AEDA_PROJETO_TIME_H
using namespace std;
#include "string"
#include "CartaoAmigo.h"

class Time {
    CartaoAmigo novo;
    int hora;
    int minutos;
    int segundos;
public:

    Time();
    int getHora() const;

    void setHora(int hora);

    int getMinutos() const;

    void setMinutos(int minutos);

    int getSegundos() const;
    void setSegundos(int segundos);

};


#endif //AEDA_PROJETO_TIME_H
