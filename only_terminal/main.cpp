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
#include "CNumeros.h"
#include "COperacion.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	VDisplay display;
	CNumeros numeroA,numeroB;
	COperacion operacion;
    int choice;
    double num1{}, num2{};
    double resultado;

    while(true){
        display.clearConsole();
	std::cout <<
             "CALCULADORA RICARDITO\n";

        std::cout << "1. Suma\n";
        std::cout << "2. Resta\n";
        std::cout << "3. Multiplicación\n";
        std::cout << "4. División\n";
        std::cout << "5. Potencia (^2)\n";
        std::cout << "6. Salir\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar cualquier entrada extra

        switch (choice) {
        case 1:
            display.clearConsole();
            display.mostrarOperacion(0, choice, 0);
            display.mostrartipocalculadora();
            cin >> num1;
            display.clearConsole();
            display.mostrarOperacion(num1, choice, 0);
            display.mostrartipocalculadora();
            cin >> num2;
            resultado = operacion.suma(num1, num2);
            display.clearConsole();
            display.mostrarOperacion(num1, choice, num2);
            display.setTextoDisplay(to_string(resultado));
            display.mostrarDisplay();
            display.waitForKeyPress();
            break;
        case 2:
            display.clearConsole();
            display.mostrarOperacion(0, choice, 0);
            display.mostrartipocalculadora();
            cin >> num1;
            display.clearConsole();
            display.mostrarOperacion(num1, choice, 0);
            display.mostrartipocalculadora();
            cin >> num2;
            resultado = operacion.resta(num1, num2);
            display.clearConsole();
            display.mostrarOperacion(num1, choice, num2);
            display.setTextoDisplay(to_string(resultado));
            display.mostrarDisplay();
            display.waitForKeyPress();
            break;
        case 3:
            display.clearConsole();
            display.mostrarOperacion(0, choice, 0);
            display.mostrartipocalculadora();
            cin >> num1;
            display.clearConsole();
            display.mostrarOperacion(num1, choice, 0);
            display.mostrartipocalculadora();
            cin >> num2;
            resultado = operacion.multiplicacion(num1, num2);
            display.clearConsole();
            display.mostrarOperacion(num1, choice, num2);
            display.setTextoDisplay(to_string(resultado));
            display.mostrarDisplay();
            display.waitForKeyPress();
            break;
        case 4:
            display.clearConsole();
            display.mostrarOperacion(0, choice, 0);
            display.mostrartipocalculadora();
            cin >> num1;
            display.clearConsole();
            display.mostrarOperacion(num1, choice, 0);
            display.mostrartipocalculadora();
            cin >> num2;
            resultado = operacion.division(num1, num2);
            display.clearConsole();
            display.mostrarOperacion(num1, choice, num2);
            display.setTextoDisplay(to_string(resultado));
            display.mostrarDisplay();
            display.waitForKeyPress();
            break;
        case 5:
            display.clearConsole();
            display.mostrarOperacion(0, choice, 0);
            display.mostrartipocalculadora();
            cin >> num1;
            resultado = operacion.potencia(num1);
            display.clearConsole();
            display.mostrarOperacion(num1, choice, 0);
            display.setTextoDisplay(to_string(resultado));
            display.mostrarDisplay();
            display.waitForKeyPress();
            break;
        case 6:
            std::cout << "Gracias por usar la calculadora Ricardito" << std::endl;
            return 0;
        default:
            std::cout << "Opción no válida. Inténtalo de nuevo.\n";
            break;
        }
    }
    
    }