#pragma once
#include "Mundo.h"
#include "ETSIDI.h"


class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();

	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char key);
	void Mueve();
	void TeclaEspecial(int key);
	void TeclaArriba(int key);

protected:
	Mundo mundo;

	enum Estado{INICIO, INSTRUCCIONES, JUEGO, EXITO, GAMEOVER, PAUSA};
	Estado estado;
};