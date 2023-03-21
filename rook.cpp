#include "rook.h"
#include "chessmove.h"
#include "board.h"

Rook::Rook(Piece::Color color, int x, int y, Chessboard* board, QObject* parent) :
    Piece(Piece::Type::Rook, color, x, y, parent), m_board(board) {
}

std::vector<ChessMove> Rook::getValidMoves() const {
    std::vector<ChessMove> moves;
    if (m_square == nullptr) {
        return moves;
    }
    if (m_board == nullptr) {
        return moves;
    }

    // Move up the board.
    for (int y = m_y - 1; y >= 0; y--) {
        Piece* piece = m_board->pieceAt(m_x, y);
        if (piece == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, m_x, y, m_board));
        } else if (piece->color() != m_color) {
            moves.push_back(ChessMove(m_x, m_y, m_x, y, m_board));
            break;
        } else {
            break;
        }
    }

    // Move down the board.
    for (int y = m_y + 1; y < 8; y++) {
        Piece* piece = m_board->pieceAt(m_x, y);
        if (piece == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, m_x, y, m_board));
        } else if (piece->color() != m_color) {
            moves.push_back(ChessMove(m_x, m_y, m_x, y, m_board));
            break;
        } else {
            break;
        }
    }

    // Move left on the board.
    for (int x = m_x - 1; x >= 0; x--) {
        Piece* piece = m_board->pieceAt(x, m_y);
        if (piece == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, x, m_y, m_board));
        } else if (piece->color() != m_color) {
            moves.push_back(ChessMove(m_x, m_y, x, m_y, m_board));
            break;
        } else {
            break;
        }
    }

    // Move right on the board.
    for (int x = m_x + 1; x < 8; x++) {
        Piece* piece = m_board->pieceAt(x, m_y);
        if (piece == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, x, m_y, m_board));
        } else if (piece->color() != m_color) {
            moves.push_back(ChessMove(m_x, m_y, x, m_y, m_board));
            break;
        } else {
            break;
        }
    }

    return moves;
}

bool Rook::canMove(int x, int y) const {
    // Check if the move is valid for the rook
    if (m_square == nullptr) {
        return false;
    }
    if (m_x != x && m_y != y) {
        return false;
    }
    if (m_x == x && m_y == y) {
        return false;
    }
    int dx = (x - m_x == 0) ? 0 : ((x - m_x > 0) ? 1 : -1);
    int dy = (y - m_y == 0) ? 0 : ((y - m_y > 0) ? 1 : -1);
    for (int i = m_x + dx, j = m_y + dy; i != x || j != y; i += dx, j += dy) {
        if (m_board->pieceAt(i, j) != nullptr) {
            return false;
        }
    }
    return true;
}
