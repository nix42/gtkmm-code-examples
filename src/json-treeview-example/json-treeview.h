#pragma once
#include <gtkmm.h>
#include <json/json.h>

class JsonTreeview : public Gtk::Window {
protected: 
    Gtk::Box mBox, eventButtons;
    Gtk::TreeView jTreeView;
    Glib::RefPtr<Gtk::ListStore> jListStore;
    Gtk::Button addEvent, editEvent, deleteEvent;
    Gtk::Dialog jDialog;

    Json::Value eventData;
    
    class jColumns : public Gtk::TreeModel::ColumnRecord {
    public:
        Gtk::TreeModelColumn<Glib::ustring> eventName;
        Gtk::TreeModelColumn<Glib::ustring> eventDesc;
        Gtk::TreeModelColumn<Glib::ustring> eventDate;
        jColumns() { add(eventName); add(eventDesc); add(eventDate); }
    };
    jColumns columns;
    
    void on_button_press(int choice);
    void on_dialog_exit();
    
public:
    JsonTreeview();
    ~JsonTreeview();
};