#include "rockwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
    //Changes windows title
    setWindowTitle("Rock Widget Here");

    //Add a label to the widget
    QLabel * label = new QLabel("This is a label",this);

    //add a styled widget and move it around

    //This will add colour
    QPalette label1Palette;
    //This will allow you to highlight the text in the label
    label1Palette.setColor(QPalette::Window,Qt::yellow);
    //This will change the colour of the text in the label
    label1Palette.setColor(QPalette::WindowText,Qt::blue);
    //The below line styles font
    QFont label1Font("Times", 20,QFont::Bold);
    QLabel * label1 = new QLabel(this);
    //you need to add the below to highlight the text
    label1->setAutoFillBackground(true);
    //Sets label text
    label1->setText("This is style");
    //Assign the font set above to the label text
    label1->setFont(label1Font);
    //Sets label text colour
    label1->setPalette(label1Palette);
    //This moves the label location
    label1->move(50,50);

    //Adding a second label:
    QPalette label2Palette;
    label2Palette.setColor(QPalette::Window,Qt::green);
    label2Palette.setColor(QPalette::WindowText,Qt::black);

    QLabel *mLabel2 = new QLabel(this);
    mLabel2->setAutoFillBackground(true);
    mLabel2->setPalette(label2Palette);
    mLabel2->setText("this is a second label");
    mLabel2->move(70,170);
    QFont seriFont("Times", 20, QFont::Bold);
    mLabel2->setFont(seriFont);

    //Add a Button
    QFont buttonFont("Time", 20, QFont::Bold);
    QPushButton * button = new QPushButton(this);
    button->setText("Click me");
    button->setFont(buttonFont);
    button->move(100,250);
    connect(button,SIGNAL(clicked()),this,SLOT(buttonClicked())); //This makes the button listen for a signal

}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this,"Message","You clicked");
}

QSize RockWidget::sizeHint() const
{
    return QSize(500,500);
}
