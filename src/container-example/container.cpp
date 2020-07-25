#include "container.h"
#include <iostream>

Container::Container() : 
mBox(Gtk::ORIENTATION_HORIZONTAL),
mButtons(Gtk::ORIENTATION_VERTICAL) {

    set_title("Container example");
    set_size_request(600, 400);
    add(mBox);

    mBox.set_homogeneous(true);
    mBox.add(mFrame);
    mBox.add(mButtons);

    mFrame.set_label("Gtk::Frame Widget");
    mFrame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
    mFrame.set_border_width(10);
    mFrame.add(label);

    label.set_label("this is an example of a container");

    showButton.set_label("Show Label");
    hideButton.set_label("Hide Label");
    closeButton.set_label("Exit");

    mButtons.set_border_width(50);
    mButtons.pack_start(showButton, Gtk::PACK_SHRINK);
    mButtons.pack_start(hideButton, Gtk::PACK_SHRINK);
    mButtons.pack_end(closeButton, Gtk::PACK_SHRINK);

    showButton.signal_clicked().connect(sigc::mem_fun(*this, &Container::on_button_show));
    hideButton.signal_clicked().connect(sigc::mem_fun(*this, &Container::on_button_hide));
    closeButton.signal_clicked().connect(sigc::mem_fun(*this, &Container::on_button_close));
    
    show_all_children();
}

void Container::on_button_show() {
    label.show();
}
void Container::on_button_hide() {
    label.hide();
}
void Container::on_button_close() {
    Gtk::Window::hide();
}

Container::~Container() {}