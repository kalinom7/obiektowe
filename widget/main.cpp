#include <iostream>
#include "widget.hpp"
#include <vector>


int main() {
  Button *yes = new Button("yes");
  Button *no = new Button("no");

  Widget *panel = new Widget("panel");
  panel->add(yes);
  panel->add(no);

  Edit *edit = new Edit("edit");

  Widget *window = new Widget("window");
  window->add(panel);
  window->add(edit);

  window->print();
  delete window;

  return 0;
}