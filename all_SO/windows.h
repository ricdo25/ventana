#ifndef WINDOWS_H
#define WINDOWS_H

#include <wx/wx.h>
#include "calculator_allSO.h"

class Ventana : public wxFrame {
private:
    wxTextCtrl* display;
    Calculadora calc;

    void CrearBoton(wxPanel* panel, const wxString& texto, int id, int x, int y, int w, int h);
    void OnButton(wxCommandEvent& event);

public:
    Ventana();
};

#endif