#include "mainwindow.h"
#include <QPushButton> //adds button class
#include <QDebug>
#include <QApplication>
#include <QMenu>
#include <QMenuBar> //adds menuBar class
#include <QStatusBar> // adds StatusBar class
#include <QAction> //this allows you to use the same 'actions' and the code that handles them in different places

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Add central widget
    QPushButton * button = new QPushButton("Hello",this);
    setCentralWidget(button); //This will be the center item, and will fill the whole windows

    //Declare Quit Action
    QAction * quitAction = new QAction("Quit");
    connect(quitAction,&QAction::triggered,[=](){
        QApplication::quit();
    });
    //Adds Menu bar items
    QMenu * fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("window");
    menuBar()->addMenu("Help");

    //Add status bar
    statusBar()->showMessage("Uploading file...",3000); //this shows the message on the status bar for 3000 miliseconds
    //statusBar()->clearMessage();

}

MainWindow::~MainWindow()
{
}

QSize MainWindow::sizeHint() const
{
    return QSize(800,500);
}

