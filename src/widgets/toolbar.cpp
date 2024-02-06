#include "toolbar.h"

namespace room_sketcher {

ToolBar::ToolBar(QWidget* parent) : QToolBar(parent) {
  addToolAction(QIcon(":/assets/icons/arrow.svg"), tr("Edit"), ToolType::Edit,
                true);
  addSeparator();
  addToolAction(QIcon(":/assets/icons/wall.svg"), tr("Wall"), ToolType::Wall);
  addToolAction(QIcon(":/assets/icons/door.svg"), tr("Door"), ToolType::Door);
  addToolAction(QIcon(":/assets/icons/window.svg"), tr("Window"),
                ToolType::Window);
  addToolAction(QIcon(":/assets/icons/measurement.svg"), tr("Measurement"),
                ToolType::Measurement);
  addToolAction(QIcon(":/assets/icons/furniture.svg"), tr("Furniture"),
                ToolType::Furniture);
  addToolAction(QIcon(":/assets/icons/text.svg"), tr("Text"), ToolType::Text);
}

void ToolBar::addToolAction(const QIcon& icon, const QString& text,
                            const ToolType& tool_type, const bool checked) {
  auto action = new QAction(icon, text, this);
  action->setCheckable(true);
  action->setChecked(checked);
  action->setData(static_cast<int>(tool_type));
  connect(action, &QAction::changed, this, &ToolBar::actionChanged);
  if (checked) {
    changeActiveTool(action);
  }
  addAction(action);
}

void ToolBar::actionChanged() {
  auto action = qobject_cast<QAction*>(sender());
  changeActiveTool(action);
}

void ToolBar::changeActiveTool(QAction* action) {
  if (action->isChecked()) {
    if (m_ActiveTool && action != m_ActiveTool) {
      m_ActiveTool->setChecked(false);
    }
    m_ActiveTool = action;
    emit toolSelected(static_cast<ToolType>(action->data().toInt()));
  }
}

}  // namespace room_sketcher