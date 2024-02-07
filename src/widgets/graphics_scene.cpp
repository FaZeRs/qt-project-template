#include "graphics_scene.h"

#include "../items/wall.h"

namespace room_sketcher {
GraphicsScene::GraphicsScene(QObject* parent) : QGraphicsScene(parent) {
  setBackgroundBrush(QBrush(Qt::white));

  const auto wall = new Wall(QLineF(50, 50, 100, 150));
  addItem(wall);
}
}  // namespace room_sketcher