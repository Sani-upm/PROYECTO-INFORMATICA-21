#pragma once

#include "Vector2D.h"

class Pared
{
public:
	Pared();
	~Pared();

	// Metodos GLUT
	void Dibuja();

	// Metodos Set

	void SetColor(unsigned char, unsigned char, unsigned char);
	void SetPos(float, float, float, float);
	void SetPos2(float, float, float, float);

	//Metodos Get

	float GetYsuperior();
	float GetYinferior();
	float GetXd();
	float GetXi();

private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float ancho;
	float largo;
	Vector2D limite1;
	Vector2D limite2;

	friend class Interaccion;

};
