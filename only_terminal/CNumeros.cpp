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
#include "CNumeros.h"
#include <iostream>
#include <string>

// Constructor
CNumeros::CNumeros() {
    numero = 0.0;
}


// Setter
void CNumeros::setNumero(double auxNumero) {
    numero = auxNumero;
}

// Setter
void CNumeros::setNumeroCIN() {
	std::cin>>numero;
}

// Getter
double CNumeros::getNumero() {
    return numero;
}

// Getter
std::string CNumeros::getNumeroString() {
    return std::to_string(numero);
}