#include "chessteacher.h"
#include "./ui_chessteacher.h"
#include <QGraphicsScene>
#include <QtCore>
#include <QPixmap>
#include <QGraphicsPixmapItem>

ChessTeacher::ChessTeacher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessTeacher)
{
    ui->setupUi(this);


    QPixmap pix("../ChessTeacher/images/ChessPiecesWallpaper.png");
    ui->homepageWallpaper->setPixmap(pix);
}

ChessTeacher::~ChessTeacher()
{
    delete ui;
}

void ChessTeacher::on_startgameButton_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->GameplayPage);
}

