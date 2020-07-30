# Gtkmm code examples (Gtk interface for C++)

- Collection of gtkmm code samples written in C++ 

## Examples in repository

- [window example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/window-example) - How to setup a basic window
- [Glade example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/glade-example) - How to use a glade file for the UI
- [Buttons example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/buttons-example) - How to setup and use buttons
- [Container example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/container-example) - How to use different types of containers
- [Grid example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/grid-example) - How to display and populate a grid
- [Dialog example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/dialog-example) - How to open a dialog via button press and receive data from it
- [Notebook example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/notebook-example) - How to setup a notebook inside a window with tabbed windows
- [Treeview example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/treeview-example) - How to setup a Treeview model with a list store
- [CSS example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/css-example) - How to use a css file with your gtkmm application
- [Json and treeview example](https://github.com/nix42/gtkmm-code-examples/tree/master/src/json-treeview-example) - Populating/manipulating a list store using JSON data (jsoncpp)

## Compiling the code
### With JSON
- g++ main.cpp -insert filename-.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs' -ljsoncpp
### Without JSON
- g++ main.cpp -insert filename-.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs'
