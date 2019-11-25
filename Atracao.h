//
// Created by laureano on 11/11/19.
//

#ifndef AEDA_PROJETO_ATRACAO_H
#define AEDA_PROJETO_ATRACAO_H

#include "Address.h"
#include <string>

class Atracao {
    string nome;
    int capacidadeMaxima;
    int lotacao;
    Address endereco;
    int id;
public:
    Atracao();

    Atracao(string nome, int capacidadeMaxima, int lotacao, Address endereco, int id);

    Atracao(const Atracao& at1);
    const string &getNome() const;

    void setNome(const string &nome);

    int getCapacidadeMaxima() const;

    void setCapacidadeMaxima(int capacidadeMaxima);

    const int getLotacao() const;

    void setLotacao(const int &lotacao);

    const Address &getEndereco() const;

    void setEndereco(const Address &endereco);

    int getId() const;

    void setId(int id);

    virtual Atracao &operator=(const Atracao &atracao);


    friend ostream &operator<<(ostream &out, const Atracao &atracao);
};


#endif //AEDA_PROJETO_ATRACAO_H
