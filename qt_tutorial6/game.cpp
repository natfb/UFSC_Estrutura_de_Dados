#include <QGraphicsTextItem>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "game.h"
#include "enemy.h"
#include <QImage>
#include <QBrush>

Game::Game(QWidget *parent)
{
    //criar scene
    scene = new QGraphicsScene();

    //fixar tamanho
    scene->setSceneRect(0, 0, 800, 600);
    scene->setBackgroundBrush(QBrush(QImage(":/images/starBackground.png")));

    setScene(scene);

    //desabilitar barras de rolagem
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //fixar tamanho
    setFixedSize(800, 600);

    //criar jogador
    player = new Player();
    //player->setRect(0, 0, 100, 100);
    player->setPos(400, 500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    //criar inimigos
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // adicionar contagem de pontos e vida do jogador
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    // adicionar som de fundo
    QMediaPlayer * music = new QMediaPlayer;
    QAudioOutput * audioOutput = new QAudioOutput;

    music->setAudioOutput(audioOutput);
    connect(music, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    music->setSource(QUrl("qrc:/game_music.mp3"));
    music->setLoops(-1); //setar loop para infinito
    music->play();
    show();
}
