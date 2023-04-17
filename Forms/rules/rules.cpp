#include "rules.h"
#include "ui_rules.h"

rules::rules(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rules)
{
    ui->setupUi(this);
}


void rules::on_pushButton_clicked()
{
close();
}






rules::~rules()
{
    delete ui;
}


