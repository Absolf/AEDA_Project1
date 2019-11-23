//
// Created by laureano on 02/11/19.
//

#ifndef AEDA_PROJETO_DATE_H
#define AEDA_PROJETO_DATE_H

#include <time.h>
#include <iostream>
#include <regex>
#include <ctime>

using namespace std;


class Date {
    unsigned short day;
    unsigned short month;
    unsigned int year;

public:
    //Construtors of the class objects Date
    Date();

    Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
    Date(unsigned short day, unsigned short month, unsigned year);

    // GET methods
    unsigned int getYear() const;

    unsigned int getMonth() const;

    unsigned int getDay() const;

    string getDateString(); // returns the date in format "yyyy/mm/dd"
    bool valid() const;

    // SET methods
    void setYear(unsigned int year);

    void setMonth(unsigned int month);

    void setDay(unsigned int day);

    void setDate(unsigned int year, unsigned int month, unsigned int day); //Set all the Date atributes individually
    void setDateString(string yearMonthDay); //Set all the Date atributes through a string
    bool isBissexto(int year); //Determines if the input year is a leap year or not
    int daysMonth(int month, int year); //Retrives the number of days in the input month (takes into account leap years)
    bool verifyDate(
            string date); //Verifies if the given string date is valid or not (taking into account days in a month, leap years and current date)
    void actualDate();
    // outhet methods */

    static string returnDate(Date date); //Displays the date in a string
    friend ostream &operator<<(ostream &out, const Date &date); //output operator
    bool operator==(const Date &); // comparison operators
    bool operator!=(const Date &);

    bool operator<(const Date &);

    bool operator>(const Date &);

    bool operator<=(const Date &);

    bool operator>=(const Date &);

    Date operator=(const Date &);

    Date operator-(const Date &d2);
};

class DiaInvalido {
    int dia;
public:
    DiaInvalido(int dia) : dia(dia) {};

    int getDia() { return dia; };
};

class MesInvalido {
    int mes;
public:
    MesInvalido(int mes) : mes(mes) {};

    int getMes() { return mes; };
};


#endif //AEDA_PROJETO_DATE_H
