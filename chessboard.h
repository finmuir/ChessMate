#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>
#include <QPixmap>
#include <QLabel>
#include <map>
#include <string>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <map>

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
    void setPiecesOnBoardFreePlay(const std::map<std::string, QLabel*>& labels);

    //set the images of all pieces on the board on tactics page
    void setPiecesOnBoardTactics(const std::map<std::string, QLabel*>& labels);

    //set the images of all pieces on the board on puzzle page
    void setPiecesOnBoardPuzzle(const std::map<std::string, QLabel*>& labels);

    //set the images of all pieces on the board on puzzle page
    void setPiecesOnBoardTutorial(const std::map<std::string, QLabel*>& labels);

    void resetPieceOnLabel(QLabel* label);

    std::map<std::string, QLabel*> labels;

private:
    QPixmap chessBoardPixmap;
    // Define the game state as a 2D array of chess pieces
};

#endif // CHESSBOARD_H

