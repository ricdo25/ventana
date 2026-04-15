#include <windows.h>
#include <string>
#include <cstdlib>
HWND input1, input2, outputBox;
HWND botonInicio, botonSuma;
HWND textoInicio;

int pantalla = 0;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    
    switch (uMsg) {
    case WM_CREATE:

        // Texto bienvenida
        textoInicio = CreateWindow("STATIC",
            "Bienvenido a la calculadora de suma de dos numeros",
            WS_VISIBLE | WS_CHILD,
            30, 40, 350, 30,
            hwnd, NULL, NULL, NULL);

        // Botón continuar
        botonInicio = CreateWindow("BUTTON", "Continuar",
            WS_VISIBLE | WS_CHILD,
            120, 100, 150, 40,
            hwnd, (HMENU)1, NULL, NULL);

        break;

    case WM_COMMAND:

        if (LOWORD(wParam) == 1) { // botón inicio

            pantalla = 1;

            // Ocultar inicio
            ShowWindow(textoInicio, SW_HIDE);
            ShowWindow(botonInicio, SW_HIDE);

            UpdateWindow(hwnd);
            InvalidateRect(hwnd, NULL, TRUE);

            // Crear calculadora
            input1 = CreateWindow("EDIT", "",
                WS_VISIBLE | WS_CHILD | WS_BORDER,
                50, 30, 200, 25,
                hwnd, NULL, NULL, NULL);

            input2 = CreateWindow("EDIT", "",
                WS_VISIBLE | WS_CHILD | WS_BORDER,
                50, 70, 200, 25,
                hwnd, NULL, NULL, NULL);

            botonSuma = CreateWindow("BUTTON", "=",
                WS_VISIBLE | WS_CHILD,
                100, 110, 100, 30,
                hwnd, (HMENU)2, NULL, NULL);

            outputBox = CreateWindow("EDIT", "",
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY,
                50, 160, 200, 25,
                hwnd, NULL, NULL, NULL);
        }

        // Botón suma
        if (LOWORD(wParam) == 2) {
            char buffer1[100];
            char buffer2[100];

            // Leer texto de los inputs
            GetWindowText(input1, buffer1, 100);
            GetWindowText(input2, buffer2, 100);

            // Convertir a string
            std::string str1 = buffer1;
            std::string str2 = buffer2;

            // Concatenar
            std::string resultado = str1 + str2;

            // Mostrar
            SetWindowText(outputBox, resultado.c_str());
        }

        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main() {
    const char CLASS_NAME[] = "MiVentana";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND window = CreateWindowEx(
        0,
        CLASS_NAME,
        "Suma de numeros",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 250,
        NULL, NULL, NULL, NULL
    );

    ShowWindow(window, SW_SHOW);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}