#include "Mundo.h"
#include <math.h>
#include "freeglut.h"
#include"Interaccion.h"

Mundo::Mundo()
{
	x_ojo = -30;
	y_ojo = 10;
	z_ojo = 7.5;

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
	jugador.setPos(-75, 10);
	jugador.setVel(0, 0);
	jugador.setAcel(0, -100);

	disparos.DestruirContenido();
	niveles.plataformas.DestruirContenido();

	if (nivel == 1)
	{
		checkpoint = 0;

		niveles.SetLvl1();
		dragones.destruircontenido();
		disparos.DestruirContenido();
		llamas.DestruirContenido();
		Dragon* aux = new Dragon(8, 0, 0, 0, 0, 0);
		dragones.agregar(aux);
		aux = new Dragon(8, 0, 100, 18, 0, 0);
		dragones.agregar(aux);

		return true;
	}
	else if (nivel == 2)
	{
		checkpoint = 1;

		niveles.SetLvl2();
		dragones.destruircontenido();
		disparos.DestruirContenido();
		llamas.DestruirContenido();

		Dragon* aux = new Dragon(8, 0, 20, 0, 0, 0);
		dragones.agregar(aux);
		aux = new Dragon(8, 0, 100, 18, 0, 0);
		dragones.agregar(aux);

		return true;
	}
	else if (nivel == 3)
	{
		checkpoint = 2;


		niveles.SetLvl3();
		dragones.destruircontenido();
		disparos.DestruirContenido();
		llamas.DestruirContenido();

		Dragon* aux = new Dragon(8, 0, 0, 0, 0, 0);
		dragones.agregar(aux);
		aux = new Dragon(8, 0, 100, 18, 0, 0);
		dragones.agregar(aux);
		return true;
	}
}
void Mundo::Inicializa()
{
	x_ojo = -30;
	y_ojo = 10;
	z_ojo = 100;//75;

	jugador.setPos(-75, 10);
	jugador.setVel(0, 0);
	jugador.setAcel(0, -100);

	if (checkpoint == -1)
		nivel = 0;
	else
		nivel = checkpoint - 1;

	CargarNivel();

}
void Mundo::Dibuja()
{
	x_ojo = jugador.getPos().x;

	gluLookAt(x_ojo, y_ojo, z_ojo,		  // posicion del ojo
		x_ojo, 0, 0.0,				 // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);			 // definimos hacia arriba (eje Y)    

	
	jugador.Dibuja();
	disparos.Dibuja();
	dragones.Dibuja();
	llamas.Dibuja();
			


	if (nivel == 1)
	{
		niveles.DibujarLvl1();
	}
	
	if (nivel == 2)
	{
		niveles.DibujarLvl2();

	}

	if (nivel == 3) 
	{
		niveles.DibujarLvl3();
	}

}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
	case ' ':
		
	if(jugador.getVel().x >=0)
		{
		Disparo* d = new Disparo();
		d->setPos(jugador.getPos().x + 3.0f, (jugador.getPos().y + (jugador.GetAltura() / 2)));
		d->setVel(100.0f, 0.0f);

		disparos.Agregar(d);

		break;
		}
	
	if (jugador.getVel().x < 0)
	{
		Disparo* d = new Disparo();
		d->setPos(jugador.getPos().x + 3.0f, (jugador.getPos().y + (jugador.GetAltura() / 2)));
		d->setVel(-100.0f, 0.0f);

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
		jugador.setVel(-30.0f, jugador.getVel().y);
		break;
	case GLUT_KEY_RIGHT:
		jugador.setVel(30.0f, jugador.getVel().y);
		break;

	case GLUT_KEY_UP:
		//if ((jugador.GetYPosicion() == 0)) //|| jugador.GetYPosicion() == 11 || remy.GetYPosicion() == 21 || remy.GetYPosicion() == 31 || remy.GetYPosicion() == 41 || remy.GetYPosicion() == 51 || remy.GetYPosicion() == 61)
		int s = jugador.GetSalto();
		if (s == 1)
		{
			jugador.setVel(jugador.getVel().x, 80);
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
		jugador.setVel(0, jugador.getVel().y);
		break;
	case GLUT_KEY_RIGHT:
		jugador.setVel(0, jugador.getVel().y);
		break;
	}
}

int Mundo::getDragones()
{
	int d = 0;
	for (int i = 0; i < dragones.getNumero(); i++)
	{
		if (dragones[i] != 0)
			d = 1;
	}
	return d;
}

void Mundo::Mueve()
{
	//Movimientos de las clases
	jugador.Mueve(0.025f);
	disparos.Mueve(0.025f);
	dragones.Mueve(0.025);
	llamas.Mueve(0.025);
	//Interacciones entre las clases

	Interaccion::Rebote(jugador, nivel);
	Interaccion::Rebote(jugador, niveles);

	for (int i = 0; i < dragones.getNumero(); i++)
	{
		Interaccion::Comportamiento_Dragon(*dragones[i], jugador);
	}

	for (int i = 0; i < disparos.GetNumero(); i++)
		for (int j = 0; j < dragones.getNumero(); j++)
		{
			bool impacto = Interaccion::Impacto_Dragon(*disparos[i], *dragones[j]);
			if (impacto == true)
			{
				disparos.Eliminar(i);
				dragones.eliminar(j);
			}
		}
	for (int i = 0; i < llamas.GetNumero(); i++)
	{
		bool impacto = Interaccion::Rebote_Ataque_Dragon(*llamas[i], jugador);
		if (impacto == true)
		{
			jugador.SetVida(0);
		}
	}


	for (int i = 0; i < dragones.getNumero(); i++)
	{
		if (dragones[i]->getAtaque() == 1) 
		{
			if(llamas.GetNumero()<1)
			{
				Fuego* aux = new Fuego();
				aux->setPos(dragones[i]->getPos().x + 3.0f, dragones[i]->getPos().y + 3);
				Vector2D direccion_unitaria = (jugador.getPos()-dragones[i]->getPos()).unitario();
				aux->setVel(30.0f *direccion_unitaria.x, 30.0f * direccion_unitaria.y);
				llamas.Agregar(aux);
				
			}
		}
	}
	for (int j = 0; j < llamas.GetNumero(); j++)
	{
			Vector2D distancia = jugador.getPos() - llamas[j]->getPos();
			float modulo = distancia.modulo();
			if (modulo > 100)
				llamas.Eliminar(j);
	}
}




void Mundo::SetVidas(int _vida)
{
	jugador.SetVida(_vida);
	vidas = _vida;
}

int Mundo::GetVida()
{
	return jugador.GetVida();
}


