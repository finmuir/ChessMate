#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>
#include <QPixmap>
#include <QLabel>
#include <map>
#include <string>

class ChessBoard : public QObject
{
    Q_OBJECT

public:
    explicit ChessBoard(QObject *parent = nullptr);

    // Set the chess board image as the pixmap of the given QLabel
    void setChessBoardImage(QLabel *label);

    // Set the image of a piece on a specific label
    void setPieceOnLabel(QLabel *label, QString piece);

    // Set the images of all pieces on the board
    void setPiecesOnBoard(const std::map<std::string, QLabel*>& labels);

private:
    QPixmap chessBoardPixmap;
};

#endif // CHESSBOARD_H

