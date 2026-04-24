
/*
Información CRC:

Clase: COperacion

Responsabilidades:
- Hacer la operacion de la calculadora.
- Guarda el resultado de la operacion como un  número.

Colaboradores:

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Marzo 2026
*/



#ifndef COPERACION_H
#define COPERACION_H
#include <string>

	class COperacion {
	private:
		double resultado;
	public:
		COperacion();
		double suma(double auxSumandoA, double auxSumandoB);
		double resta(double auxRestandoA, double auxRestandoB);
		double multiplicacion(double auxA, double auxB);
		double division(double auxdividendoA, double auxdivisorB);
		double potencia(double baseA);
		std::string getResultado();
	};

#endif // COPERACION_H

