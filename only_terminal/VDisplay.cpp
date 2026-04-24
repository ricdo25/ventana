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

#include "VDisplay.h"
#include <iostream>
#include <string>

// Metodo constructor
VDisplay::VDisplay(){
    textoDisplay = "";
}

void VDisplay::setTextoDisplay(std::string auxTexto){
    textoDisplay = auxTexto;
}

void VDisplay::mostrarDisplay(){
    std::cout<<"^-> "<< textoDisplay;
}

void VDisplay::waitForKeyPress() {
    std::cout << "\n Presiona cualquier tecla para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void VDisplay::mostrartipocalculadora(double num1, int choice, double num2) {
    if (choice == 1){
        std::cout << num1 << "+" << num2;
    } else if (choice == 2){
        std::cout << num1 << "-" << num2;
    } if (choice == 3){
        std::cout << num1 << "*" << num2;
    } else if (choice == 4){
        std::cout << num1 << "/" << num2;
    } if (choice == 5){
        std::cout << num1 << "^2";
    }
    std::cout << "\n1\t2\t3\t+\n4\t5\t6\t-\n7\t8\t9\t*\n\t0\t\t/\n";
}

void VDisplay::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    //   system("clear");
#endif
}