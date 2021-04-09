#include "Mundo.h"
#include <math.h>
#include "freeglut.h"

Mundo::Mundo()
{
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

}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,		  // posicion del ojo
		0.0, 0, 0.0,				 // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);			 // definimos hacia arriba (eje Y)    


	//dibujo del suelo
	//esfera.Dibuja();

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0, -5.0f);
	glVertex3f(-5.0f, 0, 5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(5.0f, 0, 5.0f);
	glVertex3f(5.0f, 0, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Mundo::Tecla(unsigned char key)
{

}

void Mundo::Mueve()
{
	//esfera.Mueve();

}