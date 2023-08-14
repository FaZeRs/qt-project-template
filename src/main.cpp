
#include "core/application.h"
#include "core/base.h"
#include "core/parameters.h"
#include "widgets/mainwindow.h"

int main(int argc, char *argv[]) {
  using namespace room_sketcher;
  Application app(argc, argv);

  MainWindow window;
  window.resize(parameters::window_width, parameters::window_height);
  window.show();

  return app.run();
}
