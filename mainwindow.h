#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QListWidgetItem>
#include "customitem.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addItemToScene(QListWidgetItem *item); // Add objects to the workspace
    void exportToXML();                         // Export workspace to XML
    void importFromXML();                       // Import workspace from XML

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    void setupUI();  // Setup the UI and signals
    void drawGrid(); // Draw grid lines in the workspace
};

#endif // MAINWINDOW_H
