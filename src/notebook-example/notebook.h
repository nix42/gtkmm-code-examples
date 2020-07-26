#pragma once
#include <gtkmm.h>

class Notebook : public Gtk::Window {
protected:
    Gtk::Box mBox, headerBox, nBox1, nBox2, nBox3;
    Gtk::Notebook mNotebook;
    Gtk::Label nLabel1, nLabel2, nLabel3;
    Gtk::Button nextButton, prevButton;

    void on_next_page();
    void on_prev_page();

public:
    Notebook();
    ~Notebook();
};
