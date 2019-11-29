//
// Created by laureano on 08/11/19.
//
#include "Time.h"

Time::Time() {
    this->hora = 0;
    this->minutos = 0;
    this->segundos = 0;
}

Time::Time(int hora, int minutos, int segundos) : hora(hora), minutos(minutos), segundos(segundos) {
}


int Time::getHora() const { return hora; }

void Time::setHora(int hora) { this->hora = hora; }

int Time::getMinutos() const { return minutos; }

void Time::setMinutos(int minutos) { this->minutos = minutos; }

int Time::getSegundos() const { return segundos; }


void Time::setSegundos(int segundos) { this->segundos = segundos; }


bool Time::valid() {
    if (hora >= 0 && hora <= 23)
        if (minutos >= 0 && minutos <= 59)
            if (segundos >= 0 && segundos <= 59)
                return true;
    return false;
}

void Time::setTime(int hora, int minutos, int segundos) {
    setHora(hora);
    setMinutos(minutos);
    setSegundos(segundos);
}

void Time::setTimeString(string linha) {
    //a stringg tem de vir no formato x:x:xx ou xx:x:xx ou xx:xx:xx ou x:xx:xx
    string temp;
    vector<string> tempz;
    tokenize(linha, ':', tempz);
    //verificar e blabla
    //cout << tempz[0] << ":" << tempz[1] << ":" << tempz[2];
    int hour = stoi(tempz[0]);
    int minuto = stoi(tempz[1]);
    int segundo = stoi(tempz[2]);
    if ((linha[2] != ':' || linha[1] != ':') && (linha[5] != ':' || linha[4] != ':' || linha[3] != ':')) {
        //se os ":" estao em  1:1:xx ou 12:1:xx ou 12:12:xx
        if (hour <= 23 && hour >= 0) {
            if (minuto <= 59 && minuto >= 0) {
                if (segundo <= 59 && segundo >= 0) {
                    setTime(hour, minuto, segundo);
                }
            }
        }
    }
}

string Time::getTimeString() {//É PRECISO VALIDAR????? ---------- bool verifyTime(string time)??
    string hour = to_string(getHora());
    string minuto = to_string(getMinutos());
    string segundo = to_string(getSegundos());
    string oneline = hour + ":" + minuto + ":" + segundo;
    Time time;
    time.setTimeString(oneline);
    return returnTime(time);
}

string Time::returnTime(Time &time) {
    stringstream ss;
    string time_output;
    ss << time;
    time_output = ss.str();
    return time_output;
}

void Time::actualTime() {
    int thisHour = 0, thisMinutes= 0, thisSeconds = 0;
    time_t theTime = time(0);
    tm *aTime = localtime(&theTime);
    thisHour = aTime->tm_hour;
    thisMinutes = aTime->tm_min;
    thisSeconds = aTime->tm_sec;
    this->hora = thisHour;
    this->minutos = thisMinutes;
    this->segundos = thisSeconds;
}

ostream &operator<<(ostream &out, const Time &time) {
    if (time.hora >= 10 && (time.minutos< 10 && time.minutos >0)){
        out << time.hora << ":0" << time.minutos;
    }
    if ((time.hora < 10 && time.hora >0) && (time.minutos < 10 && time.minutos >0)) {
        out << "0" << time.hora << ":0" << time.minutos;
    }
    if ((time.hora < 10 && time.hora >0) && time.getMinutos() >= 10){
        out << "0" << time.hora << ":" << time.minutos << ":59";
    }else
        out << time.hora << ":" << time.minutos<< ":59";
    return out;
}

bool Time::operator==(Time &t) {
    if (!t.valid()) { return false; }
    if ((this->hora == t.getHora()) && (this->minutos == t.getMinutos()) && (this->segundos == t.getSegundos())) {
        return true;
    };
    return false;
}


bool Time::operator!=(const Time &t) {
    return (this->hora == t.getHora() || this->minutos == t.getMinutos() || this->segundos == t.getSegundos());
}

bool Time::operator>(const Time &t) {
    // this is strict inequality
    if (this->hora == t.getHora() && this->minutos == t.getMinutos() &&
        this->segundos == t.getSegundos()) { return false; }

    if (this->hora > t.getHora()) {
        return true;
    }
    if (this->hora == t.getHora()) {
        if (this->minutos > t.getMinutos()) {
            return true;
        } else if (this->minutos == t.getMinutos()) {
            if (this->segundos > t.getSegundos())
                return true;
        }
    }
    return false;
}

bool Time::operator<(const Time &t) {
    // this is strict inequality
    if (this->hora == t.getHora() && this->minutos == t.getMinutos() &&
        this->segundos == t.getSegundos()) { return false; }

    if (this->hora < t.getHora()) {
        return true;
    }
    if (this->hora == t.getHora()) {
        if (this->minutos < t.getMinutos()) {
            return true;
        } else if (this->minutos == t.getMinutos()) {
            if (this->segundos < t.getSegundos())
                return true;
        }
    }
    return false;
}

Time Time::operator-(Time &t) {//----------------------------------------
    Time t1;
    int aux1, aux2;
    aux1 = t.minutos + 59 * t.hora;
    aux2 = minutos + 59 * hora;
    t1.minutos = (aux2 - aux1)%59;
    t1.hora =(aux2 - aux1) / 59;
    return t1;
}
/*
Time Time::operator+(Time &t) {

    Time t1;
    int aux1, aux2;

    aux1 = segundos +t.segundos;
    t1.segundos = aux1%60;
    aux2 = (aux1/60)+minutos+t.minutos;
    t1.minutos = aux2%60;
    t1.hora =(aux2/60)+hora+t.hora;
    t1.hora = t1.hora%24;
}*/

bool Time::operator<=(const Time &t){
    return (this->hora<=t.getHora() && this->minutos <=t.getMinutos());
}

bool Time::operator>=(const Time &t){
    return (this->hora>=t.getHora() && this->minutos >=t.getMinutos());
}