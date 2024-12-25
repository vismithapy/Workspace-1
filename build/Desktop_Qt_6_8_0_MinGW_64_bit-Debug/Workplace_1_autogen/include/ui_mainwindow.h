/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidgetItems;
    QPushButton *buttonUploadAssets;
    QGraphicsView *graphicsViewCanvas;
    QPushButton *buttonExport;
    QPushButton *buttonImport;
    QPushButton *buttonDelete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1400, 1000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listWidgetItems = new QListWidget(centralwidget);
        listWidgetItems->setObjectName("listWidgetItems");
        listWidgetItems->setGeometry(QRect(10, 10, 200, 850));
        listWidgetItems->setProperty("isWrapping", QVariant(false));
        buttonUploadAssets = new QPushButton(centralwidget);
        buttonUploadAssets->setObjectName("buttonUploadAssets");
        buttonUploadAssets->setGeometry(QRect(10, 600, 200, 40));
        graphicsViewCanvas = new QGraphicsView(centralwidget);
        graphicsViewCanvas->setObjectName("graphicsViewCanvas");
        graphicsViewCanvas->setGeometry(QRect(220, 10, 1100, 900));
        buttonExport = new QPushButton(centralwidget);
        buttonExport->setObjectName("buttonExport");
        buttonExport->setGeometry(QRect(1220, 920, 150, 40));
        buttonImport = new QPushButton(centralwidget);
        buttonImport->setObjectName("buttonImport");
        buttonImport->setGeometry(QRect(1020, 920, 191, 40));
        buttonDelete = new QPushButton(centralwidget);
        buttonDelete->setObjectName("buttonDelete");
        buttonDelete->setGeometry(QRect(820, 920, 191, 40));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1400, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Workplace Planner", nullptr));
        buttonUploadAssets->setText(QCoreApplication::translate("MainWindow", "Upload Assets", nullptr));
        buttonExport->setText(QCoreApplication::translate("MainWindow", "Export Plan", nullptr));
        buttonImport->setText(QCoreApplication::translate("MainWindow", "Import Plan from XML", nullptr));
        buttonDelete->setText(QCoreApplication::translate("MainWindow", "Delete Selected Item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
