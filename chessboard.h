#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>
#include <QPixmap>
#include <QLabel>

class ChessBoard : public QObject
{
    Q_OBJECT

public:
    explicit ChessBoard(QObject *parent = nullptr);

    // Set the chess board image as the pixmap of the given QLabel
    void setChessBoardImage(QLabel *label);

private:
    QPixmap chessBoardPixmap;
};

#endif // CHESSBOARD_H

