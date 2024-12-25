#ifndef CUSTOMGRAPHICSSCENE_H
#define CUSTOMGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsItem>
#include <QMenu>
#include <QObject>

class CustomGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CustomGraphicsScene(QObject *parent = nullptr);

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

signals:
    void shapeDeleted(QGraphicsItem *item);
    void shapeResized(QGraphicsItem *item);
};

#endif // CUSTOMGRAPHICSSCENE_H
