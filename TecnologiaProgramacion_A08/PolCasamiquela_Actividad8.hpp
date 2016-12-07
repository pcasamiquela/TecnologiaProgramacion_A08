#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

class Fecha {
public:
	int day, month, year;
	Fecha(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {};

	friend bool Fecha::operator==(const Fecha &fecha1, const Fecha &fecha2) {
		return (fecha1.day == fecha2.day && fecha2.month==fecha2.month && fecha1.year == fecha2.year);
	}
	friend bool Fecha::operator<(const Fecha &fecha1, const Fecha &fecha2) {
		return (fecha1.year < fecha2.year ||
				fecha1.month < fecha2.month && fecha1.year <= fecha2.year ||
				fecha1.day < fecha2.day && fecha1.month <= fecha2.month && fecha1.year <= fecha2.year);
	}
	friend bool Fecha::operator>(const Fecha &fecha1, const Fecha &fecha2) {
		return (fecha1.year > fecha2.year ||
			fecha1.month > fecha2.month && fecha1.year >= fecha2.year ||
			fecha1.day > fecha2.day && fecha1.month >= fecha2.month && fecha1.year >= fecha2.year);
	}
	friend bool Fecha::operator<=(const Fecha &fecha1, const Fecha &fecha2) {
		return (fecha1.year <= fecha2.year ||
			fecha1.month <= fecha2.month && fecha1.year <= fecha2.year ||
			fecha1.day <= fecha2.day && fecha1.month <= fecha2.month && fecha1.year <= fecha2.year);
	}
	friend bool Fecha::operator>=(const Fecha &fecha1, const Fecha &fecha2) {
		return (fecha1.year >= fecha2.year ||
			fecha1.month >= fecha2.month && fecha1.year >= fecha2.year ||
			fecha1.day >= fecha2.day && fecha1.month >= fecha2.month && fecha1.year >= fecha2.year);
	}
};

class Hora {
public:
	int hour, minutes;
	Hora(int _hour, int _minutes) : hour(_hour), minutes(_minutes) {};
	friend bool Hora::operator==(const Hora &hora1, const Hora &hora2) {
		return (hora1.hour == hora2.hour && hora1.minutes == hora2.minutes);
	}
	friend bool Hora::operator<(const Hora &hora1, const Hora &hora2) {
		return (hora1.hour < hora2.hour || hora1.hour <= hora2.hour && hora1.minutes<hora2.minutes);
	}

	friend bool Hora::operator>(const Hora &hora1, const Hora &hora2) {
		return (hora1.hour > hora2.hour || hora1.hour >= hora2.hour && hora1.minutes > hora2.minutes);
	}
	friend bool Hora::operator<=(const Hora &hora1, const Hora &hora2) {
		return (hora1.hour <= hora2.hour || hora1.hour <= hora2.hour && hora1.minutes<=hora2.minutes);
	}

	friend bool Hora::operator>=(const Hora &hora1, const Hora &hora2) {
		return (hora1.hour >= hora2.hour || hora1.hour >= hora2.hour && hora1.minutes >= hora2.minutes);
	}
};

class Agenda {
private:
	multimap<Fecha, pair<Hora, string>> agendaMap;
public:
	void insertarEvento(const Fecha &fecha, const Hora &hora, const string &descripcion); //done
	void eliminarEventos(const Fecha &desde_fecha, const Hora &desde_hora, const Fecha &hasta_fecha, const Hora &hasta_hora);//done
	void mostrarAgenda();//done
	list<pair<Hora, string>> eventosDia(const Fecha &fecha);//done
	list<pair<Hora, string>> eventosDia(const Fecha &fecha, const Hora &desde, const Hora &hasta);//done
};


void Agenda::insertarEvento(const Fecha &fecha, const Hora &hora, const string &descripcion) {
	agendaMap.insert(make_pair(fecha, make_pair(hora, descripcion)));
}

void Agenda::eliminarEventos(const Fecha &desde_fecha, const Hora &desde_hora, const Fecha &hasta_fecha, const Hora &hasta_hora) {
	
	auto it = agendaMap.begin();

	while(it != agendaMap.end()) {
		if (it->first > desde_fecha && it->first < hasta_fecha ||
			it->first == desde_fecha && it->second.first >= desde_hora ||
			it->first == hasta_fecha && it->second.first <= hasta_hora) {
			auto toErase = it;
			++it;
			agendaMap.erase(toErase);
		}
		else
			++it;
	}
}

void Agenda::mostrarAgenda() { 
	for (auto it = agendaMap.begin(); it != agendaMap.end(); ++it) {
		cout << it->first.day << "/" << it->first.month << "/" << it->first.year << ", at ";
		cout << it->second.first.hour << ":" << it->second.first.minutes << "-->" << it->second.second << endl;
	}
}

list<pair<Hora, string>> Agenda::eventosDia(const Fecha &fecha) {
	list<pair<Hora, string>> eventos;
	map<Hora, string> eventosMap;
	for (auto it = agendaMap.begin(); it != agendaMap.end(); ++it) {
		if (it->first == fecha)eventosMap.insert(make_pair(it->second.first, it->second.second));
	}
	for (auto it = eventosMap.begin(); it != eventosMap.end(); ++it) {
		eventos.push_back(make_pair(it->first, it->second));
	}
	return eventos;
}

list<pair<Hora, string>> Agenda::eventosDia(const Fecha &fecha, const Hora &desde, const Hora &hasta) {
	list<pair<Hora, string>> eventos;
	map<Hora, string> eventosMap;

	for (auto it = agendaMap.begin(); it != agendaMap.end(); ++it) {
		if (it->first == fecha && it->second.first >= desde && it->second.first <= hasta)eventosMap.insert(make_pair(it->second.first, it->second.second));
	}
	for (auto it = eventosMap.begin(); it != eventosMap.end(); ++it) {
		eventos.push_back(make_pair(it->first, it->second));
	}
	return eventos;
}

