#include "graphics_view.h"

namespace room_sketcher {
GraphicsView::GraphicsView(QGraphicsScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent) {
  setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing |
                 QPainter::SmoothPixmapTransform);
  setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
  setDragMode(QGraphicsView::RubberBandDrag);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setCacheMode(QGraphicsView::CacheBackground);
  setOptimizationFlags(QGraphicsView::DontSavePainterState);
  setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
  setMouseTracking(true);
}
}  // namespace room_sketcher
