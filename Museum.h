//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_MUSEUM_H
#define AEDA_PROJETO_MUSEUM_H

#include "string"
#include "Address.h"
#include "CartaoAmigo.h"
#include <vector>

using namespace std;
class Museum {
    string nome;
    int capacidadeMaxima;
    int lotacao;
    Address endereco;
public:
    Museum();
    virtual void sellTicket();

};






#endif //AEDA_PROJETO_MUSEUM_H
