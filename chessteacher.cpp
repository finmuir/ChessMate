#include "chessteacher.h"
#include "./ui_chessteacher.h"
#include "board.h"
#include <QPixmap>
#include <QPalette>
#include <QSizePolicy>
#include <QThread>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include "clickablelabel.h"
#include "piece.h"

ChessTeacher::ChessTeacher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessTeacher)
{
    ui->setupUi(this);

    m_chessboardLayout = new QGridLayout(ui->chessboardWidget);
    m_chessboardLayout->setSpacing(0);
    ui->chessboardWidget->setLayout(m_chessboardLayout);
    ui->chessboardWidget->setFixedSize(600, 600);

    QPixmap chessboardPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/board.png");
    QPalette chessboardPalette;
    chessboardPalette.setBrush(QPalette::Window, chessboardPixmap);
    ui->chessboardWidget->setPalette(chessboardPalette);
    ui->chessboardWidget->setAutoFillBackground(true);

    m_whitePieceImages[Piece::Type::King] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/whiteking.png");
    m_whitePieceImages[Piece::Type::Queen] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/whitequeen.png");
    m_whitePieceImages[Piece::Type::Rook] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/whiterook.png");
    m_whitePieceImages[Piece::Type::Bishop] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/whitebishop.png");
    m_whitePieceImages[Piece::Type::Knight] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/whitehorse.png");
    m_whitePieceImages[Piece::Type::Pawn] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/whitepawn.png");

    m_blackPieceImages[Piece::Type::King] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/blackking.png");
    m_blackPieceImages[Piece::Type::Queen] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/blackqueen.png");
    m_blackPieceImages[Piece::Type::Rook] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/blackrook.png");
    m_blackPieceImages[Piece::Type::Bishop] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/blackbishop.png");
    m_blackPieceImages[Piece::Type::Knight] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/blackhorse.png");
    m_blackPieceImages[Piece::Type::Pawn] = QPixmap("C:/EEE Year 2/EE273/Chess Project/ChessTeacher/images/blackpawn.png");


    const int squareSize = 69;

    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            QLabel* squareLabel = new QLabel(ui->chessboardWidget);
            squareLabel->setFixedSize(squareSize, squareSize);
            squareLabel->setScaledContents(true);
            squareLabel->setAutoFillBackground(false);
            squareLabel->setAttribute(Qt::WA_TranslucentBackground);

            m_chessboardLayout->addWidget(squareLabel, 7 - y, x);
            m_squares[x][y] = squareLabel;
        }
    }

    // Create a new ClickableLabel instead of a QLabel
    ClickableLabel* squareLabel = new ClickableLabel(ui->chessboardWidget);

    // Connect the clicked() signal of the ClickableLabel to the onPieceClicked() slot of ChessTeacher
    connect(squareLabel, &ClickableLabel::clicked, this, &ChessTeacher::onPieceClicked);

    m_board = new Chessboard(this);
    m_board->initialize(); // Initialize with the starting position

}

void ChessTeacher::displayPiece(int x, int y, Piece* piece) {
    QLabel* square = m_squares[x][y];
    if (piece) {
        QPixmap pieceImage;
        if (piece->color() == Piece::Color::White) {
            pieceImage = m_whitePieceImages[piece->type()];
        } else {
            pieceImage = m_blackPieceImages[piece->type()];
        }
        square->setPixmap(pieceImage);

        // Set the pointer to the QLabel in the Piece object
        piece->setSquare(square);

        // Print statement to check the association between the Piece object and the ClickableLabel object
        qDebug() << "Piece at" << x << "," << y << "associated with square" << square->objectName() << "and ClickableLabel" << square;
    } else {
        square->clear();
    }
}

void ChessTeacher::onPieceClicked()
{
    ClickableLabel* clickedSquare = qobject_cast<ClickableLabel*>(sender());
    if (!clickedSquare) {
        return;
    }

    // Find the Piece object associated with the clicked QLabel
    Piece* clickedPiece = clickedSquare->piece();
    if (!clickedPiece) {
        return;
    }

    // If a piece was already selected, try to move it to the clicked square
    if (m_selectedPiece) {
        // Check if the move is valid for the selected piece
        if (m_selectedPiece->canMove(clickedPiece->x(), clickedPiece->y())) {
            // Move the piece to the clicked square
            m_board->movePiece(m_selectedPiece, clickedPiece->x(), clickedPiece->y());

            // Update the visual representation of the chessboard
            for (int x = 0; x < 8; ++x) {
                for (int y = 0; y < 8; ++y) {
                    Piece* piece = m_board->pieceAt(x, y);
                    displayPiece(x, y, piece);
                }
            }
        }

        // Remove the visual indication that the piece is selected
        m_selectedPiece->square()->setStyleSheet("");

        // Clear the selected piece
        m_selectedPiece = nullptr;
    }

    // If no piece was clicked, we're done
    if (!clickedPiece) {
        return;
    }

    // Set the clicked piece as the selected piece
    m_selectedPiece = clickedPiece;

    qDebug() << "Selected piece:" << static_cast<int>(m_selectedPiece->type()) << "at" << m_selectedPiece->x() << "," << m_selectedPiece->y();

    // Add visual indication that the piece is selected
    QString styleSheet = "background-color: rgba(0, 255, 0, 100);";
    clickedSquare->setStyleSheet(styleSheet);
}

void ChessTeacher::movePiece(int oldX, int oldY, int newX, int newY) {
    QLabel* oldSquare = m_squares[oldX][oldY];
    QLabel* newSquare = m_squares[newX][newY];
    newSquare->setPixmap(oldSquare->pixmap());
    oldSquare->clear();
}

void ChessTeacher::mousePressEvent(QMouseEvent* event) {
    // Get the square that was clicked
    QLabel* square = dynamic_cast<QLabel*>(childAt(event->pos()));
    if (square) {
        qDebug() << "Clicked on square" << square->objectName();
    }
}

ChessTeacher::~ChessTeacher()
{
    delete ui;
}

void ChessTeacher::on_startgameButton_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->GameModePage);
}


void ChessTeacher::on_beginnerButton_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->BeginnerPage);
}


void ChessTeacher::on_tutorialButton_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->TutorialPage);
}



