#include "ListaFuego.h"


//Inicializacion
ListaFuego::ListaFuego()
{
	//inicializar la lista de disparos
	numero = 0;
	for (int i = 0; i < FUEGO; i++)
		lista[i] = 0;
}

ListaFuego::~ListaFuego()
{

}

bool ListaFuego::Agregar(Fuego* d)
{
	if (numero < FUEGO)
	{
		lista[numero++] = d;
		return true;
	}
	else
		return false;
	for (int i = 0; i < numero; i++)
	{
		for (int j = numero - 1; i >= 0; i--)
		{
			if ((i != j) && lista[i] == lista[j])
				return false;
		}
	}
}

//Metodos Destructor

void ListaFuego::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}

void ListaFuego::Eliminar(int index)
{
	if ((index < 0) || (index >= numero))
	{
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
	{
		lista[i] = lista[i + 1];
	}
}
void ListaFuego::Eliminar(Fuego* q)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i] == q)
			Eliminar(i);
		return;
	}
}



//Metodos GLUT
void ListaFuego::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

void ListaFuego::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

//Metodos Get

int ListaFuego::GetNumero()
{
	return numero;
}

Fuego* ListaFuego::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}