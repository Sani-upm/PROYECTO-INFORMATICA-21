#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"


using ETSIDI::SpriteSequence;

class Disparo : public ObjetoMovil
{
public:
	Disparo();

	void Dibuja();
	void Mueve(float t);

	float GetRadio();

private:

	SpriteSequence disparo;
	float radio;
	friend class Interaccion;
};

