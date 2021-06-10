#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado=INICIO;

}

Coordinador::~Coordinador()
{

}

void Coordinador::Inicializa()
{

}

void Coordinador::Dibuja()
{
	if (estado == INICIO)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/intro.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(-9.75, 7.35, -20);
		glTexCoord2d(1, 0); glVertex3f(9.75, 7.35, -20);
		glTexCoord2d(1, 1); glVertex3f(9.75, -7.35, -20);
		glTexCoord2d(0, 1); glVertex3f(-9.75, -7.35, -20);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}

	else if (estado == INSTRUCCIONES)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/instrucciones.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(-9.75, 7.35, -20);
		glTexCoord2d(1, 0); glVertex3f(9.75, 7.35, -20);
		glTexCoord2d(1, 1); glVertex3f(9.75, -7.35, -20);
		glTexCoord2d(0, 1); glVertex3f(-9.75, -7.35, -20);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else if (estado == JUEGO)
	{
		mundo.Dibuja();
	}
	
	else if (estado == PAUSA)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/pausa.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(-9.75, 7.35, -20);
		glTexCoord2d(1, 0); glVertex3f(9.75, 7.35, -20);
		glTexCoord2d(1, 1); glVertex3f(9.75, -7.35, -20);
		glTexCoord2d(0, 1); glVertex3f(-9.75, -7.35, -20);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		mundo.Dibuja();
	}

	else if (estado == GAMEOVER)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/gameover.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(-9.75, 7.35, -20);
		glTexCoord2d(1, 0); glVertex3f(9.75, 7.35, -20);
		glTexCoord2d(1, 1); glVertex3f(9.75, -7.35, -20);
		glTexCoord2d(0, 1); glVertex3f(-9.75, -7.35, -20);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else if (estado == EXITO)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/exito.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(-9.75, 7.35, -20);
		glTexCoord2d(1, 0); glVertex3f(9.75, 7.35, -20);
		glTexCoord2d(1, 1); glVertex3f(9.75, -7.35, -20);
		glTexCoord2d(0, 1); glVertex3f(-9.75, -7.35, -20);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
}

void Coordinador::Tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == ' ')
		{
			mundo.Inicializa();
			estado = INSTRUCCIONES;
		}
		if (key == 's' || key == 'S')
			exit(0);
	}
	else if (estado == INSTRUCCIONES)
	{
		if (key == ' ')
		{
			estado = JUEGO;
		}
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
		if (key == 'p' || key == 'P')
			estado = PAUSA;
	}
	
	else if (estado == PAUSA)
	{
		if (key == ' ')
		{
			estado = JUEGO;
		}
		if (key == 's' || key == 'S')
		{
			estado = INICIO;
		}
	}

	else if (estado == GAMEOVER)
	{
		if (key == ' ')
		{
			estado = INICIO;
		}
		if (key == 's' || key == 'S')
		{
			estado = INICIO;
		}
	}
	
	else if (estado == EXITO)
	{
		if (key == ' ')
		{
			estado = INICIO;
		}
		
		if (key == 's' || key == 'S')
			exit(0);
	}
}

void Coordinador::Mueve()
{
	if (estado == JUEGO)
	{
		mundo.Mueve();
	}
}

void Coordinador::TeclaEspecial(int key)
{
	if (estado == INSTRUCCIONES)
	{
		if (key == GLUT_KEY_LEFT)
		{
			estado = INICIO;
		}
	}

	if (estado == JUEGO)
	{
		//mundo.TeclaEspecial(key);
	}
}

void Coordinador::TeclaArriba(int key)
{
	//mundo.TeclaArriba(key);
}