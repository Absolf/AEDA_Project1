//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_ADDRESS_H
#define AEDA_PROJETO_ADDRESS_H
using namespace std;

#include "utilitarios.h"
#include "string"
#include <iostream>

class Address {
    string rua;
    string freguesia;
    string distrito;
    string codpostal;
    int numero;

public:

    Address();

    Address(string rue, int numero, string freguesia, string codpostal, string distrito);

    Address(string endString);

    string getRua() const;

    string getCodpostal() const;

    int getNumero() const;

    string getFreguesia() const;

    string getDistrito() const;
    //string getAddressString(); //???

    void setFreguesia(string freg);

    void setDistrito(string distrito);

    void setRua(string rua);

    void setCodpostal(string codpostal);

    void setNumero(int numero);


    bool operator==(Address &adr); //faltam estes 2 mas n vai ser preciso
    bool operator!=(Address &adr);

    Address operator=(const Address &);

    friend ostream &operator<<(ostream &out, const Address &adr);
};

#endif //AEDA_PROJETO_ADDRESS_H
