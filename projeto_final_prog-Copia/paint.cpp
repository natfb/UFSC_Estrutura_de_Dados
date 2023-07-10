#include "paint.h"
#include <QPen>
#include <QPainter>




void paint::mousePressEvent(QMouseEvent *event)
{
    ilkkonum=event->pos();
}

void paint::mouseReleaseEvent(QMouseEvent *event)
{

}

void paint::mouseMoveEvent(QMouseEvent *event)
{
    sonkonum=event->pos();
    cizkor.setPoints(ilkkonum,sonkonum);
    cizgiler.push_back(cizkor);

    ilkkonum=sonkonum;
}

void paint::paintEvent(QPaintEvent *event)
{
    QPainter cizici(&image);
    QPen kalem(Qt::black,3,Qt::SolidLine);
    cizici.setPen(kalem);
    cizici.drawLines(cizgiler);

    cizici.end();

    // Save the modified image
    image.save("output.png");
}
