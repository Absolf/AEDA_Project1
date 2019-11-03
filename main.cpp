#include <iostream>
#include "Date.h"
#include "CartaoAmigo.h"

int main() {

    CartaoAmigo *p1 = new CartaoAmigoSilver();
    p1->setContacto("32566466");
    //cout << p1->getContacto() << endl;
    Date dateAq(21,11,2019);
    p1->setDataAcquisition(dateAq);
    Date dateNc(21,11,1995);
    p1->setNascimento(dateNc);
    float i = 20.0;
    p1->setValorAssinatura(i);
    p1->setNome("Pedro");
    /*
    cout << p1->getValidade() << endl << p1->getDataAcquisition()
    << endl << p1->getNascimento() << endl << p1->getValorAssinatura() << endl << p1->getNome() << endl;*/
    p1->emitirCartao();

     std::cout << "Hello, World!" << std::endl;
    return 0;
}