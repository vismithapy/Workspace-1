#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <QPixmap>
#include <QKeyEvent>

class CustomItem : public QGraphicsPixmapItem
{
public:
    explicit CustomItem(const QString &name, const QString &imagePath,
                        QGraphicsItem *parent = nullptr);

    QString getName() const { return itemName; }

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override; // Right-click menu
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;        // Start resizing
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;         // Handle resizing
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;      // Stop resizing
    void keyPressEvent(QKeyEvent *event) override;                         // Handle keyboard events for resizing

private:
    void resizeItem(qreal scaleFactor); // Resize the item by a factor

    QString itemName;
    QPixmap originalPixmap;       // Store the original pixmap to maintain clarity during resizing
    bool resizing = false;        // Flag to check if resizing is active
    QPointF lastMousePos;         // Last position of the mouse during resizing
    QRectF originalRect;          // Store the original size for scaling
};

#endif // CUSTOMITEM_H
