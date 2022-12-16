/* Tetris
 *
 * Desc:
 * This game is my own version of the no. 9 best selling game of all time,
 * tetris. (at the time making this program)
 * Your goal is to survive as long as you can while getting as much points as
 * possible.
 *
 * Program author
 * Name: Roope Korkee
 * Student number: 291529
 * UserID: gtroko
 * E-Mail: roope.korkee@tuni.fi
 *
 * Notes about the program and it's implementation:
 * This file handles the most of the logic behind the game.
 * Extra functions are split() for splitting the vector in smaller pieces and
 * isNumber for checking if detail in leaderboard file is correct.
 *
 * More detailed info can be found in function comments or in instructions.txt
 * */
#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "smallsquare.hh"
#include <fstream>
#include <string>
#include <QDebug>
#include <vector>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <set>

// Breaks string to multiple vectors by splitting character.
// NOTE! This function is borrowed from other program not made by me.
//(Programming 2, exersize 6.2.2)
std::vector<std::string> split(const std::string& s, const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}
// Tests if a given string is a number
bool isNumber(std::string number)
{
    for (unsigned int i = 0; i < number.length(); i++)
    {
        if (isdigit(number[i]) == false)
        {
            return false;
        }
    }
    return true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Game timers
    timer = new QTimer(this);
    gameSpeed = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_time()));
    connect(gameSpeed, SIGNAL(timeout()), this, SLOT(on_down_button_clicked()));
    // for coloring lcd timers
    ui->lcdSeconds->setAutoFillBackground(true);
    QPalette Pal1 =ui->lcdSeconds->palette();
    Pal1.setColor(QPalette::Normal, QPalette::Window, Qt::gray);
    ui->lcdSeconds->setPalette(Pal1);
    ui->lcdMinutes->setAutoFillBackground(true);
    ui->lcdMinutes->setPalette(Pal1);

    // We need a graphics scene in which to draw rectangles.
    scene_ = new QGraphicsScene(this);

    // The graphicsView object is placed on the window
    // at the following coordinates, but if you want
    // different placement, you can change their values.
    const int left_margin = 100; // x coordinate
    const int top_margin = 150; // y coordinate

    // The width of the graphicsView is BORDER_RIGHT added by 2,
    // since the borders take one pixel on each side
    // (1 on the left, and 1 on the right).
    // Similarly, the height of the graphicsView is BORDER_DOWN added by 2.
    ui->graphicsView->setGeometry(left_margin, top_margin,
                                  BORDER_RIGHT + 2, BORDER_DOWN + 2);
    ui->graphicsView->setScene(scene_);

    // Create canvas for game board.
    scene_->setSceneRect(0, 0, BORDER_RIGHT, BORDER_DOWN);

    // Setting random engine ready for the first real call.
    int seed = time(0); // You can change seed value for testing purposes
    randomEng.seed(seed);
    distr = std::uniform_int_distribution<int>(0, NUMBER_OF_TETROMINOS - 1);
    distr(randomEng);
    // Wiping out the first random number (which is almost always 0)
    // After the above settings, you can use randomEng to draw the next falling
    // tetromino by calling: distr(randomEng) in a suitable method.

    // Default values for points and difficulty
    points_ = 0;
    difficulty_ = 1;
    initialize();
}

MainWindow::~MainWindow()
{
    deleteSquares();
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    int key = event->key();
    if(ui->down_button->isEnabled() and key == Qt::Key_S)
    {
        on_down_button_clicked();
    }
    else if(ui->left_button->isEnabled() and key == Qt::Key_A)
    {
        on_left_button_clicked();
    }
    else if(ui->right_button->isEnabled() and key == Qt::Key_D)
    {
        on_right_button_clicked();
    }
    else if(ui->rotate_button->isEnabled() and key == Qt::Key_W)
    {
        on_rotate_button_clicked();
    }
}

void MainWindow::initialize()
{
    clearBoard();

    ui->usernameLineEdit->setDisabled(true);
    ui->canSave->setDisabled(false);

    ui->easyRadio->setChecked(true);
    ui->easyRadio->setDisabled(false);
    ui->normalRadio->setDisabled(false);
    ui->hardRadio->setDisabled(false);

    ui->rotate_button->setDisabled(true);
    ui->down_button->setDisabled(true);
    ui->left_button->setDisabled(true);
    ui->right_button->setDisabled(true);

    ui->lcdMinutes->display(0);
    ui->lcdSeconds->display(0);

    ui->create_button->setDisabled(false);
    points_ = 0;
    updateScoreboard();
}

// Updates the top 3 best scores to the leaderboards in the game.
void MainWindow::updateScoreboard()
{
    std::ifstream readfile("leaderboards.txt");
    if(!readfile)
    {
        readfile.close();
        //Create new file if there isn't one already
        std::ofstream writefile("leaderboards.txt");
        writefile.close();
    }
    else
    {
        std::string line = "";
        scores_.clear();
        std::map<std::string, int> userScores = {};
        while(getline(readfile, line))
        {
            userScores.clear();
            std::vector<std::string> data = split(line, ';', true);
            //Correct size and values for database
            if(data.size() == 3 and isNumber(data.at(0)) and
                    isNumber(data.at(2)))
            {
                int diff = std::stoi(data.at(0));
                std::string user = data.at(1);
                int points = std::stoi(data.at(2));
                // If difficulty exist in scores
                if(scores_.find(diff) != scores_.end())
                {
                    // If user is in scores
                    if(scores_.at(diff).find(user) != scores_.at(diff).end())
                    {
                        //No need for checking points because there are no same
                        //name with different points.(Greater points will be
                        //updated to the file on game over)
                        scores_.at(diff).at(user) = points;
                    }
                    else
                    {
                        scores_.at(diff).insert({user, points});
                    }
                }
                else
                {
                    userScores.insert({data.at(1),std::stoi(data.at(2))});
                    scores_.insert({std::stoi(data.at(0)), userScores});

                }
             }
        }
        readfile.close();
        std::vector<std::vector<std::vector<std::string>>> bestScores =
                getBestScores();
        // Easy scores exist
        if(scores_.find(1) != scores_.end())
        {
            updateEasy(bestScores);
        }
        // Normal scores exist
        if(scores_.find(2) != scores_.end())
        {
            updateNormal(bestScores);
        }
        // Hard scores exist
        if(scores_.find(3) != scores_.end())
        {
            updateHard(bestScores);
        }
    }
}

std::vector<std::vector<std::vector<std::string>>> MainWindow::getBestScores()
{
    std::vector<std::vector<std::vector<std::string>>> bestScores = {};
    std::vector<std::vector<std::string>> tempvector = {};
    bestScores.clear();
    for(auto diff: scores_)
    {
        if(diff.first < 1 or diff.first > 3)
        {
            continue;
        }
        int points1 = 0;
        int points2 = 0;
        int points3 = 0;
        std::string name1 = "";
        std::string name2 = "";
        std::string name3 = "";
        // Compares current points to pointsX and if needed moves previous score
        //and name down on the list
        for(auto names: scores_.at(diff.first))
        {
            std::string userName = names.first;
            int comparedPoints = names.second;
            if(comparedPoints > points1)
            {
                if(points1 != 0)
                {
                    if(points2 != 0)
                    {
                        points3 = points2;
                        name3 = name2;
                        points2 = points1;
                        name2 = name1;
                        points1 = comparedPoints;
                        name1 = userName;
                    }
                    else
                    {
                        points2 = points1;
                        name2 = name1;
                        points1 = comparedPoints;
                        name1 = userName;
                    }
                }
                else
                {
                    points1 = comparedPoints;
                    name1 = userName;
                }
            }
            else if(comparedPoints > points2)
            {
                if(points2 != 0)
                {
                    points3 = points2;
                    name3 = name2;
                    points2 = comparedPoints;
                    name2 = userName;
                }
                else
                {
                    points2 = comparedPoints;
                    name2 = userName;
                }
            }
            else if(comparedPoints > points3)
            {
                points3 = comparedPoints;
                name3 = userName;
            }
        }
        tempvector = {{name1,std::to_string(points1)},
                      {name2,std::to_string(points2)},
                      {name3,std::to_string(points3)}};
        bestScores.push_back(tempvector);
    }
    return bestScores;
}

//Updates best score details to the game(Easy, Normal and Hard)
//Unfortunately with the different name for each label, this cannot be shortened
//(At least with my coding knowledge)
void MainWindow::updateEasy(std::vector<std::vector<std::vector<std::string>>>
                            &bestScores)
{
    ui->E1Name->setText(QString::fromStdString(bestScores.at(0).at(0).at(0)));
    ui->E1Points->setText(QString::fromStdString(bestScores.at(0).at(0).at(1)));
    ui->E2Name->setText(QString::fromStdString(bestScores.at(0).at(1).at(0)));
    ui->E2Points->setText(QString::fromStdString(bestScores.at(0).at(1).at(1)));
    ui->E3Name->setText(QString::fromStdString(bestScores.at(0).at(2).at(0)));
    ui->E3Points->setText(QString::fromStdString(bestScores.at(0).at(2).at(1)));
}
void MainWindow::updateNormal(std::vector<std::vector<std::vector<std::string>>>
                             &bestScores)
{
    ui->N1Name->setText(QString::fromStdString(bestScores.at(1).at(0).at(0)));
    ui->N1Points->setText(QString::fromStdString(bestScores.at(1).at(0).at(1)));
    ui->N2Name->setText(QString::fromStdString(bestScores.at(1).at(1).at(0)));
    ui->N2Points->setText(QString::fromStdString(bestScores.at(1).at(1).at(1)));
    ui->N3Name->setText(QString::fromStdString(bestScores.at(1).at(2).at(0)));
    ui->N3Points->setText(QString::fromStdString(bestScores.at(1).at(2).at(1)));
}
void MainWindow::updateHard(std::vector<std::vector<std::vector<std::string>>>
                            &bestScores)
{
    ui->H1Name->setText(QString::fromStdString(bestScores.at(2).at(0).at(0)));
    ui->H1Points->setText(QString::fromStdString(bestScores.at(2).at(0).at(1)));
    ui->H2Name->setText(QString::fromStdString(bestScores.at(2).at(1).at(0)));
    ui->H2Points->setText(QString::fromStdString(bestScores.at(2).at(1).at(1)));
    ui->H3Name->setText(QString::fromStdString(bestScores.at(2).at(2).at(0)));
    ui->H3Points->setText(QString::fromStdString(bestScores.at(2).at(2).at(1)));
}

// Empty game board making all spaces nullpointers
void MainWindow::clearBoard()
{
    board_.clear();
    for(int y = 0; y < ROWS; y++)
    {
        std::vector<SmallSquare*> rowVector;
        for(int x = 0; x < COLUMNS; x++)
        {
            SmallSquare* newSquare = nullptr;
            rowVector.push_back(newSquare);
            printSquare(x,y,true);
        }
        board_.push_back(rowVector);
    }
}
// Starts the game locking and unlocking some buttons and starting timers
void MainWindow::on_create_button_clicked()
{
    setDifficulty();
    timer->start(1000);
    gameSpeed->start(DIFFMAP.at(difficulty_));

    ui->usernameLineEdit->setDisabled(true);
    ui->canSave->setDisabled(true);

    ui->easyRadio->setDisabled(true);
    ui->normalRadio->setDisabled(true);
    ui->hardRadio->setDisabled(true);
    ui->create_button->setDisabled(true);

    ui->rotate_button->setDisabled(false);
    ui->down_button->setDisabled(false);
    ui->left_button->setDisabled(false);
    ui->right_button->setDisabled(false);

    createShape();
}
void MainWindow::on_down_button_clicked()
{
    //Down movement also adds points to the score
    addPoints(difficulty_);
    movePieces('d', false);
}

void MainWindow::on_left_button_clicked()
{
    movePieces('l', false);
}

void MainWindow::on_right_button_clicked()
{
    movePieces('r', false);
}

void MainWindow::on_rotate_button_clicked()
{
    //Target vector parameter will be filled inside the function
    if(isNextMovableOrNull({},true))
    {
        // This target parameter is not being used in the function because it
        //will change on every iterator round in the function.(line 490)
        moveAlgorithm({}, false, true);
    }
}
// Prints and moves empty space image or colored square
void MainWindow::printSquare(int x, int y, bool isEmpty)
{
    if(isEmpty)
    {
        QGraphicsItem *square = scene_->addPixmap(QPixmap("images/empty.png"));
        square->moveBy(x*SQUARE_SIDE,y*SQUARE_SIDE);
    }
    else
    {
        QGraphicsItem *square = scene_->addPixmap(board_.at(y).at(x)->getpix());
        square->moveBy(x*SQUARE_SIDE,y*SQUARE_SIDE);
    }

}

void MainWindow::setDifficulty()
{
    if(ui->easyRadio->isChecked())
    {
        difficulty_ = 1;
    }
    if(ui->normalRadio->isChecked())
    {
        difficulty_ = 2;
    }
    if(ui->hardRadio->isChecked())
    {
        difficulty_ = 3;
    }
}

void MainWindow::update_time()
{
    //On each second survived, user gets +1 point
    addPoints(1);
    int get_sec = ui->lcdSeconds->intValue();
    if(get_sec == 59)
    {
        int get_min = ui->lcdMinutes->intValue();
        ui->lcdSeconds->display(0);
        ui->lcdMinutes->display(get_min+1);
    }
    else
    {
        ui->lcdSeconds->display(get_sec+1);
    }

}

// Add points to player and updates points label
void MainWindow::addPoints(int pts)
{
    points_ += pts;
    ui->currentPointsLabel->setText(QString::number(points_));
}

// Creating new pointers to board_.
// COORDS has the starting coorinate information about every tetromino
//in the game.
void MainWindow::createShape()
{
    //int type = 0; // For testing each different type of tetromino
    int type = distr(randomEng);
    locations_ = COORDS.at(type);
    if(!canSpawn())
    {
        gameOver();
    }
    else
    {
        for(unsigned int i = 0; i < locations_.size(); i++)
        {
            int x = locations_.at(i).at(0);
            int y = locations_.at(i).at(1);
            {
                board_.at(y).at(x) = new SmallSquare(x,y,type,i);
                printSquare(x, y, false);
            }
        }
    }
}
// Is spawning area clear enough for new shape
bool MainWindow::canSpawn()
{
    for(auto &location : locations_)
    {
        int x = location.at(0);
        int y = location.at(1);
        // Occupied
        if(board_.at(y).at(x) != nullptr)
        {
            return false;
        }
    }
    return true;
}

void MainWindow::movePieces(char direction, bool moveAll)
{
    int dx = DIRECTIONS.at(direction).at(0);
    int dy = DIRECTIONS.at(direction).at(1);
    if(areControllableMovable(dx, dy))
    {
        moveAlgorithm(DIRECTIONS.at(direction), moveAll, false);
    }
}

// Finds out if target location is free of immovable blocks
//(walls, floor or other stationary blocks)
bool MainWindow::areControllableMovable(int &dx, int &dy)
{
    if(!isWall(dx, dy))
    {
        if(isNextMovableOrNull({dx, dy}, false))
        {
            return true;
        }
        if(dy == 1)
        {
            toggleMovability();
            checkFullRows();
            createShape();
        }
        return false;
    }
    return false;
}

void MainWindow::moveAlgorithm(std::vector<int> target, bool moveAll,
                               bool doRotate)
{
    std::vector<std::vector<int>> locations = locations_;
    if(moveAll)
    {
        // Getting "bigger" locations vector of all movable squares
        locations = ClearRowLocations_;
    }
    std::set<int> skip = {};
    // Loop until all indexes have been moved(added to "skip")
    while(locations.size() != skip.size())
    {
        for(unsigned int i = 0; i < locations.size(); i++)
        {
            // Skip already moved indexes
            if(skip.find(i) != skip.end())
            {
                continue;
            }
            int x = locations.at(i).at(0);
            int y = locations.at(i).at(1);
            if(doRotate)
            {
                // For rotationable blocks there are different target for each
                //block moved
                target = board_.at(y).at(x)->getRotationTarget();
            }
            int dx = target.at(0);
            int dy = target.at(1);
            //Target place is empty
            if(board_.at(y+dy).at(x+dx) == nullptr)
            {
                //update SmallSquare x an y values
                board_.at(y).at(x)->setX(x+dx);
                board_.at(y).at(x)->setY(y+dy);
                // Copy to another place
                board_.at(y+dy).at(x+dx) = board_.at(y).at(x);
                printSquare(x+dx, y+dy, false);
                if(doRotate)
                {
                    // Add 1 to rotation value if rotated
                    board_.at(y+dy).at(x+dx)->increaseRotation();
                }
                // overwrite old location with nullptr
                board_.at(y).at(x) = nullptr;
                printSquare(x, y, true);
                skip.insert(i);
                if(!moveAll)
                {
                    // Update also locations_ vector that has tetromino
                    //loacation details for each square
                    locations_.at(i) = {x+dx,y+dy};
                }
            }
            // if rotation square is stationary on rotate, skip on next round
            if(dx == 0 and dy == 0)
            {
                skip.insert(i);
            }
        }
    }
}

// Is target location outside of the playarea
bool MainWindow::isWall(int &dx, int &dy)
{
    for(auto &location : locations_)
    {
        // Floor: freeze, check full rows andcreate new shape.
        if(dy == 1 and location.at(1)+1 == ROWS)
        {
            toggleMovability();
            checkFullRows();
            createShape();
            return true;
        }
        // left wall
        if(dx == -1 and location.at(0)-1 < 0)
        {
            return true;
        }
        // Right wall
        if(dx == 1 and location.at(0)+1 == COLUMNS)
        {
            return true;
        }
    }
    // no wall
    return false;
}

// Freezes or unfreeses all marked squares based on locations_ vector.
void MainWindow::toggleMovability()
{
    for(auto &location : locations_)
    {
        int x = location.at(0);
        int y = location.at(1);
        board_.at(y).at(x)->toggleControl();
    }
}

void MainWindow::checkFullRows()
{
    int rowsCleared = 0;
    for(int y = 0; y < ROWS; y++)
    {
        for(int x = 0; x < COLUMNS; x++)
        {
            if(board_.at(y).at(x) == nullptr)
            {
                break;
            }
            // Full row: clear, move down, speed up.
            if(x == COLUMNS-1)
            {
                clearRow(y);
                setRowsActive(y-1);
                addActiveRows(y-1);
                moveAlgorithm(DIRECTIONS.at('d'), true, false);
                setRowsActive(y);
                setFaster();
                rowsCleared++;
            }
        }
    }
    // Points given as follows (rows:points)
    // EASY:   1:+100, 2:+400,  3:+900,  4:+1600
    // NORMAL: 1:+400, 2:+1600,  3:+3600, 4:+6400
    // HARD:   1:+900, 2:+3600, 3:+8100, 4:+14400
    addPoints(difficulty_*difficulty_*rowsCleared*rowsCleared*100);
}

void MainWindow::clearRow(int &y)
{
    for(int x = 0; x < COLUMNS; x++)
    {
        //Delete square from existance
        delete board_.at(y).at(x);
        board_.at(y).at(x) = nullptr;
        printSquare(x,y,true);
    }
}

// This is for freezing or unfreezing the square rows from y=0 to y=ymax
// Used if a row is being cleared.
void MainWindow::setRowsActive(int ymax)
{
    for(int y = 0; y <= ymax; y++)
    {
        for(int x = 0; x < COLUMNS; x++)
        {
            if(board_.at(y).at(x) == nullptr)
            {
                continue;
            }
            board_.at(y).at(x)->toggleControl();
        }
    }
}

// Updates vector that has all movable squares listed
// filled from bottom to top so moving will be more efficient to move
void MainWindow::addActiveRows(int ymax)
{
    ClearRowLocations_.clear();
    // ymax tells a what level
    for(int y = ymax; y >= 0; y--)
    {
        for(int x = 0; x < COLUMNS; x++)
        {
            if(board_.at(y).at(x) == nullptr)
            {
                continue;
            }
            ClearRowLocations_.push_back({x,y});
        }
    }
}

// For each row cleared, game speed interval shortens by 10 ms
void MainWindow::setFaster()
{
    int speed = gameSpeed->interval();
    gameSpeed->start(speed-10);
}

bool MainWindow::isNextMovableOrNull(std::vector<int> target, bool checkRotate)
{
    unsigned int correct = 0;
    for(auto &location : locations_)
    {
        int x = location.at(0);
        int y = location.at(1);
        if(checkRotate)
        {
            // Update target location on every round if block is being rotated
            target = board_.at(y).at(x)->getRotationTarget();
        }
        int dx = target.at(0);
        int dy = target.at(1);
        // Made for rotateable blocks. Target is out of bounds
        if(x+dx<0 or x+dx>=COLUMNS or y+dy<0 or y+dy>=ROWS)
        {
            break;
        }
        if(board_.at(y+dy).at(x+dx) == nullptr or
                board_.at(y+dy).at(x+dx)->isControllable())
        {
            correct++;
        }
    }
    return correct == locations_.size();
}

void MainWindow::gameOver()
{
    timer->stop();
    gameSpeed->stop();
    // Checkbox is checked and name isn't left empty.
    if(ui->canSave->isChecked() and ui->usernameLineEdit->text() != "")
    {
        updateLeaderboards();
    }
    // Question box
    QMessageBox::StandardButton reply = QMessageBox::question(
                this,"Game over!","Do you want to play again?");
    if(reply == QMessageBox::Yes)
    {
        deleteSquares();
        initialize();
    }
    else
    {
        // Send signal to quit the game
        emit quitGame();
    }
}
// Finsd and clears memory from SmallSquares left on the board
void MainWindow::deleteSquares()
{
    for(int y = 0; y < ROWS; y++)
    {
        for(int x = 0; x < COLUMNS; x++)
        {
            if(board_.at(y).at(x) != nullptr)
            {
                delete board_.at(y).at(x);
            }
        }
    }
}

void MainWindow::updateLeaderboards()
{
    std::string playerName = ui->usernameLineEdit->text().toStdString();
    std::ofstream writefile("leaderboards.txt");
    // add new score to last if it hasn't been udated to the scores_ yet
    bool addLast = true;
    // not empty
    if(scores_.size() != 0)
    {
        // Same difficulty
        if(scores_.find(difficulty_) != scores_.end())
        {
            // Same name
            if(scores_.at(difficulty_).find(playerName) !=
                    scores_.at(difficulty_).end())
            {
                // Points greater
                if(points_ > scores_.at(difficulty_).at(playerName))
                {
                    scores_.at(difficulty_).at(playerName) = points_;
                }
                addLast = false;
            }
        }
    }
    // Write scores data to file
    for(auto difficulty : scores_)
    {
        int diff = difficulty.first;
        for(auto scoredata : difficulty.second)
        {
            std::string name = scoredata.first;
            int points = scoredata.second;
            writefile << diff << ";" << name << ";" << points << std::endl;
        }
    }
    // Add new score to file if not updated already
    if(addLast)
    {
        writefile << difficulty_ << ";" << playerName << ";" << points_ <<
                     std::endl;
    }
    writefile.close();
}
