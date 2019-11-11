//
// Created by Gabriel Rocco on 23/10/2019.
//

#ifndef AEDA_PROJETO_SISTEMACARTAOAMIGOMUSEUS_H
#define AEDA_PROJETO_SISTEMACARTAOAMIGOMUSEUS_H
#include "SalaEspetaculo.h"
#include "Museum.h"
#include "Cliente.h"
#include <vector>
#include "Cliente.h"


using namespace std;


class sistemaCartaoAmigoMuseumPortugal {

    vector<Cliente*> clientes;
    vector<Evento*> eventos;
    vector<Museum*> museu;
public:
    sistemaCartaoAmigoMuseumPortugal();
    void venderBilhete(Cliente *cliente, Bilhete *b, Evento *evento);
    void addCartaoAmigo() const ;
    void addMuseum() const;
    void addSalaEspetaculo() const;

    void updateCartaoAmigo() const;
    void updateMuseum() const;
    void updateSalaEspetaculo() const;

    void deleteCartaoAmigo() const;
    void deleteMuseum() const;
    void deleteSalaEspetaculo() const;

    void readCartaoAmigo () const;
    void readMuseum() const;
    void readSalaEspetaculo() const;


};



#endif //AEDA_PROJETO_SISTEMACARTAOAMIGOMUSEUS_H









