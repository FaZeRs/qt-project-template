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

  QRectF boundingRect() const final;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) final;

 private:
  QLineF m_Segment;
  qreal m_Width{parameters::wall_width};
};
}  // namespace room_sketcher