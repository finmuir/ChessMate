#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
public:
    Knight(Color color, int x, int y, Chessboard* board, QObject* parent = nullptr);
    std::vector<ChessMove> getValidMoves() const override;
    bool canMove(int y, int x) const override;

private:
    Chessboard* m_board;
};

#endif // KNIGHT_H
