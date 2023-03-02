#include "chessteacher.h"
#include "./ui_chessteacher.h"
#include <QGraphicsScene>
#include <QtCore>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDesktopServices>

ChessTeacher::ChessTeacher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessTeacher)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->HomePage);

    QPixmap pix("../ChessTeacher/images/ChessPiecesWallpaper.png");
    ui->homepageWallpaper->setPixmap(pix);

    QPixmap pix1("../ChessTeacher/images/book2.png");
    ui->tutorialimage->setPixmap(pix1);
}

ChessTeacher::~ChessTeacher()
{
    delete ui;
}

void ChessTeacher::on_startgameButton_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->GameplayPage);
}

void ChessTeacher::on_exitgameButton_clicked()
{
   QApplication::quit();
}


void ChessTeacher::on_newsButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.chess.com/news"));
}

void ChessTeacher::on_rulesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->RulesPage);
}


void ChessTeacher::on_gametomenuButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
}


void ChessTeacher::on_rulestomenuButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
}

