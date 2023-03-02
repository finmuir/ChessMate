#include "chessteacher.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessTeacher w;
    w.show();
    return a.exec();
}
