#include <QApplication>
#include "game.h"
#include "health.h"

Game *game;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    game = new Game();
    game->show();
    qDebug()<<"0";

    return a.exec();
}
