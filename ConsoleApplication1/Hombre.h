#pragma once
#include "ETSIDI.h"
#include"Vector2D.h"

using ETSIDI::SpriteSequence;

class Hombre
{

private:

	SpriteSequence Andar; //sprite para caminar
	SpriteSequence Parar; //sprite para cuando esta quieto
	SpriteSequence Saltar; //sprite para saltos
	SpriteSequence Morir; //sprite para la muerte del personaje

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	int vida;
	float altura;

public:
	Hombre();

	void SetPosicion();
	void SetVelocidad();
	void SetAceleracion();
	void SetVida(int _vida);
	void SetAltura(float _altura);
	~Hombre();

	//funciones GLUT
	void Dibuja();
	void Mueve();
};

