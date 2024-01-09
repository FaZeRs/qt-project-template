#include "project_manager.h"

namespace room_sketcher {
ProjectManager::ProjectManager(QObject* parent) : QObject(parent) {}

Project* ProjectManager::project() const { return m_Project.get(); }

void ProjectManager::createProject(const QSizeF& size) {
  if (m_Project) {
    qWarning("Project already created");
    return;
  }
  m_Project = std::make_unique<Project>(size, this);
}
}  // namespace room_sketcher