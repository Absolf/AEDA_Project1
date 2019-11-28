#import "CartaoAmigo.h"


CartaoAmigo::CartaoAmigo() {}

const string &CartaoAmigo::getN_cartao() const {
    return n_cartao;
}

void CartaoAmigo::set_Ncartao(const string &n_cartao) {
    this->n_cartao = n_cartao;
}

float CartaoAmigo::getAnuidade() const {
    return 0.0;
}

string CartaoAmigo::getSubscription() const {
    return "";
}

const Date &CartaoAmigo::getDataAcquisition() const {
    return dataAcquisition;
}

void CartaoAmigo::setDataAcquisition(const Date &dataAcquisition) {
    this->dataAcquisition = dataAcquisition;
}

const Date &CartaoAmigo::getNascimento() const {
    return nascimento;
}

void CartaoAmigo::setNascimento(const Date &nascimento) {
    this->nascimento = nascimento;
}

const string &CartaoAmigo::getNome() const {
    return nome;
}

void CartaoAmigo::setNome(const string &nome) {
    this->nome = nome;
}

const Address &CartaoAmigo::getMorada() const {
    return morada;
}

void CartaoAmigo::setMorada(const Address &morada) {
    this->morada = morada;
}

const string &CartaoAmigo::getContacto() const {
    return contacto;
}

void CartaoAmigo::setContacto(const string &contacto) {
    this->contacto = contacto;
}


CartaoAmigo CartaoAmigo::operator=(CartaoAmigo &c1) {
    return CartaoAmigo(this->dataAcquisition = c1.getDataAcquisition(), this->nascimento = c1.getNascimento(),
                       this->nome = c1.getNome(), this->morada = c1.getMorada(), this->contacto = c1.getContacto(),
                       this->n_cartao = c1.getN_cartao());
}

//---------------------Cartao Amigo uni
CartaoAmigoUni::CartaoAmigoUni(Date dataAcquisition, Date nascimento, string nome, Address morada, string contacto,
                               string n_cartao, float anuidade, string subscription) :
        CartaoAmigo(dataAcquisition, nascimento, nome, morada, contacto, n_cartao), anuidade(anuidade),
        subscription(subscription) {};

float CartaoAmigoUni::getAnuidade() const {
    return 32.45;
}

string CartaoAmigoUni::getSubscription() const {
    return "CartaoAmigoUni";
}


CartaoAmigoUni CartaoAmigoUni::operator=(CartaoAmigoUni &c1) {
    return CartaoAmigoUni(this->dataAcquisition = c1.getDataAcquisition(), this->nascimento = c1.getNascimento(),
                          this->nome = c1.getNome(), this->morada = c1.getMorada(), this->contacto = c1.getContacto(),
                          this->n_cartao = c1.getN_cartao(), this->anuidade = c1.getAnuidade(),
                          this->subscription = c1.getSubscription());
}

//---------------------CartaoAmigo Silver
CartaoAmigoSilver::CartaoAmigoSilver(Date dataAcquisition, Date nascimento, string nome, Address morada,
                                     string contacto,
                                     string n_cartao, float anuidade, string subscription) :
        CartaoAmigo(dataAcquisition, nascimento, nome, morada, contacto, n_cartao), anuidade(anuidade),
        subscription(subscription) {};

float CartaoAmigoSilver::getAnuidade() const {
    return 30.0;
}

string CartaoAmigoSilver::getSubscription() const {
    return "CartaoAmigoSilver";
}

CartaoAmigoSilver CartaoAmigoSilver::operator=(CartaoAmigoSilver &c1) {
    return CartaoAmigoSilver(this->dataAcquisition = c1.getDataAcquisition(), this->nascimento = c1.getNascimento(),
                             this->nome = c1.getNome(), this->morada = c1.getMorada(),
                             this->contacto = c1.getContacto(),
                             this->n_cartao = c1.getN_cartao(), this->anuidade = c1.getAnuidade(),
                             this->subscription = c1.getSubscription());
}

//---------------------CartaoAmigoIndi
CartaoAmigoIndi::CartaoAmigoIndi(Date dataAcquisition, Date nascimento, string nome, Address morada, string contacto,
                                 string n_cartao, float anuidade, string subscription) :
        CartaoAmigo(dataAcquisition, nascimento, nome, morada, contacto, n_cartao), anuidade(anuidade),
        subscription(subscription) {};

float CartaoAmigoIndi::getAnuidade() const {
    return 54.9;
}

string CartaoAmigoIndi::getSubscription() const {
    return "CartaoAmigoIndi";
}

CartaoAmigoIndi CartaoAmigoIndi::operator=(CartaoAmigoIndi &c1) {
    return CartaoAmigoIndi(this->dataAcquisition = c1.getDataAcquisition(), this->nascimento = c1.getNascimento(),
                           this->nome = c1.getNome(), this->morada = c1.getMorada(), this->contacto = c1.getContacto(),
                           this->n_cartao = c1.getN_cartao(), this->anuidade = c1.getAnuidade(),
                           this->subscription = c1.getSubscription());
}









