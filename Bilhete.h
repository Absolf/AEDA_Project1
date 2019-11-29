//
// Created by laureano on 11/11/19.
//

#ifndef AEDA_PROJETO_BILHETE_H
#define AEDA_PROJETO_BILHETE_H

#include "SalaEspetaculo.h"

class Bilhete {
    float valor;
    Evento *evento;
public:
    Bilhete();

    float getValor() const;

    void setValor(float valor);

    const Evento &getEvento() const;

    void setEvento(Evento *evento);

    void printBilhete();

    friend ostream &operator<<(ostream &out, const Bilhete &bilhete);
};


#endif //AEDA_PROJETO_BILHETE_H
