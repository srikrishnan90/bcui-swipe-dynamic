#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QVBoxLayout * lay = new QVBoxLayout(this);
    QGridLayout * lay = new QGridLayout(this);
    const QSize btnSize = QSize(150, 50);
    for (int i=0;i<15 ;i++ )
    {
        for (int j=0;j<5 ;j++ )
        {
            QString s1 = QString::number(i);
             QString s2 = QString::number(j);
            QPushButton *button = new QPushButton("button"+s1+s2);
            button->setFixedSize(btnSize);
            button->setObjectName("button"+s1+s2);
            connect(button, &QPushButton::clicked, this, &MainWindow::cald);
            lay->addWidget(button,i,j);
        }

    }
    ui->scrollAreaWidgetContents->setLayout(lay);
    //ui->scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff ) ;

    // for swipe based scroll
    QWidget *w = ui->scrollArea;
    QScroller::grabGesture(w, QScroller::LeftMouseButtonGesture);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::cald()
{
    QObject *senderObj = sender(); // This will give Sender object
        QString senderObjName = senderObj->objectName();
        qDebug()<< "Button: " << senderObjName;;
        ui->label->setText(senderObjName);
}


