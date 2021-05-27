#pragma once

#include"Pared.h"
#include"Hombre.h"
#include "Niveles.h"


class Interaccion
{
public:
	Interaccion();
	~Interaccion();

	static void Rebote(Hombre& g, int& n);
	static void Rebote(Hombre&, Pared&);
	static void Rebote(Hombre&, Niveles&);
private:

};

