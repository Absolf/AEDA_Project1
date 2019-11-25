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
    vector<SalaEspetaculo> salas = {};
    vector<Museum> museus;
public:
    sistemaCartaoAmigoMuseumPortugal(const vector<SalaEspetaculo> &salas);

public:
    sistemaCartaoAmigoMuseumPortugal();

    const vector<Cliente> &getClientes() const;

    void setClientes(const Cliente &clientes);

    const vector<Evento> &getEventos() const;

    void setEventos(const Evento &evento);

    const vector<SalaEspetaculo> &getSalas() const;

    void setSalas(SalaEspetaculo sala);

    const vector<Museum> &getMuseu() const;

    void setMuseu(const Museum &museu);

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

    void WriteAllClients();
    int searchUser(string card);
    int searchSalaEspetaculo(string nome);
    int searchEvento(string nome);
    void loadClients();
    void loadSalaEspetaculos();
    void loadEventos();

};


#endif //AEDA_PROJETO_SISTEMACARTAOAMIGOMUSEUS_H









