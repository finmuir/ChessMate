#include "chessteacher.h"
#include "./ui_chessteacher.h"
#include "chessboard.h"
#include <QGraphicsScene>
#include <QtCore>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDesktopServices>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QTreeWidgetItem>

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
//     Create a map of positions to labels with "_4" appended to the label name

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

void ChessTeacher::on_tutorialButton_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->TutorialPage);
    setupBoardTutorial();
    QLabel* tutorialChessBoardLabel = findChild<QLabel*>("tutorialchessBoardLabel");
    chessBoard->setChessBoardImage(tutorialChessBoardLabel);
    ui->tutorialstep2TextEdit->setVisible(false);
    ui->rookTextEdit->setVisible(false);
    ui->tutorialstep1TextEdit->setVisible(!ui->tutorialstep1TextEdit->isVisible());

}

void ChessTeacher::on_introTutorialButton_clicked()
{
    ui->tutorialstep1TextEdit->setVisible(!ui->tutorialstep1TextEdit->isVisible());
    ui->tutorialstep2TextEdit->setVisible(false);
    ui->rookTextEdit->setVisible(false);

    std::map<std::string, QLabel*> clearmid;
    clearmid["a3_4"] = findChild<QLabel*>("a3_4");
    clearmid["b4_4"] = findChild<QLabel*>("b4_4");

    // Clear the pieces on the board
    for (auto& label : clearmid) {
        chessBoard->resetPieceOnLabel(label.second);
    }

    ui->stackedWidget->setCurrentWidget(ui->TutorialPage);
    setupBoardTutorial();
    QLabel* tutorialChessBoardLabel = findChild<QLabel*>("tutorialchessBoardLabel");
    chessBoard->setChessBoardImage(tutorialChessBoardLabel);
}

void ChessTeacher::on_pawnButton_clicked()
{
    // Create a new map with the desired layout of pieces
    std::map<std::string, QLabel*> pawn;
    pawn["a2_4"] = findChild<QLabel*>("a3_4");
    pawn["b2_4"] = findChild<QLabel*>("b4_4");
    // add the remaining labels for the desired layout

    // Create a map to clear the previous positions
    std::map<std::string, QLabel*> clearLabels;
    clearLabels["a2_4"] = findChild<QLabel*>("a2_4");
    clearLabels["b2_4"] = findChild<QLabel*>("b2_4");
    clearLabels["f5_4"] = findChild<QLabel*>("f5_4");

    // Set the pieces on the board with the new map
    chessBoard->setPiecesOnBoardTutorial(clearLabels);

    chessBoard->setPiecesOnBoardTutorial(pawn);

    // Clear the previous positions with the clear map
    for (auto& label : clearLabels) {
        chessBoard->setPieceOnLabel(label.second, "");
    }

    ui->tutorialstep2TextEdit->setVisible(!ui->tutorialstep2TextEdit->isVisible());
    ui->tutorialstep1TextEdit->setVisible(false);
    ui->rookTextEdit->setVisible(false);
}


void ChessTeacher::on_rookButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TutorialPage);
    setupBoardTutorial();
    QLabel* tutorialChessBoardLabel = findChild<QLabel*>("tutorialchessBoardLabel");
    chessBoard->setChessBoardImage(tutorialChessBoardLabel);

   // Create a new map with the desired layout of pieces
    std::map<std::string, QLabel*> rook;
    rook["h1_4"] = findChild<QLabel*>("f5_4");
    // add the remaining labels for the desired layout

    // Create a map to clear the previous positions
    std::map<std::string, QLabel*> clearLabels2;
    clearLabels2["h1_4"] = findChild<QLabel*>("h1_4");
    // add the remaining labels for the positions to be cleared

    std::map<std::string, QLabel*> clearmid;
    clearmid["a3_4"] = findChild<QLabel*>("a3_4");
    clearmid["b4_4"] = findChild<QLabel*>("b4_4");

    // Clear the pieces on the board
    for (auto& label : clearmid) {
        chessBoard->resetPieceOnLabel(label.second);
    }

    chessBoard->setPiecesOnBoardTutorial(clearLabels2);

    chessBoard->setPiecesOnBoardTutorial(rook);

    // Clear the previous positions with the clear map
    for (auto& label : clearLabels2) {
        chessBoard->setPieceOnLabel(label.second, "");
    }

    ui->tutorialstep2TextEdit->setVisible(false);
    ui->tutorialstep1TextEdit->setVisible(false);
    ui->rookTextEdit->setVisible(!ui->rookTextEdit->isVisible());

}

