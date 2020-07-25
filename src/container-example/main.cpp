#include "container.h"

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    Container c;

    app->run(c);
    
    return 0;
}