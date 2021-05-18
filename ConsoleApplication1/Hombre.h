#pragma once
#include"Vector2D.h"


class Hombre
{
public:
	Hombre();
	~Hombre();

	//Metodos GLUT
	void Dibuja();
	void Mueve(float);

	//Metodos Set
	void SetAltura(double);

	void SetPosicion(double, double);
	void SetVelocidad(double, double);
	void SetAceleracion(double, double);
	

	//Metodos Get

	double GetAltura();

	double GetXPosicion();
	double GetYPosicion();
	double GetXVelocidad();
	double GetYVelocidad();
	double GetXAceleracion();
	double GetYAceleracion();
	



private:
	double altura;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	friend class Interaccion;
};

