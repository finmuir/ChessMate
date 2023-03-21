#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include "piece.h"

//class ClickableLabel : public QLabel
//{
//    Q_OBJECT
//public:
//    explicit ClickableLabel(QWidget* parent = nullptr) : QLabel(parent) {}

//signals:
//    void clicked();

//protected:
//    void mousePressEvent(QMouseEvent* event) override {
//        if (event->button() == Qt::LeftButton) {
//            emit clicked();
//        }
//    }
//};

class ClickableLabel : public QLabel {
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget* parent = nullptr);
    Piece* piece() const;
    void setPiece(Piece* piece);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    Piece* m_piece;
};

#endif // CLICKABLELABEL_H

