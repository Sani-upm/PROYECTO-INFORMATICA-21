#pragma once
#include "Vector2D.h"

class ObjetoMovil
{
protected: 
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	virtual Vector2D getPos();
	Vector2D getVel();
	Vector2D getAcel();
	virtual void setPos(float x, float y);
	virtual void setVel(float vx, float vy);
	virtual void setAcel(float ax, float ay);
};