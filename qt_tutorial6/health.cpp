#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent)
{
    health = 10;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(QColor(36, 0, 99));
    setFont(QFont("roboto",16));
}
void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(QColor(36, 0, 99));
    setFont(QFont("roboto",16));
}
int Health::getHealth()
{
    return health;
}
