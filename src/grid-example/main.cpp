#include "grid.h"

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    Grid g;

    app->run(g);
    
    return 0;
}