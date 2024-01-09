#include "project.h"

namespace room_sketcher {
Project::Project(const QSizeF& size, QObject* parent)
    : QObject(parent), m_Size(size) {}
}  // namespace room_sketcher