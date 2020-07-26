#include "grid.h"

Grid::Grid() {
    set_title("Grid example");
    set_size_request(400, 300);
    add(mGrid);

    mGrid.set_homogeneous(true);


    show_all_children();
}

Grid::~Grid() {}