#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using ETSIDI::SpriteSequence;

class Dragon:public ObjetoMovil
{

private:
	SpriteSequence Fly;
	SpriteSequence Idle;
	SpriteSequence Attack;

	double altura;
	int atacar = 0;

public:

	Dragon(float a, int atacar, float x, float y, float vx, float vy);

	//Metodos GLUT
	void Dibuja();
	void Mueve(float t);

	//Metodos SET

	void SetAltura(double _a);
	void SetAttack(int _ataque);

	//Metodos GET
	int getAtaque();

	friend class Interaccion;
	friend class Mundo;
};