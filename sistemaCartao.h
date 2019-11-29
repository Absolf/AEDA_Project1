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
    sistemaCartao();

    const vector<Cliente> &getClientes() const;

    void setClientes(const Cliente &clientes);

    const vector<Evento> &getEventos() const;

    void setEventos(const Evento &evento);

    const vector<SalaEspetaculo> &getSalas() const;

    void setSalas(SalaEspetaculo sala);

    const vector<Museum> &getMuseu() const;

    void setMuseu(const Museum &museu);

    void venderBilhete(Cliente &cliente, Bilhete &b, Evento *evento);

    void createTicket(Cliente &cliente, Bilhete &b, Evento *ev);
    void createTicketSilver(Cliente &cliente, Bilhete &b, Evento *ev);

    void addCliente();

    void addMuseum();

    void addSalaEspetaculo();

    void addEvento();

    void updateCliente(string card);

    void updateClienteAdm();

    void updateMuseum() const;

    void updateSalaEspetaculo();

    void updateEvento();

    void deleteCliente();

    void deleteMuseum();

    void deleteSalaEspetaculo();

    void deleteEvento();

    void readClients();

    void readClient();

    void readMuseum();

    void readEvento();

    void readEventos();

    void sortClients();

    void sortSalas();

    void sortEventos();

    void readSalaEspetaculo();

    void readSala();

    //funções utilitárias

    void comprarBilhete(Cliente &cli, Bilhete &bi);

    bool procuraArea(string distrito);
    bool metricaSilver(Cliente &cliente, Bilhete &b, Evento *ev);
    void WriteAllClients();

    void WriteAllSalas();

    void WriteAllEventos();

    int searchUser(string card);
    string arrumaString(string str);

    int searchSalaEspetaculo(string nome);

    vector<string> eventosGratuitosSilver(int idx);

    bool horasParaEvento(Evento *ev);

    int searchEvento(string nome);
    int searchEventoById(int id);
    void clientsEvents(string line, Cliente &cli, Bilhete &bi);
    void loadClients();

    void loadSalaEspetaculos();

    void loadEventos();

};


#endif //AEDA_PROJETO_SISTEMACARTAO_H









