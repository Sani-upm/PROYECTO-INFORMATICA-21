#include "Dragon.h"
#include "freeglut.h"
#include <Windows.h>


Dragon::Dragon(float a, int atacar, float x, float y, float vx, float vy): Fly("bin/Imagenes/enemigofly.png", 2, 1, 50), Idle("bin/Imagenes/enemigoidle.png", 2, 1, 50), Attack("bin/Imagenes/dragonataque.png", 2, 1, 275)
{
	SetAltura(a);

	Fly.setCenter(a, (a/2)+ 6.5); 
	Fly.setSize(a, altura);

	Idle.setCenter(a, (a / 2) + 6.5);
	Idle.setSize(a, altura);

	Attack.setCenter(a, (a / 2)+ 6);
	Attack.setSize(a, altura);

	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
}

void Dragon::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.GetX(), posicion.GetY(), 0);

	if (velocidad.GetX() > 0.01)
	{
		Fly.flip(false, false);
		Idle.flip(false,false);
		Attack.flip(false, false);
	}
	else if (velocidad.GetX() < -0.01)
	{
		Fly.flip(true, false);
		Idle.flip(true,false);
		Attack.flip(true, false);
	}

	if (velocidad.GetX() < 0.01 && velocidad.GetX() > -0.01 && velocidad.GetY() == 0 && atacar == 0)
	{
		Idle.setState(0);
		Idle.draw();
	}

	if (velocidad.GetY() == 0 && (velocidad.GetX() > 0.1 || velocidad.GetX() < -0.1) && atacar == 0)
	{
		Fly.draw();
		Attack.setState(0);
	}

	if (atacar == 1)
	{
		Attack.draw();
	}

	glTranslatef(-posicion.GetX(), -posicion.GetY(), 0);
	glPopMatrix();
}
void Dragon::Mueve(float t)
{

	posicion = posicion + velocidad * t + aceleracion * (0, 5 * t * t);
	velocidad = velocidad + aceleracion * t;

	if (atacar == 0)
	{
		Fly.loop();
	}

	if (atacar == 1)
	{
		Attack.loop();
	}

}

void Dragon::SetAltura(double _a)
{
	altura = _a;
}


void Dragon::SetAttack(int _ataque)
{
	atacar = _ataque;
}

int Dragon::getAtaque()
{
	return atacar;
}

