#ifndef CHESSTEACHER_H
#define CHESSTEACHER_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include "chessboard.h"
#include <QPlainTextEdit>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class ChessTeacher; }
QT_END_NAMESPACE

class ChessTeacher : public QMainWindow
{
    Q_OBJECT

public:
    ChessTeacher(QWidget *parent = nullptr);
    ~ChessTeacher();

private slots:
    void on_startgameButton_clicked();
    void on_exitgameButton_clicked();
    void on_newsButton_clicked();
    void on_rulesButton_clicked();
    void on_gametomenuButton_clicked();
    void on_rulestomenuButton_clicked();
    void on_freeplayButton_clicked();
    void on_freeplaytomenuButton_clicked();
    void on_tutorialButton_clicked();
    void on_puzzleButton_clicked();
    void on_tacticsButton_clicked();
    void setupBoardTactics();
    void setupBoardFreePlay();
    void setupBoardPuzzle();
    void setupBoardTutorial();
    void on_tutorialbackButton_clicked();
    void on_tacticsbackButton_clicked();
    void on_puzzlebackButton_clicked();
    void on_introTutorialButton_clicked();
    void on_pawnButton_clicked();

    void on_rookButton_clicked();

private:
    Ui::ChessTeacher *ui;
    ChessBoard *chessBoard;
    QLabel *chessBoardLabel;


};

#endif // CHESSTEACHER_H

