#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Dragon
{

private:
	SpriteSequence Fly("imagenes/enemigoafly.png",2,1,50);
	SpriteSequence Idle ("imagenes/enemigoidle.png",2,1,50);
	SpriteSequence Attack("imagenes/enemigoattack.png",5, 1, 50);

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

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