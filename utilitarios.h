//
// Created by laureano on 15/11/19.
//

#ifndef AEDA_PROJETO_UTILITARIOS_H
#define AEDA_PROJETO_UTILITARIOS_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>
#include <iomanip>
#include <map>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iostream>
#include "Date.h"

using namespace std;

void tokenize(string const &str, char delim, vector<string> &out);

int readOptions(const vector<string> &menu);

template<typename T>
istream &getInput(string prompt, T &input);

template<typename T>
istream &getInput(T &input);

int readInteger(string prompt);

int &readInteger();

double readDouble(string prompt);

string readString(string input);


#endif //AEDA_PROJETO_UTILITARIOS_H
