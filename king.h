#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
public:
    King(Color color, int x, int y, Chessboard* board, QObject* parent = nullptr);
    std::vector<ChessMove> getValidMoves() const override;
    bool canMove(int y, int x) const override;

private:
    Chessboard* m_board;
};

#endif // KING_H
