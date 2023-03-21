#include "piece.h"
#include <QObject>

Piece::Piece(Piece::Type type, Piece::Color color, int x, int y, QObject* parent)
    : QObject(parent), m_type(type), m_color(color), m_x(x), m_y(y), m_square(nullptr) {}

Piece::~Piece() {}

Piece::Color Piece::color() const {
    return m_color;
}

Piece::Type Piece::type() const {
    return m_type;
}

int Piece::x() const {
    return m_x;
}

int Piece::y() const {
    return m_y;
}

void Piece::setPosition(int x, int y) {
    m_x = x;
    m_y = y;
}

void Piece::setSquare(QLabel* square) {
    m_square = square;
}

QLabel* Piece::square() const {
    return m_square;
}







