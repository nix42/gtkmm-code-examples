#include <gtkmm.h>
#include <iostream>

Gtk::Window* gWindow = nullptr;

int main(int argc, char const *argv[])
{  
    auto app = Gtk::Application::create("org.gtkmm.example");

    auto gladeBuilder = Gtk::Builder::create();
    
    gladeBuilder->add_from_file("window.glade");
    
    gladeBuilder->get_widget("mainWindow", gWindow);

    app->run(*gWindow);
    return 0;
}