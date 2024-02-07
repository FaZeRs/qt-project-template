#pragma once

#include <QMainWindow>

#include "../core/base.h"
#include "../core/namespace.h"
#include "../core/project_manager.h"
#include "../core/settings.h"
#include "graphics_scene.h"
#include "graphics_view.h"

namespace room_sketcher {

class MainWindow : public QMainWindow {
 public:
  MainWindow(QWidget *parent = nullptr);

 private:
  Scope<Settings> m_Settings = CreateScope<Settings>();
  ProjectManager m_ProjectManager;
  ToolType m_CurrentToolType = ToolType::Edit;
  Scope<GraphicsView> m_View{nullptr};
  Scope<GraphicsScene> m_Scene{nullptr};

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
