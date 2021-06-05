
#include "Niveles.h"

void Niveles::SetLvl1()
{
	Pared* aux = new Pared(-5, -12, 0.0f, 18);
	plataformas.Agregar(aux);
	aux = new Pared(40, 1, 0.0f, 27);
	plataformas.Agregar(aux);
	aux = new Pared(-80, -21, 0.0f, 68);
	plataformas.Agregar(aux);
	aux = new Pared(23, -21, 0.0f, 63);
	plataformas.Agregar(aux);
	aux = new Pared(53, 14, 0.0f, 75);
	plataformas.Agregar(aux);
	aux = new Pared(140, 2, 0.0f, 18);
	plataformas.Agregar(aux);
	aux = new Pared(143, -21, 0.0f, 77);
	plataformas.Agregar(aux);
	
}

void Niveles::SetLvl2()
{
	Pared* aux = new Pared(-13, -13, 0.0f, 19); // 3
	plataformas.Agregar(aux);
	aux = new Pared(92, -4, 0.0f, 28);// 5
	plataformas.Agregar(aux);
	aux = new Pared(-80, -4, 0.0f, 38);// 1
	plataformas.Agregar(aux);
	aux = new Pared(-45, -13, 0.0f, 20);// 2
	plataformas.Agregar(aux);
	aux = new Pared(132, 16, 0.0f, 21); //6
	plataformas.Agregar(aux);
	aux = new Pared(26, 5, 0.0f, 38);// 4
	plataformas.Agregar(aux);
	aux = new Pared(161, -12, 0.0f, 10);// 7
	plataformas.Agregar(aux);
	aux = new Pared(171, -3, 0.0f, 29);// 8 
	plataformas.Agregar(aux);
	aux = new Pared(199, -20, 0.0f, 21);// 9 
	plataformas.Agregar(aux);
}

void Niveles::SetLvl3()
{
	Pared* aux = new Pared(-12.5, -16.5, 0.0f, 29); // 3
	plataformas.Agregar(aux);
	aux = new Pared(44, 8, 0.0f, 19);// 5
	plataformas.Agregar(aux);
	aux = new Pared(-80, -19.5, 0.0f, 38);// 1
	plataformas.Agregar(aux);
	aux = new Pared(-69, 16, 0.0f, 39.5);// 2
	plataformas.Agregar(aux);
	aux = new Pared(59, -18.5, 0.0f, 57); //6
	plataformas.Agregar(aux);
	aux = new Pared(-2, 10, 0.0f, 19.5);// 4
	plataformas.Agregar(aux);
	aux = new Pared(72, -5, 0.0f, 39);// 7
	plataformas.Agregar(aux);
	aux = new Pared(85, 19.5, 0.0f, 40);// 8 
	plataformas.Agregar(aux);
	aux = new Pared(150, -11.5, 0.0f, 19);// 9 
	plataformas.Agregar(aux);
	aux = new Pared(182, 10, 0.0f, 38);// 10 
	plataformas.Agregar(aux);
}

void Niveles::DibujarLvl1()
{
	//AQUI SE PINTA LAS PLATAFORMAS

	plataformas.Dibuja();
	//quesos.Dibuja();
	//bombas.Dibuja();
	//vidas.Dibuja();
	
	//AQUI SE PINTA LA PARED DEL PRINCIPIO
	glBegin(GL_POLYGON);
	glColor3ub(20, 60, 32);
	glVertex3f(-150, -10, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-150, 90, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, 90, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, -10, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, -10, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, -10, -10);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, 90, -10);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, 90, 1);
	glEnd();
	//AQUI SE PINTA LA PARED FINAL
	glBegin(GL_POLYGON);
	glColor3ub(20, 32, 64);
	glVertex3f(800, -10, -10);
	glColor3ub(20, 32, 64);
	glVertex3f(800, 90, -10);
	glColor3ub(20, 32, 64);
	glVertex3f(880, 90, -10);
	glColor3ub(20, 32, 64);
	glVertex3f(880, -10, -10);
	glEnd();

	//AQUI SE PINTA EL FONDO
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-80, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(220, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(220, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(-80, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	
}

void Niveles::DibujarLvl2()
{
	//AQUI SE PINTA LAS PLATAFORMAS

	plataformas.Dibuja();
	//quesos.Dibuja();
	//bombas.Dibuja();
	//vidas.Dibuja();

	//AQUI SE PINTA LA PARED DEL PRINCIPIO
	glBegin(GL_POLYGON);
	glColor3ub(20, 60, 32);
	glVertex3f(-150, -10, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-150, 90, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, 90, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, -10, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, -10, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, -10, -10);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, 90, -10);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, 90, 1);
	glEnd();
	//AQUI SE PINTA LA PARED FINAL
	glBegin(GL_POLYGON);
	glColor3ub(20, 32, 64);
	glVertex3f(800, -10, -10);
	glColor3ub(20, 32, 64);
	glVertex3f(800, 90, -10);
	glColor3ub(20, 32, 64);
	glVertex3f(880, 90, -10);
	glColor3ub(20, 32, 64);
	glVertex3f(880, -10, -10);
	glEnd();

	//AQUI SE PINTA EL FONDO

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-80, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(220, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(220, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(-80, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Niveles::DibujarLvl3()
{
	//AQUI SE PINTA LAS PLATAFORMAS

	plataformas.Dibuja();
	//quesos.Dibuja();
	//bombas.Dibuja();
	//vidas.Dibuja();

	//AQUI SE PINTA LA PARED DEL PRINCIPIO
	glBegin(GL_POLYGON);
	glColor3ub(20, 60, 32);
	glVertex3f(-150, -10, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-150, 90, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, 90, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, -10, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, -10, 1);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, -10, -10);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, 90, -10);
	glColor3ub(20, 60, 32);
	glVertex3f(-80, 90, 1);
	glEnd();
	//AQUI SE PINTA LA PARED FINAL
	glBegin(GL_POLYGON);
	glColor3ub(20, 32, 64);
	glVertex3f(800, -10, -10);
	glColor3ub(20, 32, 64);
	glVertex3f(800, 90, -10);
	glColor3ub(20, 32, 64);
	glVertex3f(880, 90, -10);
	glColor3ub(20, 32, 64);
	glVertex3f(880, -10, -10);
	glEnd();

	//AQUI SE PINTA EL FONDO

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/Imagenes/nivel3.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-80, 38, -10);
	glTexCoord2d(1, 0); glVertex3f(220, 38, -10);
	glTexCoord2d(1, 1); glVertex3f(220, -43, -10);
	glTexCoord2d(0, 1); glVertex3f(-80, -43, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Niveles::Mueve(float _t)
{

}