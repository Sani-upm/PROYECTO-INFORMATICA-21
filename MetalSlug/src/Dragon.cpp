#include "Dragon.h"
#include "freeglut.h"

Dragon::Dragon(): Fly("bin/Imagenes/enemigofly.png", 2, 1, 50), Idle("bin/Imagenes/enemigoidle.png", 2, 1, 50), Attack("bin/Imagenes/enemigoattack.png", 5, 1, 50)
{
	SetAltura(5); //modificar

	Fly.setCenter(0, 0); //modoficar todos los setCenter y setSize
	Fly.setSize(5, altura);

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

void Dragon::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3ub(rojo, verde, azul);

	if (velocidad.x > 0.01)
	{
		Fly.flip(false, false);
	}
	else if (velocidad.x < -0.01)
	{
		Fly.flip(true, false);
	}

	if (velocidad.x < 0.01 && velocidad.x > -0.01 && velocidad.y == 0 && atacar == 0)
	{
		Idle.setState(0);
		Idle.draw();
	}

	if (velocidad.y == 0 && (velocidad.x > 0.1 || velocidad.x < -0.1) && atacar == 0)
	{
		Fly.draw();
		Attack.setState(0);
	}

	if (atacar == 1)
	{
		Attack.draw();
	}

	glTranslatef(-posicion.x, -posicion.y, 0);
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