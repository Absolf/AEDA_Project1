//
// Created by Gabriel Rocco on 23/10/2019.
//

#ifndef AEDA_PROJETO_SISTEMACARTAO_H
#define AEDA_PROJETO_SISTEMACARTAO_H

#include "SalaEspetaculo.h"
#include "Museum.h"
#include "Cliente.h"
#include <vector>
#include "Cliente.h"
#include <ctime>
#include <time.h>


using namespace std;


class sistemaCartao {

    vector<Cliente> clientes;
    vector<Evento> eventos;
    vector<SalaEspetaculo> salas;
    vector<Museum> museus;
public:
    sistemaCartao(const vector<SalaEspetaculo> &salas);

public:
    sistemaCartao();

    const vector<Cliente> &getClientes() const;

    void setClientes(const Cliente &clientes);

    const vector<Evento> &getEventos() const;

    void setEventos(const Evento &evento);

    const vector<SalaEspetaculo> &getSalas() const;

    void setSalas(SalaEspetaculo sala);

    const vector<Museum> &getMuseu() const;

    void setMuseu(const Museum &museu);

    void venderBilhete(Cliente *cliente, Bilhete &b, Evento *evento);

    void createTicket(Cliente *cliente, Bilhete &b, Evento *ev);

    void addCliente();

    void addMuseum();

    void addSalaEspetaculo();

    void updateCliente(string card);

    void updateClienteAdm();

    void updateMuseum() const;

    void updateSalaEspetaculo();

    void deleteCliente();

    void deleteMuseum();

    void deleteSalaEspetaculo();

    void readClients();

    void readClient();

    void readMuseum();

    void readSalaEspetaculo();

    void readSala();

    //funções utilitárias

    void WriteAllClients();

    void WriteAllSalas();

    void WriteAllEventos();

    int searchUser(string card);

    int searchSalaEspetaculo(string nome);

    int searchEvento(string nome);

    void loadClients();

    void loadSalaEspetaculos();

    void loadEventos();

};


#endif //AEDA_PROJETO_SISTEMACARTAO_H









