
#pragma once
#define MAX_PLATAFORMAS 51
#include "Hombre.h"
//#include "Enemigo.h"
#include "Pared.h"

class ListaPlataformas
{
private:
	Pared* lista[MAX_PLATAFORMAS];
	int numero;

public:

	//Metodos inicializacion
	ListaPlataformas();
	virtual ~ListaPlataformas();

	//Metodos GLUT
	void Dibuja();

	//Metodos Set

	//Mertodos Get
	int GetNumero();
	Pared GetPlataforma(int j);

	//Metodos añadir nuevas paredes

	bool Agregar(Pared* e);


	//REBOTE
	void Rebote(Hombre&);
	//void Rebote(Enemigo& r);

	//DESTRUCTOR
	void destruirContenido();
	void Eliminar(int index);
	void Eliminar(Pared* e);


};