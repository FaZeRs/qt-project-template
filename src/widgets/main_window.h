#pragma once

#include <QMainWindow>

#include "../core/base.h"
#include "../core/project_manager.h"
#include "../core/settings.h"

namespace room_sketcher {

class MainWindow : public QMainWindow {
 public:
  explicit MainWindow(QWidget* parent = nullptr, Qt::WindowFlags flags = {});

 private:
  Scope<Settings> m_Settings = CreateScope<Settings>();
  ProjectManager m_ProjectManager;

  void setupToolBar();
  void setupMenuBar();

 private slots:
  void openProject();
  void createProject();
  void saveProject();
  void saveAsProject();
  void doUndo();
  void doRedo();
  void doCopy();
  void doPaste();
  void doCut();
  void aboutApp();
  void settingsApp();
};

}  // namespace room_sketcher
