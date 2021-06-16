#include "Fuego.h"
#include "Vector2D.h"
#include "freeglut.h"

Fuego::Fuego() : fuegodragon("bin/Imagenes/fuegodragon.png", 3, 1, 100)
{
	radio = 0.5f;
	fuegodragon.setCenter(5, 7);
	fuegodragon.setSize(5, 5);
}

// Metodos GLUT

void Fuego::Dibuja()
{
	glPushMatrix();
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


//Metodos Get

float Fuego::GetRadio()
{
	return radio;
}

