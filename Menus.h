//
// Created by laureano on 05/11/19.
//

#ifndef AEDA_PROJETO_MENUS_H
#define AEDA_PROJETO_MENUS_H

#include <vector>
#include "sistemaCartao.h"

using namespace std;


void mainMenu();

void loadBilhetes();

void deleteFileToRewrite(string file);

int auxMenu(int idx);

void messageSilver(int idx);

void firstMenu(int &idx);

void leaving();

int AdminMode();

//void cleanLog();
#endif //AEDA_PROJETO_MENUS_H
