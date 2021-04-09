#pragma once
class Esfera
{
public:


	double			radio;
	double				x;
	double				y;
	unsigned char	 rojo;
	unsigned char	verde;
	unsigned char	 azul;

	Esfera();
	~Esfera();
	
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetRadio(double r);
	void SetPos(double ix, double iy);
	void Inicializa(unsigned char r, unsigned char g, unsigned char a, double rr, double ix, double iy);
	void Dibuja();
	void Mueve();

private:

};
