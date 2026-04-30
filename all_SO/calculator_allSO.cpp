#include "calculator_allSO.h"
#include <vector>
#include <cctype>
#include <stdexcept>

//npos= valor especial que significa no encontrado
//Constructor
Calculadora::Calculadora() {
    pantalla = "";
}

bool Calculadora::esOperador(char c) { //verifica si un carácter es un operador que se pueda poner
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void Calculadora::agregarDigito(char digito) { 
    if (isdigit(digito)) { //solo acepta digitos
        pantalla += digito;
    }
}

void Calculadora::agregarPunto() { 
    size_t pos = pantalla.find_last_of("+-*/"); //busca el ultimo operador para no confundir con otro numero
    std::string actual;

    if (pos == std::string::npos) //si no hay operador entonces todo es un numero
        actual = pantalla;
    else
        actual = pantalla.substr(pos + 1); //numero después del operador

        //Lógica: Solo agrega punto si: no hay otro punto en el numero actual, si la pantalla no esta vacia y si el ultimo caracter es un numero
    if (actual.find('.') == std::string::npos && !pantalla.empty() && isdigit(pantalla.back())) {
        pantalla += '.';
    }
}

void Calculadora::agregarOperador(char op) { 
    //Lógica: Solo agrega el operador si: la pantalla no esta vacia, el ultimo numero es un digito y si el ultimo no es un punto
    if (!pantalla.empty() && (isdigit(pantalla.back()) || !pantalla.back() == '.')) {
        pantalla += op;
    }
}

void Calculadora::borrarUno() {
    if (!pantalla.empty()) {
        pantalla.pop_back(); //se elimina el ultimo (<-)
    }
}

void Calculadora::borrarTodo() {
    pantalla = "";
}

void Calculadora::borrarUltimo() { 
    size_t pos = pantalla.find_last_of("+-*/");

    if (pos != std::string::npos) {
        pantalla = pantalla.substr(0, pos + 1); //deja solo hasta el operador
    } else { //si no hay operadores borra todo
        pantalla = "";
    }
}

double Calculadora::resultadoExpresion(const std::string& expr) {
    std::vector<double> numeros; //almacena números
    std::vector<char> ops; //almacena operadores
    std::string num = ""; //construye números carácter por carácter

    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i]; //Separar números y operadores
        if (isdigit(c) || c == '.') {
            num += c; //construir número
        } else if (esOperador(c)) {
            if (num.empty()) throw std::runtime_error("Error"); //si num está vacío entonces aparecio un operador sin haber un numero antesito
            numeros.push_back(std::stod(num)); //convierte de string a double y lo sube al vector
            num = ""; //reinicio a num para construir otro numero
            ops.push_back(c); //se guarda el ultimo operador
        }
    }

    if (num.empty()) throw std::runtime_error("Error"); //verifico que si haya quedado un ultimo numero valido, no 5+
    numeros.push_back(std::stod(num)); //convierte de string a double y lo sube al vector

    for (size_t i = 0; i < ops.size();) { //recorrido por los operadores 
        if (ops[i] == '*' || ops[i] == '/') { // para resolver primero multiplicaciones y divisiones
            double res; //para el resultado de esa operacion

            if (ops[i] == '*') {
                res = numeros[i] * numeros[i + 1]; //multiplica el número actual con el siguiente
            } else {
                if (numeros[i + 1] == 0) throw std::runtime_error("Error"); //que el denominador no sea 0
                res = numeros[i] / numeros[i + 1]; //divide el número actual con el siguiente
            }

            numeros[i] = res; //se reemplaza el primer numero de la operacion por el resultado
            numeros.erase(numeros.begin() + i + 1); //se elimina el segundo numero porque ya fue usado
            ops.erase(ops.begin() + i); //el operador se elimina pues ya fue usado
        } else {
            i++; //se avanza al siguiente operador
        }
    }

    double resultado = numeros[0]; //tomar el primer numero del vector numeros para + o -

    for (size_t i = 0; i < ops.size(); i++) { //se resuelve por + o -
        if (ops[i] == '+')
            resultado += numeros[i + 1];
        else if (ops[i] == '-')
            resultado -= numeros[i + 1];
    }

    return resultado;
}

void Calculadora::igual() {
    if (pantalla.empty()) return;

    double resultado = resultadoExpresion(pantalla);
    pantalla = std::to_string(resultado); //pasa el resultado de double a string y lo muestra en pantalla
}

void Calculadora::inverso() {
    if (pantalla.empty()) {
        return;
    }
    double resultado = resultadoExpresion(pantalla);
    if (resultado == 0) throw std::runtime_error("Error");
    double inverso= 1.0 / resultado;
    pantalla = std::to_string(inverso);
}

void Calculadora::porcentaje() {
    if (pantalla.empty()) return;

    size_t pos = pantalla.find_last_of("+-*/");

    if (pos == std::string::npos) { //aca si solo hay un numero
        double num = std::stod(pantalla);
        pantalla = std::to_string(num / 100.0);
        return;
    }

    std::string antes = pantalla.substr(0, pos + 1); //guarda la parte de la expresion hasta el operador incluido
    std::string ultimo = pantalla.substr(pos + 1); //guarda la parte de la expresion despues del operador
    char op = pantalla[pos];

    double A = std::stod(pantalla.substr(0, pos)); //pasa a numero antes
    double B = std::stod(ultimo); //pasa a numero ultimo

    double res;
    if (op == '+' || op == '-') { //si el operador es + o -, se calcula el B% de A
        res = A * B / 100;
    } else { //si el operador es * o /, se calcula solo el % de B
        res = B / 100;
    }

    pantalla = antes + std::to_string(res); //reemplaza el ultimo numero por su equivalente en porcentaje
}

std::string Calculadora::obtenerPantalla() const {
    return pantalla;
}