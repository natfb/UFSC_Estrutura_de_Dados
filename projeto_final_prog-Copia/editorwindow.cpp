#include "editorwindow.h"
#include "ui_editorwindow.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QFile>
#include <QDebug>
#include <QDateTime>
#include <QCamera>
#include <QScroller>
#include <QGraphicsBlurEffect>
#include "savewindow.h"

editorwindow::editorwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::editorwindow)
{
    ui->setupUi(this);
    scenee = new QGraphicsScene(this);
}

//construtor | arquivo aberto pelo explorador
editorwindow::editorwindow(const QString& photoPath, QWidget *parent) :
   QMainWindow(parent)
 ,  ui(new Ui::editorwindow)
{
    ui->setupUi(this);
    scenee = new QGraphicsScene(this);

    //mostrar foto
    setScene(photoPath);

    //visibilidade dos widgets
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    QScroller::grabGesture(ui->scrollArea->viewport(), QScroller::TouchGesture);
    //stylesheet dos sliders
    ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal {"
                                        "    height: 5px;"
                                        "    background: white;"
                                        "    border-radius: 10px;"
                                        "}"
                                        "QSlider::handle:horizontal {"
                                        "    width: 20px;"
                                        "    height: 20px;"
                                        "    background: rgb(40, 146, 252);"
                                        "    margin: -10px 0;"
                                        "    border-radius: 10px;"
                                        "}");
    ui->sliderSaturacao->setStyleSheet("QSlider::groove:horizontal {"
                                       "    height: 5px;"
                                       "    background: white;"
                                       "    border-radius: 10px;"
                                       "}"
                                       "QSlider::handle:horizontal {"
                                       "    width: 20px;"
                                       "    height: 20px;"
                                       "    background: rgb(40, 146, 252);"
                                       "    margin: -10px 0;"
                                       "    border-radius: 10px;"
                                       "}");

}
//construtor | foto tirada pela camera
editorwindow::editorwindow(const QImage &img, QWidget *parent)
    :
    QMainWindow(parent)
    ,  ui(new Ui::editorwindow)
{
    ui->setupUi(this);
    scenee = new QGraphicsScene(this);

    //mostrar foto
    image = new QPixmap(QPixmap::fromImage(img));
    originalImage = new QPixmap(*image);

    if (!image->isNull()) {
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);

        scenee->setSceneRect(pixmapItem->boundingRect());
        ui->graphicsView->setScene(scenee);
        qreal scaleFactor = qMin(sizeW / scenee->sceneRect().width(), sizeH / scenee->sceneRect().height());
        ui->graphicsView->scale(scaleFactor, scaleFactor);
        ui->graphicsView->setFixedSize(sizeW, sizeH);
    };

    //visibilidade dos widgets
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    QScroller::grabGesture(ui->scrollArea->viewport(), QScroller::TouchGesture);
    //stylesheet dos slider
    ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal {"
                                        "    height: 5px;"
                                        "    background: white;"
                                        "    border-radius: 10px;"
                                        "}"
                                        "QSlider::handle:horizontal {"
                                        "    width: 20px;"
                                        "    height: 20px;"
                                        "    background: rgb(40, 146, 252);"
                                        "    margin: -10px 0;"
                                        "    border-radius: 10px;"
                                        "}");
    ui->sliderSaturacao->setStyleSheet("QSlider::groove:horizontal {"
                                       "    height: 5px;"
                                       "    background: white;"
                                       "    border-radius: 10px;"
                                       "}"
                                       "QSlider::handle:horizontal {"
                                       "    width: 20px;"
                                       "    height: 20px;"
                                       "    background: rgb(40, 146, 252);"
                                       "    margin: -10px 0;"
                                       "    border-radius: 10px;"
                                       "}");

}
editorwindow::~editorwindow()
{
    delete ui;
}
//mostrar imagem
void editorwindow::setScene(const QString& path)
{
    if (!path.isEmpty()) {
        // Load the image using QPixmap
        QPixmap pixmap(path);

        image = new QPixmap(pixmap);
        originalImage = new QPixmap(pixmap);

        if (!pixmap.isNull()) {
            QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);

            scenee->setSceneRect(pixmapItem->boundingRect());

            ui->graphicsView->setScene(scenee);

            // scale
            qreal scaleFactor = qMin(sizeW / scenee->sceneRect().width(), sizeH / scenee->sceneRect().height());
            ui->graphicsView->scale(scaleFactor, scaleFactor);

            // tamanho fixo do graphicsView
            ui->graphicsView->setFixedSize(sizeW, sizeH);
        };

    }
}
//salvar
void editorwindow::on_save_clicked()
{
    //salva a photo em downloads
    QString filePath = "/storage/emulated/0/Download/img_" + QString::number(QDateTime::currentSecsSinceEpoch())  + ".png";  // Replace with your desired file path
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        bool success = image->save(&file, "PNG");  // Save as JPEG format
        file.close();

        if (success) {
            saveWindow* save = new saveWindow(this);
            save->show();

        } else {
            qDebug()<<" N salvou";
        }
    } else {
        // Error opening file
    }
}
//voltar
void editorwindow::on_voltar_clicked()
{
    close();
}
//ferramentas
void editorwindow::on_ferramentas_clicked()
{
    ui->widget->setVisible(true);
    ui->horizontalSlider->setVisible(false);
    ui->sliderSaturacao->setVisible(false);
    ui->widget_2->setVisible(false);
}

//filtros
void editorwindow::on_filtros_clicked()
{
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);
}

//default
void editorwindow::on_default_2_clicked()
{
    ui->graphicsView->scene()->clear();
    image = new QPixmap(*originalImage);

    if (!image->isNull()) {
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);
        scenee->setSceneRect(pixmapItem->boundingRect());

        ui->graphicsView->setScene(scenee);
        ui->graphicsView->fitInView(scenee->sceneRect(), Qt::KeepAspectRatio);
    }

    filters = new Filters(*image);

    //brilho blur e saturação 0
    ui->horizontalSlider->setValue(0);
    ui->sliderSaturacao->setValue(0);
    ui->graphicsView->setGraphicsEffect(nullptr);
}

//brilho
void editorwindow::on_pushButton_clicked()
{
    filters = new Filters(*image);
    ui->horizontalSlider->setVisible(true);
    ui->sliderSaturacao->setVisible(false);
    ui->saturacao->setStyleSheet(" QPushButton{background: rgb(43, 43, 43); color: white; border: 1px solid transparent; margin: auto; border-radius: 10px}");
    ui->pushButton->setStyleSheet(" QPushButton{background: rgb(50, 50, 50); color: white; border: 1px solid transparent; margin: auto; border-radius: 10px; padding-right: 3px; padding-left: 3px} ");
}
//brilho slider
void editorwindow::on_horizontalSlider_valueChanged(int value)
{
    QImage *imageF = filters->addBrightness(value);
    image = new QPixmap(QPixmap::fromImage(*imageF));

    if (!image->isNull()) {
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);
        scenee->setSceneRect(pixmapItem->boundingRect());
        ui->graphicsView->setScene(scenee);
        ui->graphicsView->fitInView(scenee->sceneRect(), Qt::KeepAspectRatio);
    }
}
//saturação
void editorwindow::on_saturacao_clicked()
{
    filters = new Filters(*image);
    ui->sliderSaturacao->setVisible(true);
    ui->horizontalSlider->setVisible(false);
    ui->pushButton->setStyleSheet(" QPushButton{background: rgb(43, 43, 43); color: white; border: 1px solid transparent; margin: auto; border-radius: 10px}");
    ui->saturacao->setStyleSheet(" QPushButton{background: rgb(50, 50, 50); color: white; border: 1px solid transparent; margin: auto; border-radius: 10px; padding-right: 3px; padding-left: 3px} ");
}


//saturação slider
void editorwindow::on_sliderSaturacao_valueChanged(int value)
{
    QImage *imageF = filters->changeSaturation(value);
    image = new QPixmap(QPixmap::fromImage(*imageF));

    if (!image->isNull()) {
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);
        scenee->setSceneRect(pixmapItem->boundingRect());
        ui->graphicsView->setScene(scenee);
        ui->graphicsView->fitInView(scenee->sceneRect(), Qt::KeepAspectRatio);
    }
}
//girar
void editorwindow::on_girar_clicked()
{
    ui->graphicsView->scene()->clear();
    QTransform transform;
    transform.rotate(90); // Set the desired rotation angle here

    QImage rotatedImage = image->toImage();
    QImage rotatedImage2 = rotatedImage.transformed(transform);

    image = new QPixmap(QPixmap::fromImage(rotatedImage2));

    if (!image->isNull()) {
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);
        scenee->setSceneRect(pixmapItem->boundingRect());

        ui->graphicsView->setScene(scenee);
        ui->graphicsView->fitInView(scenee->sceneRect(), Qt::KeepAspectRatio);
    }


}

//filtros
//preto e branco
void editorwindow::on_peb_clicked()
{
    QImage grayscaleImage = image->toImage();
    grayscaleImage = grayscaleImage.convertToFormat(QImage::Format_Grayscale8);

    image = new QPixmap(QPixmap::fromImage(grayscaleImage));
    if (!image->isNull()) {
        // Create a QGraphicsPixmapItem with the loaded pixmap
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);

        // Optional: Adjust the scene's bounding rectangle to match the size of the pixmap item
        scenee->setSceneRect(pixmapItem->boundingRect());

        // Set the created scene as the scene for the QGraphicsView widget
        ui->graphicsView->setScene(scenee);

        // Optional: Adjust the view to fit the scene
        ui->graphicsView->fitInView(scenee->sceneRect(), Qt::KeepAspectRatio);
    }
}

//inverter
void editorwindow::on_inverter_clicked()
{
    QImage inverted = image->toImage();
    inverted.invertPixels();

    image = new QPixmap(QPixmap::fromImage(inverted));
    if (!image->isNull()) {
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);
        scenee->setSceneRect(pixmapItem->boundingRect());
        ui->graphicsView->setScene(scenee);
        ui->graphicsView->fitInView(scenee->sceneRect(), Qt::KeepAspectRatio);
    }
}

//blur
void editorwindow::on_blur_clicked()
{
    QGraphicsBlurEffect* blurEffect = new QGraphicsBlurEffect;
    blurEffect->setBlurRadius(5);
    if (!image->isNull()) {
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);
        scenee->setSceneRect(pixmapItem->boundingRect());
        ui->graphicsView->setScene(scenee);
        ui->graphicsView->fitInView(scenee->sceneRect(), Qt::KeepAspectRatio);
        ui->graphicsView->setGraphicsEffect(blurEffect);
    }
}

//sepia
void editorwindow::on_sepia_clicked()
{
    filters = new Filters(*image);
    QImage *imageF = filters->Sepia();
    image = new QPixmap(QPixmap::fromImage(*imageF));

    if (!image->isNull()) {
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);
        scenee->setSceneRect(pixmapItem->boundingRect());
        ui->graphicsView->setScene(scenee);
        ui->graphicsView->fitInView(scenee->sceneRect(), Qt::KeepAspectRatio);
    }
}

//filtro FX01
void editorwindow::on_special_clicked()
{
    filters = new Filters(*image);
    QImage *imageF = filters->Special();
    image = new QPixmap(QPixmap::fromImage(*imageF));

    if (!image->isNull()) {
        QGraphicsPixmapItem* pixmapItem = scenee->addPixmap(*image);
        scenee->setSceneRect(pixmapItem->boundingRect());
        ui->graphicsView->setScene(scenee);
        ui->graphicsView->fitInView(scenee->sceneRect(), Qt::KeepAspectRatio);
    }
}

