#pragma once
#include <gtkmm.h>

class Buttons : public Gtk::Window {
protected:
    Gtk::Box mBox, leftBox, rightBox;
    Gtk::Button showButton, hideButton;
    Gtk::Label label;

    void on_label_hide();
    void on_label_show();

public:
    Buttons();
    ~Buttons();    
};