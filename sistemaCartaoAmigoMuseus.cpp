//
// Created by Gabriel Rocco on 23/10/2019.
//

#include "sistemaCartaoAmigoMuseus.h"
//-----------------------

sistemaCartaoAmigoMuseumPortugal::sistemaCartaoAmigoMuseumPortugal() {
};

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
    string handler;
    cout << "Nome: ";
    getline(cin, handler);
    newSala.setNome(handler);
    newSala.setCapacidadeMaxima(readInteger("capacidade: "));
    newSala.setLotacao(0);
    cin.clear();
    cout << "\n *No formato Rua / Nº Porta / Freguesia / Código-Postal / Distrito* \nEndereço: " << endl;
    getline(cin, handler);
    Address endereco(handler);
    newSala.setEndereco(endereco);
    newSala.setAderente(readInteger("0 pra falso e 1 para verdadeiro \n aderente: "));
    newSala.setId(readInteger("Id"));
    salas.push_back(newSala);
}

void sistemaCartaoAmigoMuseumPortugal::readSalaEspetaculo() {
    if (salas.size() == NULL) {
        cout << "Não há salas de espetáculo!\n";
    } else {
        for (auto it = this->salas.begin(); it != this->salas.end(); it++) {
            cout << (*it) << "\n";
        }
    }
}

void sistemaCartaoAmigoMuseumPortugal::deleteSalaEspetaculo() {
    if (salas.size() == 0) {
        cout << "Não há salas de espetáculo!\n";
    } else {
        string name;
        cout << "Type the name to remove: ";
        getline(cin, name);
        for (auto it = salas.begin(); it == salas.end(); it++) {
            if ((*it).getNome() == name) {
                cout << "Sala de espetáculo encontrada!" << endl;
                cout << salas.size();
                salas.erase(it);
            }
        }
        cout << "A sala ' " << name << "' foi removida com sucesso! \n";
    }
}

void sistemaCartaoAmigoMuseumPortugal::updateSalaEspetaculo() {
    if (salas.size() == 0) {
        cout << "Não há salas de espetáculo para atualizar! " << endl;
    } else {
        string line, text;
        cout << "Type the name to update: ";
        getline(cin, text);
        vector<string> menu = {"Nome: ", "Capacidade: ", "Endereco: ", "Aderente: "};
        cout << endl;
        for (size_t i = 0; i < salas.size(); i++) {
            if (salas[i].getNome() == text) {
                int op = readOptions(menu);
                if (op == 1) {
                    cout << "Novo nome da sala: ";
                    getline(cin, line);
                    salas[i].setNome(line);
                }
                if (op == 2) {
                    salas[i].setCapacidadeMaxima(readInteger("Nova Capacidade: "));
                }

                if (op == 3) {
                    cout << "Novo Endereço: ";
                    getline(cin, line);
                    Address aux(line);
                    salas[i].setEndereco(aux);
                }
                if (op == 4) {
                    salas[i].setAderente(readInteger("Aderente: "));
                }
                if (op == 5) {
                    salas[i].setId(readInteger("Aderente: "));
                }
            }
        }
    }

    cout << "Sala de Espetaculo atualizada com sucesso! \n";
}

void sistemaCartaoAmigoMuseumPortugal::addCliente() {
    cin.ignore();
    Cliente newClient;
    Date thisYear;
    thisYear.actualDate();
    srand(time(NULL));
    string handler = to_string(thisYear.getYear()) + "00" + to_string(rand() % 9999);
    newClient.setN_cartao(handler);
    cin.clear();
    cout << endl << "--- Criando novo cliente ---\npor favor digite seu nome completo: ";
    getline(cin, handler);
    newClient.setNome(handler);

    handler = readString("\n dia/mes/ano\nData de Nascimento: ");
    Date nascimento;
    cin.clear();
    bool isDate = nascimento.verifyDate(handler); // verify if the input is actualy a date
    while (isDate == false) {
        cin.clear();
        handler = readString("Data de Nascimento: ");
        isDate = nascimento.verifyDate(handler);
    }
    nascimento.setDateString(handler);
    newClient.setNascimento(nascimento);
    newClient.setContacto(readString("Contacto: "));
    cout << "\n *No formato Rua / Nº Porta / Freguesia / Código-Postal / Distrito* \nEndereço: " << endl;
    getline(cin, handler);
    Address end(handler);
    newClient.setMorada(end);

    handler = readString("É membro de uma universidadae (aluno/professor)? ");
    if (handler == "sim")
        newClient.setUniversitario(true);
    cin.clear();
    newClient.aderirCartao();
    newClient.printCliente();
    clientes.push_back(newClient);
    cout << "cliente novo adicionado!";
    cout << endl << "*************************************************************************" << endl;
    cout << "Parabéns " << newClient.getNome() << ", você acaba de completar seu cadastro com sucesso! " << endl;
    cout << "AVISO: O número de seu cartão é " << newClient.getN_cartao() << endl;
    cout << "Por favor compareca à qualquer Museu da Rede Portuguesa " << endl
         << "para a emissão do seu cartão, não se esqueca de " << endl;
    cout << "levar um documento com foto e Cartão de estudante caso necessário.";
    cout << endl << endl;
    cout << endl << "*************************************************************************" << endl << endl << endl;
}

void sistemaCartaoAmigoMuseumPortugal::readCliente(string card) {}

void sistemaCartaoAmigoMuseumPortugal::deleteCliente(string card) {}

void sistemaCartaoAmigoMuseumPortugal::updateCliente(string card) {
    if (clientes.size() == 0) {
        cout << "Não há clientes" << endl;
    } else {
        string line;
        vector<string> menu = {"Endereco: ", "Contacto: ", "Vínculo universitário: "};
        for (size_t i = 0; i < clientes.size(); i++) {
            if (clientes[i].getN_cartao() == card) {
                Date oldDate(clientes[i].getCartao().getDataAcquisition());
                int op = readOptions(menu);
                if (op == 1) {

                    cout << "Novo Endereço: ";
                    getline(cin, line);
                    Address aux(line);
                    clientes[i].setMorada(aux);
                    clientes[i].aderirCartao();
                    CartaoAmigo *novo = const_cast<CartaoAmigo *>(&(clientes[i].getCartao()));
                    novo->setDataAcquisition(oldDate);
                    clientes[i].setCartao(novo);
                }
                if (op == 2) {
                    cout << "Novo contacto: ";
                    getline(cin, line);
                    clientes[i].setContacto(line);
                    clientes[i].aderirCartao();
                }
                if (op == 3) {
                    if (clientes[i].getUniversitario() == true) {
                        cout
                                << "Deseja alterar seu status de membro académico? \nAtualmente você tem um vínculo com uma universidade\n";
                        cout << "Valor atual da anuidade: " << clientes[i].getCartao().getAnuidade() << endl;
                        line = readString("S = sim /N = não");
                        if (line == "S") {
                            clientes[i].setUniversitario(false);
                            clientes[i].aderirCartao();
                            CartaoAmigo *novo = const_cast<CartaoAmigo *>(&(clientes[i].getCartao()));
                            novo->setDataAcquisition(oldDate);
                            clientes[i].setCartao(novo);
                            cout << "Nova anuidade: " << clientes[i].getCartao().getAnuidade();
                        }
                    } else {
                        cout
                                << "Deseja alterar seu status de membro académico? \nAtualmente você tem nao possui um vínculo com uma universidade\n";
                        cout << "Valor atual da anuidade: " << clientes[i].getCartao().getAnuidade() << endl;
                        line = readString("S = sim /N = não");
                        if (line == "S") {
                            clientes[i].setUniversitario(false);
                            clientes[i].aderirCartao();
                            CartaoAmigo *novo = const_cast<CartaoAmigo *>(&(clientes[i].getCartao()));
                            novo->setDataAcquisition(oldDate);
                            clientes[i].setCartao(novo);
                            cout << "Nova anuidade: " << clientes[i].getCartao().getAnuidade();
                        }
                    }
                }
            }
        }
    }
}

void sistemaCartaoAmigoMuseumPortugal::WriteAllClients() {
    //Apaga o arquivo do cliente
    deleteFileToRewrite("../clientes.txt");
    ofstream outClients("../clientes.txt");

    if (outClients.is_open()) {
        for (size_t i = 0; i < clientes.size(); i++) {
            if(i==3 && clientes[i].getN_cartao() != clientes[i-1].getN_cartao())
                outClients << clientes[i].getCartao().getDataAcquisition();
            else
                outClients << clientes[i];
        }
        outClients.close();
    }
}
int sistemaCartaoAmigoMuseumPortugal::searchUser(string card) {
    for(size_t i = 0; i < getClientes().size(); i++){
        if (card == getClientes().at(i).getN_cartao()){
            return i;
        }
    }
    return -1;
}

int sistemaCartaoAmigoMuseumPortugal::searchSalaEspetaculo(string nome) {
    for(size_t i = 0; i < getSalas().size(); i++){
        if (nome == getSalas().at(i).getNome()){
            return i;
        }
    }
    return -1;
}

int sistemaCartaoAmigoMuseumPortugal::searchEvento(string nome) {
    for(size_t i = 0; i < getEventos().size(); i++){
        if (nome == getEventos().at(i).getNome()){
            return i;
        }
    }
    return -1;
}

//Tela inicial quando o programa é aberto, aparece apenas uma vez.
void sistemaCartaoAmigoMuseumPortugal::loadClients() {
    vector<string> lines;
    string newline;
    ifstream myfile("../clientes.txt");
    if (myfile.is_open()) {
        for (string line; getline(myfile, line);) {
            lines.push_back(line);
        }
        for (int i = 0; i < lines.size(); i++) {
            Cliente user;

            user.setN_cartao(lines[i]);
            i++;
            user.setNome(lines[i]);
            i++;
            Date tempNascimento;
            tempNascimento.setDateString(lines[i]);
            user.setNascimento(tempNascimento);
            i++;
            Date oldDate;
            oldDate.setDateString(lines[i]);
            i++;
            user.setContacto(lines[i]);
            i++;
            user.setMorada(lines[i]);
            i++;
            if (lines[i] == "1") {
                user.setUniversitario(true);
            } else {
                user.setUniversitario(false);
            }
            user.aderirCartao();
            CartaoAmigo *novo = const_cast<CartaoAmigo *>(&(user.getCartao()));
            novo->setDataAcquisition(oldDate);
            user.setCartao(novo);
            setClientes(user);

        }
        myfile.close();
        cout << endl << "DADOS CLIENTES CARREGADOS COM SUCESSO" << endl << endl;
    } else {
        cout << endl << "PROBLEMA NO CARREGAMENTO DE BASE DE DADOS DE CLIENTES" << endl << endl;
    }
};


void sistemaCartaoAmigoMuseumPortugal::loadSalaEspetaculos() {
    vector<string> temp_espec;
    string lines;
    ifstream myfile;
    myfile.open("../salaEspetaculos.txt");
    if(myfile.is_open()) {

        while (getline(myfile, lines, '\n')) // Cycles trough the file
        {
            if (lines == "::::::::::") {
                SalaEspetaculo newSala;
                newSala.setNome(temp_espec[0]);
                istringstream cap(temp_espec[1]);
                int capAux;
                cap >> capAux;
                newSala.setCapacidadeMaxima(capAux);
                istringstream lot(temp_espec[2]);
                int lotAux;
                lot >> lotAux;
                newSala.setLotacao(lotAux);
                Address novoEnd(temp_espec[3]);
                newSala.setEndereco(novoEnd);
                istringstream id(temp_espec[4]);
                int idAux;
                id >> idAux;
                newSala.setId(idAux);
                if (temp_espec[5] == "1") {
                    newSala.setAderente(true);
                } else {
                    newSala.setAderente(false);
                }
                this->salas.push_back(newSala);
                temp_espec.clear();
            } else {
                temp_espec.push_back(lines);
            }

        }
        SalaEspetaculo lastSala;
        lastSala.setNome(temp_espec[0]);
        istringstream cap(temp_espec[1]);
        int capAux;
        cap >> capAux;
        lastSala.setCapacidadeMaxima(capAux);
        istringstream lot(temp_espec[2]);
        int lotAux;
        lot >> lotAux;
        lastSala.setLotacao(lotAux);
        Address novoEnd(temp_espec[3]);
        lastSala.setEndereco(novoEnd);
        istringstream id(temp_espec[4]);
        int idAux;
        id >> idAux;
        lastSala.setId(idAux);
        if (temp_espec[5] == "1") {
            lastSala.setAderente(true);
        } else {
            lastSala.setAderente(false);
        }
        this->salas.push_back(lastSala);

        myfile.close();
        cout << endl << "DADOS DE SALAS DE ESPETACULO CARREGADOS COM SUCESSO" << endl << endl;
    }else {
        cout << endl << "PROBLEMA NO CARREGAMENTO DE BASE DE DADOS DAS SALAS DE ESPETACULO" << endl << endl;
    }
}

void sistemaCartaoAmigoMuseumPortugal::loadEventos(){
    vector<string> lines;
    string newline;
    ifstream myfile("../eventos.txt");
    int sala;
    if (myfile.is_open()) {
        for (string line; getline(myfile, line);) {
            lines.push_back(line);
        }
        for (int i = 0; i < lines.size(); i++) {
            sala = searchSalaEspetaculo(lines[i]);
            if(sala !=-1){
                i++;
                string eventName = lines[i];
                i++;
                Date eventDate;
                eventDate.setDateString(lines[i]);
                Evento newEvent(getSalas()[sala].getNome(), getSalas()[sala].getCapacidadeMaxima(), getSalas()[sala].getLotacao(), getSalas()[sala].getEndereco(), getSalas()[sala].getId(), getSalas()[sala].isAderente(), eventName, eventDate);
                eventos.push_back(newEvent);
            }
        }

        myfile.close();
        cout << endl << "DADOS DE EVENTOS CARREGADOS COM SUCESSO" << endl << endl;
    } else {
        cout << endl << "PROBLEMA NO CARREGAMENTO DE BASE DE DADOS DOS EVENTOS" << endl << endl;
    }
}

const vector<Cliente> &sistemaCartaoAmigoMuseumPortugal::getClientes() const {
    return clientes;
}

void sistemaCartaoAmigoMuseumPortugal::setClientes(const Cliente &cliente) {
   this->clientes.push_back(cliente);
}

const vector<Evento> &sistemaCartaoAmigoMuseumPortugal::getEventos() const {
    return eventos;
}

void sistemaCartaoAmigoMuseumPortugal::setEventos(const Evento &evento) {
    this->eventos.push_back(evento);
}

const vector<SalaEspetaculo> &sistemaCartaoAmigoMuseumPortugal::getSalas() const {
    return salas;
}

void sistemaCartaoAmigoMuseumPortugal::setSalas(SalaEspetaculo sala) {
    this->salas.push_back(sala);
}

const vector<Museum> &sistemaCartaoAmigoMuseumPortugal::getMuseu() const {
    return museus;
}

void sistemaCartaoAmigoMuseumPortugal::setMuseu(const Museum &museu) {
    this->museus.push_back(museu);
}

sistemaCartaoAmigoMuseumPortugal::sistemaCartaoAmigoMuseumPortugal(const vector<SalaEspetaculo> &salas){
}

