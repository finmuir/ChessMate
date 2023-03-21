#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QLabel>
#include "chessmove.h"

class Piece : public QObject
{
    Q_OBJECT
public:
    enum class Type {
        King,
        Queen,
        Rook,
        Bishop,
        Knight,
        Pawn
    };

    enum class Color {
        White,
        Black
    };

    Piece(Type type, Color color, int x, int y, QObject* parent = nullptr);
    virtual ~Piece();

    virtual std::vector<ChessMove> getValidMoves() const = 0;

    Type type() const;
    Color color() const;
    int x() const;
    int y() const;
    void setX(int x);
    void setY(int y);

    // This function is used to set the pointer to the QLabel that represents the piece
    void setSquare(QLabel* square);
    QLabel* square() const;

    // This function should be overridden by each Piece subclass
    virtual bool canMove(int x, int y) const = 0;
    void setPosition(int x, int y);
    int m_x;
    int m_y;
    Color m_color;
    QLabel* m_square;
    Chessboard* m_board;

private:
    Type m_type;
};

#endif // PIECE_H
