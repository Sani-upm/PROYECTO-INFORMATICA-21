#pragma once
#include "Vector2D.h"

class Pared
{
public:
	Pared();
	~Pared();

	void SetColor(unsigned char,unsigned char, unsigned char);
	void SetPos(float , float, float, float);
	void Dibuja();

private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D limite1;
	Vector2D limite2;

};


