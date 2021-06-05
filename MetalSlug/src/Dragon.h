#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Dragon
{

private:
	SpriteSequence Fly;
	SpriteSequence Idle;
	SpriteSequence Attack;

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	double altura;
	int atacar = 0;

public:

	Dragon();


	//Metodos GLUT
	void Dibuja();
	void Mueve(float t);

	//Metodos SET
	void SetPosicion(double _x, double _y);
	void SetPosicion(Vector2D _xy);
	void SetVelocidad(double _vx, double _vy);
	void SetAceleracion(double _xa, double _ya);
	void SetAltura(double _a);
	void SetAttack(int _ataque);

	//Metodos GET
	float GetXPosicion();
	float GetYPosicion();
	float GetXVelocidad();
	float GetYVelocidad();
	float GetXAceleracion();
	float GetYAceleracion();
	Vector2D GetPosicion();


	friend class Interaccion;
};