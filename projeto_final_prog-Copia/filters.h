#ifndef FILTERS_H
#define FILTERS_H

#include <QObject>
#include <QPixmap>
class QImage;

class Filters{

private:
    QPixmap const &sourceImage;
    int brilho, saturation;
    QImage* setColorsCoeficients(QImage *image);

public:
    explicit Filters(const QPixmap &image);
    QImage* addBrightness(int num);
    QImage* changeSaturation(int num);
    QImage*  Sepia();
    QImage*  Special();
    QImage* blur();
};

#endif // FILTERS_H
