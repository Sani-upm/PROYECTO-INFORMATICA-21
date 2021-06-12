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

	else if (g.GetYPosicion() < -48)	//Colision con el suelo
	{	
		g.SetVida(g.GetVida() - 1);
	}

	if (g.GetXPosicion() < -75)						//colision pared inicial
	{
		g.SetPosicion(-75, g.GetYPosicion());
		g.SetVelocidad(0.0, g.GetYVelocidad());
	}
	if (n == 1 && g.GetXPosicion() > 220)			//colision pared final primer mapa
	{
		g.SetPosicion(210, g.GetYPosicion());
		g.SetVelocidad(0.0, g.GetYVelocidad());
	}
	if (n != 1 && g.GetXPosicion() > 550)		//colision pared final mapas 2 y 3
	{
		g.SetPosicion(550, g.GetYPosicion());
		g.SetVelocidad(0.0, g.GetYVelocidad());
	}
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