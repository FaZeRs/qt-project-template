#pragma once

#include <qmainwindow.h>
#include <qnamespace.h>

class QWidget;

namespace room_sketcher {

class MainWindow : public QMainWindow {
 public:
  explicit MainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = {});

 private:
  void setupToolBar();
  void setupMenuBar();
  void about();
};

}  // namespace room_sketcher
