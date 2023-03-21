#include "king.h"
#include "chessmove.h"
#include "board.h"

King::King(Piece::Color color, int x, int y, Chessboard* board, QObject* parent) :
    Piece(Piece::Type::King, color, x, y, parent), m_board(board)
{
}

std::vector<ChessMove> King::getValidMoves() const {
    std::vector<ChessMove> moves;
    if (m_square == nullptr) {
        return moves;
    }
    if (m_board == nullptr) {
        return moves;
    }

    // Check for moves in all directions (horizontally, vertically, diagonally) with a maximum of 1 square away
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;  // Skip the current position
            int toX = m_x + i;
            int toY = m_y + j;
            if (toX < 0 || toX > 7 || toY < 0 || toY > 7) continue;  // Skip if out of bounds
            Piece* piece = m_board->pieceAt(toX, toY);
            if (piece == nullptr || piece->color() != m_color) {
                moves.push_back(ChessMove(m_x, m_y, toX, toY, m_board));
            }
        }
    }

    return moves;
}

bool King::canMove(int x, int y) const {
    // Check if the move is valid for the king
    std::vector<ChessMove> moves = getValidMoves();
    for (const ChessMove& move : moves) {
        if (move.endX() == x && move.endY() == y) {
            return true;
        }
    }
    return false;
}
