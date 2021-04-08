#pragma once
class Esfera
{
public:


	float			radio;
	float				x;
	float				y;
	unsigned char	 rojo;
	unsigned char	verde;
	unsigned char	 azul;

	Esfera();
	~Esfera();
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetRadio(float r);
	void SetPos(float ix, float iy);
	void Dibuja();
	void Mueve();

private:

};



