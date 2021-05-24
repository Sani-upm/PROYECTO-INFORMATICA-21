
#include"Vector2D.h"
#include"math.h"



Vector2D::Vector2D(float xv, float yv)
{
	x = xv;
	y = yv;
}

Vector2D::~Vector2D()
{
}

void Vector2D::SetCoordenadas(float _x, float _y)
{
	x = _x;
	y = _y;
}

float Vector2D::GetX()
{
	return x;
}
float Vector2D::GetY()
{
	return y;
}


Vector2D Vector2D::operator+(float real)
{
	Vector2D resultado;
	resultado.x = x + real;
	resultado.y = y;
	return resultado;
}


float Vector2D::modulo()
{
	return (float)sqrt(x * x + y * y);
}

float Vector2D::argumento()
{
	return (float)atan2(y, x);
}

Vector2D Vector2D::unitario()
{
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D::operator - (Vector2D v)
{
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}
Vector2D Vector2D::operator + (Vector2D v)
{
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

float Vector2D::operator *(Vector2D v)
{
	return (float)(x * v.x + y * v.y);
}

Vector2D Vector2D::operator *(float a)
{
	Vector2D res;
	res.x = x * a;
	res.y = y * a;
	return res;
}

float Vector2D::Angulo(Vector2D v)
{
	double mod1 = modulo();
	double mod2 = (float)sqrt(v.x * v.x + v.y * v.y);
	double prodEscalar = x * v.x + y * v.y;
	return (float)acos(prodEscalar / mod1 * mod2);
}