#include "json-treeview.h"

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    JsonTreeview j;

    app->run(j);
    
    return 0;
}