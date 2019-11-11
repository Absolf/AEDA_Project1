//
// Created by laureano on 08/11/19.
//

#include "Time.h"

int Time::getHora() const { return hora; }

void Time::setHora(int hora) { this->hora = hora; }

int Time::getMinutos() const { return minutos; }

void Time::setMinutos(int minutos) { this->minutos = minutos; }

int Time::getSegundos() const { return segundos; }


void Time::setSegundos(int segundos) { this->segundos = segundos; }


bool Time::valid() const {//AJUDA A IMPLEMENTAR NO RESTO
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
	istringstream ss(linha);
	string temp;
	vector <string> tempz;


	for (int i = 0; i <= 2; i++) {
		getline((ss), temp, ':');

		tempz.push_back(temp);
	}
	//verificar e blabla
	//cout << tempz[0] << ":" << tempz[1] << ":" << tempz[2];
	int hour = stoi(tempz[0]);
	int minuto = stoi(tempz[1]);
	int segundo = stoi(tempz[2]);
	if ((linha[2] != ":" || linha[1] != ":") && (linha[5] != ":" || linha[4] != ":" || linha[3] != ":")) {
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
	string zero = "0";
	if (hour.size() == 1) {
		hour = zero + hour;
	}
	if (minuto.size() == 1) {
		minuto = zero + minuto;
	}
	if (segundo.size() == 1) {
		segundo = zero + segundo;
	}
	string oneline = hora + ":" + minuto + ":" + segundo;

	return oneline;
}

ostream &operator<<(ostream &out, Time &time) {
	out << Time.hora << ":" << Time.minutos << ":" << Time.segundos;
	return out;
}

bool Time::operator == (const Date& t) {
	if (!t.valid()) { return false; };

	if ((this->hora == t.getHora()) && (this->minutos == t.getMinutos()) && (this->segundos == t.getSegundos())) {
		return true;
	};
	return false;
}


bool Time::operator !=(const Date&t) {
	return !(this->hora == t.getHora() || this->minutos == t.getMinutos() || this->segundos == t.getSegundos());
}

bool Time::operator>(const Time& t) {
	// this is strict inequality
	if (this->hora == t.getHora() && this->minutos == t.getMinutos() && this->segundos == t.getSegundos()) { return false; };

	if (this->hora > t.getHora()) {
		return true;
	}
	if (this->hora == t.getHora()) {
		if (this->minutos > t.getMinutos()) {
			return true;
		}
		else if (this->minutos == t.getMinutos()) {
			if (this->segundos > t.getSegundos())
				return true;
		}
	}
	return false;
}

bool Time::operator<(const Time& t) {
	// this is strict inequality
	if (this->hora == t.getHora() && this->minutos == t.getMinutos() && this->segundos == t.getSegundos()) { return false; };

	if (this->hora < t.getHora()) {
		return true;
	}
	if (this->hora == t.getHora()) {
		if (this->minutos < t.getMinutos()) {
			return true;
		}
		else if (this->minutos == t.getMinutos()) {
			if (this->segundos < t.getSegundos())
				return true;
		}
	}
	return false;
}

Time Time::operator-(const Time& t) {
	//Podia fazer com matematica mas isto veio-me a cabeça primeiro...
	// fazer com % divisao e com abs()
	//possivelmente 59*3 iteraçoes para isto -_-
	int hora = this->hora - t.getHora();
	int minuto = this->minutos - t.getMinutos();
	int segundo = this->segundos - t.getSegundos();
	int c = 0;
	if (hora < 0) {
		while (hora != 0) {
			hora++;
			c++;
		}
		hora = 24 - c;
		//dia = dia - 1 class Time ou a couna
	}
	c = 0;
	if (minuto < 0) {
		while (minuto != 0) {
			minuto++;
			c++
		}
		minuto = 60 - c;
		hora--;
	}
	c = 0;
	if (segundo < 0) {
		while (segundo != 0) {
			segundo++;
			c++
		}
		segundo = 60 - c;
		minuto--;
	}
	return Date(hora, minuto, segundo);
}


Time Time::operator+(const Time& t) {
	//Podia fazer com matematica mas isto veio-me a cabeça primeiro...
	// fazer com % divisao e com abs()
	//possivelmente 59*3 iteraçoes para isto -_-
	// voltar a fazer ... secalhar
	int hora = this->hora + t.getHora();
	int minuto = this->minutos + t.getMinutos();
	int segundo = this->segundos + t.getSegundos();
	int c = 0;
	if (hora > 23) {
		while (hora != 23) {
			hora--;
			c++;
		}
		hora = c;
		if (hora == 1)
			hora = 0;
		//dia = dia + 1 class Time ou a couna
	}
	c = 0;
	if (minuto > 59) {
		while (minuto != 59) {
			minuto--;
			c++
		}
		minuto = c;
		hora++;

	}
	c = 0;
	if (segundo > 59) {
		while (segundo != 59) {
			segundo--;
			c++
		}
		segundo = c;
		minuto++;
	}
	return Date(hora, minuto, segundo);
}

