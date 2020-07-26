#include "css.h"
#include <iostream>

Css::Css() : 
mBox(Gtk::ORIENTATION_VERTICAL) {

    set_title("css example");
    set_size_request(600, 400);
    add(mBox);

    mBox.set_name("main-box");
    topBox.set_name("top-box");
    leftBox.set_name("left-box");
    rightBox.set_name("right-box");
    bottomBox.set_name("bottom-box");

    mBox.pack_start(topBox);
    mBox.pack_start(bottomBox);
    topBox.pack_start(leftBox);
    topBox.pack_start(rightBox);

    leftLabel.set_label("This is the left box");
    rightLabel.set_label("This is the right box");
    colorButton.set_label("Change text color");

    leftBox.set_center_widget(leftLabel);
    rightBox.set_center_widget(rightLabel);
    bottomBox.set_center_widget(colorButton);

    colorButton.signal_clicked().connect(sigc::mem_fun(*this, &Css::on_color_choice));

    auto css = Gtk::CssProvider::create();
    css->load_from_path("style.css");
    Gtk::StyleContext::add_provider_for_screen
                   (Gdk::Screen::get_default(), css, 
                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    show_all_children();
}

void Css::on_color_choice() {
    cDialog.run();
    mColor = cDialog.get_rgba();

    leftLabel.override_color(mColor);
    rightLabel.override_color(mColor);

    cDialog.hide();
}

Css::~Css() {}