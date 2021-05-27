#include "Mundo.h"
#include <math.h>
#include "freeglut.h"
#include"Interaccion.h"

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

bool Mundo::CargarNivel()
{
	nivel++;
	jugador.SetVida(vidas);
	jugador.SetPosicion(0, 10);
	jugador.SetVelocidad(0, 0);
	jugador.SetAceleracion(0, -100);

	disparos.DestruirContenido();
	niveles.plataformas.DestruirContenido();

	if (nivel == 1)
	{
		checkpoint = 0;

		

		niveles.SetLvlTutorial();
		return true;
	}
}
void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 10;
	z_ojo = 100;//75;


	suelo.SetColor(255, 255, 0);
	suelo.SetPos2(-40, -20, 0.3, 120);

	jugador.SetPosicion(0, 10);
	jugador.SetVelocidad(0, 0);
	jugador.SetAceleracion(0, -100);

	if (checkpoint == -1)
		nivel = 0;
	else
		nivel = checkpoint - 1;

	CargarNivel();

}
void Mundo::Dibuja()
{
	x_ojo = jugador.GetXPosicion();

	gluLookAt(x_ojo, y_ojo, z_ojo,		  // posicion del ojo
		x_ojo, 0, 0.0,				 // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);			 // definimos hacia arriba (eje Y)    

	suelo.Dibuja();
	jugador.Dibuja();
	dragon.Dibuja();
	disparos.Dibuja();

	if (nivel == 1)
	{
		niveles.DibujarLvlTutorial();
	}


}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
	case ' ':
		
	if(jugador.GetXVelocidad() >=0)
		{
		Disparo* d = new Disparo();
		d->SetPos(jugador.GetPosicion().x + 3.0f, (jugador.GetPosicion().y + (jugador.GetAltura() / 2)));
		d->SetVel(100.0f, 0.0f);

		disparos.Agregar(d);

		break;
		}
	
	if (jugador.GetXVelocidad() < 0)
	{
		Disparo* d = new Disparo();
		d->SetPos(jugador.GetPosicion().x + 3.0f, (jugador.GetPosicion().y + (jugador.GetAltura() / 2)));
		d->SetVel(-100.0f, 0.0f);

		disparos.Agregar(d);

		break;
	}

	}
	

	

}

void Mundo::TeclaEspecial(unsigned char _key)
{
	switch (_key)
	{
	case GLUT_KEY_LEFT:
		jugador.SetVelocidad(-35.0f, jugador.GetYVelocidad());
		break;
	case GLUT_KEY_RIGHT:
		jugador.SetVelocidad(35.0f, jugador.GetYVelocidad());
		break;

	case GLUT_KEY_UP:
		//if ((jugador.GetYPosicion() == 0)) //|| jugador.GetYPosicion() == 11 || remy.GetYPosicion() == 21 || remy.GetYPosicion() == 31 || remy.GetYPosicion() == 41 || remy.GetYPosicion() == 51 || remy.GetYPosicion() == 61)
		int s = jugador.GetSalto();
		if (s == 1)
		{
			jugador.SetVelocidad(jugador.GetXVelocidad(), 80);
			jugador.SetSalto(0);
		}
		//	ETSIDI::play("sonidos/SaltoRemy.mp3");

		break;
	}
}

void Mundo::TeclaArriba(unsigned char _key)
{
	switch (_key)
	{
	case GLUT_KEY_LEFT:
		jugador.SetVelocidad(0, jugador.GetYVelocidad());
		break;
	case GLUT_KEY_RIGHT:
		jugador.SetVelocidad(0, jugador.GetYVelocidad());
		break;
	}
}

void Mundo::Mueve()
{
	//esfera.Mueve();

	//Movimientos de las clases
	jugador.Mueve(0.025f);
	dragon.Mueve(0.025f);
	disparos.Mueve(0.025);

	//Interacciones entre las clases
	Interaccion::Rebote(jugador, suelo);
	Interaccion::Rebote(jugador, nivel);
	Interaccion::Rebote(jugador, niveles);


}

