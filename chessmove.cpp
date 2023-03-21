#include "chessmove.h"

ChessMove::ChessMove(int startX, int startY, int endX, int endY, Chessboard* board, QObject *parent)
    : QObject(parent), m_startX(startX), m_startY(startY), m_endX(endX), m_endY(endY)
{
}

ChessMove::ChessMove(const ChessMove& other) : QObject(other.parent()), m_startX(other.startX()), m_startY(other.startY()), m_endX(other.endX()), m_endY(other.endY())
{

}

int ChessMove::startX() const
{
    return m_startX;
}

int ChessMove::startY() const
{
    return m_startY;
}

int ChessMove::endX() const
{
    return m_endX;
}

int ChessMove::endY() const
{
    return m_endY;
}
