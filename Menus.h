//
// Created by laureano on 05/11/19.
//

#ifndef AEDA_PROJETO_MENUS_H
#define AEDA_PROJETO_MENUS_H

#include <vector>
#include "sistemaCartaoAmigoMuseus.h"

using namespace std;

string NomeUsuario;
int numeroUsuario, index;

void mainMenu();

void loadEverything();

void subMenuSeeAll();

void PrintInstituicoes();

void PrintEventos();

void WriteAllClients();

void firstOpen();

void deleteFileToRewrite(string file);

int searchForNameById(int usuario, int &index, string &Nome);

void ChangePersonalInfo();

void novoCadastro();

void printClientes();

void VerInformacoesClienteSubmenu();

void fillClient();

void verificaValidade(int id);

//void cleanLog();
#endif //AEDA_PROJETO_MENUS_H
