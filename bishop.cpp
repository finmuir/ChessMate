#include "bishop.h"
#include "chessmove.h"
#include "board.h"

Bishop::Bishop(Color color, int x, int y, Chessboard* board, QObject* parent)
    : Piece(Piece::Type::Bishop, color, x, y, parent), m_board(board)
{
}

std::vector<ChessMove> Bishop::getValidMoves() const {
    std::vector<ChessMove> moves;
    if (m_square == nullptr) {
        return moves;
    }
    if (m_board == nullptr) {
        return moves;
    }
    // Check for valid moves in all diagonal directions
    int x = m_x + 1, y = m_y + 1;
    while (x < 8 && y < 8) {
        Piece* piece = m_board->pieceAt(x, y);
        if (piece == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, x, y, m_board));
        } else if (piece->color() != m_color) {
            moves.push_back(ChessMove(m_x, m_y, x, y, m_board));
            break;
        } else {
            break;
        }
        x++;
        y++;
    }
    x = m_x - 1;
    y = m_y + 1;
    while (x >= 0 && y < 8) {
        Piece* piece = m_board->pieceAt(x, y);
        if (piece == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, x, y, m_board));
        } else if (piece->color() != m_color) {
            moves.push_back(ChessMove(m_x, m_y, x, y, m_board));
            break;
        } else {
            break;
        }
        x--;
        y++;
    }
    x = m_x - 1;
    y = m_y - 1;
    while (x >= 0 && y >= 0) {
        Piece* piece = m_board->pieceAt(x, y);
        if (piece == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, x, y, m_board));
        } else if (piece->color() != m_color) {
            moves.push_back(ChessMove(m_x, m_y, x, y, m_board));
            break;
        } else {
            break;
        }
        x--;
        y--;
    }
    x = m_x + 1;
    y = m_y - 1;
    while (x < 8 && y >= 0) {
        Piece* piece = m_board->pieceAt(x, y);
        if (piece == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, x, y, m_board));
        } else if (piece->color() != m_color) {
            moves.push_back(ChessMove(m_x, m_y, x, y, m_board));
            break;
        } else {
            break;
        }
        x++;
        y--;
    }
    return moves;
}

bool Bishop::canMove(int x, int y) const {
    // Check if the move is valid for the bishop
    std::vector<ChessMove> moves = getValidMoves();
    for (const ChessMove& move : moves) {
        if (move.endX() == x && move.endY() == y) {
            return true;
        }
    }
    return false;
}


