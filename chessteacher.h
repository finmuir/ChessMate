#ifndef CHESSTEACHER_H
#define CHESSTEACHER_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QMap>
#include "piece.h"
#include "board.h"

class Chessboard;

QT_BEGIN_NAMESPACE
namespace Ui { class ChessTeacher; }
QT_END_NAMESPACE

class ChessTeacher : public QMainWindow
{
    Q_OBJECT

public:
    ChessTeacher(QWidget *parent = nullptr);
    ~ChessTeacher();
    void displayPiece(int x, int y, Piece* piece);
    void onSquareClicked(int x, int y);

private slots:
    void on_startgameButton_clicked();
    void on_beginnerButton_clicked();
    void on_tutorialButton_clicked();
    void onPieceClicked();

public slots:
    void movePiece(int oldX, int oldY, int newX, int newY);

private:
    Ui::ChessTeacher *ui;
    QGridLayout* m_chessboardLayout;
    QLabel* m_squares[8][8];
    QMap<Piece::Type, QPixmap> m_whitePieceImages;
    QMap<Piece::Type, QPixmap> m_blackPieceImages;
    QLabel* m_square;
    Piece* m_selectedPiece = nullptr;
    Chessboard* m_board;

protected:
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // CHESSTEACHER_H

