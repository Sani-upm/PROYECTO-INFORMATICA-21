#include"Hombre.h"
#include"freeglut.h"

Hombre::Hombre()
{
	SetVida(5); //que el personaje tenga 5 vidas?
	SetAltura(5); //no se que poner en altura

	Walk.setCenter(0, 0); //hay que configurar todos los setCenter y setSize
	Walk.setSize(0, altura);

	Idle.setCenter(0, 0);
	Idle.setSize(0, altura);

	Jump.setCenter(0, 0);
	Jump.setSize(0, altura);

	Dead.setCenter(0, 0);
	Dead.setSize(0, altura);

	//altura = 5; ¿ESTO NO SIRVE NO? Si ya se define arriba
	rojo = 255;
	verde = 0;
	azul = 0;
	posicion = 0;
	velocidad = 0;
	aceleracion = 0;
}

Hombre::~Hombre() //pa que
{
}

// Metodos GLUT 

void Hombre::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3ub(rojo, verde, azul);

	if (velocidad.x > 0.01 && vida > 0)
	{
		Walk.flip(false, false);
		Jump.flip(false, false);
	}
	else if (velocidad.x < -0.01 && vida > 0)
	{
		Walk.flip(true, false);
		Jump.flip(true, false);

	}

	if (velocidad.x < 0.01 && velocidad.x > -0.01 && velocidad.y == 0 && vida > 0)
	{
		Idle.setState(0);
		Idle.draw();
	}

	if (velocidad.y == 0 && (velocidad.x > 0.1 || velocidad.x < -0.1) && vida > 0)
	{
		Walk.draw();
	}
	if (velocidad.y != 0 && vida > 0)
	{
		Jump.draw();

	}
	if (vida <= 0)
	{
		Dead.draw();
	}

	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
void Hombre::Mueve(float t)
{
	if (vida > 0)
	{
		posicion = posicion + velocidad * t + aceleracion * (0,5f * t * t);
		velocidad = velocidad + aceleracion * t;
		Walk.loop();
		Jump.loop();
	}
}


// Metodos Set

void Hombre::SetAltura(double _a)
{
	altura = _a;
}


void Hombre::SetPosicion(double _x, double _y)
{
	posicion.SetCoordenadas(_x, _y);

}

void Hombre::SetPosicion(Vector2D _xy)
{
	posicion = _xy;
}


void Hombre::SetVelocidad(double _vx, double _vy)
{
	velocidad.SetCoordenadas(_vx, _vy);

}
void Hombre::SetAceleracion(double _ax, double _ay)
{
	aceleracion.SetCoordenadas(_ax, _ay);

}

void Hombre::SetVida(int _vida)
{
	vida = _vida;
}

// Metodos Get

float Hombre::GetAltura()
{
	return altura;
}

float Hombre::GetXPosicion()
{
	return posicion.x;
}
float Hombre::GetYPosicion()
{
	return posicion.y;
}
float Hombre::GetXVelocidad()
{
	return velocidad.x;
}
float Hombre::GetYVelocidad()
{
	return velocidad.y;
}
float Hombre::GetXAceleracion()
{
	return aceleracion.x;
}
float Hombre::GetYAceleracion()
{
	return aceleracion.y;
}

Vector2D Hombre::GetPosicion()
{
	return posicion;
}

int Hombre::GetVida()
{
	return vida;
}