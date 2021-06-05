#include "Patata.h"
#include "freeglut.h"

Patata::Patata() : Idle("bin/Imagenes/idlepatata.png", 2, 1, 50), Attack("bin/Imagenes/ataquepatata.png", 4, 1, 50)
{
	SetAltura(5); //modificar

	Idle.setCenter(10, 0);
	Idle.setSize(5, altura);

	Attack.setCenter(0, 0);
	Attack.setSize(5, altura);

	rojo = 255;
	verde = 0;
	azul = 0;
	posicion = 0;

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
		Attack.setState(0);
	}

	else if (atacar == 1)
	{
		Attack.draw();
	}

	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
void Patata::Mueve(float t)
{

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

void Patata::SetAltura(double _a)
{
	altura = _a;
}

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
	atacar = _ataque;
}

// Metodos Get


float Patata::GetXPosicion()
{
	return posicion.x;
}
float Patata::GetYPosicion()
{
	return posicion.y;
}

Vector2D Patata::GetPosicion()
{
	return posicion;
}