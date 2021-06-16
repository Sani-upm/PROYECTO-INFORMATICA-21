#include "Disparo.h"
#include "Vector2D.h"
#include "freeglut.h"

Disparo::Disparo() : disparo("bin/Imagenes/disparo.png", 3, 1, 100)
{
	radio = 0.5f;
	disparo.setCenter(5,7);
	disparo.setSize(5,5);
}

// Metodos GLUT

void Disparo::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	disparo.draw();
	glPopMatrix();
}

void Disparo::Mueve(float t)
{
	posicion = posicion + velocidad * t;
	disparo.loop();
}

//Metodos Get

float Disparo::GetRadio()
{
	return radio;
}