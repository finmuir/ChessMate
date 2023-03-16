#include "chessteacher.h"
#include "./ui_chessteacher.h"

ChessTeacher::ChessTeacher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessTeacher)
{
    ui->setupUi(this);
}

ChessTeacher::~ChessTeacher()
{
    delete ui;
}

void ChessTeacher::on_startgameButton_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->GameModePage);
}


void ChessTeacher::on_beginnerButton_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->BeginnerPage);
}


void ChessTeacher::on_tutorialButton_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->TutorialPage);
}

