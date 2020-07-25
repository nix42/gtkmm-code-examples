#include "buttons.h"

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    Buttons b;

    app->run(b);

    return 0;
}