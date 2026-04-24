/*
Información CRC:

Clase: VDisplay

Responsabilidades:
- Presentar en pantalla los datos de la calculadora.
- Puede presentar número u operaciones.

Colaboradores:

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.

    
    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Marzo 2026
*/


#ifndef VDISPLAY_H
#define VDISPLAY_H

#include <string>

	class VDisplay {
	private:
		std::string textoDisplay;
	public:
		VDisplay();
		void setTextoDisplay(std::string auxTexto);
		void mostrarDisplay();
		void waitForKeyPress() ;
		void clearConsole();
		void mostrartipocalculadora(double num1, int choice, double num2);
	};

#endif // VDISPLAY_H
