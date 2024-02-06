#pragma once

#include <kddockwidgets/MainWindow.h>

#include "../core/base.h"
#include "../core/namespace.h"
#include "../core/project_manager.h"
#include "../core/settings.h"

namespace room_sketcher {

class MainWindow : public KDDockWidgets::QtWidgets::MainWindow {
 public:
  MainWindow(const QString &unique_name,
             KDDockWidgets::MainWindowOptions options,
             QWidget *parent = nullptr);

 private:
  Scope<Settings> m_Settings = CreateScope<Settings>();
  ProjectManager m_ProjectManager;
  ToolType m_CurrentToolType = ToolType::Edit;

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
  void onToolSelected(const ToolType &tool_type);
};

}  // namespace room_sketcher
