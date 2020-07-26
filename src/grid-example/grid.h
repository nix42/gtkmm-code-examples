#pragma once
#include <gtkmm.h>
 
class Grid : public Gtk::Window {
protected:
    Gtk::Grid mGrid;
    
public:
    Grid();
    ~Grid();
    
};