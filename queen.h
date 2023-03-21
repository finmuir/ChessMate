#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
public:
    Queen(Color color, int x, int y, Chessboard* board, QObject* parent = nullptr);
    std::vector<ChessMove> getValidMoves() const override;
    bool canMove(int y, int x) const override;

private:
    Chessboard* m_board;
};

#endif // QUEEN_H
