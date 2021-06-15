#pragma once

#include"Pared.h"
#include"Hombre.h"
#include "Niveles.h"
#include "Dragon.h"
#include "Disparo.h"
#include "Fuego.h"
#include "ListaFuego.h"




class Interaccion
{
public:
	Interaccion();
	~Interaccion();

	static void Rebote(Hombre& g, int& n);
	static void Rebote(Hombre&, Pared&);
	static void Rebote(Hombre&, Niveles&);
	static bool Comportamiento_Dragon(Dragon& d, Hombre& h);
	static bool Impacto_Dragon(Disparo& disp, Dragon& d);
private:

};

