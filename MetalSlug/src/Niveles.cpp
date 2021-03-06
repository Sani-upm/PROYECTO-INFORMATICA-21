
#include "Niveles.h"

void Niveles::SetLvl1()
{
	Pared* aux = new Pared(-5, -12, 0.0f, 18);
	plataformas.Agregar(aux);
	aux = new Pared(40, 1, 0.f, 27);
	plataformas.Agregar(aux);
	aux = new Pared(-80, -21, 0.0f, 69);
	plataformas.Agregar(aux);
	aux = new Pared(23, -21, 0.0f, 63);
	plataformas.Agregar(aux);
	aux = new Pared(53, 14, 0.0f, 75);
	plataformas.Agregar(aux);
	aux = new Pared(140, 2, 0.0f, 18);
	plataformas.Agregar(aux);
	aux = new Pared(143, -21, 0.0f, 90);
	plataformas.Agregar(aux);
	
}

void Niveles::SetLvl2()
{
	Pared* aux = new Pared(-24, -13, 0.0f, 17); // 3
	plataformas.Agregar(aux);
	aux = new Pared(65, -4, 0.0f, 23.5);// 5
	plataformas.Agregar(aux);
	aux = new Pared(-80, -4, 0.0f, 31);// 1
	plataformas.Agregar(aux);
	aux = new Pared(-50, -13, 0.0f, 17);// 2
	plataformas.Agregar(aux);
	aux = new Pared(98, 16, 0.0f, 16.5); //6
	plataformas.Agregar(aux);
	aux = new Pared(8, 5, 0.0f, 33);// 4
	plataformas.Agregar(aux);
	aux = new Pared(123, -12, 0.0f, 8.5);// 7
	plataformas.Agregar(aux);
	aux = new Pared(130.3, -3, 0.0f, 25.5);// 8 
	plataformas.Agregar(aux);
	aux = new Pared(155.5, -20, 0.0f, 33);// 9 
	plataformas.Agregar(aux);
	aux = new Pared(210, 3, 0.0f, 32); //10
	plataformas.Agregar(aux);
	aux = new Pared(268, 9.5, 0.0f, 15.5);// 11
	plataformas.Agregar(aux);
	aux = new Pared(305, -4, 0.0f, 32);// 12
	plataformas.Agregar(aux);
	aux = new Pared(364.5, 7.6, 0.0f, 24);// 13
	plataformas.Agregar(aux);
	aux = new Pared(426.5, -20.5, 0.0f, 45); //14
	plataformas.Agregar(aux);
	aux = new Pared(446, -5.2, 0.0f, 46);// 15
	plataformas.Agregar(aux);
	aux = new Pared(485, 11, 0.0f, 45.5);// 16
	plataformas.Agregar(aux);
	aux = new Pared(530.5, -15, 0.0f, 30);// 17
	plataformas.Agregar(aux);
}

void Niveles::SetLvl3()
{
	Pared* aux = new Pared(-22.5, -16.5, 0.0f, 25.5); // 3
	plataformas.Agregar(aux);
	aux = new Pared(25, 8.5, 0.0f, 15.5);// 5
	plataformas.Agregar(aux);
	aux = new Pared(-80, -19.5, 0.0f, 32);// 1
	plataformas.Agregar(aux);
	aux = new Pared(-70, 16, 0.0f, 33);// 2
	plataformas.Agregar(aux);
	aux = new Pared(38, -18.5, 0.0f, 46); //6
	plataformas.Agregar(aux);
	aux = new Pared(-14, 10, 0.0f, 15.5);// 4
	plataformas.Agregar(aux);
	aux = new Pared(48, -5, 0.0f, 33);// 7
	plataformas.Agregar(aux);
	aux = new Pared(60, 19.5, 0.0f, 32);// 8 
	plataformas.Agregar(aux);
	aux = new Pared(112, -12, 0.0f, 16);// 9 
	plataformas.Agregar(aux);
	aux = new Pared(140, 10, 0.0f, 41);// 10 
	plataformas.Agregar(aux);
	aux = new Pared(204, 10, 0.0f, 16);// 11
	plataformas.Agregar(aux);
	aux = new Pared(240, 10, 0.0f, 16);// 12
	plataformas.Agregar(aux);
	aux = new Pared(283, -3.5, 0.0f, 17);// 13
	plataformas.Agregar(aux);
	aux = new Pared(331, 9, 0.0f, 31.5); //14
	plataformas.Agregar(aux);
	aux = new Pared(387, -10.5, 0.0f, 32);// 15
	plataformas.Agregar(aux);
	aux = new Pared(433.5, 11.5, 0.0f, 16);// 16
	plataformas.Agregar(aux);
	aux = new Pared(473.5, -20.5, 0.0f, 16);// 17
	plataformas.Agregar(aux);
	aux = new Pared(489.5, -12, 0.0f, 16);// 18
	plataformas.Agregar(aux);
	aux = new Pared(505.5, -4.25, 0.0f, 16);// 19
	plataformas.Agregar(aux);
	aux = new Pared(521.5, 4, 0.0f, 71);// 20
	plataformas.Agregar(aux);
}

void Niveles::DibujarLvl1()
{
	//AQUI SE PINTA LAS PLATAFORMAS

	plataformas.Dibuja();
	//PARED INICIAL
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel1inicio.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-300, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(-79.5, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(-79.5, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(-300, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//PARED PRINCIPAL
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-80, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(221, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(221, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(-80, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	
	//PARED FINAL
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel1final.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(218, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(520, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(520, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(218, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Niveles::DibujarLvl2()
{
	//AQUI SE PINTA LAS PLATAFORMAS

	plataformas.Dibuja();

	//AQUI SE PINTA LA PARED DEL PRINCIPIO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel2inicio.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-709, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(-79.5, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(-79.5, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(-709, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//AQUI SE PINTA EL FONDO

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-80, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(551, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(551, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(-80, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	
	//AQUI SE PINTA LA PARED FINAL
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel2final.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(549, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(1180, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(1180, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(549, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Niveles::DibujarLvl3()
{
	//AQUI SE PINTA LAS PLATAFORMAS

	plataformas.Dibuja();

	//AQUI SE PINTA LA PARED DEL PRINCIPIO

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel3inicio.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-709, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(-79.5, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(-79.5, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(-709, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//AQUI SE PINTA LA PARED PRINCIPAL

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel3.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-80, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(551, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(551, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(-80, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);	
	
	//AQUI SE PINTA EL FONDO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel3final.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(549, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(1177.5, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(1177.5, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(549, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Niveles::Mueve(float _t)
{

}