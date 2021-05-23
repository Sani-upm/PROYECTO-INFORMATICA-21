#pragma once
#include"Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Hombre
{
private:

	SpriteSequence Walk("imagenes/camina.png", 8, 1, 50);
	SpriteSequence Idle("imagenes/parado.png", 5, 1, 50);
	SpriteSequence Jump("imagenes/salto.png", 5, 1, 50);
	SpriteSequence Dead("imagenes/dead.png", 3, 1, 50);

	double altura;
	int vida;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	Hombre();
	~Hombre(); //pa que

	//Metodos GLUT
	void Dibuja();
	void Mueve(float t);

	//Metodos SET
	void SetPosicion(double _x, double _y);
	void SetPosicion(Vector2D _xy);
	void SetVelocidad(double _vx, double _vy);
	void SetAceleracion(double _xa, double _ya);
	void SetVida(int _vida);
	void SetAltura(double _a);

	//Metodos GET
	float GetXPosicion();
	float GetYPosicion();
	float GetXVelocidad();
	float GetYVelocidad();
	float GetXAceleracion();
	float GetYAceleracion();
	float GetAltura();
	int GetVida();
	Vector2D GetPosicion();


	friend class Interaccion;
};