#pragma once
#include <gtkmm.h>

class Dialog : public Gtk::Window {
    protected:
        Gtk::Box mBox;
        Gtk::Label mLabel;
        Gtk::Button mButton;
        Gtk::Dialog mDialog;

        void on_open_dialog();
        void on_close_dialog();
        
    public:
        Dialog();
        ~Dialog();
};