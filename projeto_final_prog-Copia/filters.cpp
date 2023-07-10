#include "filters.h"
#include <QDebug>
#include <QImage>

Filters::Filters(const QPixmap &image) : sourceImage(image) {};

QImage* Filters::addBrightness(int num)
{
    QImage *imageToReturn{new QImage(sourceImage.toImage())};
    //QImage *imageToReturn{new QImage(sourceImage)};
    qDebug()<<"aqui";
    brilho = num;
    return setColorsCoeficients(imageToReturn);
}

QImage *Filters::changeSaturation(int num)
{
    QImage *saturatedImage{new QImage(sourceImage.toImage())};
    saturation = num*5.1;
    for (int y = 0; y < saturatedImage->height(); ++y) {
        for (int x = 0; x < saturatedImage->width(); ++x) {
            QRgb pixel = saturatedImage->pixel(x, y);

            // Convert the pixel values to HSL color space
            int h, s, l;
            QColor::fromRgb(pixel).getHsl(&h, &s, &l);

            // Adjust the saturation value
            s = qBound(0, static_cast<int>(s + saturation), 255);

            // Convert the modified HSL values back to RGB
            QColor newColor = QColor::fromHsl(h, s, l);
            saturatedImage->setPixel(x, y, newColor.rgb());
        }
    }
    return saturatedImage;
}

QImage *Filters::Sepia()
{
    QImage* sepiaImage{new QImage(sourceImage.toImage())};

    for (int y = 0; y < sepiaImage->height(); ++y) {
        for (int x = 0; x < sepiaImage->width(); ++x) {
            QRgb pixel = sepiaImage->pixel(x, y);
            int gray = qGray(pixel);
            int sepiaRed = qBound(0, gray + 40, 255);
            int sepiaGreen = qBound(0, gray + 20, 255);
            int sepiaBlue = qBound(0, gray - 20, 255);
            sepiaImage->setPixel(x, y, qRgb(sepiaRed, sepiaGreen, sepiaBlue));
        }
    }
    return sepiaImage;
}

QImage *Filters::Special()
{
    QImage* filteredImage{new QImage(sourceImage.toImage())};

    for (int y = 0; y < filteredImage->height(); ++y) {
        for (int x = 0; x < filteredImage->width(); ++x) {
            QRgb pixel = filteredImage->pixel(x, y);

            // Retrieve the original red, green, and blue values
            int red = qRed(pixel);
            int green = qGreen(pixel);

            // Convert the RGB values to grayscale


            // Set the red and green channels to the grayscale value,
            // effectively removing the distinction between red and green
            filteredImage->setPixel(x, y, qRgb(red, green, green));
        }
    }

    return filteredImage;
}

QImage *Filters::blur()
{
    QImage* filteredImage{new QImage(sourceImage.toImage())};


    return filteredImage;
}

QImage* Filters::setColorsCoeficients(QImage *image)
{
   // QImage filterImage = image->toImage();


    for(int w{0}; w < image->width(); w++)
    {
        for(int h{0}; h < image->height(); h++)
        {
            QColor color = image->pixel(w, h);

            if(brilho > 0)
            {
                color.setRed(std::min(color.red() + brilho, 255));
                color.setGreen(std::min(color.green() + brilho, 255));
                color.setBlue(std::min(color.blue() + brilho, 255));
            }
            else
            {
                color.setRed(std::max(color.red() + brilho, 0));
                color.setGreen(std::max(color.green() + brilho, 0));
                color.setBlue(std::max(color.blue() + brilho , 0));
            }


            image->setPixelColor(w, h, color);
        }
    }
    return image;
}

