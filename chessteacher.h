#ifndef CHESSTEACHER_H
#define CHESSTEACHER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChessTeacher; }
QT_END_NAMESPACE

class ChessTeacher : public QMainWindow
{
    Q_OBJECT

public:
    ChessTeacher(QWidget *parent = nullptr);
    ~ChessTeacher();

private:
    Ui::ChessTeacher *ui;
};
#endif // CHESSTEACHER_H
