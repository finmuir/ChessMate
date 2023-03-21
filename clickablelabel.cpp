#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent)
    : QLabel(parent), m_piece(nullptr)
{
    setAttribute(Qt::WA_Hover, true);
}

void ClickableLabel::setPiece(Piece* piece)
{
    m_piece = piece;
}

Piece* ClickableLabel::piece() const
{
    return m_piece;
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}
