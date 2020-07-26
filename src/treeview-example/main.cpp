#include "treeview.h"

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    Treeview t;

    app->run(t);
    
    return 0;
}