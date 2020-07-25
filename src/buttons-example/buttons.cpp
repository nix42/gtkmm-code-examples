#include "buttons.h"
#include <iostream>

Buttons::Buttons() : 
mBox(Gtk::ORIENTATION_VERTICAL),
leftBox(Gtk::ORIENTATION_VERTICAL),
rightBox(Gtk::ORIENTATION_VERTICAL) {

    set_title("Buttons example");
    set_size_request(250, 250);
    add(mBox);

    mBox.add(leftBox);
    mBox.add(rightBox);

    showButton.set_label("Show label");
    hideButton.set_label("Hide label");
    label.set_label("This is a basic button example");
    label.set_padding(20, 20);

    showButton.signal_clicked().connect(sigc::mem_fun(*this, &Buttons::on_label_show));
    hideButton.signal_clicked().connect(sigc::mem_fun(*this, &Buttons::on_label_hide));

    leftBox.pack_start(showButton, Gtk::PACK_SHRINK);
    leftBox.pack_start(hideButton, Gtk::PACK_SHRINK);

    rightBox.pack_start(label, Gtk::PACK_SHRINK);

    show_all_children();
    label.hide();
}

void Buttons::on_label_show() {
    label.show();
}

void Buttons::on_label_hide() {
    label.hide();
}

Buttons::~Buttons() {}
