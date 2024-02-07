#pragma once

#include <QGraphicsView>

namespace room_sketcher {
class GraphicsView final : public QGraphicsView {
 public:
  explicit GraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr);
  GraphicsView(const GraphicsView&) = delete;
  GraphicsView& operator=(const GraphicsView&) = delete;
  GraphicsView(GraphicsView&&) = delete;
  GraphicsView& operator=(GraphicsView&&) = delete;
  ~GraphicsView() final = default;
};
}  // namespace room_sketcher
