//
// Created by Gabriel Rocco on 23/10/2019.
//

#include "sistemaCartaoAmigoMuseus.h"
//-----------------------

sistemaCartaoAmigoMuseumPortugal::sistemaCartaoAmigoMuseumPortugal() {};

void sistemaCartaoAmigoMuseumPortugal::venderBilhete(Cliente *cliente, Bilhete *b, Evento *evento) {
    float newPrice;
    cout << evento->getLotacao() << endl;
    if (cliente->temCartao() && evento->isAderente() == true) {
        newPrice = b->getValor() - (b->getValor() * 0.25);
        b->setValor(newPrice);
        if (evento->getLotacao() < evento->getCapacidadeMaxima()) {
            cliente->addBilhete(b);
            int lot = evento->getLotacao() + 1;
            evento->setLotacao(lot);
            cout << evento->getLotacao() << endl;
        } else
            cout << "Lotação máxima atingida" << endl;
    }

}

void sistemaCartaoAmigoMuseumPortugal::addSalaEspetaculo() {
    SalaEspetaculo newSala;
    string nome;
    cout << "Nome: ";
    getline(cin, nome);
    newSala.setNome(nome);
    newSala.setCapacidadeMaxima(readInteger("capacidade: "));
    newSala.setLotacao(0);
    string address;
    cout << "\n *No formato Rua / Nº Porta / Freguesia / Código-Postal / Distrito* \nEndereço: " << endl;
    getline(cin, address);
    Address endereco(address);
    newSala.setEndereco(endereco);
    newSala.setAderente(readInteger("0 pra falso e 1 para verdadeiro \n aderente: "));
    newSala.setId(readInteger("Id"));
    salas.push_back(newSala);
}

void sistemaCartaoAmigoMuseumPortugal::readSalaEspetaculo() const {
    if (salas.size() == NULL){
        cout << "Não há salas de espetáculo!\n";
    }
    else {
        for (auto it = salas.begin(); it != salas.end(); it++)
        {
            cout << (*it) << "\n";
        }
    }
}

void  sistemaCartaoAmigoMuseumPortugal::deleteSalaEspetaculo() {
    if (salas.size() == 0) {
        cout << "Não há salas de espetáculo!\n";
    }else
    {
        string name;
        cout << "Type the name to remove: ";
        getline(cin, name);
        for(auto it = salas.begin(); it == salas.end(); it++){
            if((*it).getNome() == name){
                cout << "Sala de espetáculo encontrada!" << endl;
                cout << salas.size();
                salas.erase(it);
            }
        }
        cout << "A sala ' " << name << "' foi removida com sucesso! \n";
    }
}

void sistemaCartaoAmigoMuseumPortugal::updateSalaEspetaculo(){
    if(salas.size() == 0){
        cout << "Não há salas de espetáculo para atualizar! " << endl;
    }else
    {
        string line, text;
        cout << "Type the name to update: ";
        getline(cin, text);
        vector<string> menu = {"Nome: ", "Capacidade: ", "Endereco: " , "Aderente: "};
        cout << endl;
        for(size_t i = 0; i < salas.size(); i++){
            if(salas[i].getNome() == text) {
                int op = readOptions(menu);
                if (op == 1){
                    cout << "Novo nome da sala: ";
                    getline(cin, line);
                    salas[i].setNome(line);
                }
                if( op == 2){
                    salas[i].setCapacidadeMaxima(readInteger("Nova Capacidade: "));
                }

                if (op == 3){
                    cout << "Novo Endereço: ";
                    getline(cin, line);
                    Address aux(line);
                    salas[i].setEndereco(aux);
                }
                if (op == 4){
                    salas[i].setAderente(readInteger("Aderente: "));
                }
                if (op == 5){
                    salas[i].setId(readInteger("Aderente: "));
                }
            }
        }
    }

    cout << "Sala de Espetaculo atualizada com sucesso! \n";
}



