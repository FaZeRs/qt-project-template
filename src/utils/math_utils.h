#pragma once

#include <QLineF>
#include <QPolygonF>

namespace room_sketcher {
namespace math_utils {
QPolygonF lineToPolygon(const QLineF& line, const qreal width,
                        const qreal margin = 0);
}  // namespace math_utils
}  // namespace room_sketcher