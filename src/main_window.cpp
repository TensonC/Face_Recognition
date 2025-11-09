#include "main_window.h"
#include "ui.h"

Face::Face(QWidget *parent)
    : QMainWindow(parent)
    , ui(new UI::Face)
{
    ui->setupUI(this);

    connect(ui->btn_face, &QPushButton::clicked, 
            [=](){ ui->Page->setCurrentIndex(0); });
    connect(ui->btn_log, &QPushButton::clicked, 
            [=](){ ui->Page->setCurrentIndex(1); });
    connect(ui->btn_new, &QPushButton::clicked, 
            [=](){ ui->Page->setCurrentIndex(2); });

}

Face::~Face()
{
    delete ui;
}
