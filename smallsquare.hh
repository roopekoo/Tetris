/* Tetris
 *
 * Desc:
 * Header file for SmallSquare class
 *
 * Program author
 * Name: Roope Korkee
 * Student number: 291529
 * UserID: gtroko
 * E-Mail: roope.korkee@tuni.fi
 *
 * More detailed info can be found in function comments or in instructions.txt
 * */
#ifndef SMALLSQUARE_HH
#define SMALLSQUARE_HH
#include <QPixmap>

class SmallSquare
{
public:
    // SmallSquare class takes coordinates x and y, type(one of seven types),
    //and index number(n.th sqaure created)
    SmallSquare(int x, int y, int type, int index);

    // Gives picture in this class object
    QPixmap getpix();

    // Updates x value
    void setX(int x);

    // Updates y value
    void setY(int y);

    // set square movable or immovable
    void toggleControl();

    // Gives value if square is movable by player(not collided with the wall)
    bool isControllable();

    // Returns relational coordinates to rotate the square in vector.
    std::vector<int> getRotationTarget();

    // Increases rotation value.
    void increaseRotation();

private:
    // Set the image of the small square on creation.
    void updateGraphics();

    int x_;
    int y_;
    int type_;
    int index_;
    bool isControllable_;
    int rotation_;
    QPixmap pix_;

    // This is a 3d matrix of every single rotation possible clockwice
    // The following information can be found in the vector:
    // Relative coordinates(dx,dy)<-small square's index number [0 to 3]<-
    //rotate in[0 to 3]<-square type eg. HORIZONTAL [0 to 6]
    const std::vector<std::vector<std::vector<std::vector<int>>>> ROTATION_INFO=
    {
        {
            //HORIZONTAL
            {{1,-1},{0,0},{-1,1},{-2,2}},
            {{-1,1},{0,0},{1,-1},{2,-2}},
            {{1,-1},{0,0},{-1,1},{-2,2}},
            {{-1,1},{0,0},{1,-1},{2,-2}}
        },
        {
            //LEFT_CORNER
            {{2,0},{1,-1},{0,0},{-1,1}},
            {{0,2},{1,1},{0,0},{-1,-1}},
            {{-2,0},{-1,1},{0,0},{1,-1}},
            {{0,-2},{-1,-1},{0,0},{1,1}}
        },
        {
            //RIGHT_CORNER
            {{0,2},{1,-1},{0,0},{-1,1}},
            {{-2,0},{1,1},{0,0},{-1,-1}},
            {{0,-2},{-1,1},{0,0},{1,-1}},
            {{2,0},{-1,-1},{0,0},{1,1}}
        },
        {
            //SQUARE
            {{0,0},{0,0},{0,0},{0,0}},
            {{0,0},{0,0},{0,0},{0,0}},
            {{0,0},{0,0},{0,0},{0,0}},
            {{0,0},{0,0},{0,0},{0,0}}
        },
        {
            //STEP_UP_RIGHT
            {{0,0},{-1,1},{0,-2},{-1,-1}},
            {{0,0},{1,-1},{0,2},{1,1}},
            {{0,0},{-1,1},{0,-2},{-1,-1}},
            {{0,0},{1,-1},{0,2},{1,1}}
        },
        {
            //PYRAMID
            {{1,1},{1,-1},{0,0},{-1,1}},
            {{-1,1},{1,1},{0,0},{-1,-1}},
            {{-1,-1},{-1,1},{0,0},{1,-1}},
            {{1,-1},{-1,-1},{0,0},{1,1}}
        },
        {
            //STEP_UP_LEFT
            {{1,-1},{0,0},{-1,-1},{-2,0}},
            {{-1,1},{0,0},{1,1},{2,0}},
            {{1,-1},{0,0},{-1,-1},{-2,0}},
            {{-1,1},{0,0},{1,1},{2,0}}
        }
    };
};
#endif // SMALLSQUARE_HH
