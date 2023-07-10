#ifndef editorwindow_H
#define editorwindow_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include "filters.h"
#include "paint.h"
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class editorwindow; }
QT_END_NAMESPACE

class editorwindow : public QMainWindow
{
    Q_OBJECT

public:
    editorwindow(QWidget *parent = nullptr);
    explicit editorwindow(const QString& photoPath, QWidget *parent = nullptr);
    explicit editorwindow(const QImage& img, QWidget *parent = nullptr);
    ~editorwindow();
    void setScene(const QString &path);
    /*void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);*/
    int sizeW = 437;
    int sizeH = 631;
private slots:

    void on_girar_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_peb_clicked();

    void on_inverter_clicked();

    void on_save_clicked();

    void on_default_2_clicked();

    void on_ferramentas_clicked();

    void on_filtros_clicked();

    void on_voltar_clicked();

    void on_pushButton_clicked();

    void on_saturacao_clicked();

    void on_sliderSaturacao_valueChanged(int value);


    void on_blur_clicked();

    void on_sepia_clicked();

    void on_special_clicked();

private:
    Ui::editorwindow *ui;
    QPixmap *originalImage;
    QPixmap *image;
    Filters *filters;
    ClipScene* scene;
    QGraphicsScene* scenee;
    /* QPoint ilkkonum;
    QPoint sonkonum;
    QLine cizkor;
    QVector<QLine> cizgiler;*/

};
#endif // editorwindow_H
