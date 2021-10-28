#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * button = new QPushButton(this);
    button->setText("Click Me");
    button->move(50,50);
    connect(button,&QPushButton::clicked,[=](){

        /*
        //This is the hard way
        QMessageBox message;
        message.setMinimumSize(300,200);
        message.setWindowTitle("MessageTitle");
        message.setText("Something here");
        message.setInformativeText("Do something here");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);
        //int ret = message.exec();
        */

       //Best way to show a critical message
       int ret = QMessageBox::critical(this,"Message Title","Something Happend, Do you want to continue?",QMessageBox::Ok,QMessageBox::Cancel);

       /*
        * There are other ways that you can do the same thing for information box etc.
        *
        * Below is an information box
        * int ret = QMessageBox::information(this,"Message Title","Something Happend, Do you want to continue?",QMessageBox::Ok,QMessageBox::Cancel);
        *
        * Below is a Question Box
        * int ret = QMessageBox::question(this,"Message Title","Something Happend, Do you want to continue?",QMessageBox::Ok,QMessageBox::Cancel);
        *
        * Below is a Warning box
        * int ret = QMessageBox::warning(this,"Message Title","Something Happend, Do you want to continue?",QMessageBox::Ok,QMessageBox::Cancel);
        */




        if(ret == QMessageBox::Ok)
        {
            qDebug() << "User Clicked OK";
        }

        if(ret == QMessageBox::Cancel)
        {
            qDebug() << "Clicked Cancel";
        }

    });

}

Widget::~Widget()
{
}

QSize Widget::sizeHint() const
{
    return QSize(500,500);
}

