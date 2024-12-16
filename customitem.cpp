#include "customitem.h"
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QKeyEvent>
#include <QCursor>

CustomItem::CustomItem(const QString &name, const QColor &color, const QSizeF &size, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), itemName(name)
{
    setRect(0, 0, size.width(), size.height());
    setBrush(color);

    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);

    setCursor(Qt::SizeAllCursor); // Default cursor for moving
}

// Mouse press: Initiate resizing or moving
void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QRectF rect = this->rect();
    QPointF clickPos = event->pos();

    // Detect bottom-right corner for resizing
    if (qAbs(clickPos.x() - rect.width()) < 10 && qAbs(clickPos.y() - rect.height()) < 10) {
        resizing = true;
        lastMousePos = event->scenePos();
        setCursor(Qt::SizeFDiagCursor);
    } else {
        QGraphicsRectItem::mousePressEvent(event);
    }
}

// Mouse move: Handle resizing or moving
void CustomItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (resizing) {
        QPointF delta = event->scenePos() - lastMousePos;

        QRectF newRect = rect();
        newRect.setWidth(qMax(20.0, newRect.width() + delta.x()));
        newRect.setHeight(qMax(20.0, newRect.height() + delta.y()));
        setRect(newRect);

        lastMousePos = event->scenePos();
    } else {
        QGraphicsRectItem::mouseMoveEvent(event);
    }
}

// Mouse release: Stop resizing
void CustomItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (resizing) {
        resizing = false;
        setCursor(Qt::SizeAllCursor);
    }
    QGraphicsRectItem::mouseReleaseEvent(event);
}

// Context menu: Handle rotate and delete actions
void CustomItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *rotateAction = menu.addAction("Rotate 45°");
    QAction *deleteAction = menu.addAction("Delete");

    QAction *selectedAction = menu.exec(event->screenPos());

    if (selectedAction == rotateAction) {
        setRotation(rotation() + 45);
    } else if (selectedAction == deleteAction) {
        delete this;
    }
}
