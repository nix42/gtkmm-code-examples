#include "window.h"

Window::Window() : 
mBox(Gtk::ORIENTATION_VERTICAL) {
    set_title("Basic Window Example");
    set_default_size(400, 300);
    add(mBox);

    label.set_label("This is a basic window");

    mBox.pack_start(label, Gtk::PACK_SHRINK);

    show_all_children();
}

Window::~Window() {}