#include "wall.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace room_sketcher {
Wall::Wall(const QLineF& segment, QGraphicsItem* parent)
    : QGraphicsItem(parent), m_Segment(segment) {
  setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
  updateShape();
}

QRectF Wall::boundingRect() const {
  return m_BoundingPath.toFillPolygon().boundingRect();
}

void Wall::paint(QPainter* painter, const QStyleOptionGraphicsItem* /*option*/,
                 QWidget* /*widget*/) {
  painter->setPen(QPen(Qt::black, m_Width));
  painter->drawLine(m_Segment);

  if (isSelected()) {
    painter->setPen(QPen(Qt::black, 1, Qt::DashLine));
    painter->drawPolygon(m_BoundingPath.toFillPolygon());
  }
}

QPainterPath Wall::shape() const { return m_Shape; }

void Wall::updateShape() {
  QPainterPath path;
  path.moveTo(m_Segment.p1());
  path.lineTo(m_Segment.p2());

  QPainterPathStroker shape_stroker;
  shape_stroker.setWidth(m_Width);
  m_Shape = shape_stroker.createStroke(path);

  QPainterPathStroker bounding_stroker;
  bounding_stroker.setWidth(m_Width + parameters::selection_margin);
  m_BoundingPath = bounding_stroker.createStroke(path);
}

}  // namespace room_sketcher
