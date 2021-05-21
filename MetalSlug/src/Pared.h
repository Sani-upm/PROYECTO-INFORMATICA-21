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
	void SetPos2(double, double, double, double);

	//Metodos Get

	double GetYsuperior();
	double GetYinferior();
	double GetXd();
	double GetXi();

private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	double ancho;
	double largo;
	Vector2D limite1;
	Vector2D limite2;

	friend class Interaccion;

};
