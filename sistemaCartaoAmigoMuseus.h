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
#include <ctime>
#include <time.h>


using namespace std;


class sistemaCartaoAmigoMuseumPortugal {

    vector<Cliente> clientes;
    vector<Evento> eventos;
    vector<SalaEspetaculo> salas;
    vector<Museum> museu;
public:
    sistemaCartaoAmigoMuseumPortugal();

    void venderBilhete(Cliente *cliente, Bilhete *b, Evento *evento);

    void addCliente();

    void addMuseum();

    void addSalaEspetaculo();

    void updateCliente();

    void updateMuseum() const;

    void updateSalaEspetaculo();

    void deleteCliente();

    void deleteMuseum();

    void deleteSalaEspetaculo();

    void readCliente();

    void readMuseum();

    void readSalaEspetaculo();

    //funções utilitárias

    void loadEverything();

};


#endif //AEDA_PROJETO_SISTEMACARTAOAMIGOMUSEUS_H









