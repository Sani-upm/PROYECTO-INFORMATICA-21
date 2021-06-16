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
	if (n == 1 && g.GetXPosicion() > 227)			//colision pared final primer mapa
	{
		g.SetPosicion(227, g.GetYPosicion());
		g.SetVelocidad(0.0, g.GetYVelocidad());
	}
	if (n != 1 && g.GetXPosicion() > 600)		//colision pared final mapas 2 y 3
	{
		g.SetPosicion(557, g.GetYPosicion());
		g.SetVelocidad(0.0, g.GetYVelocidad());
	}
}

//Rebote contra una pared
void Interaccion::Rebote(Hombre& j, Pared& p)
{
	
	if ((j.GetYPosicion() < p.GetYsuperior() + 1) && (j.GetYPosicion() > p.GetYsuperior() - 1) && (j.GetXPosicion() > p.GetXi()) && (j.GetXPosicion() < p.GetXd()))
	{
		j.SetPosicion(j.GetXPosicion(), (float)p.GetYsuperior() + (float)1.0f);
		j.SetVelocidad(j.GetXVelocidad(), 0);
		j.SetSalto(1);
	}
}

void Interaccion::Rebote(Hombre& j, Niveles& nivel)
{
	nivel.plataformas.Rebote(j);

}

bool Interaccion::Comportamiento_Dragon(Dragon& d, Hombre& h)
{
	Vector2D distancia = d.posicion - h.posicion;
	Vector2D unitario = distancia.unitario();
	float modulo = distancia.modulo();

	

	if (modulo < 50)
	{
		d.atacar = 1;
		d.SetVelocidad(((float)-10.0f * (float)unitario.x), ((float)-10.0f * (float)unitario.y));
		

		if (modulo <= 3)
		{
			h.SetVida(0);
			//h.SetPosicion(-70, 0);
			//h.SetVelocidad(0, 0);
		}
		return true;
	}

	else
	{
		d.SetVelocidad(0,0);
		d.atacar = 0;

		return false;
	}
}

bool Interaccion::Impacto_Dragon(Disparo& disp, Dragon& d)
{
	float altura_real = d.posicion.y + 6;
	Vector2D  posicion_real(d.posicion.x, altura_real);
	Vector2D distancia = disp.posicion - posicion_real;
	float modulo = distancia.modulo();

	if (modulo < 2.5)
		return true;
	else
		return false;
	
}

bool Interaccion::Rebote_Ataque_Dragon(Fuego& f, Hombre& h)
{
	float altura_real = h.posicion.y + 6;
	Vector2D  posicion_real(h.posicion.x, altura_real);
	Vector2D distancia = f.posicion - posicion_real;
	float modulo = distancia.modulo();

	if (modulo < 2.5)
		return true;
	else
		return false;

}

