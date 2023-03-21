#include "pawn.h"
#include "chessmove.h"
#include "board.h"

Pawn::Pawn(Piece::Color color, int x, int y, Chessboard* board, QObject* parent) :
    Piece(Piece::Type::Pawn, color, x, y, parent), m_board(board)
{
}

std::vector<ChessMove> Pawn::getValidMoves() const {
    std::vector<ChessMove> moves;
    if (m_square == nullptr) {
        return moves;
    }
    if (m_board == nullptr) {
        return moves;
    }
    if (m_color == Piece::Color::White) {
        if (m_y > 0 && m_board->pieceAt(m_x, m_y - 1) == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, m_x, m_y - 1, m_board));
        }
        if (m_y == 6 && m_board->pieceAt(m_x, m_y - 2) == nullptr && m_board->pieceAt(m_x, m_y - 1) == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, m_x, m_y - 2, m_board));
        }
        // Check for capturing other pieces
        if (m_x > 0 && m_y > 0) {
            Piece* piece = m_board->pieceAt(m_x - 1, m_y - 1);
            if (piece != nullptr && piece->color() != m_color) {
                moves.push_back(ChessMove(m_x, m_y, m_x - 1, m_y - 1, m_board));
            }
        }
        if (m_x < 7 && m_y > 0) {
            Piece* piece = m_board->pieceAt(m_x + 1, m_y - 1);
            if (piece != nullptr && piece->color() != m_color) {
                moves.push_back(ChessMove(m_x, m_y, m_x + 1, m_y - 1, m_board));
            }
        }
    } else {
        if (m_y < 7 && m_board->pieceAt(m_x, m_y + 1) == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, m_x, m_y + 1, m_board));
        }
        if (m_y == 1 && m_board->pieceAt(m_x, m_y + 2) == nullptr && m_board->pieceAt(m_x, m_y + 1) == nullptr) {
            moves.push_back(ChessMove(m_x, m_y, m_x, m_y + 2, m_board));
        }
        // Check for capturing other pieces
        if (m_x > 0 && m_y < 7) {
            Piece* piece = m_board->pieceAt(m_x - 1, m_y + 1);
            if (piece != nullptr && piece->color() != m_color) {
                moves.push_back(ChessMove(m_x, m_y, m_x - 1, m_y + 1, m_board));
            }
        }
        if (m_x < 7 && m_y < 7) {
            Piece* piece = m_board->pieceAt(m_x + 1, m_y + 1);
            if (piece != nullptr && piece->color() != m_color) {
                moves.push_back(ChessMove(m_x, m_y, m_x + 1, m_y + 1, m_board));
            }
        }
    }
    return moves;
}

bool Pawn::canMove(int x, int y) const {
    // Check if the move is valid for the pawn
    std::vector<ChessMove> moves = getValidMoves();
    for (const ChessMove& move : moves) {
        if (move.endX() == x && move.endY() == y) {
            return true;
        }
    }
    return false;
}







