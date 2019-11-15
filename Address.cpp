//
// Created by laureano on 08/11/19.
//

#include "Address.h"

Address::Address(){
    rua = "";
    distrito = "";
    freguesia = "";
    codpostal = "";
    numero = 0;
}

Address::Address(string handler) {
    vector<string> addres_vec;
    tokenize(handler, '/', addres_vec); //Creates a vector with the attributes of an address (through a string)
    for (int i = 0; (unsigned)i < addres_vec.size(); i++)
    {
        if (i == 0)
        {
            this->rua = addres_vec.at(0);
        }
        else if (i == 1)
        {
            istringstream teste(addres_vec.at(1));
            teste >> this->numero;
        }
        else if (i == 2)
        {
            this->freguesia = addres_vec.at(2);
        }
        else if (i == 3)
        {
            this->codpostal = addres_vec.at(3);
        }
        else if (i == 4)
        {
            this->distrito = addres_vec.at(4);
        }
    }
};


//------------------Gets
string Address::getRua() const {return rua;}
string Address::getDistrito()const { return distrito;}
string Address::getFreguesia() const {return freguesia;}
string Address::getCodpostal() const{return codpostal;}
int Address::getNumero() const { return numero; }

//------------------Sets

void Address::setRua(string rua) {this->rua = rua;}
void Address::setCodpostal(string codpostal) {this->codpostal = codpostal;}
void Address::setNumero(int numero) { this->numero = numero;}
void Address::setDistrito(string distrito) {this->distrito = distrito;}
void Address::setFreguesia(string freg) {this->freguesia = freg;}

//------------------other methods
friend ostream &operator<<(ostream &out, const Address &adr){
    out << "Rua: " << adr.rua << "\nNumero: " << adr.numero << "\nFreguesia: " << adr.freguesia << "\nCódigo Postal: " << adr.codpostal << "\nDistrito: Porto" << endl;
}