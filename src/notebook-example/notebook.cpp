#include "notebook.h"

Notebook::Notebook() : 
mBox(Gtk::ORIENTATION_VERTICAL),
headerBox(Gtk::ORIENTATION_HORIZONTAL) {

    set_title("Notebook example");
    set_size_request(500, 450);
    set_resizable(false);
    add(mBox);

    mBox.pack_start(headerBox, Gtk::PACK_SHRINK);
    mBox.pack_start(mNotebook);

    prevButton.set_image_from_icon_name("go-previous", Gtk::ICON_SIZE_BUTTON);
    nextButton.set_image_from_icon_name("go-next", Gtk::ICON_SIZE_BUTTON);

    headerBox.pack_end(nextButton, Gtk::PACK_SHRINK);
    headerBox.pack_end(prevButton, Gtk::PACK_SHRINK);

    nextButton.signal_clicked().connect(sigc::mem_fun(*this, &Notebook::on_next_page));
    prevButton.signal_clicked().connect(sigc::mem_fun(*this, &Notebook::on_prev_page));

    mNotebook.popup_enable();
    mNotebook.set_scrollable();
    mNotebook.append_page(nBox1, "Page 1", true);
    mNotebook.append_page(nBox2, "Page 2", true);
    mNotebook.append_page(nBox3, "Page 3", true);

    nLabel1.set_label("This is page 1");
    nLabel2.set_label("This is page 2");
    nLabel3.set_label("This is page 3");

    nBox1.set_center_widget(nLabel1);
    nBox2.set_center_widget(nLabel2);
    nBox3.set_center_widget(nLabel3);

    show_all_children();
}

void Notebook::on_next_page() {
    if (mNotebook.get_current_page() == 2) {
        mNotebook.set_current_page(0);
    } else {
        mNotebook.next_page();
    }
}

void Notebook::on_prev_page() {
    if (mNotebook.get_current_page() == 0) {
        mNotebook.set_current_page(2);
    } else {
        mNotebook.prev_page();
    }
}

Notebook::~Notebook() {}