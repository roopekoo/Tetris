/* Tetris
 *
 * Desc:
 * Header file for MainWindow class
 *
 * Program author
 * Name: Roope Korkee
 * Student number: 291529
 * UserID: gtroko
 * E-Mail: roope.korkee@tuni.fi
 *
 * More detailed info can be found in function comments or in instructions.txt
 * */
#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <random>
#include "smallsquare.hh"
#include <map>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // Event activates if key is pressed(for moving piece by keyboard)
    void keyPressEvent(QKeyEvent* event) override;

signals:
    // Emitted, when the game will be quit.
    void quitGame();

private slots:
    void on_create_button_clicked();
    void on_down_button_clicked();
    void on_left_button_clicked();
    void on_right_button_clicked();
    void on_rotate_button_clicked();

    //Slot for normal clock to update time after every timeout
    void update_time();


private:
    Ui::MainWindow *ui;
    QTimer* timer;
    QTimer* gameSpeed;
    QGraphicsScene* scene_;
    int points_;
    int difficulty_;
    std::vector<std::vector<int>> locations_;
    std::vector<std::vector<int>> ClearRowLocations_;
    std::map<int,std::map<std::string, int>> scores_;
    // Game board used in the game
    std::vector<std::vector<SmallSquare*>> board_;

    // Constants describing scene coordinates
    // Copied from moving circle example and modified a bit
    const int BORDER_UP = 0;
    const int BORDER_DOWN = 480; // 260; (in moving circle)
    const int BORDER_LEFT = 0;
    const int BORDER_RIGHT = 240; // 680; (in moving circle)

    // Size of a tetromino component
    const int SQUARE_SIDE = 20;
    // Number of horizontal cells (places for tetromino components)
    const int COLUMNS = BORDER_RIGHT / SQUARE_SIDE;
    // Number of vertical cells (places for tetromino components)
    const int ROWS = BORDER_DOWN / SQUARE_SIDE;

    // Starting coordinates for each kindo of tetromino
    // 1st vector is square type
    // 2nd is square index
    // 3rd is x and y coordinates
    const std::vector<std::vector<std::vector<int>>> COORDS =
    {
        //HORIZONTAL
        {{4,0},{5,0},{6,0},{7,0}},
        //LEFT_CORNER
        {{5,0},{5,1},{6,1},{7,1}},
        //RIGHT_CORNER
        {{7,0},{5,1},{6,1},{7,1}},
        //SQUARE
        {{5,0},{6,0},{5,1},{6,1}},
        //STEP_UP_RIGHT
        {{6,0},{7,0},{5,1},{6,1}},
        //PYRAMID
        {{6,0},{5,1},{6,1},{7,1}},
        //STEP_UP_LEFT
        {{5,0},{6,0},{6,1},{7,1}}
    };
    // Map of directoins and {dx,dy} as direction where to move
    const std::map<char, std::vector<int>> DIRECTIONS =
    {
        {'d',{0,1}},
        {'l',{-1,0}},
        {'r',{1,0}}
    };
    // Map includes difficulty multiplier for points and interval value for
    //gameSpeed (ms)
    const std::map<int, int> DIFFMAP = {{1,1000},{2,500},{3,250}};

    // Constants for different tetrominos and the number of them
    enum Tetromino_kind {HORIZONTAL,
                         LEFT_CORNER,
                         RIGHT_CORNER,
                         SQUARE,
                         STEP_UP_RIGHT,
                         PYRAMID,
                         STEP_UP_LEFT,
                         NUMBER_OF_TETROMINOS};
    // From the enum values above, only the last one is needed in this template.
    // Recall from enum type that the value of the first enumerated value is 0,
    // the second is 1, and so on.
    // Therefore the value of the last one is 7 at the moment.
    // Remove those tetromino kinds above that you do not implement,
    // whereupon the value of NUMBER_OF_TETROMINOS changes, too.
    // You can also remove all the other values, if you do not need them,
    // but most probably you need a constant value for NUMBER_OF_TETROMINOS.


    // For randomly selecting the next dropping tetromino
    std::default_random_engine randomEng;
    std::uniform_int_distribution<int> distr;

    // Resets values so new game can be started
    void initialize();

    // Deletes square pointers from memory
    void deleteSquares();

    // Glears gameboard area from squares.
    void clearBoard();

    // Prints on certain location colored square or empty square
    // x and y are coordinates for the square
    // isEmpty prints empty block otherwice a colored block
    void printSquare(int x, int y, bool isEmpty);

    // Updates selected difficulty value to game details
    void setDifficulty();

    // Creates new random shape to gameboard.(one of seven)
    void createShape();

    // Add points(pts) to game details (points_)
    void addPoints(int pts);

    // Checks if shape fits in spawn location
    bool canSpawn();

    // New shape doesnt fit => quit or create new game
    void gameOver();

    // Pieces move event
    // direction is a letter for movement direction 'd'=down,'l'=left,'r'=right
    // moveAll if more than 4 pieces must be moved at once (on row cleared)
    void movePieces(char direction, bool moveAll);

    // Checks if move location is free to move
    //(no walls/floor or immovable blocks)
    // dx and dy are relative coordinates for square
    bool areControllableMovable(int &dx, int &dy);

    // Can move piece to target location(realtive coordinates) if it is normal
    //movement(left, right, down) or rotation movement(doRotate) or on clearing
    //full rows(moveAll)=> (moving all above rows down)
    void moveAlgorithm(std::vector<int> target, bool moveAll, bool doRotate);

    // Checks if target location is out of bounds
    // dx and dy are relative coordinates to move for one square
    bool isWall(int &dx, int &dy);

    // Checks if target location (move or rotate) is free or will be free.
    // target vector has relative x and y xcoordinates where to move.
    // checkRotate is for getting target vector form ROTATION_INFO if piece
    //will rotate
    bool isNextMovableOrNull(std::vector<int> target, bool checkRotate);

    // Toggles square mobility
    // Used on full rows cleared -moving
    void toggleMovability();

    //Checks if row is full of blocks
    void checkFullRows();

    // Sets y level full of nullptrs
    void clearRow(int &y);

    // Toggles movability for all rows of blocks below or equal to ymax
    //coordinate.
    void setRowsActive(int ymax);

    // Adds x and y coordinates to clearRowLocations_ vector
    // ymax is height coordinate. y coordinates equal or lower to this gets
    //added to the vector
    void addActiveRows(int ymax);

    // Sets gamespeed faster on each rows cleared
    void setFaster();

    // Updates ingame leaderboards from leaderboards.txt file
    void updateScoreboard();

    //returns vector with top 3 players and scores
    std::vector<std::vector<std::vector<std::string>>> getBestScores();

    // 3 functions below adds players with top scores to the leaderboards in the
    //game according the vector given to them(bestscores).
    void updateEasy(std::vector<std::vector<std::vector<std::string>>>
                    &bestScores);
    void updateNormal(std::vector<std::vector<std::vector<std::string>>>
                      &bestScores);
    void updateHard(std::vector<std::vector<std::vector<std::string>>>
                    &bestScores);

    //Adds or update a new player/score to the leaderboards.txt
    void updateLeaderboards();
};

#endif // MAINWINDOW_HH
