#include "app.h"
#include "ui_app.h"
#include <QFileDialog>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPen>
#include <QPainter>
#include <editorwindow.h>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QImageCapture>
#include <QGraphicsVideoItem>
#include <QWidget>
#include <QMediaDevices>
#include <QRectF>

app::app(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::app)
{
    ui->setupUi(this);
    ui->shutter->setVisible(false);
    mainFrame = new QWidget();

    existingLayout = ui->horizontalLayout_2;
}

app::~app()
{
    delete ui;
    delete m_graphicsVideoItem;
    delete m_cameraView;
    delete m_cameraScene;
}

void app::on_open_2_clicked()
{
     QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "~/Pictures/",
                                                    tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));

    // Open a file dialog to select the image file
    editorwindow* editorWindow = new editorwindow(filename, this);
    editorWindow->show();
}

//camera
void app::on_pushButton_clicked()
{
    ui->shutter->setVisible(true);

    mainFrame->setMinimumSize(437, 800);

    existingLayout->setSpacing(0);
    existingLayout->setContentsMargins(0, 0, 0, 0);

    m_cameraScene = new QGraphicsScene();
    m_cameraView  = new QGraphicsView(m_cameraScene);

    m_cameraView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_cameraView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_cameraView->setScene(m_cameraScene);
    existingLayout->addWidget(m_cameraView);
    m_graphicsVideoItem = new QGraphicsVideoItem();
    m_captureSession.setVideoOutput(m_graphicsVideoItem);
    m_cameraScene->addItem(m_graphicsVideoItem);

    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
    if (cameras.isEmpty())
    {
        // sem camera
    }
    auto thisCamera = new QCamera(cameras.first());
    m_camera.reset(thisCamera);
    m_captureSession.setCamera(m_camera.data());

    imageCapture = new QImageCapture;

    m_camera->start();

    //resize camera
    m_cameraView->setGeometry(0, 0, 437, 700);
    m_graphicsVideoItem->setSize(QSizeF(437, 700));

}


void app::on_shutter_clicked()
{
    m_captureSession.setImageCapture(imageCapture);

    connect(imageCapture, &QImageCapture::imageCaptured, [=](int id, QImage imagee) {
        m_camera->stop();
        //abrir janela do editor
        ui->shutter->setVisible(true);
        editorwindow* editorWindow = new editorwindow(imagee, this);
        editorWindow->show();
    });

    imageCapture->capture();
}

