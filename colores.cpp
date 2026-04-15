#include <windows.h>

HWND boton;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        boton = CreateWindow(
            "BUTTON", "Click",
            WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
            100, 100, 150, 50,
            hwnd, (HMENU)1, NULL, NULL
        );
        break;

    case WM_DRAWITEM:
    {
        LPDRAWITEMSTRUCT dis = (LPDRAWITEMSTRUCT)lParam;

        if (dis->CtlID == 1) // nuestro botón
        {
            // Fondo verde
            HBRUSH brush = CreateSolidBrush(RGB(0, 200, 0));
            FillRect(dis->hDC, &dis->rcItem, brush);
            DeleteObject(brush);

            // Texto blanco
            SetTextColor(dis->hDC, RGB(255, 255, 255));
            SetBkMode(dis->hDC, TRANSPARENT);

            DrawText(dis->hDC, "Click", -1, &dis->rcItem,
                     DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            return TRUE;
        }
        break;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == 1)
        {
            MessageBox(hwnd, "Funciona", "OK", MB_OK);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
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
        "Boton con color",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
        NULL, NULL, NULL, NULL
    );

    ShowWindow(window, SW_SHOW);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}