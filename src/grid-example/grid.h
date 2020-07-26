#pragma once
#include <gtkmm.h>
 
class Grid : public Gtk::Window {
protected:
    Gtk::Box mBox;
    Gtk::Grid mGrid;
    Gtk::Label mLabel1, mLabel2, mLabel3;
    Gtk::Button mButton;

    void on_button_exit();
    
public:
    Grid();
    ~Grid();
    
};