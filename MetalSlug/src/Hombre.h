#pragma once
#include"Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using ETSIDI::SpriteSequence;

class Hombre: public ObjetoMovil
{
private:
	SpriteSequence Walk;
	SpriteSequence Idle;
	SpriteSequence Jump;
	SpriteSequence Dead;

	float altura;
	int vida;
	int Salto_cargado;
	
public:
	Hombre();
	~Hombre(); 

	void Dibuja();
	void Mueve(float t);

	void SetVida(int _vida);
	void SetAltura(float _a);
	void SetSalto(int s);

	float GetAltura();
	int GetSalto();
	int GetVida();

	friend class Interaccion;
};