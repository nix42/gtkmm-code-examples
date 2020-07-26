#include "css.h"

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    Css c;

    app->run(c);

    return 0;
}