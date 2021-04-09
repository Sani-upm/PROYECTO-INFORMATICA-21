
#pragma once
#include "Esfera.h"

class Mundo
{
public:
	Mundo();
	~Mundo();

	void RotarOjo();
	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char key);
	void Mueve();


private:
	double x_ojo;
	double y_ojo;
	double z_ojo;

	Esfera esfera;

};