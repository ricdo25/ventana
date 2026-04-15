#include <windows.h>
#include <string>
#include <vector>
#include <cctype>
HWND inputBox, otrico, outputBox;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch (uMsg){
    case WM_CREATE:
        // Input
        outputBox = CreateWindow("EDIT", "",
                                 WS_VISIBLE | WS_CHILD | WS_BORDER | ES_RIGHT,
                                 20, 50, 250, 20,
                                 hwnd, NULL, NULL, NULL);

        // Números
        CreateWindow("BUTTON", "0",
                     WS_VISIBLE | WS_CHILD ,
                     20, 200, 100, 30,
                     hwnd, (HMENU)10, NULL, NULL);

        CreateWindow("BUTTON", "1",
                     WS_VISIBLE | WS_CHILD ,
                     20, 170, 50, 30,
                     hwnd, (HMENU)1, NULL, NULL);

        CreateWindow("BUTTON", "2",
                     WS_VISIBLE | WS_CHILD,
                     70, 170, 50, 30,
                     hwnd, (HMENU)2, NULL, NULL);
        CreateWindow("BUTTON", "3",
                     WS_VISIBLE | WS_CHILD,
                     120, 170, 50, 30,
                     hwnd, (HMENU)3, NULL, NULL);

        CreateWindow("BUTTON", "4",
                     WS_VISIBLE | WS_CHILD,
                     20, 140, 50, 30,
                     hwnd, (HMENU)4, NULL, NULL);

        CreateWindow("BUTTON", "5",
                     WS_VISIBLE | WS_CHILD,
                     70, 140, 50, 30,
                     hwnd, (HMENU)5, NULL, NULL);

        CreateWindow("BUTTON", "6",
                     WS_VISIBLE | WS_CHILD,
                     120, 140, 50, 30,
                     hwnd, (HMENU)6, NULL, NULL);
        CreateWindow("BUTTON", "7",
                     WS_VISIBLE | WS_CHILD,
                     20, 110, 50, 30,
                     hwnd, (HMENU)7, NULL, NULL);

        CreateWindow("BUTTON", "8",
                     WS_VISIBLE | WS_CHILD,
                     70, 110, 50, 30,
                     hwnd, (HMENU)8, NULL, NULL);

        CreateWindow("BUTTON", "9",
                     WS_VISIBLE | WS_CHILD,
                     120, 110, 50, 30,
                     hwnd, (HMENU)9, NULL, NULL);
        CreateWindow("BUTTON", "<-",
                     WS_VISIBLE | WS_CHILD,
                     20, 80, 50, 30,
                     hwnd, (HMENU)17, NULL, NULL);

        CreateWindow("BUTTON", "CE",
                     WS_VISIBLE | WS_CHILD,
                     70, 80, 50, 30,
                     hwnd, (HMENU)18, NULL, NULL);

        CreateWindow("BUTTON", "C",
                     WS_VISIBLE | WS_CHILD,
                     120, 80, 50, 30,
                     hwnd, (HMENU)19, NULL, NULL);
        CreateWindow("BUTTON", ".",
                     WS_VISIBLE | WS_CHILD,
                     120, 200, 50, 30,
                     hwnd, (HMENU)11, NULL, NULL);

        // Operaciones
        CreateWindow("BUTTON", "+",
                     WS_VISIBLE | WS_CHILD,
                     170, 200, 50, 30,
                     hwnd, (HMENU)12, NULL, NULL);
        CreateWindow("BUTTON", "-",
                     WS_VISIBLE | WS_CHILD,
                     170, 170, 50, 30,
                     hwnd, (HMENU)13, NULL, NULL);
        CreateWindow("BUTTON", "*",
                     WS_VISIBLE | WS_CHILD,
                     170, 140, 50, 30,
                     hwnd, (HMENU)14, NULL, NULL);
        CreateWindow("BUTTON", "/",
                     WS_VISIBLE | WS_CHILD,
                     170, 110, 50, 30,
                     hwnd, (HMENU)15, NULL, NULL);
        CreateWindow("BUTTON", "1/x",
                     WS_VISIBLE | WS_CHILD,
                     220, 140, 50, 30,
                     hwnd, (HMENU)20, NULL, NULL);
        CreateWindow("BUTTON", "%",
                     WS_VISIBLE | WS_CHILD,
                     220, 110, 50, 30,
                     hwnd, (HMENU)21, NULL, NULL);
        
        //Resultado:
        CreateWindow("BUTTON", "=",
                     WS_VISIBLE | WS_CHILD,
                     220, 170, 50, 60,
                     hwnd, (HMENU)16, NULL, NULL);

        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1){ // botón "1"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "1";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 2){ //botón "2"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "2";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 3){ //Botón "3"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "3";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 4){ //Botón "4"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "4";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 5){ // botón "5"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "5";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 6){ // botón "6"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "6";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 7){ // botón "7"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "7";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 8){ // botón "8"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "8";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 9){ // botón "9"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "9";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 10){ // botón "10"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            numero += "0";

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 11){ // botón "."
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;

            // buscar último operador
            size_t pos = numero.find_last_of("+-*/");

            // obtener el número actual
            std::string actual;

            if (pos == std::string::npos)
                actual = numero; // solo hay un número
            else
                actual = numero.substr(pos + 1); // lo que está después del operador

            // verificar si ya tiene punto
            if (actual.find('.') == std::string::npos && !numero.empty() && isdigit(numero.back()))
            {
                numero += ".";
            }

            SetWindowText(outputBox, numero.c_str());
        
        } else if (LOWORD(wParam) == 12){ // botón "+"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            if (!numero.empty() && isdigit(numero.back()))
            {
                numero += "+";
                SetWindowText(outputBox, numero.c_str());
            }
        
        } else if (LOWORD(wParam) == 13){ // botón "-"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;

            if (!numero.empty() && isdigit(numero.back()))
            {
                numero += "-";
                SetWindowText(outputBox, numero.c_str());
            }
        
        }else if (LOWORD(wParam) == 14){ // botón "*"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            if (!numero.empty() && isdigit(numero.back()))
            {
                numero += "*";
                SetWindowText(outputBox, numero.c_str());
            }

        } else if (LOWORD(wParam) == 15){ // botón "/"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string numero = buffer;
            if (!numero.empty() && isdigit(numero.back()))
            {
                numero += "/";
                SetWindowText(outputBox, numero.c_str());
            }
        
        } else if (LOWORD(wParam) == 16) { //Botón "="
            //se toma lo que escribio el usuario
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string expr = buffer; //Se convierte a string lo que escribio el usuario

            std::vector<double> numeros; //Guarda los numeros
            std::vector<char> ops; //Guarda las operaciones

            std::string num = ""; // Variable temporal para ir construyendo números carácter por carácter.

            //separar números y operadores
            for (char c : expr) { //recorrer cada carácter dentro de expr y guárdalo en c uno por uno
                if (isdigit(c) || c == '.') {
                    num += c; //se va sumando a num para construir el número carácter por carácter
                } else { //si no es número o si no es un punto entonces sería un +-/*
                    numeros.push_back(std::stod(num));
                    num = "";
                    ops.push_back(c);
                }
            }
            numeros.push_back(std::stod(num));

            //primero * y /
            for (int i = 0; i < ops.size(); ) {
                if (ops[i] == '*' || ops[i] == '/') {
                    double res;

                    if (ops[i] == '*')
                        res = numeros[i] * numeros[i + 1];
                    else {
                        if (numeros[i + 1] == 0) {
                            SetWindowText(outputBox, "Error");
                            return 0;
                        }
                        res = numeros[i] / numeros[i + 1];
                    }

                    numeros[i] = res;
                    numeros.erase(numeros.begin() + i + 1);
                    ops.erase(ops.begin() + i);
                } else {
                    i++;
                }
            }

            // luego + y -
            double resultado = numeros[0];

            for (int i = 0; i < ops.size(); i++) {
                if (ops[i] == '+')
                    resultado += numeros[i + 1];
                else if (ops[i] == '-')
                    resultado -= numeros[i + 1];
            }

            //mostrar resultado
            SetWindowText(outputBox, std::to_string(resultado).c_str());
        
        } else if (LOWORD(wParam)==17){ //Botón "<-"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string texto = buffer;
            if(!texto.empty()){
                texto.pop_back();                    
            }
            
             SetWindowText(outputBox, texto.c_str());
        } else if (LOWORD(wParam) == 18) { //Botón "CE"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string texto = buffer;

            // buscar último operador
            size_t pos = texto.find_last_of("+-*/");

            if (pos != std::string::npos) {
                // dejar solo hasta el operador
                texto = texto.substr(0, pos + 1);
            } else {
                // si no hay operador → borrar todo
                texto = "";
            }

            SetWindowText(outputBox, texto.c_str());
        
        } else if (LOWORD(wParam) == 19) { //Botón "C"

            SetWindowText(outputBox, "");
        
        } else if (LOWORD(wParam) == 20) { //Botón "1/x"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string expr = buffer;

            std::vector<double> numeros;
            std::vector<char> ops;

            std::string num = "";

            //separar números y operadores
            for (char c : expr) {
                if (isdigit(c) || c == '.') {
                    num += c;
                } else {
                    numeros.push_back(std::stod(num));
                    num = "";
                    ops.push_back(c);
                }
            }
            numeros.push_back(std::stod(num));

            //primero * y /
            for (int i = 0; i < ops.size(); ) {
                if (ops[i] == '*' || ops[i] == '/') {
                    double res;

                    if (ops[i] == '*')
                        res = numeros[i] * numeros[i + 1];
                    else {
                        if (numeros[i + 1] == 0) {
                            SetWindowText(outputBox, "Error");
                            return 0;
                        }
                        res = numeros[i] / numeros[i + 1];
                    }

                    numeros[i] = res;
                    numeros.erase(numeros.begin() + i + 1);
                    ops.erase(ops.begin() + i);
                } else {
                    i++;
                }
            }

            //luego + y -
            double resultado = numeros[0];

            for (int i = 0; i < ops.size(); i++) {
                if (ops[i] == '+')
                    resultado += numeros[i + 1];
                else if (ops[i] == '-')
                    resultado -= numeros[i + 1];
            }

            try {
                if (resultado == 0) {
                    SetWindowText(outputBox, "Error");
                    return 0;
                }

                double resultados = 1 / resultado;

                std::string res = std::to_string(resultados);
                SetWindowText(outputBox, res.c_str());
            }
            catch (...) {
                SetWindowText(outputBox, "Error");
            }
        
        } else if (LOWORD(wParam) == 21) { //Botón "%"
            char buffer[100];
            GetWindowText(outputBox, buffer, 100);

            std::string texto = buffer;

            size_t pos = texto.find_last_of("+-*/");

            std::string antes, ultimo;

            if (pos == std::string::npos) {
                // solo un número dividirlo entre 100
                try {
                    double num = std::stod(texto);
                    num = num / 100;

                    SetWindowText(outputBox, std::to_string(num).c_str());
                } catch (...) {
                    SetWindowText(outputBox, "Error");
                }
                return 0;
            }

            antes = texto.substr(0, pos + 1);
            ultimo = texto.substr(pos + 1);
            char op = texto[pos];

            try {
                double A = std::stod(texto.substr(0, pos));
                double B = std::stod(ultimo);

                double res;

                if (op == '+' || op == '-') {
                    res = A * B / 100.0;
                } else { // * o /
                    res = B / 100.0;
                }

                std::string nuevo = antes + std::to_string(res);
                SetWindowText(outputBox, nuevo.c_str());
            }
            catch (...) {
                SetWindowText(outputBox, "Error");
            }
        }
        break;
            
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    
   /* case WM_DRAWITEM:{
            LPDRAWITEMSTRUCT dis = (LPDRAWITEMSTRUCT)lParam;

            if (dis->CtlID == 1) {// nuestro botón
                // Fondo verde
                HBRUSH brush = CreateSolidBrush(RGB(236, 242, 247));
                FillRect(dis->hDC, &dis->rcItem, brush);
                DeleteObject(brush);

                // Texto blanco
                SetTextColor(dis->hDC, RGB(30, 57, 91));
                SetBkMode(dis->hDC, TRANSPARENT);

                DrawText(dis->hDC, "1", -1, &dis->rcItem,
                        DT_CENTER | DT_VCENTER | DT_SINGLELINE);

                return TRUE;
            } else if (dis->CtlID == 2) {// nuestro botón
                // Fondo verde
                HBRUSH brush = CreateSolidBrush(RGB(236, 242, 247));
                FillRect(dis->hDC, &dis->rcItem, brush);
                DeleteObject(brush);

                // Texto blanco
                SetTextColor(dis->hDC, RGB(30, 57, 91));
                SetBkMode(dis->hDC, TRANSPARENT);

                DrawText(dis->hDC, "2", -1, &dis->rcItem,
                        DT_CENTER | DT_VCENTER | DT_SINGLELINE);

                return TRUE;
            } else if (dis->CtlID == 3) {// nuestro botón
                // Fondo verde
                HBRUSH brush = CreateSolidBrush(RGB(236, 242, 247));
                FillRect(dis->hDC, &dis->rcItem, brush);
                DeleteObject(brush);

                // Texto blanco
                SetTextColor(dis->hDC, RGB(30, 57, 91));
                SetBkMode(dis->hDC, TRANSPARENT);

                DrawText(dis->hDC, "3", -1, &dis->rcItem,
                        DT_CENTER | DT_VCENTER | DT_SINGLELINE);

                return TRUE;
            }
        }
        break;*/
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main()
{
    const char CLASS_NAME[] = "MiVentana";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND window = CreateWindowEx(
        0,
        CLASS_NAME,
        "App simple",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 300,
        NULL, NULL, NULL, NULL);

    ShowWindow(window, SW_SHOW);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}