//
// Created by laureano on 08/11/19.
//

#include "SalaEspetaculo.h"

SalaEspetaculo::SalaEspetaculo() : Atracao() {};

SalaEspetaculo::SalaEspetaculo(string nome, int capacidadeMaxima, int lotacao, Address endereco, int id, bool aderente)
        :
        Atracao(nome, capacidadeMaxima, lotacao, endereco, id), aderente(aderente) {};

bool SalaEspetaculo::isAderente() const {
    return aderente;
}

void SalaEspetaculo::setAderente(bool aderente) {
    this->aderente = aderente;
}

SalaEspetaculo &SalaEspetaculo::operator=(const SalaEspetaculo &espetaculo) {
    Atracao::operator=(espetaculo);
    this->aderente = espetaculo.aderente;
}

/*
SalaEspetaculo newSala;
newSala.setNome(readString("Nome: "));
newSala.setCapacidadeMaxima(readInteger("capacidade: "));
newSala.setLotacao(0);
Address endereco(readString("\n *No formato Rua / Nº Porta / Freguesia / Código-Postal / Distrito* \nEndereço: "));
newSala.setEndereco(endereco);
newSala.setAderente(readInteger("0 pra falso e 1 para verdadeiro \n aderente: "));
newSala.setId(readInteger("Id"));
salas.push_back(newSala);
 */
vector<string> Handler(vector<string> vec) {
    string line;
    vector<string> new_sala;
    cout << "::::::::::::::" << endl;
    cin.ignore();
    for (size_t i = 0; i < vec.size(); i++) {
        if (i == 0) //for sala name
        {
            line = vec[i];
            getline(cin, line);
            new_sala.push_back(line);
        }
        if (i == 1) // for max capacity;
        {
            new_sala.push_back(to_string(readInteger(vec[i])));
        }
        if (i == 2) // for adddress;
        {
            line = vec[i];
            getline(cin, line);
            new_sala.push_back(line);
        }
        if (i == 3) // for Aderente;
        {
            new_sala.push_back(to_string(readInteger(vec[i])));
        }
    }

    return new_sala;
}
// --------------------------------Evento

Evento::Evento() : SalaEspetaculo() {};

Evento::Evento(string nome, int capacidadeMaxima, int lotacao, Address endereco, int id, bool aderente,
               string nomeEvento, Date data, time_t horario) :
        SalaEspetaculo(nome, capacidadeMaxima, lotacao, endereco, id, aderente), nomeEvento(nomeEvento), data(data),
        horario(horario) {};

const string &Evento::getNomeEvento() const {
    return nomeEvento;
}

void Evento::setNomeEvento(const string &nomeEvento) {
    this->nomeEvento = nomeEvento;
}

const Date &Evento::getData() const {
    return data;
}

void Evento::setData(const Date &data) {
    this->data = data;
}

const time_t &Evento::getHorario() const {
    return horario;
}

void Evento::setHorario(const time_t &horario) {
    this->horario = horario;
}



