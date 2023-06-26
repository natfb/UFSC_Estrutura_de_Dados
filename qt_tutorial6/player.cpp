#include "player.h"
#include "bullet.h"
#include "enemy.h"

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QAudioOutput>
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
   setPixmap(QPixmap(":/images/enemyUFO.png"));

    bulletsound = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    bulletsound->setAudioOutput(audioOutput);
    connect(bulletsound, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    bulletsound->setSource(QUrl("qrc:/laser.mp3"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<"Key press";

    if(event->key() == Qt::Key_Left) {
        // limite para não sair da tela
        if(pos().x() > 0)
            setPos(x()-10,y());

    } else if(event->key() == Qt::Key_Right){
        // limite para não sair da tela
        if(pos().x() + 100 < 800 )
            setPos(x()+10,y());

    } else if(event->key() == Qt::Key_Up) {
        setPos(x(),y()-10);

    } else if(event->key() == Qt::Key_Down) {
        setPos(x(),y()+10);
    }

    //criar tiro
    else if(event->key() == Qt::Key_Space)
    {
        // teste via Debug
        // qDebug()<<"Bullet created";
        setPixmap(QPixmap(":/images/playerLeft.png"));
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+35,y()-40);
        scene()->addItem(bullet);

        // analizando o estado de reprodução de Player

        if(bulletsound->playbackState() == QMediaPlayer::PlayingState)
        {
            // caso o som ainda esta tocando resetar o Player para posição inicial
            bulletsound->setPosition(0);
        }

        else if(bulletsound->playbackState() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    // Reset image when space key is released
    if (event->key() == Qt::Key_Space) {
        setPixmap(QPixmap(":/images/enemyUFO.png"));
    }
}
void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
