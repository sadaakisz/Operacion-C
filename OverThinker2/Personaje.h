#pragma once
#include <string>
using namespace std;
class Personaje {
protected:
	bool vivo;
	string nombre;
	string escenario;
	int intel;
public:
	Personaje(char* nombre, char* escenario, int intel) : nombre((string)nombre), escenario((string)escenario), intel(intel), vivo(1) {}
	~Personaje() { vivo = 0, escenario = "null", intel = 0; }

	bool getVivo() { return vivo; }
	void setVivo(int n) { vivo = n; }

	string getNombre() { return nombre; }
	void setNombre(string n) { nombre = n; }

	string getEscenario() { return escenario; }
	void setEscenario(string n) { escenario = n; }

	int getIntel() { return intel; }
	void setIntel(int n) { intel = n; }
};