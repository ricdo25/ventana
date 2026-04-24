/*
    Proyecto: Calculadora
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto simula una calculadora.
   

    Autores: Curso FPOO 2026
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2026
*/
#include "COperacion.h"
#include <string>
#include <stdexcept>

// Constructor: Inicializa el resultado en 0
COperacion::COperacion() {
	resultado = 0.0;
}

// Función suma: Suma dos números y guarda el resultado
double COperacion::suma(double auxSumandoA, double auxSumandoB) {
	resultado = auxSumandoA + auxSumandoB;
	return resultado;
}

// Función resta: Resta dos números y guarda el resultado
double COperacion::resta(double auxRestandoA, double auxRestandoB) {
	resultado = auxRestandoA - auxRestandoB;
	return resultado;
}

double COperacion::multiplicacion(double auxA, double auxB) {
	resultado = auxA * auxB;
	return resultado;
}

double COperacion::division(double auxdividendoA, double auxdivisorB) {
    if(auxdivisorB==0){
       throw std::runtime_error("Error: division por cero");
    } else {
        resultado = auxdividendoA / auxdivisorB;
        return resultado;
    }
    
	
}

double COperacion::potencia(double baseA) {
        resultado = baseA*baseA;
        return resultado;
}

std::string COperacion::getResultado(){
	return std::to_string(resultado);
}