#include "savewindow.h"
#include "ui_savewindow.h"

saveWindow::saveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::saveWindow)
{
    ui->setupUi(this);
}

saveWindow::~saveWindow()
{
    delete ui;
}

void saveWindow::on_voltar_clicked()
{
    close();
}

