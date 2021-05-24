#pragma once
#include"Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Hombre
{
private:
<<<<<<< HEAD

	SpriteSequence Walk;
	SpriteSequence Idle;
	SpriteSequence Jump;
	SpriteSequence Dead;


	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float altura;
=======

	SpriteSequence Walk("Imagenes/camina.png", 8);
	SpriteSequence Idle("Imagenes/parado.png", 5);
	SpriteSequence Jump("Imagenes/salto.png", 5);
	SpriteSequence Dead("Imagenes/dead.png", 3);

	double altura;
>>>>>>> ae6011c0afe360842ba5e5dfe26075e35195f787
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
<<<<<<< HEAD
	void SetAltura(float _a);
=======
	void SetAltura(double _a);
>>>>>>> ae6011c0afe360842ba5e5dfe26075e35195f787

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