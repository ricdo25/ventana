#include <wx/wx.h>
#include "windows.h"

class App : public wxApp {
public:
    bool OnInit() override {
        Ventana* ventana = new Ventana();
        ventana->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(App);