#include "chesspiece.h"
#include "game.h"
#include <QDebug>
#include "chesspiece/king.h"

extern Game *game;
ChessPiece::ChessPiece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
    firstMove = true;
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Deselect
    if(this == game->pieceToMove){
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->decolor();
        game->pieceToMove = NULL;
       return;
    }
    //if it is already consumed or not the respective color's turn
    if((!getIsPlaced() )|| ( (game->getTurn() != this->getSide())&& (!game->pieceToMove)) )
        return;
    //selecting
    if(!game->pieceToMove){

        game->pieceToMove = this;
        game->pieceToMove->getCurrentBox()->setColor(Qt::yellow);
        game->pieceToMove->moves();
    }
    //Consuming counterPart of the ChessBox
    else if(this->getSide() != game->pieceToMove->getSide()){
        this->getCurrentBox()->mousePressEvent(event);
    }


}

void ChessPiece::setCurrentBox(ChessBox *box)
{

    currentBox = box;
}


int ChessPiece::getColumn()
{
   return currentBox->colLoc;
}

int ChessPiece::getRow()
{
    return currentBox->rowLoc;
}


ChessBox *ChessPiece::getCurrentBox()
{
    return currentBox;
}

QString ChessPiece::getSide()
{
    return side;
}

void ChessPiece::setSide( QString value)
{
    side = value;
}

bool ChessPiece::getIsPlaced()
{
    return isPlaced;
}

void ChessPiece::setIsPlaced(bool value)
{
    isPlaced = value;

}
int ChessPiece::settype(const QString& piece)
{
    if (piece == "Pawn") {
        return 1;
    } else if (piece == "Knight") {
        return 2;
    } else if (piece == "Bishop") {
        return 3;
    } else if (piece == "Rook") {
        return 4;
    } else if (piece == "Queen") {
        return 5;
    } else if (piece == "King") {
        return 6;
    } else {
        // handle invalid piece input
        return 0;
    }
}
int ChessPiece::gettype()
{
    return pieceType;
}
QList<ChessBox *> ChessPiece::moveLocation()
{
    return location;
}
void ChessPiece::decolor()
{
    for(size_t i = 0, n = static_cast<size_t>(location.size()); i < n;i++) {
         location[static_cast<int>(i)]->resetOriginalColor();
    }
}

bool ChessPiece::boxSetting(ChessBox *box)
{
    if(box->getHasChessPiece()) {
        King *q = dynamic_cast<King*>(location.last()->currentPiece);
        if(q){
            box->setColor(QColor(118, 150, 86));
        }
        else
            box->setColor(Qt::red);
        return true;
    }
    else
        location.last()->setColor(Qt::darkYellow);
    return false;
}
