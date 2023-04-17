#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QGraphicsPixmapItem>
#include "chessbox.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class ChessBox;
class ChessPiece:public QGraphicsPixmapItem
{
public:
    ChessPiece(QString team = "",QGraphicsItem *parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setCurrentBox(ChessBox *box);

    ChessBox *getCurrentBox() ;

    int getColumn() ;
    int getRow() ;
    int gettype();


    QString getSide() ;
    void setSide( QString value);
    virtual void setImage() = 0;

    bool getIsPlaced() ;
    void setIsPlaced(bool value);

    QList <ChessBox *> moveLocation();
    virtual void moves() = 0;
    void decolor();

    bool firstMove;

    bool boxSetting(ChessBox *box);
protected:
    ChessBox *currentBox;
    QString side;
    bool isPlaced;
    int pieceType;
    QString chessboardLocation;
    QList <ChessBox *> location;

    int settype(const QString &piece);
};

#endif // CHESSPIECE_H
