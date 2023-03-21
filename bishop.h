#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(Color color, int x, int y, Chessboard* board, QObject* parent = nullptr);
    std::vector<ChessMove> getValidMoves() const override;
    bool canMove(int y, int x) const override;

private:
    Chessboard* m_board;
};

#endif // BISHOP_H
