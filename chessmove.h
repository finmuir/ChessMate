#ifndef CHESSMOVE_H
#define CHESSMOVE_H

#include <QObject>

class Chessboard;

class ChessMove : public QObject
{
    Q_OBJECT
public:
    ChessMove(int startX, int startY, int endX, int endY, Chessboard* board, QObject *parent = nullptr);
    ChessMove(const ChessMove& other);
    int startX() const;
    int startY() const;
    int endX() const;
    int endY() const;
private:
    int m_startX;
    int m_startY;
    int m_endX;
    int m_endY;
};

#endif // CHESSMOVE_H
