#pragma once

#include <QGraphicsScene>

namespace room_sketcher {
class GraphicsScene final : public QGraphicsScene {
 public:
  explicit GraphicsScene(QObject* parent = nullptr);
  GraphicsScene(const GraphicsScene&) = delete;
  GraphicsScene& operator=(const GraphicsScene&) = delete;
  GraphicsScene(GraphicsScene&&) = delete;
  GraphicsScene& operator=(GraphicsScene&&) = delete;
  ~GraphicsScene() final = default;
};
}  // namespace room_sketcher
