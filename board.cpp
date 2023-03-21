#include "board.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "piece.h"
#include "chessteacher.h"

Chessboard::Chessboard(ChessTeacher* teacher, QObject* parent) : QObject(parent), m_teacher(teacher) {
    initialize();
}

Chessboard::~Chessboard() {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            delete m_board[x][y];
        }
    }
}

void Chessboard::initialize() {
    // Clear the board
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            m_board[x][y] = nullptr;
        }
    }

    for (int x = 0; x < 8; ++x) {
        m_board[x][6] = new Pawn(Piece::Color::Black, x, 6, this);
        m_board[x][1] = new Pawn(Piece::Color::White, x, 1, this);
    }

    m_board[0][7] = new Rook(Piece::Color::Black, 0, 7, this);
    m_board[7][7] = new Rook(Piece::Color::Black, 7, 7, this);
    m_board[1][7] = new Knight(Piece::Color::Black, 1, 7, this);
    m_board[6][7] = new Knight(Piece::Color::Black, 6, 7, this);
    m_board[2][7] = new Bishop(Piece::Color::Black, 2, 7, this);
    m_board[5][7] = new Bishop(Piece::Color::Black, 5, 7, this);
    m_board[3][7] = new Queen(Piece::Color::Black, 3, 7, this);
    m_board[4][7] = new King(Piece::Color::Black, 4, 7, this);

    m_board[0][0] = new Rook(Piece::Color::White, 0, 0, this);
    m_board[7][0] = new Rook(Piece::Color::White, 7, 0, this);
    m_board[1][0] = new Knight(Piece::Color::White, 1, 0, this);
    m_board[6][0] = new Knight(Piece::Color::White, 6, 0, this);
    m_board[2][0] = new Bishop(Piece::Color::White, 2, 0, this);
    m_board[5][0] = new Bishop(Piece::Color::White, 5, 0, this);
    m_board[3][0] = new Queen(Piece::Color::White, 3, 0, this);
    m_board[4][0] = new King(Piece::Color::White, 4, 0, this);

    for (int x = 0; x < 8; ++x) {
           for (int y = 0; y < 8; ++y) {
               m_teacher->displayPiece(x, y, m_board[x][y]);
           }
       }
}


Piece* Chessboard::pieceAt(int x, int y) const {
    return m_board[x][y];
}

void Chessboard::setPieceAt(int x, int y, Piece* piece) {
    m_board[x][y] = piece;
}

void Chessboard::movePiece(Piece* piece, int x, int y) {
    // Check if move is valid
    if (piece->canMove(x, y)) {
        // Clear old position
        int oldX = piece->x();
        int oldY = piece->y();
        m_board[oldX][oldY] = nullptr;

        // Set new position
        piece->setPosition(x, y);
        m_board[x][y] = piece;

        // Update GUI
        m_teacher->movePiece(oldX, oldY, x, y);
    }
}

