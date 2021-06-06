#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Patata
{

private:

	SpriteSequence Idle;
	SpriteSequence Attack;

	Vector2D posicion;


	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	double altura;
	int atacar = 0;

public:

	Patata();

	//Metodos GLUT
	void Dibuja();
	void Mueve(float t);

	//Metodos SET
	void SetPosicion(double _x, double _y);
	void SetPosicion(Vector2D _xy);
	void SetAltura(double _a);
	void SetAttack(int _ataque);

	//Metodos GET
	float GetXPosicion();
	float GetYPosicion();
	Vector2D GetPosicion();


	friend class Interaccion;
};
