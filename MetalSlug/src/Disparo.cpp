#include "Disparo.h"
#include "Vector2D.h"
#include "freeglut.h"

Disparo::Disparo() : disparo("bin/Imagenes/disparo.png", 3, 1, 100)
{
	radio = 0.5f;
	rojo = 255;
	verde = 127;
	azul = 0;
	disparo.setCenter(5,7);
	disparo.setSize(5,5);
}

// Metodos GLUT

void Disparo::Dibuja()
{
	glPushMatrix();
	glColor3f(rojo,verde , azul);
	glTranslatef(posicion.x, posicion.y, 0);
	disparo.draw();
	glPopMatrix();
}

void Disparo::Mueve(float t)
{
	posicion = posicion + velocidad * t;
	disparo.loop();
}

//Metodos Set

void Disparo::SetPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}

void Disparo::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

//Metodos Get

float Disparo::GetRadio()
{
	return radio;
}

Vector2D Disparo::GetPos()
{
	return posicion;
}

void Disparo::SetColor(float r, float g, float b)
{
	rojo = r;
	verde = g;
	azul = b;
}