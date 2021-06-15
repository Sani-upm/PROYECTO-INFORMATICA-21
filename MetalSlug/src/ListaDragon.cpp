#include "ListaDragon.h"

ListaDragones::ListaDragones()
{
	numero = 0;
	for (int i = 0; i < MAX_DRAGON; i++)
		lista[i] = 0;
}

bool ListaDragones::agregar(Dragon* d)
{
	if (numero < MAX_DRAGON)
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
			if (i != j || lista[i] == lista[j])
				return false;
		}
	}
}

void ListaDragones::Dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->Dibuja();
	}

}

void ListaDragones::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

void ListaDragones::destruircontenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaDragones::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDragones::eliminar(Dragon* d)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
		{
			eliminar(i);
			return;
		}
}

int ListaDragones::getNumero()
{
	return numero;
}

Dragon* ListaDragones::Comportamiento_Dragon(Hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::Comportamiento_Dragon(*(lista[i]), h))
			return lista[i];
	}
	return 0;
}

Dragon* ListaDragones::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}
