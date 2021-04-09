
#include"Esfera.h"
#include"freeglut.h"

Esfera::Esfera()
{
}

Esfera ::~Esfera()
{
}

void Esfera::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
void Esfera::SetRadio(double r)
{
	if (r < 0.1f)
		r = 0.1f;
	radio = r;

}
void Esfera::SetPos(double ix, double iy)
{
	x = ix;
	y = iy;
}

void Esfera::Inicializa(unsigned char r, unsigned char g, unsigned char a, double rr, double ix, double iy)
{

	Esfera::SetColor( r,  g,  a);
	Esfera::SetRadio( rr);
	Esfera::SetPos( ix, iy);
}
void Esfera::Dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(x, y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-x, -y, 0);
}
void Esfera::Mueve()
{
	radio += 0.01f;
	if (radio > 2)
		radio = 0.5f;
}