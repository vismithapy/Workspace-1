#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsPathItem>
#include <QListWidgetItem>
#include <QMenuBar>
#include <QMenu>
#include <QMouseEvent>
#include <QPointF>
#include <QColor>
#include <QAction>
#include <QComboBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void addItemToScene(QListWidgetItem *item);
    void addProductToScene();
    //void createShape();
    void exportToXML();
    void uploadAssets();
    void showPreview();
    void importFromXML();
    void deleteSelectedItem();
    void setColor();
    void createShape();
    void zoomIn();
    void zoomOut();
    void selectRectangle();
    void selectCircle();
    void selectTriangle();

    // New Menu Options
    void saveFile();
    void saveFileAs();
    void addTextField();
    void drawCircle();
    void drawRectangle();
    void drawTriangle();
    void enableCustomDrawing();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    QComboBox *productComboBox;
    double currentScaleFactor;
    QColor selectedColor;

    // Custom Drawing
    QGraphicsPathItem *customPathItem;
    bool customDrawingEnabled;
    QPainterPath customPath;
    QGraphicsRectItem *selectionRect;  // Temporary rectangle for area selection

    QPointF selectionStartPoint;  // Starting point for the selection rectangle
    QPointF startPoint; // To store the starting point of the drag
    QGraphicsRectItem *currentRect; // Current rectangle being drawn
    QGraphicsEllipseItem *currentEllipse; // Current ellipse being drawn
    QPolygonF currentPolygon; // Current polygon (for triangle) being drawn
    QGraphicsPolygonItem *currentPolygonItem; // For triangle
    QString selectedShape; // The selected shape type (Rectangle, Circle, Triangle)

    void resetCurrentShape(); // To reset shape variables



    // Helper Functions
    void setupUI();
    void setupMenuBar();
    void drawGrid();
    void drawSections();
};

#endif // MAINWINDOW_H
