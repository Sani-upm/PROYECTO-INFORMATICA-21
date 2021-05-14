#include "Mundo.h"
#include <math.h>
#include "freeglut.h"

Mundo::Mundo()
{
	x_ojo = 0;
	y_ojo = 10;
	z_ojo = 75;

}

Mundo::~Mundo()
{
}
void Mundo::RotarOjo()
{
	double dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	double ang = atan2(z_ojo, x_ojo);
	ang += 0.05;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 10;
	z_ojo = 75;

	//esfera.Inicializa(5, 200, 100, 2.5, 0, 10);
	/*
	esfera.SetColor(5, 200, 100);
	esfera.SetRadio(2.5);
	esfera.SetPos(0, 10);
	
	*/
	suelo.SetColor(255, 255, 0);
	//suelo.SetLimites();

}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,		  // posicion del ojo
		0.0, 0, 0.0,				 // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);			 // definimos hacia arriba (eje Y)    

	suelo.Dibuja();
	

	


}

void Mundo::Tecla(unsigned char key)
{

}

void Mundo::Mueve()
{
	//esfera.Mueve();

}