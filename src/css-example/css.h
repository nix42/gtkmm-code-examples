#pragma once
#include <gtkmm.h>

class Css : public Gtk::Window {
protected:
    Gtk::Box mBox, topBox, leftBox, rightBox, bottomBox;
    Gtk::Label leftLabel, rightLabel;
    Gtk::Button colorButton;

    Gtk::ColorChooserDialog cDialog;
    Gdk::RGBA mColor;
    
    void on_color_choice();

public:
    Css();
    ~Css();
};