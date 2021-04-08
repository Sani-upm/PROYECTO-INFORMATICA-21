// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>


#include "freeglut.h"
#include "Esfera.h"
#include "Mundo.h"

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
float         radio_esfera = 2.0f;
float         x_esfera = 0.0f;
float         y_esfera = 0.0f;
unsigned char rojo_esfera = 255;
unsigned char verde_esfera = 0;
unsigned char azul_esfera = 255;

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 10, 20,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo
	glColor3ub(rojo_esfera, verde_esfera, azul_esfera);
	glTranslatef(x_esfera, y_esfera, 0);
	glutSolidSphere(radio_esfera, 20, 20);
	glTranslatef(-x_esfera, y_esfera, 0);

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	if (key == '+' && radio_esfera < 3)
		radio_esfera += 0.5f;
	if (key == '-' && radio_esfera > 1)
		radio_esfera -= 0.5f;
	if (key == 'r')
	{
		rojo_esfera = 255;
		verde_esfera = 0;
		azul_esfera = 0;
	}
	if (key == 'g')
	{
		rojo_esfera = 0;
		verde_esfera = 255;
		azul_esfera = 0;
	}
	if (key == 'b')
	{
		rojo_esfera = 0;
		verde_esfera = 0;
		azul_esfera = 255;
	}
	if (key == 'a')			//izq, X negativo
		x_esfera -= 0.1f;
	if (key == 'd')			//drch, X positivo
		x_esfera += 0.1f;
	if (key == 'w')			//izq, Y positivo
		y_esfera += 0.1f;
	if (key == 's')			//izq, Y negativo
		y_esfera -= 0.1f;
	glutPostRedisplay();

}

void OnTimer(int value)
{

}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
