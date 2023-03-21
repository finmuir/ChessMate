#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "chessmove.h"

class Pawn : public Piece {
public:
    Pawn(Color color, int x, int y, Chessboard* board, QObject* parent = nullptr);
    std::vector<ChessMove> getValidMoves() const override;
    bool canMove(int y, int x) const override;

private:
    Chessboard* m_board;
};

#endif // PAWN_H
