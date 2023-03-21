#include "queen.h"
#include "chessmove.h"
#include "board.h"

Queen::Queen(Piece::Color color, int x, int y, Chessboard* board, QObject* parent) :
    Piece(Piece::Type::Queen, color, x, y, parent), m_board(board)
{
}

std::vector<ChessMove> Queen::getValidMoves() const {
    std::vector<ChessMove> moves;
    if (m_square == nullptr) {
        return moves;
    }
    if (m_board == nullptr) {
        return moves;
    }
    // Check the moves in all 8 directions
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            for (int i = 1; i <= 7; i++) {
                int newX = m_x + i * dx;
                int newY = m_y + i * dy;
                if (newX < 0 || newX > 7 || newY < 0 || newY > 7) {
                    break;
                }
                Piece* piece = m_board->pieceAt(newX, newY);
                if (piece == nullptr) {
                    moves.push_back(ChessMove(m_x, m_y, newX, newY, m_board));
                } else if (piece->color() != m_color) {
                    moves.push_back(ChessMove(m_x, m_y, newX, newY, m_board));
                    break;
                } else {
                    break;
                }
            }
        }
    }
    return moves;
}

bool Queen::canMove(int x, int y) const {
    // Check if the move is valid for the queen
    std::vector<ChessMove> moves = getValidMoves();
    for (const ChessMove& move : moves) {
        if (move.endX() == x && move.endY() == y) {
            return true;
        }
    }
    return false;
}
