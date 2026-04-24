/*
Información CRC:

Clase: CNumeros

Responsabilidades:
- Almacenar temoporalmente los datos de la operacion de la calculadora.
- Puede presentar número.

Colaboradores:

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.

  
    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Marzo 2026
*/

#ifndef CNUMEROS_H
#define CNUMEROS_H

#include <string>
	class CNumeros {
	private:
		double numero;
	public:
		CNumeros();
		void setNumero(double auxNumero);
		void setNumeroCIN();
		double getNumero();
		std::string getNumeroString();
	};

#endif // CNUMEROS_H
