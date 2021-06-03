#include"Interaccion.h"



Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}


// Rebote con los limites del juego
void Interaccion::Rebote(Hombre& g, int& n)
{
	if (g.GetYPosicion() > 30)			//colision con el techito
	{
	g.SetPosicion(g.GetXPosicion(), 30);
	g.SetVelocidad(g.GetXVelocidad(), -0.01);
	}

	/*else if (g.GetYPosicion() < -40)	//Colision con el suelo
	{
		g.SetPosicion(g.GetXPosicion(), -70);
		g.SetVelocidad(g.GetXVelocidad(), 0);
	}*/
}

//Rebote contra una pared
void Interaccion::Rebote(Hombre& j, Pared& p)
{
	
	if ((j.GetYPosicion() < p.GetYsuperior() + 1) && (j.GetYPosicion() > p.GetYsuperior() - 1) && (j.GetXPosicion() > p.GetXi()) && (j.GetXPosicion() < p.GetXd()))
	{
		j.SetPosicion(j.GetXPosicion(), p.GetYsuperior() + 1.0f);
		j.SetVelocidad(j.GetXVelocidad(), 0);
		j.SetSalto(1);
	}
}

void Interaccion::Rebote(Hombre& j, Niveles& nivel)
{
	nivel.plataformas.Rebote(j);

}