#include "game.h"
#include "button.h"
#include <QPixmap>
#include "chesspiece/king.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QJsonArray>
#include <QGraphicsProxyWidget>
#include <QPushButton>

Game::Game(QWidget *parent ):QGraphicsView(parent)
{

    //Making the Scene
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1400,900);

    //Making the view
    setFixedSize(1400,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    pieceToMove = nullptr;

    //display turn
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-100,10);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turn : WHITE");

    //display Check
    check = new QGraphicsTextItem();
    check->setPos(width()/2-100,860);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("",18));
    check->setPlainText("CHECK!");
    check->setVisible(false);
    setTurn("WHITE");
}

void Game::saveGame()
{
    qInfo("save game Clicked.");
    // Create a JSON object to store the game state
    QJsonObject gameState;
    gameState["turn"] = getTurn();

    // Loop over all alive pieces and add them to the JSON object
    QJsonArray alivePiecesArray;
    for (ChessPiece* piece : alivePiece) {
        QJsonObject pieceObject;
        pieceObject["type"] = piece->gettype();
        pieceObject["color"] = piece->getSide();
        pieceObject["row"] = piece->getRow();
        pieceObject["col"] = piece->getColumn();
        alivePiecesArray.append(pieceObject);
    }
    gameState["alivePieces"] = alivePiecesArray;

    // Loop over all dead pieces and add them to the JSON object
    QJsonArray deadPiecesArray;
    for (ChessPiece* piece : whiteDead) {
        QJsonObject pieceObject;
        pieceObject["type"] = piece->gettype();
        pieceObject["color"] = piece->getSide();
        deadPiecesArray.append(pieceObject);
    }
    for (ChessPiece* piece : blackDead) {
        QJsonObject pieceObject;
        pieceObject["type"] = piece->gettype();
        pieceObject["color"] = piece->getSide();
        deadPiecesArray.append(pieceObject);
    }
    gameState["deadPieces"] = deadPiecesArray;

    // Convert the JSON object to a JSON document
    QJsonDocument doc(gameState);

    // Write the JSON document to a file
    QFile file("gamestate.json");
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }
    file.write(doc.toJson());
    file.close();
}


void Game::drawChessBoard()
{
    chess = new ChessBoard();
    drawDeadHolder(0,0,Qt::lightGray);
    drawDeadHolder(1100,0,Qt::lightGray);
    chess->drawBoxes(width()/2-400,50);

}

void Game::displayDeadWhite()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = static_cast<size_t>(whiteDead.size()); i<n; i++) {
        if(j == 4){
            k++;
            j = 0;
        }
        whiteDead[static_cast<int>(i)]->setPos(40+SHIFT*j++,100+SHIFT*2*k);
    }
}

void Game::displayDeadBlack()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = static_cast<size_t>(blackDead.size()); i<n; i++) {
        if(j == 4){
            k++;
            j = 0;
        }
        blackDead[static_cast<int>(i)]->setPos(1140+SHIFT*j++,100+SHIFT*2*k);
    }
}

void Game::placeInDeadPlace(ChessPiece *piece)
{
    if(piece->getSide() == "WHITE") {
        whiteDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if(g){

            check->setPlainText("Black Won");
            gameOver();
        }
        displayDeadWhite();
    }
    else{
        blackDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if(g){

            check->setPlainText("White Won");
            gameOver();
        }
        displayDeadBlack();
    }
    alivePiece.removeAll(piece);
}

void Game::addToScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);

}

QString Game::getTurn()
{
    return turn;
}

void Game::setTurn(QString value)
{
    turn = value;
}

void Game::changeTurn()
{
    if(getTurn() == "WHITE")
        setTurn("BLACK");
    else
        setTurn("WHITE");
    turnDisplay->setPlainText("Turn : " + getTurn());
}

void Game::start()
{
    for(size_t i =0, n = static_cast<size_t>(listG.size()); i < n; i++)
        removeFromScene(listG[static_cast<int>(i)]);

    addToScene(turnDisplay);
    addToScene(check);
    chess->addChessPiece();


    // Create a QPushButton widget
    QPushButton *button = new QPushButton("Save Game");

    // Create a QGraphicsProxyWidget to hold the button
    QGraphicsProxyWidget *proxy = gameScene->addWidget(button);

    // Set the position and size of the proxy widget
    proxy->setPos(50, 50);
    proxy->setMinimumSize(100, 50);
    connect(button,SIGNAL(clicked()) , this , SLOT(saveGame()));
    gameScene->addItem(proxy);



}

void Game::rules(){
    rulesScreen.show();


}

void Game::loadGame()
{
    //    qInfo("load game Clicked.");

    //    // Open the saved game file
    //    QFile file("gamestate.json");
    //    if (!file.open(QIODevice::ReadOnly)) {
    //        qWarning("Couldn't open saved game file.");
    //        return;
    //    }

    //    // Read the game state from the JSON document
    //    QByteArray data = file.readAll();
    //    QJsonDocument doc(QJsonDocument::fromJson(data));
    //    QJsonObject gameState = doc.object();

    //    // Set the turn
    //    QString turn = gameState["turn"].toString();
    //    setTurn(turn);
    //    turnDisplay->setPlainText("Turn : " + getTurn());

    //    // Load the alive pieces
    //    QJsonArray alivePiecesArray = gameState["alivePieces"].toArray();
    //    for (const auto& pieceObject : alivePiecesArray) {
    //        QString type = pieceObject.toObject()["type"].toString();
    //        QString color = pieceObject.toObject()["color"].toString();
    //        int row = pieceObject.toObject()["row"].toInt();
    //        int col = pieceObject.toObject()["col"].toInt();
    //        createChessPiece(type, color, row, col);
    //    }

    //    // Load the dead pieces
    //    QJsonArray deadPiecesArray = gameState["deadPieces"].toArray();
    //    for (const auto& pieceObject : deadPiecesArray) {
    //        QString type = pieceObject.toObject()["type"].toString();
    //        QString color = pieceObject.toObject()["color"].toString();
    //        ChessPiece* piece = createChessPiece(type, color, -1, -1);
    //        placeInDeadPlace(piece);
    //    }

    //    file.close();
}
void Game::drawDeadHolder(int x, int y,QColor color)
{
    deadHolder = new QGraphicsRectItem(x,y,300,900);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    deadHolder->setBrush(brush);
    addToScene(deadHolder);
}




void Game::selectGameLevel(){

    for(size_t i =0, n = static_cast<size_t>(listG.size()); i < n; i++)
        removeFromScene(listG[static_cast<int>(i)]);

    //Create the title
    QGraphicsTextItem *titleText = new QGraphicsTextItem("Select Hardness Level");
    QFont titleFont("roboto" , 40);
    titleText->setFont( titleFont);
    int xPos = static_cast<int>(width()/2 - titleText->boundingRect().width()/2);
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    listG.append(titleText);
    //create Button

    Button * easyPlayButton = new Button("Easy");
    int pxPos = static_cast<int>(width()/2 - easyPlayButton->boundingRect().width()/2);
    int pyPos = 300;
    easyPlayButton->setPos(pxPos,pyPos);
    connect(easyPlayButton,SIGNAL(clicked()) , this , SLOT(setGameEasy()));
    addToScene(easyPlayButton);
    listG.append(easyPlayButton);

    Button * mediumPlayButton = new Button("Medium");
    int qxPos = static_cast<int>(width()/2 - mediumPlayButton->boundingRect().width()/2);
    mediumPlayButton->setPos(pxPos,(pyPos+75));
    connect(mediumPlayButton,SIGNAL(clicked()) , this , SLOT(setGameMedium()));
    addToScene(mediumPlayButton);
    listG.append(mediumPlayButton);

    Button * hardPlayButton = new Button("Hard");
    int rxPos = static_cast<int>(width()/2 - hardPlayButton->boundingRect().width()/2);
    hardPlayButton->setPos(pxPos,(pyPos+150));
    connect(hardPlayButton,SIGNAL(clicked()) , this , SLOT(setGameHard()));
    addToScene(hardPlayButton);
    listG.append(hardPlayButton);
}

void Game::setGameEasy(){

    hardnessLevel ="Easy";

    qInfo()<<"Game Hardness :: " <<hardnessLevel;

QList<QStringList> csvData = loadCSVFile("path/to/my/csv/file.csv");
    start();
}

void Game::setGameMedium(){

    hardnessLevel ="Medium";
    qInfo()<<"Game Hardness :: " <<hardnessLevel;
}
void Game::setGameHard(){

    hardnessLevel ="Hard";
    qInfo()<<"Game Hardness :: " <<hardnessLevel;
}





// Load CSV file into QList<QStringList>
QList<QStringList>  Game::loadCSVFile(QString fileName) {
    QList<QStringList> data;

    // Open the file
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return data;

    // Read in the data and parse it into the QList
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        data.append(fields);
    }

    // Close the file and return the QList
    file.close();
    return data;
}



void Game::displayMainMenu()
{

    //Create the title
    QGraphicsTextItem *titleText = new QGraphicsTextItem("Chess Teacher");
    QFont titleFont("roboto" , 50);
    titleText->setFont( titleFont);
    int xPos = static_cast<int>(width()/2 - titleText->boundingRect().width()/2);
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    listG.append(titleText);
    //create Button
    Button * playButton = new Button("Start");
    int pxPos = static_cast<int>(width()/2 - playButton->boundingRect().width()/2);
    int pyPos = 300;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(selectGameLevel()));
    addToScene(playButton);
    listG.append(playButton);

    //Create Rules Button
    Button * rulestButton = new Button("Rules");
    int qxPos = static_cast<int>(width()/2 - rulestButton->boundingRect().width()/2);
    int qyPos = 375;
    rulestButton->setPos(qxPos,qyPos);
    connect(rulestButton, SIGNAL(clicked()),this,SLOT(rules()));
    addToScene(rulestButton);
    drawChessBoard();
    listG.append(rulestButton);

    //Create LoadGame Button
    Button * loadGameButton = new Button("Load Game");
    int lgxPos = static_cast<int>(width()/2 - loadGameButton->boundingRect().width()/2);
    int lgyPos = 450;
    loadGameButton->setPos(lgxPos,lgyPos);
    connect(loadGameButton, SIGNAL(clicked()),this,SLOT(loadGame()));
    addToScene(loadGameButton);
    drawChessBoard();
    listG.append(loadGameButton);

    //Create Quit Button
    Button * quitButton = new Button("Quit");
    int rxPos = static_cast<int>(width()/2 - quitButton->boundingRect().width()/2);
    int ryPos = 525;
    quitButton->setPos(rxPos,ryPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    addToScene(quitButton);
    drawChessBoard();
    listG.append(quitButton);
}

void Game::gameOver()
{
    //removeAll();
    setTurn("WHITE");
    alivePiece.clear();
    chess->reset();

}



void Game::removeAll(){
    QList<QGraphicsItem*> itemsList = gameScene->items();
    for(size_t i = 0, n = static_cast<size_t>(itemsList.size());i<n;i++) {
        if(itemsList[static_cast<int>(i)]!=check)
            removeFromScene(itemsList[static_cast<int>(i)]);
    }
}
