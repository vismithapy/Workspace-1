#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>

class CustomItem : public QGraphicsRectItem
{
public:
    explicit CustomItem(const QString &name, const QColor &color = Qt::gray,
                        const QSizeF &size = QSizeF(50, 50), QGraphicsItem *parent = nullptr);

    QString getName() const { return itemName; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

private:
    QString itemName;
    QPointF lastMousePos;    // Track last mouse position for resizing
    bool resizing = false;   // True if resizing
    bool rotateMode = false; // True if rotation is enabled

    void showContextMenu(const QPointF &pos); // Display the context menu
};

#endif // CUSTOMITEM_H
