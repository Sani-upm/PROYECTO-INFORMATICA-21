#include "ObjetoMovil.h"


Vector2D ObjetoMovil::getPos()
{
	return posicion;
}

Vector2D ObjetoMovil::getVel()
{
	return velocidad;
}

Vector2D ObjetoMovil::getAcel()
{
	return aceleracion;
}

void ObjetoMovil::setPos(float x,float y)
{
	posicion.x = x;
	posicion.y = y;
}

void ObjetoMovil::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void ObjetoMovil::setAcel(float ax, float ay)
{
	aceleracion.x = ax;
	aceleracion.y = ay;
}
