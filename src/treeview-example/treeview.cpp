#include "treeview.h"

Treeview::Treeview() : 
mBox(Gtk::ORIENTATION_VERTICAL) {

    set_title("Treeview Example");
    set_default_size(400, 300);
    add(mBox);
    mBox.pack_start(tTreeView);

    tListStore = Gtk::ListStore::create(columns);
    tTreeView.set_model(tListStore);
    tTreeView.append_column("Event", columns.eventName);
    tTreeView.append_column("Job", columns.eventDesc);
    tTreeView.append_column("Start date", columns.eventDate);

    Gtk::TreeModel::Row row = *(tListStore->append());
    row[columns.eventName] = "John Smith";
    row[columns.eventDesc] = "Cleaner";
    row[columns.eventDate] = "27/06/2005";

    row = *(tListStore->append());
    row[columns.eventName] = "jean Smith";
    row[columns.eventDesc] = "administrator";
    row[columns.eventDate] = "12/02/2007";

    show_all_children();
}

Treeview::~Treeview() {}