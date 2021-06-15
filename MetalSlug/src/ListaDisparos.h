#pragma once

#define MAX_DISPAROS 50
#include "disparo.h"
#include "Interaccion.h"

class ListaDisparos
{
public:

	//Metodos Inicializacion
	ListaDisparos();
	virtual  ~ListaDisparos();

	//Creacion
	bool Agregar(Disparo* d);

	//Destructor

	void DestruirContenido();

	void Eliminar(int index);
	void Eliminar(Disparo* q);
	

	//Metodos GLUT
	void Mueve(float t);
	void Dibuja();

	//Metodos Get
	int GetNumero();
	Disparo* operator [](int i);

private:
	Disparo* lista[MAX_DISPAROS];
	Disparo disparo;
	int numero;
};

