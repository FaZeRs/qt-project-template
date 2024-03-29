#pragma once

#include "project.h"

namespace room_sketcher {

class ProjectManager final : public QObject {
 public:
  explicit ProjectManager(QObject* parent = nullptr);
  ProjectManager(const ProjectManager&) = delete;
  ProjectManager& operator=(const ProjectManager&) = delete;
  ProjectManager(ProjectManager&&) = delete;
  ProjectManager& operator=(ProjectManager&&) = delete;
  ~ProjectManager() final = default;

  [[nodiscard]] Project* project() const;
  void createProject(const QSizeF& size);

 private:
  std::unique_ptr<Project> m_Project{nullptr};
};

}  // namespace room_sketcher
