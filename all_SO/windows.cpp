#include "windows.h"

Ventana::Ventana() : wxFrame(NULL, wxID_ANY, "Calculadora", wxDefaultPosition, wxSize(240, 280)) {
    wxPanel* panel = new wxPanel(this);
    panel->SetBackgroundColour(wxColour(236, 244, 252));

    display = new wxTextCtrl(panel, wxID_ANY, "",
                             wxPoint(20, 20), wxSize(170, 40),
                             wxTE_RIGHT);

    display->SetBackgroundColour(wxColour(231, 237, 245));
    display->SetForegroundColour(wxColour(30, 30, 30));

    // Columna 1
        CrearBoton(panel, "<-", 17, 20, 70, 33, 27);
        CrearBoton(panel, "7", 7, 20, 98, 33, 27);
        CrearBoton(panel, "4", 4, 20, 126, 33, 27);
        CrearBoton(panel, "1", 1, 20, 154, 33, 27);
        CrearBoton(panel, "0", 10, 20, 182, 66, 27);
        
        
        // Columna 2
        CrearBoton(panel, "CE", 18, 54, 70, 33, 27);
        CrearBoton(panel, "8", 8, 54, 98, 33, 27);
        CrearBoton(panel, "5", 5, 54, 126, 33, 27);
        CrearBoton(panel, "2", 2, 54, 154, 33, 27);
        
        
        // Columna 3
        CrearBoton(panel, "C", 19, 88, 70, 33, 27);
        CrearBoton(panel, "9", 9, 88, 98, 33, 27);
        CrearBoton(panel, "6", 6, 88, 126, 33, 27);
        CrearBoton(panel, "3", 3, 88, 154, 33, 27);
        CrearBoton(panel, ".", 11, 88, 182, 33, 27);
        
        
        // Columna 4
        CrearBoton(panel, "/", 15, 122, 98, 33, 27);
        CrearBoton(panel, "*", 14, 122, 126, 33, 27);
        CrearBoton(panel, "-", 13, 122, 154, 33, 27);
        CrearBoton(panel, "+", 12, 122, 182, 33, 27);
        

        // Columna 5
        CrearBoton(panel, "%", 21, 156, 98, 33, 27);
        CrearBoton(panel, "1/x", 20, 156, 126, 33, 27);
        CrearBoton(panel, "=", 16, 156, 154, 33, 54);
}

void Ventana::CrearBoton(wxPanel* panel, const wxString& texto, int id, int x, int y, int w, int h) {
    wxButton* btn = new wxButton(panel, id, texto, wxPoint(x, y), wxSize(w, h));

    btn->SetBackgroundColour(wxColour(232, 239, 246));

    //if (texto == "=") {
      //  btn->SetBackgroundColour(wxColour(0, 120, 215));
        //btn->SetForegroundColour(*wxWHITE);
    //}

    Bind(wxEVT_BUTTON, &Ventana::OnButton, this, id);
}

void Ventana::OnButton(wxCommandEvent& event) {
    int id = event.GetId();

    try {
        if (id >= 1 && id <= 9){ // agrega números
                calc.agregarDigito('0' + id);
            } else if (id == 10){ // agrega 0
                calc.agregarDigito('0');
            } else if (id == 11){ // agrega punto
                calc.agregarPunto();
            } else if (id == 12){ // agrega +
                calc.agregarOperador('+');
            } else if (id == 13) { // agrega -
                calc.agregarOperador('-');
            } else if (id == 14){ // agrega *
                calc.agregarOperador('*');
            } else if (id == 15){ // agrega /
                calc.agregarOperador('/');
            } else if (id == 16){ // Boton igual
                calc.igual();
            } else if (id == 17) { // Boton <-
                calc.borrarUno();
            } else if (id == 18) { // Boton CE
                calc.borrarUltimo(); 
            } else if (id == 19) { // Boton C
                calc.borrarTodo();
            } else if (id == 20){ //Boto 1/x
                calc.inverso();
            }

        display->SetValue(calc.obtenerPantalla());
    }
    catch (...) {
        display->SetValue("Error");
    }
}