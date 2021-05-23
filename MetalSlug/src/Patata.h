#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Patata
{

private:
	SpriteSequence Idle("imagenes/idlepatata.png", 2, 1, 50);
	SpriteSequence Attack("imagenes/ataquepatata.png", 4, 1, 50);

	Vector2D posicion;
	int atacar = 0;

public:

	Patata();

	//Metodos GLUT
	void Dibuja();
	void Mueve(float t);

	//Metodos SET
	void SetPosicion(double _x, double _y);
	void SetPosicion(Vector2D _xy);
	void SetAttack(int _ataque);


	friend class Interaccion;
};