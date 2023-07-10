#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include "clipscene.h"
class paint
{
public:
    paint(QImage &imagee) : image(imagee){};
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);

private:
    QImage &image;
    QPoint ilkkonum;
    QPoint sonkonum;
    QLine cizkor;
    QVector<QLine> cizgiler;
};

#endif // PAINT_H

