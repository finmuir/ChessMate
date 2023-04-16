#include "chessbox.h"
#include "game.h"
#include <QDebug>
#include "chesspiece/king.h"

extern Game *game;
ChessBox::ChessBox(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //making the Square Chess Box
    setRect(0,0,100,100);
    QPen nullPen(Qt::NoPen); // create a null pen
    setPen(nullPen); // set the border pen to null
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasChessPiece(false);
    setChessPieceColor("NONE");
    currentPiece = nullptr;
}

ChessBox::~ChessBox()
{
    delete this;
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //  qDebug() << getChessPieceColor();
    //Deselecting counter part of ChessPiece
    if(currentPiece == game->pieceToMove && currentPiece){

        currentPiece->mousePressEvent(event);
        return;
    }

    //if selected
    if(game->pieceToMove){
        //if same team
        if(this->getChessPieceColor() == game->pieceToMove->getSide()){


            return;
        }
        //removing the eaten piece
        QList <ChessBox *> movLoc = game->pieceToMove->moveLocation();
        int check = 0;
        for(size_t i = 0, n = static_cast<size_t>(movLoc.size()); i < n;i++) {
            if(movLoc[static_cast<int>(i)] == this) {
                check++;

            }
        }
        // if not prsent return
        if(check == 0)
            return;
        //change the color back to normal
        game->pieceToMove->decolor();
        //make the first move false applicable for pawn only
        game->pieceToMove->firstMove = false;
        //this is to eat or consume the enemy present inn the movable region
        if(this->getHasChessPiece()){
            this->currentPiece->setIsPlaced(false);
            this->currentPiece->setCurrentBox(nullptr);
            game->placeInDeadPlace(this->currentPiece);

        }
        //changing the new stat and resetting the previous left region
        game->pieceToMove->getCurrentBox()->setHasChessPiece(false);
        game->pieceToMove->getCurrentBox()->currentPiece = nullptr;
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        placePiece(game->pieceToMove);

        game->pieceToMove = nullptr;
        //changing turn
        game->changeTurn();
        checkForCheck();
    }
    //Selecting couterpart of the chessPiece
    else if(this->getHasChessPiece())
    {
        this->currentPiece->mousePressEvent(event);
    }
}

void ChessBox::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

void ChessBox::placePiece(ChessPiece *piece)
{

    piece->setPos(x()+50- piece->pixmap().width()/2  ,y()+50-piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasChessPiece(true,piece);
    currentPiece = piece;


}

void ChessBox::resetOriginalColor()
{
    setColor(originalColor);
}



void ChessBox::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

bool ChessBox::getHasChessPiece()
{
    return hasChessPiece;
}

void ChessBox::setHasChessPiece(bool value, ChessPiece *piece)
{
    hasChessPiece = value;
    if(value)
        setChessPieceColor(piece->getSide());
    else
        setChessPieceColor("NONE");
}

void ChessBox::checkForCheck()
{
    int c = 0;
    QList <ChessPiece *> pList = game->alivePiece;
    for(size_t i = 0,n=static_cast<size_t>(pList.size()); i < n; i++ ) {

        King * p = dynamic_cast<King *> (pList[static_cast<int>(i)]);
        if(p){
            continue;
        }
        pList[static_cast<int>(i)]->moves();
        pList[static_cast<int>(i)]->decolor();
        QList <ChessBox *> bList = pList[static_cast<int>(i)]->moveLocation();
        for(size_t j = 0,n = static_cast<size_t>(bList.size()); j < n; j ++) {
            King * p = dynamic_cast<King *> (bList[static_cast<int>(j)]->currentPiece);
            if(p) {
                if(p->getSide() == pList[static_cast<int>(i)]->getSide())
                    continue;
                bList[static_cast<int>(j)]->setColor(Qt::blue);
                pList[static_cast<int>(i)]->getCurrentBox()->setColor(Qt::darkYellow);
                if(!game->check->isVisible())
                    game->check->setVisible(true);
                else{
                    bList[static_cast<int>(j)]->resetOriginalColor();
                    pList[static_cast<int>(i)]->getCurrentBox()->resetOriginalColor();
                    game->gameOver();
                }
                c++;

            }
        }


    }
    if(!c){
        game->check->setVisible(false);
        for(size_t i = 0,n=static_cast<size_t>(pList.size()); i < n; i++ )
            pList[static_cast<int>(i)]->getCurrentBox()->resetOriginalColor();
    }
}

QString ChessBox::getChessPieceColor()
{
    return chessPieceColor;
}

void ChessBox::setChessPieceColor(QString value)
{
    chessPieceColor = value;
}
