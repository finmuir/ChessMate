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
