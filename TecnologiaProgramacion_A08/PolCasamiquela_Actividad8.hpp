#include <iostream>
#include <map>
#include <list>
using namespace std;

class Fecha {

};

class Hora {

};

class Agenda {
private:
	map<Hora, string> time;
	map<Fecha, map<Hora, string>> agendaMap;
public:
	void insertarEvento(const Fecha &fecha, const Hora &hora, const string &descripcion);
	void eliminarEventos(const Fecha &desde_fecha, const Hora &desde_hora, const Fecha &hasta_fecha, const Hora &hasta_hora);
	list<pair<Hora, string>> eventosDia(const Fecha &fecha);
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
	eventos.push_back(agendaMap.begin());
}