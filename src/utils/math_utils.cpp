#include "math_utils.h"

#include <QtMath>

namespace room_sketcher {
namespace math_utils {
QPolygonF lineToPolygon(const QLineF& line, const qreal width,
                        const qreal margin) {
  QPolygonF polygon;

  if (line.isNull()) {
    return polygon;
  }

  // Get the angle of the line
  //   qreal angle = line.angle();

  //   // Get the perpendicular angle
  //   qreal perpendicular_angle = angle + 90.0;

  //   // Calculate the offset for each endpoint of the line
  //   qreal dx =
  //       (width / 2.0 + margin) *
  //       qCos(qDegreesToRadians(perpendicular_angle));
  //   qreal dy =
  //       (width / 2.0 + margin) *
  //       qSin(qDegreesToRadians(perpendicular_angle));

  //   // Calculate the coordinates for the rectangle
  //   QPointF p1(line.p1().x() - dx, line.p1().y() - dy);
  //   QPointF p2(line.p2().x() - dx, line.p2().y() - dy);
  //   QPointF p3(line.p2().x() + dx, line.p2().y() + dy);
  //   QPointF p4(line.p1().x() + dx, line.p1().y() + dy);

  //   polygon << p1 << p2 << p3 << p4;

  QPointF p1 = line.p1();
  QPointF p2 = line.p2();

  // Calculate perpendicular vector
  QPointF v = p2 - p1;
  QPointF perpendicular(-v.y(), v.x());
  perpendicular /= QLineF(p1, p2).length();  // Normalize

  // Calculate vertices for the polygon
  QPointF offset = perpendicular * width / 2;
  QPointF marginOffset = perpendicular * margin;

  QPointF p1Left = p1 - offset - marginOffset;
  QPointF p1Right = p1 + offset - marginOffset;
  QPointF p2Left = p2 - offset + marginOffset;
  QPointF p2Right = p2 + offset + marginOffset;

  //   QPolygonF polygon;
  polygon << p1Left << p1Right << p2Right << p2Left;

  return polygon;
}
}  // namespace math_utils
}  // namespace room_sketcher