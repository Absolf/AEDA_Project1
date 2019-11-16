//
// Created by laureano on 05/11/19.
//

#ifndef AEDA_PROJETO_MENUS_H
#define AEDA_PROJETO_MENUS_H

#include <vector>
#include "sistemaCartaoAmigoMuseus.h"

using namespace std;


void mainMenu();

void loadClients();

void deleteFileToRewrite(string file);

int searchUser(string card);
int auxMenu(int idx);

//void cleanLog();
#endif //AEDA_PROJETO_MENUS_H
