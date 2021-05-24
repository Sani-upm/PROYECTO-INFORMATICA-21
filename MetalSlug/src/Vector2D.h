#pragma once

class Vector2D
{
public:

	~Vector2D();
	float x, y;

	//Metodos Set
	void SetCoordenadas(float _x, float _y);

	//Metodos Get
	float GetX();
	float GetY();



	Vector2D(float xv = 0.0f, float yv = 0.0f); // (1)constructor
	float modulo();								// (2) modulo del vector
	float argumento();							// (3) argumento del vector
	Vector2D unitario();						// (4) devuelve un vector unitario
	Vector2D operator - (Vector2D);				// (5) resta de vectores
	Vector2D operator + (Vector2D);				// (6) suma de vectores
	Vector2D operator + (float real);
	float operator *(Vector2D);					// (7) producto escalar
	Vector2D operator *(float);				    // (8) producto por un escalar
	float Angulo(Vector2D);						// (9) angulo entre dos vectores
private:

};
