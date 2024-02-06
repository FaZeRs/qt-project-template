#pragma once

#include <QToolBar>

#include "../core/namespace.h"

namespace room_sketcher {

class ToolBar final : public QToolBar {
  Q_OBJECT
 public:
  ToolBar(QWidget* parent = nullptr);
  ToolBar(const ToolBar&) = delete;
  ToolBar& operator=(const ToolBar&) = delete;
  ToolBar(ToolBar&&) = delete;
  ToolBar& operator=(ToolBar&&) = delete;
  ~ToolBar() final = default;

 private:
  QAction* m_ActiveTool{nullptr};
  void addToolAction(const QIcon& icon, const QString& text,
                     const ToolType& tool_type, const bool checked = false);
  void changeActiveTool(QAction* action);

 private slots:
  void actionChanged();

 signals:
  void toolSelected(ToolType tool_type);
};

}  // namespace room_sketcher