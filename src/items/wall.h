#pragma once

#include <QGraphicsItem>

#include "../core/parameters.h"

namespace room_sketcher {
class Wall final : public QGraphicsItem {
 public:
  explicit Wall(const QLineF& segment, QGraphicsItem* parent = nullptr);
  Wall(const Wall&) = delete;
  Wall& operator=(const Wall&) = delete;
  Wall(Wall&&) = delete;
  Wall& operator=(Wall&&) = delete;
  ~Wall() final = default;

  [[nodiscard]] QRectF boundingRect() const final;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) final;
  [[nodiscard]] QPainterPath shape() const final;

 private:
  QLineF m_Segment;
  qreal m_Width{parameters::wall_width};
  QPainterPath m_Shape;
  QPainterPath m_BoundingPath;

  void updateShape();
};
}  // namespace room_sketcher
