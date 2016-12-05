#include <iostream>
#include <map>
#include <list>
using namespace std;

class Fecha {
	int day, month, year;

	friend bool Fecha::operator==(Fecha &fecha1, Fecha &fecha2) {
		return (fecha1.day == fecha2.day && fecha2.month==fecha2.month && fecha1.year == fecha2.year);
	}
	friend bool Fecha::operator<(Fecha &fecha1, Fecha &fecha2) {
		return (fecha1.year < fecha2.year ||
				fecha1.month < fecha2.month && fecha1.year < fecha2.year ||
				fecha1.day < fecha2.day && fecha1.month < fecha2.month && fecha1.year<fcha2.year);
	}
};

class Hora {
	int hour, minutes;

	friend bool Hora::operator==(Hora &hora1, Hora &hora2) {
		return (hora1.hour == hora2.hour && hora1.minutes == hora2.minutes);
	}
	friend bool Hora::operator<(Hora &hora1, Hora &hora2) {
		return (hora1.hour < hora2.hour || hora1.hour < hora2.hour && hora1.minutes<hora2.minutes);
	}
};

class Agenda {
private:
	map<Hora, string> time;
	map<Fecha, map<Hora, string>> agendaMap;
public:
	void insertarEvento(const Fecha &fecha, const Hora &hora, const string &descripcion); //done
	void eliminarEventos(const Fecha &desde_fecha, const Hora &desde_hora, const Fecha &hasta_fecha, const Hora &hasta_hora);
	list<pair<Hora, string>> eventosDia(const Fecha &fecha);
	list<pair<Hora, string>> eventosDia(const Fecha &fecha, const Hora &desde, const Hora &hasta);

};


void Agenda::insertarEvento(const Fecha &fecha, const Hora &hora, const string &descripcion) {
	time.insert(pair<Hora, string>(hora, descripcion));
	agendaMap.insert(pair<Fecha, map<Hora, string>> (fecha, time));
}

void Agenda::eliminarEventos(const Fecha &desde_fecha, const Hora &desde_hora, const Fecha &hasta_fecha, const Hora &hasta_hora) {
	
	auto start = agendaMap.find(desde_fecha);
	auto end = agendaMap.find(hasta_fecha);

	agendaMap.erase(start, end);
	for (auto it = agendaMap.begin(); it != agendaMap.end(); ++it) {
		agendaMap.erase(it);
	}

}

list<pair<Hora, string>> Agenda::eventosDia(const Fecha &fecha) {
	list<pair<Hora, string>> eventos;
	agendaMap.find(fecha);
	return eventos;
}

list<pair<Hora, string>> Agenda::eventosDia(const Fecha &fecha, const Hora &desde, const Hora &hasta) {
	list<pair<Hora, string>> eventos;
	agendaMap.find(fecha);
	return eventos;
}