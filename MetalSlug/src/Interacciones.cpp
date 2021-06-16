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
	if (g.getPos().y > 30)			//colision con el techito
	{
	g.setPos(g.getPos().x, 30);
	g.setVel(g.getVel().x, -0.01);
	}

	else if (g.getPos().y < -48)	//Colision con el suelo
	{	
		g.SetVida(g.GetVida() - 1);
	}

	if (g.getPos().x < -75)						//colision pared inicial
	{
		g.setPos(-75, g.getPos().y);
		g.setVel(0.0, g.getVel().y);
	}
	if (n == 1 && g.getPos().x > 227)			//colision pared final primer mapa
	{
		g.setPos(227, g.getPos().y);
		g.setVel(0.0, g.getVel().y);
	}
	if (n != 1 && g.getPos().x > 600)		//colision pared final mapas 2 y 3
	{
		g.setPos(557, g.getPos().y);
		g.setVel(0.0, g.getVel().y);
	}
}

//Rebote contra una pared
void Interaccion::Rebote(Hombre& j, Pared& p)
{
	
	if ((j.getPos().y < p.GetYsuperior() + 1) && (j.getPos().y > p.GetYsuperior() - 1) && (j.getPos().x > p.GetXi()) && (j.getPos().x < p.GetXd()))
	{
		j.setPos(j.getPos().x, (float)p.GetYsuperior() + (float)1.0f);
		j.setVel(j.getVel().x, 0);
		j.SetSalto(1);
	}
}

void Interaccion::Rebote(Hombre& j, Niveles& nivel)
{
	nivel.plataformas.Rebote(j);
}

bool Interaccion::Comportamiento_Dragon(Dragon& d, Hombre& h)
{
	Vector2D distancia = d.getPos() - h.getPos();
	Vector2D unitario = distancia.unitario();
	float modulo = distancia.modulo();

	

	if (modulo < 60)
	{
		d.atacar = 1;
		d.setVel(((float)-15.0f * (float)unitario.x), ((float)-15.0f * (float)unitario.y));
		

		if (modulo <= 3)
			h.SetVida(0);
		
		return true;
	}

	else
	{
		d.setVel(0, 0);
		d.atacar = 0;
		return false;
	}
}

bool Interaccion::Impacto_Dragon(Disparo& disp, Dragon& d)
{
	Vector2D  posicion_real(d.getPos().x, d.getPos().y);
	Vector2D distancia = disp.getPos() - posicion_real;
	float modulo = distancia.modulo();

	if (modulo < 2.5)
		return true;
	else
		return false;
	
}

bool Interaccion::Rebote_Ataque_Dragon(Fuego& f, Hombre& h)
{
	float altura_real = h.getPos().y + 6;
	Vector2D  posicion_real(h.getPos().x, altura_real);
	Vector2D distancia = f.getPos() - posicion_real;
	float modulo = distancia.modulo();

	if (modulo < 2.5)
		return true;
	else
		return false;

}