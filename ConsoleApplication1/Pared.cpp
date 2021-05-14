
#include"freeglut.h"
#include "Pared.h"

Pared::Pared()
{
	rojo  = 255;
	verde = 255;
	azul  = 255;

	limite1.x = -30;
	limite1.y = -5;
	limite2.x = 30;
	limite2.y = 5;
}

Pared::~Pared()
{
}

void Pared::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo  = r;
	verde = v;
	azul  = a;
}

void Pared::SetPos(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
void Pared::Dibuja()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(rojo,verde,azul);
	glVertex3f(limite1.x, 0, limite1.y); // vertice arriba izq, NO ZE, COSAS
	glVertex3f(limite1.x, 0, limite2.y);  // vertice abajo izquierda
	//glColor3ub(255, 255, 0);
	glVertex3f(limite2.x, 0, limite2.y);   // vertice arriba derecha
	glVertex3f(limite2.x, 0, limite1.y);  // vertice abajo derecha
	glEnd();
	glEnable(GL_LIGHTING);
}