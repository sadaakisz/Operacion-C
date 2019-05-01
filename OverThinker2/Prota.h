#pragma once
#include "Personaje.h"

class CProta : public  Personaje{
	int cordura;

public:
	CProta() : Personaje("Veradi", 0, 85),cordura(100), intel(50){}
	int getCordura() { return this->cordura; }
	void setCordura(int cor) { cordura = cor; }

};