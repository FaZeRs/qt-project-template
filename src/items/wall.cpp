#include "wall.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

#include "../utils/math_utils.h"

namespace room_sketcher {
Wall::Wall(const QLineF& segment, QGraphicsItem* parent)
    : QGraphicsItem(parent), m_Segment(segment) {
  setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

QRectF Wall::boundingRect() const {
  const auto polygon = math_utils::lineToPolygon(m_Segment, m_Width);
  return polygon.boundingRect();
}

void Wall::paint(QPainter* painter, const QStyleOptionGraphicsItem* /*option*/,
                 QWidget* /*widget*/) {
  painter->setPen(QPen(Qt::black, m_Width));
  painter->drawLine(m_Segment);

  // if (isSelected()) {
  painter->setPen(QPen(Qt::red, 1, Qt::DashLine));
  const auto polygon = math_utils::lineToPolygon(m_Segment, m_Width, 10);
  painter->drawPolygon(polygon);
  //}
}

}  // namespace room_sketcher