#pragma once
#include <iostream>
#include <string>
using namespace std;

class CObjeto {
protected:
	string nombre;
	string tipo;
	
public:
	CObjeto(string nom, string tipo): nombre(nom), tipo(tipo){}
	~CObjeto(){}
	string getNombre() { return this->nombre; }
	string getTipo() { return this->tipo; }
	void setNombre(string nom) { this->nombre = nom; }
	void setTipo(string tip) { this->tipo = tip; }
	
};