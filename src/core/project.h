#pragma once

#include <QObject>
#include <QSize>
#include <QUndoStack>

namespace room_sketcher {

class Project final : public QObject {
 public:
  Project(const QSizeF& size, QObject* parent = nullptr);
  Project(const Project&) = delete;
  Project& operator=(const Project&) = delete;
  Project(Project&&) = delete;
  Project& operator=(Project&&) = delete;
  ~Project() final = default;

 private:
  QSizeF m_Size;
  QUndoStack m_UndoStack;
};

}  // namespace room_sketcher