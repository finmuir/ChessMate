#include "labelclick.h"

Labelclick::Labelclick(QWidget* parent)
    : QLabel(parent)
{
}

void Labelclick::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
    QLabel::mousePressEvent(event);
}
