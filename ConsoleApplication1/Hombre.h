#pragma once
#include"Vector2D.h"


class Hombre
{
public:
	Hombre();
	~Hombre();
	void Dibuja();
	void Mueve();

private:
	double altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
};

