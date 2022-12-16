/* Tetris
 *
 * Desc:
 * Handles SmallSquare class details
 *
 * Program author
 * Name: Roope Korkee
 * Student number: 291529
 * UserID: gtroko
 * E-Mail: roope.korkee@tuni.fi
 *
 * NOTES:
 * Instead of using Qtbrush to print squares to the canvas, I use more beautiful
 * hand drawn images.
 *
 * More detailed info can be found in function comments or in instructions.txt
 * */
#include "smallsquare.hh"
#include "mainwindow.hh"

const std::vector<std::string> images = {
    "images/1.png",
    "images/2.png",
    "images/3.png",
    "images/4.png",
    "images/5.png",
    "images/6.png",
    "images/7.png"
};

SmallSquare::SmallSquare(int x, int y, int type, int index):
    x_(x),
    y_(y),
    type_(type),
    index_(index)
{
    //Default values for every square spawned
    isControllable_ = true;
    rotation_= 0;
    updateGraphics();
}

void SmallSquare::updateGraphics()
{
    QPixmap pix(QString::fromStdString(images.at(type_)));
    pix_ = pix;
}

QPixmap SmallSquare::getpix()
{
    return pix_;
}

bool SmallSquare::isControllable()
{
    return isControllable_;
}

// Searches relational coordinates to move in ROTATION_INFO and return them in
//vector
std::vector<int> SmallSquare::getRotationTarget()
{
    int dx = ROTATION_INFO.at(type_).at(rotation_).at(index_).at(0);
    int dy = ROTATION_INFO.at(type_).at(rotation_).at(index_).at(1);
    std::vector<int> target = {dx,dy};
    return target;
}

void SmallSquare::setX(int x)
{
    x_ = x;
}

void SmallSquare::setY(int y)
{
    y_ = y;
}

void SmallSquare::toggleControl()
{
    isControllable_ = !isControllable_;
}
// Rotation can have 4 values 0 to 3, Rotations clockwice
// 0=0deg
// 1=90deg
// 2=180deg
// 3=270deg
void SmallSquare::increaseRotation()
{
    rotation_+=1;
    if(rotation_ == 4)
    {
        rotation_ = 0;
    }
}
