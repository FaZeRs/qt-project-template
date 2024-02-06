#include "core/application.h"
#include "core/base.h"
#include "core/parameters.h"
#include "widgets/main_window.h"

int main(int argc, char *argv[]) {
  using namespace room_sketcher;
  Application app(argc, argv);

  KDDockWidgets::MainWindowOptions options =
      KDDockWidgets::MainWindowOption_None;
  MainWindow window(QStringLiteral("MainWindow"), options);
  window.resize(parameters::window_width, parameters::window_height);
  window.show();

  return app.run();
}
