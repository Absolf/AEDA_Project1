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
    string endereco;
    int id;
public:
    Atracao();
    Atracao(string nome, int capacidadeMaxima, int lotacao, string endereco, int id);

    virtual void venderBilhete();
    //virtual void reservarBilhete();

    const string &getNome() const;

    void setNome(const string &nome);

    int getCapacidadeMaxima() const;

    void setCapacidadeMaxima(int capacidadeMaxima);

    const int getLotacao() const;

    void setLotacao(const int &lotacao);

    const string &getEndereco() const;

    void setEndereco(const string &endereco);

    int getId() const;

    void setId(int id);
};


#endif //AEDA_PROJETO_ATRACAO_H