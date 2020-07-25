#pragma once
#include <gtkmm.h>

class Container : public Gtk::Window {
    protected:  
        Gtk::Box mBox;
        Gtk::Frame mFrame;
        Gtk::ButtonBox mButtons;
        Gtk::Button showButton, hideButton, closeButton;
        Gtk::Label label;

        void on_button_show();
        void on_button_hide();
        void on_button_close();

    public:
        Container();
        ~Container();
};