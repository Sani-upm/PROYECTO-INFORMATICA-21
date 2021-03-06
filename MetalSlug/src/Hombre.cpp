#include"Hombre.h"
#include"freeglut.h"
#include"ETSIDI.h"

Hombre::Hombre() :Walk("bin/Imagenes/walk.png",3,1,60), Idle("bin/Imagenes/parado.png",5,1,20), Jump("bin/Imagenes/jump2.png", 2,1,550), Dead("bin/Imagenes/dead.png",1,1,50)
{
	SetVida(1); //que el personaje tenga 1 vida
	SetAltura(10); 

	Walk.setCenter(5, 3); 
	Walk.setSize(8, altura);

	Idle.setCenter(5, 3);
	Idle.setSize(8, altura);

	Jump.setCenter(5, 1);
	Jump.setSize(8, altura);

	Dead.setCenter(5, 1);
	Dead.setSize(10, 7);

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
	glPushMatrix();
	glTranslatef(posicion.GetX(), posicion.GetY(), 0);
	//glColor3ub(rojo, verde, azul);

	if (velocidad.GetX() > 0.01 && vida > 0)
	{
		Walk.flip(false, false);
		Jump.flip(false, false);
	}
	else if (velocidad.GetX() < -0.01 && vida > 0)
	{
		Walk.flip(true, false);
		Jump.flip(true, false);

	}

	if (velocidad.GetX() < 0.01 && velocidad.GetX() > -0.01 && velocidad.GetY() == 0 && vida > 0)
	{
		Idle.setState(1);
		Idle.draw();
	}

	if (velocidad.GetY() == 0 && (velocidad.GetX() > 0.1 || velocidad.GetX() < -0.1) && vida > 0)
	{
		Walk.draw();
	}
	if (velocidad.GetY() != 0 && vida > 0)
	{
		Jump.draw();

	}
	if (vida <= 0)
	{
		Dead.draw();
	}

	glTranslatef(-posicion.GetX(), -posicion.GetY(), 0);
	glPopMatrix();
}
void Hombre::Mueve(float t)
{
	if (vida > 0)
	{
		posicion = posicion + velocidad * t + aceleracion * (0, 5 * t * t);
		velocidad = velocidad + aceleracion * t;
		Walk.loop();
		Jump.loop();
	}
}


// Metodos Set

void Hombre::SetAltura(float _a)
{
	altura = _a;
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

int Hombre::GetVida()
{
	return vida;
}

void Hombre::SetSalto(int s)
{
	Salto_cargado = s;
}

int Hombre::GetSalto()
{
	return Salto_cargado;
}