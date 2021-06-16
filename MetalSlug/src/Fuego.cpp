#include "Fuego.h"
#include "Vector2D.h"
#include "freeglut.h"

Fuego::Fuego() : fuegodragon("bin/Imagenes/fuegodragon.png", 5, 1, 100)
{
	radio = 0.5f;
	rojo = 255;
	verde = 127;
	azul = 0;
	fuegodragon.setCenter(5, 7);
	fuegodragon.setSize(5, 5);
}

// Metodos GLUT

void Fuego::Dibuja()
{
	glPushMatrix();
	glColor3f(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	fuegodragon.draw();
	glPopMatrix();
}

void Fuego::Mueve(float t)
{
	posicion = posicion + velocidad * t;
	fuegodragon.loop();
}

//Metodos Set

void Fuego::SetPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}

void Fuego::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

//Metodos Get

float Fuego::GetRadio()
{
	return radio;
}

Vector2D Fuego::GetPos()
{
	return posicion;
}

void Fuego::SetColor(float r, float g, float b)
{
	rojo = r;
	verde = g;
	azul = b;
}
