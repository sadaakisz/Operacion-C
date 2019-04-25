#pragma once
#include <iostream>
#include <string>
using namespace std;

enum tipo {
	Arma, Miscelaneo, Consumible, Clave
};

class CObjeto {
protected:
	string nombre;
	string tipo;
	
public:
	CObjeto(string nom, string tipo): nombre(nom), tipo(tipo){}
	~CObjeto(){}
	string getNombre() { return this->nombre; }
	string getTipo() { return this->tipo; }
	void mostrar() {
		cout << "Nombre: " << getNombre() << endl;
		cout << "Tipo: " << getTipo() << endl;
	}
};