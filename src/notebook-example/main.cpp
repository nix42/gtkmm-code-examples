#include "notebook.h"

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    Notebook n;

    app->run(n);
    
    return 0;
}