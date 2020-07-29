#include "json-treeview.h"
#include <fstream>
#include <iostream>

JsonTreeview::JsonTreeview() : 
mBox(Gtk::ORIENTATION_VERTICAL) {
    set_title("Json and treeview Example");
    set_default_size(500, 400);
    add(mBox);

    std::ifstream eventsConf("events.json");
    eventsConf >> eventData;
    eventsConf.close();

    mBox.pack_start(eventButtons, Gtk::PACK_SHRINK);
    mBox.pack_start(jTreeView);

    addEvent.set_label("Add");
    editEvent.set_label("Edit");
    deleteEvent.set_label("Delete");

    addEvent.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &JsonTreeview::on_button_press), 1));
    editEvent.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &JsonTreeview::on_button_press), 2));
    deleteEvent.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &JsonTreeview::on_button_press), 3));

    eventButtons.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    eventButtons.pack_end(deleteEvent, Gtk::PACK_SHRINK);
    eventButtons.pack_end(editEvent, Gtk::PACK_SHRINK);
    eventButtons.pack_end(addEvent, Gtk::PACK_SHRINK);

    jListStore = Gtk::ListStore::create(columns);
    jTreeView.set_model(jListStore);
    jTreeView.append_column("Event", columns.eventName);
    jTreeView.append_column("Job", columns.eventDesc);
    jTreeView.append_column("Start date", columns.eventDate);

    for (int i = 0; i < eventData["events"].size(); i++) {
        Gtk::TreeModel::Row row; 
        row = *(jListStore->append());
        row[columns.eventName] = eventData["events"][i]["name"].asString();
        row[columns.eventDesc] = eventData["events"][i]["desc"].asString();
        row[columns.eventDate] = eventData["events"][i]["date"].asString();
    }

    show_all_children();
}

void JsonTreeview::on_button_press(int choice) {
    jDialog.set_size_request(300, 200);
    Gtk::Entry eventNameEntry, eventDescEntry, eventDateEntry;
    Gtk::Label eventNameLabel, eventDescLabel, eventDateLabel;
    Gtk::Button exitButton;

    eventNameLabel.set_text("Enter the event name:");
    eventNameLabel.set_halign(Gtk::ALIGN_START);
    eventDescLabel.set_text("Enter the event description:");
    eventDescLabel.set_halign(Gtk::ALIGN_START);
    eventDateLabel.set_text("Enter the event date(DD/MM/YY):");
    eventDateLabel.set_halign(Gtk::ALIGN_START);

    exitButton.set_label("Enter details");
    exitButton.set_halign(Gtk::ALIGN_END);
    exitButton.signal_clicked().connect(sigc::mem_fun(*this, &JsonTreeview::on_dialog_exit));

    if (choice == 1) {
        jDialog.set_title("Add an event");
        jDialog.get_vbox()->pack_start(eventNameLabel, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventNameEntry, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventDescLabel, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventDescEntry, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventDateLabel, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventDateEntry, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_end(exitButton, Gtk::PACK_SHRINK);

        jDialog.show_all();
        jDialog.run();

        std::string name, desc, date;
        name = eventNameEntry.get_text();
        desc = eventDescEntry.get_text();
        date = eventDateEntry.get_text();

        Gtk::TreeModel::Row row = *(jListStore->append());
        row[columns.eventName] = name;
        row[columns.eventDesc] = desc;
        row[columns.eventDate] = date;

        Json::Value newData;
        newData["name"] = name;
        newData["desc"] = desc;
        newData["date"] = date;
        eventData["events"].append(newData);

        std::ofstream writeEvent("events.json");
        writeEvent << eventData;
        writeEvent.close();

    } else if (choice == 2) {
        jDialog.set_title("Edit an event");
        eventNameLabel.set_text("Enter the name of the event you would like to edit");

        jDialog.get_vbox()->pack_start(eventNameLabel, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventNameEntry, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_end(exitButton, Gtk::PACK_SHRINK);

        jDialog.show_all();
        jDialog.run();

        std::string getName = eventNameEntry.get_text();
        Gtk::TreeModel::Row editRow;
        typedef Gtk::TreeModel::Children type_children; 
        type_children rows = jListStore->children();
        for(type_children::iterator iter = rows.begin(); iter != rows.end(); ++iter) {
            editRow = *iter;
            if (getName == editRow[columns.eventName]) {
                eventNameLabel.set_text("Edit event name");
                eventNameEntry.set_text(editRow[columns.eventName]);
                eventDescLabel.set_text("Edit event description");
                eventDescEntry.set_text(editRow[columns.eventDesc]);
                eventDateLabel.set_text("Edit event date");
                eventDateEntry.set_text(editRow[columns.eventDate]);
                break;
            } else if (iter != rows.end()) {
                continue;
            }
        }

        jDialog.get_vbox()->pack_start(eventDescLabel, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventDescEntry, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventDateLabel, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventDateEntry, Gtk::PACK_SHRINK);

        jDialog.show_all();
        jDialog.run();
        
        editRow[columns.eventName] = eventNameEntry.get_text();
        editRow[columns.eventDesc] = eventDescEntry.get_text();
        editRow[columns.eventDate] = eventDateEntry.get_text();

        std::string name = eventNameEntry.get_text();
        std::string desc = eventDescEntry.get_text();
        std::string date = eventDateEntry.get_text();

        for (int i = 0; i < eventData["events"].size(); i++) {
            if (eventData["events"][i]["name"] == getName) {
                eventData["events"][i]["name"] = name;
                eventData["events"][i]["desc"] = desc;
                eventData["events"][i]["date"] = date;

                std::ofstream eventEdit("events.json");
                eventEdit << eventData;
                eventEdit.close();
                break;
            }
        }

    } else if (choice == 3) {
        jDialog.set_title("Delete an event");
        jDialog.get_vbox()->pack_start(eventNameLabel, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_start(eventNameEntry, Gtk::PACK_SHRINK);
        jDialog.get_vbox()->pack_end(exitButton, Gtk::PACK_SHRINK);

        jDialog.show_all();
        jDialog.run();

        std::string getName = eventNameEntry.get_text();
        Gtk::TreeModel::Row delRow;

        typedef Gtk::TreeModel::Children type_children; 
        type_children rows = jListStore->children();
        for(type_children::iterator iter = rows.begin(); iter != rows.end(); ++iter) {
            Gtk::TreeModel::Row delRow = *iter;
            if (getName == delRow[columns.eventName]) {
                jListStore->erase(iter);
                break;
            } else if (iter != rows.end()) {
                continue;
            }
        }

        Json::Value newData;
        int skip;
        for (int i = 0; i < eventData["events"].size(); i++) {
            if (getName == eventData["events"][i]["name"].asString()) {
                continue;
            }
            newData["events"][i] = eventData["events"][i];
        }

        std::ofstream eventDelete("events.json");
        eventDelete << newData;
        eventDelete.close();

        std::string line;
        std::ifstream readFile("events.json");
        std::ofstream delNull("temp.json");
        while (getline(readFile, line)) {
            if (line.find("null") != std::string::npos) {
                continue;
            }
            delNull << line << std::endl;
        }
        readFile.close();
        delNull.close();
        
        std::ifstream temp("temp.json");
        std::ofstream temp2("events.json");
        while (getline(temp, line))
        {
        temp2 << line << std::endl;
        }
        temp.close();
        temp2.close();
        std::remove("temp.json");    
    }
}

void JsonTreeview::on_dialog_exit() {
    jDialog.hide();
}

JsonTreeview::~JsonTreeview() {}