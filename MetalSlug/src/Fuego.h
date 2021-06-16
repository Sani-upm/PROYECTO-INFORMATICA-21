#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"


using ETSIDI::SpriteSequence;

class Fuego: public ObjetoMovil
{
public:

	Fuego();

	virtual void Dibuja();
	void Mueve(float t);

	float GetRadio();

private:

	SpriteSequence fuegodragon;

	float radio;
	friend class Interaccion;
};


