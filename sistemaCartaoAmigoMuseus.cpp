//
// Created by Gabriel Rocco on 23/10/2019.
//

#include "sistemaCartaoAmigoMuseus.h"
//-----------------------

sistemaCartaoAmigoMuseumPortugal::sistemaCartaoAmigoMuseumPortugal() {};
void sistemaCartaoAmigoMuseumPortugal::venderBilhete(Cliente *cliente, Bilhete *b, Evento *evento){
    float newPrice;
    cout << evento->getLotacao() << endl;
    if(cliente->temCartao() && evento->isAderente() == true)
    {
        newPrice = b->getValor() - (b->getValor()*0.25);
        b->setValor(newPrice);
        if(evento->getLotacao() < evento->getCapacidadeMaxima())
        {
            cliente->addBilhete(b);
            int lot = evento->getLotacao() + 1;
            evento->setLotacao(lot);
            cout << evento->getLotacao() << endl;
        }
        else
            cout << "Lotação máxima atingida" << endl;
    }

}

