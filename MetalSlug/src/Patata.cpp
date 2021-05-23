#include "Patata.h"
#include "freeglut.h"

Patata::Patata()
{
	SetAltura(5); //modificar

	Idle.setCenter(0, 0);
	Idle.setSize(5, altura);

	Attack.setCenter(0, 0);
	Attack.setSize(5, altura);

	rojo = 255;
	verde = 0;
	azul = 0;
	posicion = 0;
	velocidad = 0;
	aceleracion = 0;

}

void Patata::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3ub(rojo, verde, azul);


	if (atacar == 0)
	{
		Idle.setState(0);
		Idle.draw();
	}


	if (atacar == 1)
	{
		Attack.setState(0, false);
		Attack.draw();
	}

	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
void Patata::Mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0,5f * t * t);
	velocidad = velocidad + aceleracion * t;

	if (atacar == 0)
	{
		Idle.loop();
	}

	if (atacar == 1)
	{
		Attack.loop();
	}

}


// Metodos Set

void Patata::SetPosicion(double _x, double _y)
{
	posicion.SetCoordenadas(_x, _y);

}

void Patata::SetPosicion(Vector2D _xy)
{
	posicion = _xy;
}

void Patata::SetAttack(int _ataque)
{
	ataque = _ataque;
}

