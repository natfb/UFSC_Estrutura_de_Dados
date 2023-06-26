#include <QTimer>
#include <QGraphicsScene>

#include <stdlib.h>
#include <QDebug>

#include "enemy.h"
#include "game.h"

extern Game * game;

Enemy::Enemy()
{
    //posicao aletoria
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //desenhar inimigo
   // setRect(0, 0, 100, 100);
    setPixmap(QPixmap(":/images/enemyShip.png"));

    //mov
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y() > 600)
    {
        game->health->decrease();

        scene()->removeItem(this);
        //game = new Game();
        //game->health->decrease();
        delete this;
    }
}
