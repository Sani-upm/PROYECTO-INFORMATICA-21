#include "ListaDisparos.h"


//Inicializacion
ListaDisparos::ListaDisparos()
{
	//inicializar la lista de disparos
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;
}

ListaDisparos::~ListaDisparos()
{

}

bool ListaDisparos::Agregar(Disparo *d)
{
	if (numero < MAX_DISPAROS)
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

void ListaDisparos::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}

void ListaDisparos::Eliminar(int index)
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
void ListaDisparos::Eliminar(Disparo* q)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i] == q)
			Eliminar(i);
		return;
	}
}



//Metodos GLUT
void ListaDisparos::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

void ListaDisparos::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

//Metodos Get

int ListaDisparos::GetNumero()
{
	return numero;
}

Disparo* ListaDisparos::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}