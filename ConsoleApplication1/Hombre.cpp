
#include"Hombre.h"
#include"freeglut.h"

Hombre::Hombre()
{
	altura = 5;
	rojo = 255;
	verde = 0;
	azul = 0;
	posicion = 0;
	velocidad = 0;
	aceleracion = 0;
}

Hombre::~Hombre()
{
}

// Metodos GLUT 

void Hombre::Dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidCube(altura);
	
}
void Hombre::Mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0, 5 * t * t);
	velocidad = velocidad + aceleracion * t;
}


// Metodos Set

void Hombre::SetAltura(double a)
{
	altura = a;
}


void Hombre::SetPosicion(double _x, double _y)
{
	posicion.SetCoordenadas(_x, _y);

}

void Hombre::SetVelocidad(double _vx, double _vy)
{
	velocidad.SetCoordenadas(_vx,_vy);
	
}
void Hombre::SetAceleracion(double _ax, double _ay)
{
	aceleracion.SetCoordenadas(_ax, _ay);

}

// Metodos Get

double Hombre::GetAltura()
{
	return altura;
}

double Hombre::GetXPosicion()
{
	return posicion.x;
}
double Hombre::GetYPosicion()
{
	return posicion.y;
}
double Hombre::GetXVelocidad()
{
	return velocidad.x;
}
double Hombre::GetYVelocidad()
{
	return velocidad.y;
}
double Hombre::GetXAceleracion()
{
	return aceleracion.x;
}
double Hombre::GetYAceleracion()
{
	return aceleracion.y;
}