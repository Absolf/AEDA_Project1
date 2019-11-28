//
// Created by laureano on 08/11/19.
//

#ifndef AEDA_PROJETO_TIME_H
#define AEDA_PROJETO_TIME_H

#include <sstream>
#include <string>
#include <vector>
#include "utilitarios.h"

using namespace std;

class Time {
    int hora;
    int minutos;
    int segundos;

public:
    Time();

    Time(int hora, int minutos, int segundos);

    int getHora() const;

    void setHora(int hora);

    int getMinutos() const;

    void setMinutos(int minutos);

    int getSegundos() const;

    void setSegundos(int segundos);


    //-------------------------------
    bool valid();

    void setTime(int hora, int minutos, int segundos);

    void setTimeString(string linha);//set Time throw a string
    string getTimeString(); //???
    //bool verifyTime(string time); verifica a func de cima.

    //other methods
    //static string returnTime(Time time); //Displays the date in a string
    friend ostream &operator<<(ostream &out, const Time &time); //output operator
    bool operator==(Time &t); // comparison operators
    bool operator!=(const Time &t);

    bool operator>(const Time &t);

    bool operator<(const Time &t);

    string returnTime(Time &time);

    //------------------------------//
    Time operator-(Time &t);

    Time operator+(const Time &t1);


};

#endif //AEDA_PROJETO_TIME_H
