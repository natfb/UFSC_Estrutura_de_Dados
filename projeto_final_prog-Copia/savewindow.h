#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class saveWindow;
}

class saveWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit saveWindow(QWidget *parent = nullptr);
    ~saveWindow();

private slots:
    void on_voltar_clicked();

private:
    Ui::saveWindow *ui;
};

#endif // SAVEWINDOW_H
