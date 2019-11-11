//
// Created by laureano on 11/11/19.
//

#include "Bilhete.h"

float Bilhete::getValor() const {
    return valor;
}

void Bilhete::setValor(float valor) {
    Bilhete::valor = valor;
}

const Evento &Bilhete::getEvento() const {
    return *evento;
}

void Bilhete::setEvento(Evento *evento) {
    this->evento = evento;
}

void Bilhete::printBilhete()
{
    cout << " Apresentando função printBilhete() \n------------Bilhete------------- \n";
    cout << "Sala de Espetáculo: " << evento->getNome() << endl;
    cout << "Evento: " <<evento->getNomeEvento()  << endl;
    cout <<"Valor: $" << valor << endl;
    cout << "Data: "<< evento->getData() << endl;
    cout << "Horário: " << evento->getHorario();
    cout << "Lotacao: " << evento->getLotacao() << endl;

}
