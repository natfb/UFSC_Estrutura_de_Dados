#include "score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(QColor(97, 134, 189));
    setFont(QFont("roboto",16));
}
void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(QColor(97, 134, 189));
    setFont(QFont("roboto",16));
}
int Score::getScore()
{
    return score;
}
