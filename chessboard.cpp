#include "chessboard.h"
#include <QObject>
#include <QPixmap>
#include <QLabel>
#include <map>
#include <string>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

ChessBoard::ChessBoard(QObject *parent) : QObject(parent)
{
    // Load the chess board image from the resources file
    chessBoardPixmap.load("../ChessTeacher/images/chessboard.png");
}

void ChessBoard::setChessBoardImage(QLabel *label)
{
    // Set the chess board image as the pixmap of the given QLabel
    label->setPixmap(chessBoardPixmap);
}

void ChessBoard::setPiecesOnBoardFreePlay(const std::map<std::string, QLabel*>& labels)
{
    // Map of positions to piece names
    std::map<std::string, std::string> pieces = {
        {"a1", "rook1w"}, {"b1", "knight1w"}, {"c1", "bishop1w"}, {"d1", "queenw"},
        {"e1", "kingw"}, {"f1", "bishop2w"}, {"g1", "knight2w"}, {"h1", "rook2w"},
        {"a2", "pawn1w"}, {"b2", "pawn2w"}, {"c2", "pawn3w"}, {"d2", "pawn4w"},
        {"e2", "pawn5w"}, {"f2", "pawn6w"}, {"g2", "pawn7w"}, {"h2", "pawn8w"},
        {"a7", "pawn1b"}, {"b7", "pawn2b"}, {"c7", "pawn3b"}, {"d7", "pawn4b"},
        {"e7", "pawn5b"}, {"f7", "pawn6b"}, {"g7", "pawn7b"}, {"h7", "pawn8b"},
        {"a8", "rook1b"}, {"b8", "knight1b"}, {"c8", "bishop1b"}, {"d8", "queenb"},
        {"e8", "kingb"}, {"f8", "bishop2b"}, {"g8", "knight2b"}, {"h8", "rook2b"}
    };

    // Loop over all the labels
    for (auto& label : labels) {
        // Get the position from the map key
        std::string position = label.first;

        // If the position has a corresponding piece name in the pieces map, set the piece on the label
        if (pieces.count(position) > 0) {
            std::string pieceName = pieces[position];
            setPieceOnLabel(label.second, QString::fromStdString(pieceName));
        }
    }
}

void ChessBoard::setPiecesOnBoardTactics(const std::map<std::string, QLabel*>& labels)
{
    // Map of positions to piece names
    std::map<std::string, std::string> pieces = {
        {"a1_2", "rook1w"}, {"b1_2", "knight1w"}, {"c1_2", "bishop1w"}, {"d1_2", "queenw"},
        {"e1_2", "kingw"}, {"f1_2", "bishop2w"}, {"g1_2", "knight2w"}, {"h1_2", "rook2w"},
        {"a2_2", "pawn1w"}, {"b2_2", "pawn2w"}, {"c2_2", "pawn3w"}, {"d2_2", "pawn4w"},
        {"e2_2", "pawn5w"}, {"f2_2", "pawn6w"}, {"g2_2", "pawn7w"}, {"h2_2", "pawn8w"},
        {"a7_2", "pawn1b"}, {"b7_2", "pawn2b"}, {"c7_2", "pawn3b"}, {"d7_2", "pawn4b"},
        {"e7_2", "pawn5b"}, {"f7_2", "pawn6b"}, {"g7_2", "pawn7b"}, {"h7_2", "pawn8b"},
        {"a8_2", "rook1b"}, {"b8_2", "knight1b"}, {"c8_2", "bishop1b"}, {"d8_2", "queenb"},
        {"e8_2", "kingb"}, {"f8_2", "bishop2b"}, {"g8_2", "knight2b"}, {"h8_2", "rook2b"}
    };

    // Loop over all the labels
    for (auto& label : labels) {
        // Get the position from the map key
        std::string position = label.first;

        // If the position has a corresponding piece name in the pieces map, set the piece on the label
        if (pieces.count(position) > 0) {
            std::string pieceName = pieces[position];
            setPieceOnLabel(label.second, QString::fromStdString(pieceName));
        }
    }
}

void ChessBoard::setPiecesOnBoardPuzzle(const std::map<std::string, QLabel*>& labels)
{
    // Map of positions to piece names
    std::map<std::string, std::string> pieces = {
        {"a1_3", "rook1w"}, {"b1_3", "knight1w"}, {"c1_3", "bishop1w"}, {"d1_3", "queenw"},
        {"e1_3", "kingw"}, {"f1_3", "bishop2w"}, {"g1_3", "knight2w"}, {"h1_3", "rook2w"},
        {"a2_3", "pawn1w"}, {"b2_3", "pawn2w"}, {"c2_3", "pawn3w"}, {"d2_3", "pawn4w"},
        {"e2_3", "pawn5w"}, {"f2_3", "pawn6w"}, {"g2_3", "pawn7w"}, {"h2_3", "pawn8w"},
        {"a7_3", "pawn1b"}, {"b7_3", "pawn2b"}, {"c7_3", "pawn3b"}, {"d7_3", "pawn4b"},
        {"e7_3", "pawn5b"}, {"f7_3", "pawn6b"}, {"g7_3", "pawn7b"}, {"h7_3", "pawn8b"},
        {"a8_3", "rook1b"}, {"b8_3", "knight1b"}, {"c8_3", "bishop1b"}, {"d8_3", "queenb"},
        {"e8_3", "kingb"}, {"f8_3", "bishop2b"}, {"g8_3", "knight2b"}, {"h8_3", "rook2b"}
    };

    // Loop over all the labels
    for (auto& label : labels) {
        // Get the position from the map key
        std::string position = label.first;

        // If the position has a corresponding piece name in the pieces map, set the piece on the label
        if (pieces.count(position) > 0) {
            std::string pieceName = pieces[position];
            setPieceOnLabel(label.second, QString::fromStdString(pieceName));
        }
    }
}

void ChessBoard::setPiecesOnBoardTutorial(const std::map<std::string, QLabel*>& labels)
{
    // Map of positions to piece names
    std::map<std::string, std::string> pieces = {
        {"a1_4", "rook1w"}, {"b1_4", "knight1w"}, {"c1_4", "bishop1w"}, {"d1_4", "queenw"},
        {"e1_4", "kingw"}, {"f1_4", "bishop2w"}, {"g1_4", "knight2w"}, {"h1_4", "rook2w"},
        {"a2_4", "pawn1w"}, {"b2_4", "pawn2w"}, {"c2_4", "pawn3w"}, {"d2_4", "pawn4w"},
        {"e2_4", "pawn5w"}, {"f2_4", "pawn6w"}, {"g2_4", "pawn7w"}, {"h2_4", "pawn8w"},
        {"a7_4", "pawn1b"}, {"b7_4", "pawn2b"}, {"c7_4", "pawn3b"}, {"d7_4", "pawn4b"},
        {"e7_4", "pawn5b"}, {"f7_4", "pawn6b"}, {"g7_4", "pawn7b"}, {"h7_4", "pawn8b"},
        {"a8_4", "rook1b"}, {"b8_4", "knight1b"}, {"c8_4", "bishop1b"}, {"d8_4", "queenb"},
        {"e8_4", "kingb"}, {"f8_4", "bishop2b"}, {"g8_4", "knight2b"}, {"h8_4", "rook2b"}
    };

//     Loop over all the labels
    for (auto& label : labels) {
        // Get the position from the map key
        std::string position = label.first;

        // If the position has a corresponding piece name in the pieces map, set the piece on the label
        if (pieces.count(position) > 0) {
            std::string pieceName = pieces[position];
            setPieceOnLabel(label.second, QString::fromStdString(pieceName));
        }
    }

}

void ChessBoard::resetPieceOnLabel(QLabel* label)
{
    QPixmap nullPixmap(1, 1);
    nullPixmap.fill(Qt::transparent);
    label->setPixmap(nullPixmap);
}

void ChessBoard::setPieceOnLabel(QLabel *label, QString piece)
{
    // Load the image of the piece and set it as the pixmap of the given QLabel
    QPixmap piecePixmap(QString("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/%1.png").arg(piece));
    label->setPixmap(piecePixmap);
}





