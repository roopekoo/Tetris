/* Tetris
 *
 * Desc:
 * Starts the GUI for tetris game
 *
 * Program author
 * Name: Roope Korkee
 * Student number: 291529
 * UserID: gtroko
 * E-Mail: roope.korkee@tuni.fi
 *
 * Notes about the program and it's implementation:
 * Added only connect method for quitting the game on game over answer "no"
 *
 * More detailed info can be found in function comments or in instructions.txt
 * */
#include "mainwindow.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QObject::connect(&w, SIGNAL(quitGame()),&w,SLOT(close()));
    w.show();

    return a.exec();
}
