#include "Disparo.h"
#include "Vector2D.h"
#include "freeglut.h"

Disparo::Disparo() : disparo("bin/Imagenes/Peashooter.png", 3, 1, 60)
{
	radio = 0.5f;
	rojo = 0;
	verde = 255;
	azul = 255;
	disparo.setCenter(5,5);
	disparo.setSize(5,5);
}

// Metodos GLUT

void Disparo::Dibuja()
{
	glPushMatrix();
	glColor3f(0, 255, 255);
	glTranslatef(posicion.x, posicion.y, 0);
	disparo.draw();
	glutSolidSphere(radio, 20, 20);
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

