#include "Dragon.h"
#include "freeglut.h"
#include <Windows.h>


Dragon::Dragon(float a, int atacar, float x, float y, float vx, float vy): Fly("bin/Imagenes/enemigofly.png", 2, 1, 50), Idle("bin/Imagenes/enemigoidle.png", 2, 1, 50), Attack("bin/Imagenes/enemigoattack.png", 5, 1, 50)
{
	SetAltura(a); //modificar

	Fly.setCenter(0, 0); //modoficar todos los setCenter y setSize
	Fly.setSize(a, altura);

	Idle.setCenter(0, 0);
	Idle.setSize(a, altura);

	Attack.setCenter(0, 0);
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
	glColor3ub(rojo, verde, azul);

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
		/*for (int i = 0; i < llamas.GetNumero(); i++)
		{
			llamas[i]->Dibuja();
		}*/
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
		Idle.loop();
		
	}

	if (atacar == 1)
	{
		Attack.loop();
		/*for (int i = 0; i < llamas.GetNumero(); i++)
			llamas[i]->Mueve(0.0025);*/

	}

}


// Metodos Set

void Dragon::SetAltura(double _a)
{
	altura = _a;
}

void Dragon::SetPosicion(double _x, double _y)
{
	posicion.SetCoordenadas(_x, _y);

}

void Dragon::SetPosicion(Vector2D _xy)
{
	posicion = _xy;
}

void Dragon::SetVelocidad(double _vx, double _vy)
{
	velocidad.SetCoordenadas(_vx, _vy);

}
void Dragon::SetAceleracion(double _ax, double _ay)
{
	aceleracion.SetCoordenadas(_ax, _ay);

}

void Dragon::SetAttack(int _ataque)
{
	atacar = _ataque;
}

// Metodos Get


float Dragon::GetXPosicion()
{
	return posicion.x;
}
float Dragon::GetYPosicion()
{
	return posicion.y;
}
float Dragon::GetXVelocidad()
{
	return velocidad.x;
}
float Dragon::GetYVelocidad()
{
	return velocidad.y;
}
float Dragon::GetXAceleracion()
{
	return aceleracion.x;
}
float Dragon::GetYAceleracion()
{
	return aceleracion.y;
}

Vector2D Dragon::GetPosicion()
{
	return posicion;
}

int Dragon::getAtaque()
{
	return atacar;
}

