#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customitem.h"
#include <QFile>
#include <QDomDocument>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Workplace Planner");
    resize(1200, 800);

    // Initialize the scene
    scene = new QGraphicsScene(this);
    ui->graphicsViewCanvas->setScene(scene);
    ui->graphicsViewCanvas->setFocus();
    ui->graphicsViewCanvas->setInteractive(true);

    setupUI();
    drawGrid();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Initialize the UI
void MainWindow::setupUI()
{
    QStringList items = {"Chair", "Table", "Work Zone", "Office Zone", "Storage Zone"};
    for (const QString &item : items) {
        ui->listWidgetItems->addItem(item);
    }

    connect(ui->listWidgetItems, &QListWidget::itemClicked, this, &MainWindow::addItemToScene);
    connect(ui->buttonExport, &QPushButton::clicked, this, &MainWindow::exportToXML);
    connect(ui->buttonImport, &QPushButton::clicked, this, &MainWindow::importFromXML);
}

// Draw grid lines for alignment
void MainWindow::drawGrid()
{
    const int gridSize = 50;
    const int sceneSize = 2000;
    QPen gridPen(QColor(200, 200, 200, 50), 1, Qt::DotLine);

    for (int x = 0; x < sceneSize; x += gridSize)
        scene->addLine(x, 0, x, sceneSize, gridPen)->setZValue(-10);

    for (int y = 0; y < sceneSize; y += gridSize)
        scene->addLine(0, y, sceneSize, y, gridPen)->setZValue(-10);

    scene->setSceneRect(0, 0, sceneSize, sceneSize);
}

// Add an item to the workspace
void MainWindow::addItemToScene(QListWidgetItem *item)
{
    CustomItem *customItem = nullptr;

    if (item->text() == "Chair") {
        customItem = new CustomItem("Chair");
        customItem->setRect(0, 0, 50, 50);
        customItem->setBrush(Qt::gray);
        customItem->setPen(QPen(Qt::black, 1));
    } else if (item->text() == "Table") {
        customItem = new CustomItem("Table");
        customItem->setRect(0, 0, 100, 50);
        customItem->setBrush(Qt::blue);
        customItem->setPen(QPen(Qt::darkBlue, 1));
    } else if (item->text() == "Work Zone") {
        customItem = new CustomItem("Work Zone");
        customItem->setRect(0, 0, 200, 150);
        customItem->setBrush(QColor("#98FB98"));
        customItem->setPen(QPen(Qt::darkGreen, 1));
    } else if (item->text() == "Office Zone") {
        customItem = new CustomItem("Office Zone");
        customItem->setRect(0, 0, 200, 150);
        customItem->setBrush(QColor("#FFEB3B"));
        customItem->setPen(QPen(Qt::darkYellow, 1));
    } else if (item->text() == "Storage Zone") {
        customItem = new CustomItem("Storage Zone");
        customItem->setRect(0, 0, 200, 150);
        customItem->setBrush(QColor("#FF9800"));
        customItem->setPen(QPen(Qt::darkRed, 1));
    }

    if (customItem) {
        customItem->setZValue(0);
        scene->addItem(customItem);
    }
}
// Export the workspace to an XML file
void MainWindow::exportToXML()
{
    QDomDocument doc;
    QDomElement root = doc.createElement("workspace");
    doc.appendChild(root);

    for (QGraphicsItem *item : scene->items()) {
        CustomItem *customItem = dynamic_cast<CustomItem *>(item);
        if (customItem) {
            QDomElement element = doc.createElement("Object");
            element.setAttribute("name", customItem->getName());
            element.setAttribute("x", customItem->x());
            element.setAttribute("y", customItem->y());
            element.setAttribute("width", customItem->rect().width());
            element.setAttribute("height", customItem->rect().height());
            element.setAttribute("rotation", customItem->rotation());
            element.setAttribute("zValue", customItem->zValue());
            root.appendChild(element);
        }
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Export Plan", "", "XML Files (*.xml)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream stream(&file);
            doc.save(stream, 4);
            file.close();
            QMessageBox::information(this, "Success", "Plan exported successfully!");
        }
    }
}

// Import a workspace from an XML file
void MainWindow::importFromXML()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Import Plan", "", "XML Files (*.xml)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open XML file.");
        return;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        QMessageBox::critical(this, "Error", "Failed to parse XML file.");
        file.close();
        return;
    }
    file.close();

    scene->clear();
    drawGrid();

    QDomNodeList objects = doc.documentElement().elementsByTagName("Object");

    for (int i = 0; i < objects.count(); ++i) {
        QDomElement element = objects.at(i).toElement();

        QString name = element.attribute("name");
        qreal x = element.attribute("x").toDouble();
        qreal y = element.attribute("y").toDouble();
        qreal width = element.attribute("width").toDouble();
        qreal height = element.attribute("height").toDouble();
        qreal rotation = element.attribute("rotation").toDouble();
        qreal zValue = element.attribute("zValue").toDouble();

        CustomItem *item = new CustomItem(name, Qt::gray, QSizeF(width, height));
        item->setPos(x, y);
        item->setRotation(rotation);
        item->setZValue(zValue);
        scene->addItem(item);
    }

    QMessageBox::information(this, "Success", "Plan imported successfully!");
}
