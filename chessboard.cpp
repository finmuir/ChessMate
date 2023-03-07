#include "chessboard.h"

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

void ChessBoard::setPiecesOnBoard(const std::map<std::string, QLabel*>& labels)
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

void ChessBoard::setPieceOnLabel(QLabel *label, QString piece)
{
    // Load the image of the piece and set it as the pixmap of the given QLabel
    QPixmap piecePixmap(QString("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/%1.png").arg(piece));
    label->setPixmap(piecePixmap);
}



