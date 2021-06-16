
#pragma once
//#include "Esfera.h"
#include "Pared.h"
#include "Hombre.h"
#include "Dragon.h"
#include "ListaDisparos.h"
#include "Niveles.h"
#include "ListaDragon.h"
#include "ListaFuego.h"

class Mundo
{
public:

	//Metodos Inicializacion
	Mundo();
	~Mundo();

	//Metodos GLUT
	void RotarOjo();
	void Inicializa();
	void Dibuja();

	void Mueve();

	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	void TeclaArriba(unsigned char _key);
	int getDragones();

	 //Metodos Set
	void SetVidas(int);

	 //Metodos Get
	
	int GetVida();

	//Metodos de los niveles
	bool CargarNivel();

	int nivel = 0;
	int checkpoint = -1;
	int vidas =1;	
	
	Hombre jugador;
	ListaDragones dragones;
	ListaDisparos disparos;
	ListaFuego llamas;
	Niveles niveles;

private:
	double x_ojo;
	double y_ojo;
	double z_ojo;

	//Esfera esfera;
	//Pared  suelo;



};