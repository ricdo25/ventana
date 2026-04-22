#include <string>
#include <vector>
#include <cctype>

class Calculadora {
private:
    std::string pantalla;

    bool esOperador(char c);
    double evaluarExpresion(const std::string& expr);
public:
    Calculadora();

    void agregarDigito(char digito);
    void agregarPunto();
    void agregarOperador(char op);

    void borrarUno();      // <-
    void borrarTodo();     // C
    void borrarUltimo();  // CE

    void inverso();        // 1/x
    void porcentaje();     // %
    void igual();          // =

    std::string obtenerPantalla() const;


};