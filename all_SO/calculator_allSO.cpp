#include "calculator_allSO.h"
#include <vector>
#include <cctype>
#include <stdexcept>

Calculadora::Calculadora() {
    pantalla = "";
}

bool Calculadora::esOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void Calculadora::agregarDigito(char digito) {
    if (isdigit(digito)) {
        pantalla += digito;
    }
}

void Calculadora::agregarPunto() {
    size_t pos = pantalla.find_last_of("+-*/");
    std::string actual;

    if (pos == std::string::npos)
        actual = pantalla;
    else
        actual = pantalla.substr(pos + 1);

    if (actual.find('.') == std::string::npos && !pantalla.empty() && isdigit(pantalla.back())) {
        pantalla += '.';
    }
}

void Calculadora::agregarOperador(char op) {
    if (!pantalla.empty() && (isdigit(pantalla.back()) || pantalla.back() == '.')) {
        pantalla += op;
    }
}

void Calculadora::borrarUno() {
    if (!pantalla.empty()) {
        pantalla.pop_back();
    }
}

void Calculadora::borrarTodo() {
    pantalla = "";
}

void Calculadora::borrarUltimo() {
    size_t pos = pantalla.find_last_of("+-*/");

    if (pos != std::string::npos) {
        pantalla = pantalla.substr(0, pos + 1);
    } else {
        pantalla = "";
    }
}

double Calculadora::evaluarExpresion(const std::string& expr) {
    std::vector<double> numeros;
    std::vector<char> ops;
    std::string num = "";

    for (char c : expr) {
        if (isdigit(c) || c == '.') {
            num += c;
        } else if (esOperador(c)) {
            if (num.empty()) throw std::runtime_error("Error");
            numeros.push_back(std::stod(num));
            num = "";
            ops.push_back(c);
        }
    }

    if (num.empty()) throw std::runtime_error("Error");
    numeros.push_back(std::stod(num));

    for (size_t i = 0; i < ops.size();) {
        if (ops[i] == '*' || ops[i] == '/') {
            double res;

            if (ops[i] == '*') {
                res = numeros[i] * numeros[i + 1];
            } else {
                if (numeros[i + 1] == 0) throw std::runtime_error("Error");
                res = numeros[i] / numeros[i + 1];
            }

            numeros[i] = res;
            numeros.erase(numeros.begin() + i + 1);
            ops.erase(ops.begin() + i);
        } else {
            i++;
        }
    }

    double resultado = numeros[0];

    for (size_t i = 0; i < ops.size(); i++) {
        if (ops[i] == '+')
            resultado += numeros[i + 1];
        else if (ops[i] == '-')
            resultado -= numeros[i + 1];
    }

    return resultado;
}

void Calculadora::igual() {
    if (pantalla.empty()) return;

    double resultado = evaluarExpresion(pantalla);
    pantalla = std::to_string(resultado);
}

void Calculadora::inverso() {
    if (pantalla.empty()) return;

    double resultado = evaluarExpresion(pantalla);
    if (resultado == 0) throw std::runtime_error("Error");

    pantalla = std::to_string(1.0 / resultado);
}

void Calculadora::porcentaje() {
    if (pantalla.empty()) return;

    size_t pos = pantalla.find_last_of("+-*/");

    if (pos == std::string::npos) {
        double num = std::stod(pantalla);
        pantalla = std::to_string(num / 100.0);
        return;
    }

    std::string antes = pantalla.substr(0, pos + 1);
    std::string ultimo = pantalla.substr(pos + 1);
    char op = pantalla[pos];

    double A = std::stod(pantalla.substr(0, pos));
    double B = std::stod(ultimo);

    double res;
    if (op == '+' || op == '-') {
        res = A * B / 100.0;
    } else {
        res = B / 100.0;
    }

    pantalla = antes + std::to_string(res);
}

std::string Calculadora::obtenerPantalla() const {
    return pantalla;
}