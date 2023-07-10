#include "app.h"
#include "ui_app.h"
#include <QFileDialog>
#include <QVBoxLayout>
#include "paint.h"
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
    //scenee = new QGraphicsScene(this);
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

//camera copiar mais codigo do moco
void app::on_pushButton_clicked()
{
    ui->shutter->setVisible(true);
    mainFrame = new QWidget();
    mainFrame->setFixedSize(437, 800);
    // camera

    // mask
    //m_mainMaskFrame = new QWidget(mainFrame);// talvez era importante??
    //mainLayout = new QVBoxLayout(this);
    //ui->widget(mainFrame);

    QVBoxLayout* existingLayout = ui->verticalLayout;
    existingLayout->setSpacing(0);
    existingLayout->setContentsMargins(0, 0, 0, 0);

    m_cameraScene = new QGraphicsScene();
    m_cameraView  = new QGraphicsView(m_cameraScene);

    m_cameraView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_cameraView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // m_cameraView->setFixedSize(420, 700);

    m_cameraView->setScene(m_cameraScene);
    existingLayout->addWidget(m_cameraView);
    m_graphicsVideoItem = new QGraphicsVideoItem();
    m_captureSession.setVideoOutput(m_graphicsVideoItem);
    m_cameraScene->addItem(m_graphicsVideoItem);

    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
    if (cameras.isEmpty())
    {
        // erro
    }
    auto thisCamera = new QCamera(cameras.first());
    m_camera.reset(thisCamera);
    m_captureSession.setCamera(m_camera.data());

    imageCapture = new QImageCapture;

    m_camera->start();
    QRectF sceneRect = m_cameraScene->sceneRect();
    m_cameraView->setSceneRect(sceneRect);
    m_cameraView->fitInView(sceneRect, Qt::KeepAspectRatio);

    /*int height = 0;  //arrumar isso!!!!!!!
    int width  = 0;
    int y      = 0;
    int x      = 0;
    // cover size comput
    const QList<QCameraFormat> videoFormats = m_camera->cameraDevice().videoFormats();
    if (videoFormats.isEmpty())
    {
        // todo throw
    }
    auto defaultFormat = videoFormats.first();

    QSize  cameraSize        =   defaultFormat.resolution();
    double cameraAspectRatio = ( double )cameraSize.width() / cameraSize.height();
    QRect  widgetSize        = existingLayout->geometry();
    double widgetAspectRatio = ( double )widgetSize.width() / widgetSize.height();
    if (cameraAspectRatio > widgetAspectRatio)
    {
        height = widgetSize.height();
        width  = height * cameraAspectRatio;
        x      = (widgetSize.width() - width) / 2;
    }
    else
    {
        width  = widgetSize.width();
        height = width / cameraAspectRatio;
        y      = (widgetSize.height() - height) / 2;
    }
    this->setGeometry(x, y, width, height);

    m_graphicsVideoItem->setSize(QSizeF(width, height));*/
}


void app::on_shutter_clicked()
{
    QImage image;
    m_captureSession.setImageCapture(imageCapture);


    connect(imageCapture, &QImageCapture::imageCaptured, [=](int id, QImage imagee) {
        // Create and show the editor window
        m_camera->stop();
        editorwindow* editorWindow = new editorwindow(imagee, this);
        editorWindow->show();
    });

    imageCapture->capture();
}

