#pragma once

#define FUEGO 50
#include "Fuego.h"
#include "Interaccion.h"

class ListaFuego
{
public:

	//Metodos Inicializacion
	ListaFuego();
	virtual  ~ListaFuego();

	//Creacion
	bool Agregar(Fuego* d);

	//Destructor

	void DestruirContenido();

	void Eliminar(int index);
	void Eliminar(Fuego* q);


	//Metodos GLUT
	void Mueve(float t);
	void Dibuja();

	//Metodos Get
	int GetNumero();
	Fuego* operator [](int i);

	friend class Interaccion;

private:
	Fuego* lista[FUEGO];
	Fuego fuego;
	int numero;
};


