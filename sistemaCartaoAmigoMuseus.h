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

    const vector<Cliente> &getClientes() const;

    void setClientes(const Cliente &clientes);

    const vector<Evento> &getEventos() const;

    void setEventos(const vector<Evento> &eventos);

    const vector<SalaEspetaculo> &getSalas() const;

    void setSalas(const vector<SalaEspetaculo> &salas);

    const vector<Museum> &getMuseu() const;

    void setMuseu(const vector<Museum> &museu);

    void venderBilhete(Cliente *cliente, Bilhete *b, Evento *evento);

    void addCliente();

    void addMuseum();

    void addSalaEspetaculo();

    void updateCliente(string card);

    void updateMuseum() const;

    void updateSalaEspetaculo();

    void deleteCliente(string card);

    void deleteMuseum();

    void deleteSalaEspetaculo();

    void readCliente(string card);

    void readMuseum();

    void readSalaEspetaculo();

    //funções utilitárias

    void loadClients();

    void WriteAllClients();

};


#endif //AEDA_PROJETO_SISTEMACARTAOAMIGOMUSEUS_H









