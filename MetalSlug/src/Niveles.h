#pragma once

#include "ETSIDI.h"
#include "freeglut.h"
#include "ListaPlataformas.h"

//#include "ListaVidas.h"
//#include "ListaBombas.h"
//#include "ListaQuesos.h"



class Niveles
{
private:
	friend class Interaccion;

public:

	ListaPlataformas plataformas;
	void SetLvlTutorial();
	//void SetLvl1();
	//void SetLvl2();
	//void SetLvl3();
	//void SetLvl4();
	void DibujarLvlTutorial();
	//void PintarLvl1();
	//void PintarLvl2();
	//void PintarLvl3();
	//void PintarLvl4();
	void Mueve(float _t);

	//ListaQuesos quesos;
	//ListaVidas vidas;
	//ListaBombas bombas;
};