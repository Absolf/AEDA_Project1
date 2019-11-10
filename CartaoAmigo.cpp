#import "CartaoAmigo.h"


CartaoAmigo::CartaoAmigo() {}

const string &CartaoAmigo::getNif() const {
    return nif;
}

void CartaoAmigo::setNif(const string &nif) {
    CartaoAmigo::nif = nif;
}

float CartaoAmigo::getValorAssinatura() const {
    return valorAssinatura;
}
void CartaoAmigo::setValorAssinatura(float &valorAssinatura) {
    this->nif = nif;
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

const Address & CartaoAmigo::getMorada() const {
    return morada;
}
void CartaoAmigo::setMorada(const Address &morada){
    this->morada = morada;
}

const string & CartaoAmigo::getContacto() const{
    return contacto;
}
void CartaoAmigo::setContacto(const string &contacto) {
    this->contacto = contacto;
}

void CartaoAmigo::emitirCartao(){
    CartaoAmigo novo;
    string line;
    cout << "Nome:" << endl;
    getline(cin, line);
    novo.setNome(line);
    cout << "Data Aqcquisition:" << endl;
    getline(cin, line);
    Date teste(line);
    novo.setDataAcquisition((teste));

    cout << "Data Nascimento:" << endl;
    getline(cin, line);
    Date nascimento(line);
    nascimento.setDateString(line);
    novo.setNascimento(nascimento);

    cout << novo.getNome() << endl;
    cout << novo.getDataAcquisition();
    cout << novo.getNascimento();
}

float darDescontoMuseu();
float darDescontoEvento();




