#import "CartaoAmigo.h"


CartaoAmigo::CartaoAmigo() {}

const string &CartaoAmigo::getNif() const {
    return nif;
}

void CartaoAmigo::setNif(const string &nif) {
    this->nif = nif;
}

float CartaoAmigo::getAnuidade() const{
    return anuidade;
}

const Date& CartaoAmigo::getDataAcquisition() const {
    return dataAcquisition;
}
void CartaoAmigo::setDataAcquisition(const Date &dataAcquisition){
    this->dataAcquisition = dataAcquisition;
}

const Date& CartaoAmigo::getNascimento() const {
    return nascimento;
}
void CartaoAmigo::setNascimento(const Date &nascimento) {
    this->nascimento = nascimento;
}

const string & CartaoAmigo::getNome() const{
    return nome;
}
void CartaoAmigo::setNome(const string &nome){
    this-> nome=nome;
}

const string & CartaoAmigo::getMorada() const {
    return morada;
}
void CartaoAmigo::setMorada(const string &morada){
    this->morada = morada;
}

const string & CartaoAmigo::getContacto() const{
    return contacto;
}
void CartaoAmigo::setContacto(const string &contacto) {
    this->contacto = contacto;
}

CartaoAmigo CartaoAmigo::operator=(const CartaoAmigo &c1) {
    return CartaoAmigo(this->dataAcquisition = c1.getDataAcquisition(), this->nascimento = c1.getNascimento(), this->nome = c1.getNome(), this->morada = c1.getMorada(), this->contacto = c1.getContacto(), this->anuidade = c1.getAnuidade(), this->nif = c1.getNif());
}




//---------------------Cartao Amigo uni

float CartaoAmigoUni::getAnuidade() const{
    return 32.45;
}



//---------------------CartaoAmigo Silver

float CartaoAmigoSilver::getAnuidade() const{
    return 30.0;
}


//---------------------CartaoAmigoIndi

float CartaoAmigoIndi::getAnuidade() const {
    return 54.9;
}










