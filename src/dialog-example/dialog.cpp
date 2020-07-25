#include "dialog.h"

Dialog::Dialog() :
mBox(Gtk::ORIENTATION_VERTICAL) {

    set_title("Dialog example");
    set_size_request(300, 200);
    add(mBox);
    
    mLabel.set_label("change the text of this label");
    mButton.set_label("Change text");

    mBox.set_border_width(20);
    mBox.pack_start(mLabel, Gtk::PACK_SHRINK);
    mBox.pack_end(mButton, Gtk::PACK_SHRINK);

    mButton.signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_open_dialog));
    show_all_children();

}

void Dialog::on_open_dialog() {
    Gtk::Entry dEntry;
    Gtk::Label dLabel;
    Gtk::ButtonBox dButtonBox;
    Gtk::Button dButton;

    mDialog.set_size_request(300, 200);
    mDialog.set_border_width(10);

    dLabel.set_label("Enter the new text for the label:");

    dButton.set_label("Enter");
    dButton.signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_close_dialog));

    dButtonBox.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    dButtonBox.pack_end(dButton, Gtk::PACK_SHRINK);
    
    mDialog.get_vbox()->pack_start(dLabel, Gtk::PACK_SHRINK);
    mDialog.get_vbox()->pack_start(dEntry, Gtk::PACK_SHRINK);
    mDialog.get_vbox()->pack_end(dButtonBox, Gtk::PACK_SHRINK);

    mDialog.show_all();
    mDialog.run();

    mLabel.set_label(dEntry.get_text());

}

void Dialog::on_close_dialog() {
    mDialog.hide();
}

Dialog::~Dialog() {}