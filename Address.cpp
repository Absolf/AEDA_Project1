//
// Created by laureano on 08/11/19.
//

#include "Address.h"

Address::Address() {
    rua = "";
    distrito = "";
    freguesia = "";
    codpostal = "";
    numero = 0;
}

Address::Address(string rua, int numero, string freguesia, string codpostal, string distrito) : rua(rua),
                                                                                                numero(numero),
                                                                                                freguesia(freguesia),
                                                                                                codpostal(codpostal),
                                                                                                distrito(distrito) {};

Address::Address(string handler) {
    vector<string> addres_vec;
    tokenize(handler, '/', addres_vec); //Creates a vector with the attributes of an address (through a string)
    for (int i = 0; (unsigned) i < addres_vec.size(); i++) {
        if (i == 0) {
            this->rua = addres_vec.at(0);
        } else if (i == 1) {
            istringstream teste(addres_vec.at(1));
            teste >> this->numero;
        } else if (i == 2) {
            this->freguesia = addres_vec.at(2);
        } else if (i == 3) {
            this->codpostal = addres_vec.at(3);
        } else if (i == 4) {
            this->distrito = addres_vec.at(4);
        }
    }
};


//------------------Gets
string Address::getRua() const { return rua; }

string Address::getDistrito() const { return distrito; }

string Address::getFreguesia() const { return freguesia; }

string Address::getCodpostal() const { return codpostal; }

int Address::getNumero() const { return numero; }

//------------------Sets

void Address::setRua(string rua) { this->rua = rua; }

void Address::setCodpostal(string codpostal) { this->codpostal = codpostal; }

void Address::setNumero(int numero) { this->numero = numero; }

void Address::setDistrito(string distrito) { this->distrito = distrito; }

void Address::setFreguesia(string freg) { this->freguesia = freg; }

//------------------other methods
ostream &operator<<(ostream &out, const Address &adr) {
    out << adr.rua << "/" << adr.numero << "/" << adr.freguesia << "/"
        << adr.codpostal << "/" << adr.distrito;
    return out;
}

/*
Date Date::operator=(const Date &d2) {
    return Date(this->day = d2.getDay(), this->month = d2.getMonth(), this->year = d2.getYear());
}
 */

Address Address::operator=(const Address &adr) {
    return Address(this->rua = adr.getRua(), this->numero = adr.getNumero(), this->freguesia = adr.getFreguesia(),
                   this->codpostal = adr.getCodpostal(), this->distrito = adr.getDistrito());
}