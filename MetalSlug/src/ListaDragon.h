#pragma once
#define MAX_DRAGON 10
#include "Hombre.h"
#include "Dragon.h"
#include "Interaccion.h"


class ListaDragones
{
public:
	ListaDragones();
	bool agregar(Dragon* d);
	void Dibuja();
	void Mueve(float t);
	void destruircontenido();
	void eliminar(int index);
	void eliminar(Dragon* d);
	int getNumero();
	
	Dragon* Comportamiento_Dragon(Hombre& h);
	Dragon* operator [](int i);

private:
	Dragon* lista[MAX_DRAGON];
	int numero;
};
