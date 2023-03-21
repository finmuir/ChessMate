#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>
#include <QLabel>
#include "piece.h"

class ChessTeacher;

class Chessboard : public QObject {
    Q_OBJECT

public:
    Chessboard(ChessTeacher* teacher, QObject* parent = nullptr);
    ~Chessboard();

    void initialize();
    Piece* pieceAt(int x, int y) const;
    void setPieceAt(int x, int y, Piece* piece);
    void movePiece(Piece* piece, int x, int y);

private:
    ChessTeacher* m_teacher;
    Piece* m_board[8][8];
    QLabel* m_squares[8][8];
    QLabel* m_square;
};

#endif // CHESSBOARD_H
