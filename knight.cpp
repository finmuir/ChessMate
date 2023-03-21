#include "knight.h"
#include "chessmove.h"
#include "board.h"

Knight::Knight(Piece::Color color, int x, int y, Chessboard* board, QObject* parent)
    : Piece(Piece::Type::Knight, color, x, y, parent), m_board(board)
{
}

std::vector<ChessMove> Knight::getValidMoves() const
{
    std::vector<ChessMove> moves;

    if (m_square == nullptr) {
        return moves;
    }

    if (m_board == nullptr) {
        return moves;
    }

    // Possible moves of a knight
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        int x = m_x + dx[i];
        int y = m_y + dy[i];
        if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
            Piece* piece = m_board->pieceAt(x, y);
            if (piece == nullptr || piece->color() != m_color) {
                moves.push_back(ChessMove(m_x, m_y, x, y, m_board));
            }
        }
    }

    return moves;
}

bool Knight::canMove(int x, int y) const
{
    // Check if the move is valid for the knight
    std::vector<ChessMove> moves = getValidMoves();
    for (const ChessMove& move : moves) {
        if (move.endX() == x && move.endY() == y) {
            return true;
        }
    }
    return false;
}
