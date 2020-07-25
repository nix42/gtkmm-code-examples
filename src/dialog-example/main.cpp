#include "dialog.h"

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    Dialog d;

    app->run(d);
    
    return 0;
}