//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_ADDRESS_H
#define AEDA_PROJETO_ADDRESS_H
using namespace std;

#include "string"

class Address {
    string rua;
    int cep;
    bool isPredio;
    int numero;
    int andar = 0;
public:

    Address();

    const string &getRua() const;

    void setRua(const string &rua);

    int getCep() const;

    void setCep(int cep);
};


#endif //AEDA_PROJETO_ADDRESS_H
