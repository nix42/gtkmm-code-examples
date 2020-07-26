#include "grid.h"

Grid::Grid() {
    set_title("Grid example");
    set_size_request(200, 200);
    add(mBox);

    mBox.set_homogeneous(true);
    mBox.set_center_widget(mGrid);

    mLabel1.set_label("This");
    mLabel2.set_label("is");
    mLabel3.set_label("a grid");

    mButton.set_label("exit");
    mButton.signal_clicked().connect(sigc::mem_fun(*this, &Grid::on_button_exit));

    mGrid.attach(mLabel1, 1, 1);
    mGrid.attach(mLabel2, 2, 1);
    mGrid.attach(mLabel3, 3, 1);
    mGrid.attach_next_to(mButton, mLabel2, Gtk::POS_BOTTOM);

    show_all_children();
}

void Grid::on_button_exit() {
    Gtk::Window::hide();
}

Grid::~Grid() {}