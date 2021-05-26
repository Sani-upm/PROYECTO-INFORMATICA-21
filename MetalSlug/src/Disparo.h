#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"


using ETSIDI::SpriteSequence;

class Disparo
{
public:

	Disparo();

	//Metodos GLUT
	virtual void Dibuja();
	void Mueve(float t);

	//Metodos Set

	void SetPos(float xi, float yi);
	void SetVel(float vx, float vy);

	//Metodos Get

	float GetRadio();
	Vector2D GetPos();

private:

	SpriteSequence disparo;

	float radio;
	Vector2D posicion;
	Vector2D velocidad;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	friend class Interaccion;
};

