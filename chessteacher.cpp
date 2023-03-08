#include "chessteacher.h"
#include "./ui_chessteacher.h"
#include <QGraphicsScene>
#include <QtCore>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDesktopServices>
#include <QMessageBox>

ChessTeacher::ChessTeacher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessTeacher)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->HomePage);

    QPixmap pix("../ChessTeacher/images/ChessPiecesWallpaper.png");
    ui->homepageWallpaper->setPixmap(pix);

    QPixmap pix1("../ChessTeacher/images/book3.png");
    ui->tutorialimage->setPixmap(pix1);

    QPixmap pix2("../ChessTeacher/images/freeimage.png");
    ui->freeplayimage->setPixmap(pix2);

    QPixmap pix3("../ChessTeacher/images/puzzleImage1.png");
    ui->puzzleimage->setPixmap(pix3);

    QPixmap pix4("../ChessTeacher/images/swordimage.png");
    ui->tacticsimage->setPixmap(pix4);

    QPixmap pix5("../ChessTeacher/images/ChessPiecesWallpaper.png");
    ui->gameplayWallpaper->setPixmap(pix5);

    QPixmap pix6("../ChessTeacher/images/ChessPiecesWallpaper.png");
    ui->rulesWallpaper->setPixmap(pix6);

    QPixmap pix7("../ChessTeacher/images/ChessPiecesWallpaper.png");
    ui->freeplayWallpaper->setPixmap(pix7);

    QPixmap pix8("../ChessTeacher/images/ChessPiecesWallpaper.png");
    ui->tacticspageWallpaper->setPixmap(pix8);

    QPixmap pix9("../ChessTeacher/images/ChessPiecesWallpaper.png");
    ui->puzzlepageWallpaper->setPixmap(pix9);

    QPixmap pix10("../ChessTeacher/images/ChessPiecesWallpaper.png");
    ui->tutorialpageWallpaper->setPixmap(pix10);

    // Create a new ChessBoard object
    chessBoard = new ChessBoard(this);

    // Find the chess board QLabel on the UI and set its pixmap
    chessBoardLabel = findChild<QLabel*>("chessBoardLabel");

}

ChessTeacher::~ChessTeacher()
{
    delete ui;
}

void ChessTeacher::on_startgameButton_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->GameplayPage);
}

void ChessTeacher::on_exitgameButton_clicked()
{
    QMessageBox::StandardButton confirmExit = QMessageBox::question(this, "Confirm Exit", "Are you sure you want to exit?", QMessageBox::Yes|QMessageBox::No);
    if (confirmExit == QMessageBox::Yes) {
        qApp->quit();
    }
}


void ChessTeacher::on_newsButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.chess.com/news"));
}

void ChessTeacher::on_rulesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->RulesPage);
}


void ChessTeacher::on_gametomenuButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
}


void ChessTeacher::on_rulestomenuButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
}


void ChessTeacher::on_freeplaytomenuButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->GameplayPage);

}

void ChessTeacher::on_tutorialbackButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->GameplayPage);
}


void ChessTeacher::on_tacticsbackButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->GameplayPage);
}

void ChessTeacher::on_puzzlebackButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->GameplayPage);
}


void ChessTeacher::setupBoardFreePlay()
{
    std::map<std::string, QLabel*> labels;
    for (char col = 'a'; col <= 'h'; ++col) {
        for (int row = 1; row <= 8; ++row) {
            std::string position = std::string(1, col) + std::to_string(row);
            QLabel* label = findChild<QLabel*>(position.c_str());
            labels[position] = label;
        }
    }

    // Set the chess board image on the label
    chessBoard->setChessBoardImage(chessBoardLabel);

    // Set the pieces on the board
    chessBoard->setPiecesOnBoardFreePlay(labels);
}


void ChessTeacher::on_freeplayButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->FreePlayPage);
    setupBoardFreePlay();
    // Find the chess board QLabel on the UI and set its pixmap
    QLabel* tacticsChessBoardLabel = findChild<QLabel*>("tacticschessBoardLabel");
    chessBoard->setChessBoardImage(tacticsChessBoardLabel);

}


void ChessTeacher::setupBoardTactics()
{
    // Create a map of positions to labels with "_2" appended to the label name
    std::map<std::string, QLabel*> labels;
    for (char col = 'a'; col <= 'h'; ++col) {
        for (int row = 1; row <= 8; ++row) {
            std::string position = std::string(1, col) + std::to_string(row) + "_2";
            QLabel* label = findChild<QLabel*>(position.c_str());
            labels[position] = label;
        }
    }

    // Set the chess board image on the label
    chessBoard->setChessBoardImage(chessBoardLabel);

    // Set the pieces on the board
    chessBoard->setPiecesOnBoardTactics(labels);

}


void ChessTeacher::on_tacticsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TacticsPage);
    setupBoardTactics();
    // Find the chess board QLabel on the UI and set its pixmap
    QLabel* tacticsChessBoardLabel = findChild<QLabel*>("tacticschessBoardLabel");
    chessBoard->setChessBoardImage(tacticsChessBoardLabel);

}

void ChessTeacher::setupBoardTutorial()
{
    // Create a map of positions to labels with "_4" appended to the label name
    std::map<std::string, QLabel*> labels;
    for (char col = 'a'; col <= 'h'; ++col) {
        for (int row = 1; row <= 8; ++row) {
            std::string position = std::string(1, col) + std::to_string(row) + "_4";
            QLabel* label = findChild<QLabel*>(position.c_str());
            labels[position] = label;
        }
    }

    // Set the chess board image on the label
    chessBoard->setChessBoardImage(chessBoardLabel);

    // Set the pieces on the board
    chessBoard->setPiecesOnBoardTutorial(labels);

}

void ChessTeacher::on_tutorialButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TutorialPage);
    setupBoardTutorial();
    QLabel* tutorialChessBoardLabel = findChild<QLabel*>("tutorialchessBoardLabel");
    chessBoard->setChessBoardImage(tutorialChessBoardLabel);
}

void ChessTeacher::setupBoardPuzzle()
{
    // Create a map of positions to labels with "_3" appended to the label name
    std::map<std::string, QLabel*> labels;
    for (char col = 'a'; col <= 'h'; ++col) {
        for (int row = 1; row <= 8; ++row) {
            std::string position = std::string(1, col) + std::to_string(row) + "_3";
            QLabel* label = findChild<QLabel*>(position.c_str());
            labels[position] = label;
        }
    }

    // Set the chess board image on the label
    chessBoard->setChessBoardImage(chessBoardLabel);

    // Set the pieces on the board
    chessBoard->setPiecesOnBoardPuzzle(labels);

}

void ChessTeacher::on_puzzleButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PuzzlePage);
    setupBoardPuzzle();
    QLabel* puzzleChessBoardLabel = findChild<QLabel*>("puzzlechessBoardLabel");
    chessBoard->setChessBoardImage(puzzleChessBoardLabel);
}

