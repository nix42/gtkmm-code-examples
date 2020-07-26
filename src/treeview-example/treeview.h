#pragma once
#include <gtkmm.h>

class Treeview : public Gtk::Window {
protected:
    Gtk::Box mBox;
    Gtk::TreeView tTreeView;
    Glib::RefPtr<Gtk::ListStore> tListStore;
    
    class tColumns : public Gtk::TreeModel::ColumnRecord {
    public:
        Gtk::TreeModelColumn<Glib::ustring> eventName;
        Gtk::TreeModelColumn<Glib::ustring> eventDesc;
        Gtk::TreeModelColumn<Glib::ustring> eventDate;
        tColumns() { add(eventName); add(eventDesc); add(eventDate); }
    };
    tColumns columns;

public:
    Treeview();
    ~Treeview();
};