
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


private:
	float x_ojo;
	float y_ojo;
	float z_ojo;

	Esfera esfera;

};