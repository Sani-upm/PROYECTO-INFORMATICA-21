#include"Interaccion.h"



Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

void Interaccion::Rebote(Hombre &j, Pared p)
{
	if (j.GetYPosicion() < -5)
		j.SetPosicion(j.GetXPosicion(),-5);

	if (j.GetXPosicion() < -5)
		j.SetPosicion(-5, j.GetXPosicion());
}