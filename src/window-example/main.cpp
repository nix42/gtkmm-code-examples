#include "window.h"

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    Window w;

    app->run(w);

    return 0;
}