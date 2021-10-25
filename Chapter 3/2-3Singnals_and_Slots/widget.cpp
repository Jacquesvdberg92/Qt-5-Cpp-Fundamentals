#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    Here ar 3 ways to manually us Slots & Signls:
    */

    //1.String Notation
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(changeText()));



    //2.Functor Notation : Regular Slots
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::changeText);



    //3.Functor Notation : Lambdas
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->label->setText("Lambdas");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    qDebug() << "User Clicked the Button";
    ui->label->setText("Hello there");
}

