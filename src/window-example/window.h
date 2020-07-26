#pragma once
#include <gtkmm.h>

class Window : public Gtk::Window {
protected:
    Gtk::Box mBox;
    Gtk::Label label;
    
public:
    Window();
    ~Window();

};