#pragma once
#include <string>
#include <iostream>
using namespace std;
class Personaje {
protected:
	bool vivo;
	string nombre;
	int intel;
public:
	Personaje(char* nombre, int intel) : nombre((string)nombre), intel(intel), vivo(1) {}
	~Personaje() { vivo = 0, intel = 0; }

	bool getVivo() { return vivo; }
	void setVivo(int n) { vivo = n; }

	string getNombre() { return nombre; }
	void setNombre(string n) { nombre = n; }

	int getIntel() { return intel; }
	void setIntel(int n) { intel = n; }
};