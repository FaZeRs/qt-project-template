#include <QDebug>
#include <QMap>
#include <QPainter>
#include <QPainterPath>

#include "core/application.h"
#include "widgets/mainwindow.h"

int main(int argc, char *argv[]) {
  using namespace room_sketcher;
  Application app(argc, argv);

  MainWindow window;
  window.resize(800, 600);
  window.show();

  return app.run();
}
