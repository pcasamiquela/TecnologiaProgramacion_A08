#include "PolCasamiquela_Actividad8.hpp"

int main() {
	Agenda agenda;

	agenda.insertarEvento(Fecha (5, 12, 2016), Hora (15, 00), "Examen");
	agenda.insertarEvento(Fecha (5, 12, 2016), Hora (17, 00), "Practica");
	agenda.insertarEvento(Fecha (5, 12, 2016), Hora (22, 00), "Estudiar");

	agenda.mostrarAgenda();

	cout << "...............................\n";

	//agenda.eliminarEventos(Fecha(4, 12, 2016), Hora(15, 00), Fecha (7, 12, 2016), Hora (22, 0));
	agenda.mostrarAgenda();
	agenda.eventosDia(Fecha(5, 12, 2016), Hora(18,00), Hora(21,00));
	system("PAUSE");
	return 0;
}