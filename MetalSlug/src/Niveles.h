#pragma once

#include "ETSIDI.h"
#include "freeglut.h"
#include "ListaPlataformas.h"




class Niveles
{
private:
	friend class Interaccion;

public:

	ListaPlataformas plataformas;
	//void SetLvlTutorial();
	void SetLvl1();
	void SetLvl2();
	void SetLvl3();

	//void DibujarLvlTutorial();
	void DibujarLvl1();
	void DibujarLvl2();
	void DibujarLvl3();
	
	void Mueve(float _t);

};