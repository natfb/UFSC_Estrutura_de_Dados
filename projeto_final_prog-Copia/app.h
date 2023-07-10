#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include "filters.h"
#include "paint.h"
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QCamera>
#include <QImageCapture>
#include <QWidget>
#include <QGraphicsVideoItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaCaptureSession>
#include <QVBoxLayout>
#include <QScopedPointer>
QT_BEGIN_NAMESPACE
namespace Ui { class app; }
QT_END_NAMESPACE

class app : public QMainWindow
{
    Q_OBJECT

public:
    app(QWidget *parent = nullptr);
    ~app();
    /*void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);*/

private slots:

    void on_open_2_clicked();

    void on_pushButton_clicked();

    void on_shutter_clicked();

private:
    Ui::app *ui;
    //QImage *image;
    QPixmap *originalImage;
    QPixmap *image;
    Filters *filters;
    ClipScene* scene;
    QGraphicsScene* scenee;
    QScopedPointer<QCamera> m_camera;
    QCamera *camera;
    QVBoxLayout*            mainLayout;
    QImageCapture *imageCapture;
    QWidget* mainFrame;
    QGraphicsVideoItem*  m_graphicsVideoItem;
    QGraphicsView*       m_cameraView;
    QGraphicsScene*      m_cameraScene;
    QMediaCaptureSession m_captureSession;

};
#endif // APP_H
