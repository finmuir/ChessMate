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

