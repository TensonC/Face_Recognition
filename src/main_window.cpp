#include <QAction>
#include <QPushButton>
#include "log_thread.h"
#include "face_ui.h"
#include "main_window.h"

Face::Face(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Face)
{

    //init
    ui->setupUi(this);

    Face::nextLogPage();

    //action
    auto* actFace = new QAction(tr("face_recognition"),this);
    auto* actLog = new QAction(tr("log"),this);
    auto* actNew = new QAction(tr("new_face"),this);

    ui->face_recognition->addAction(actFace);
    ui->log->addAction(actLog);
    ui->new_face->addAction(actNew);

    connect(actFace,&QAction::triggered,this,[this](){ui->Page->setCurrentIndex(0); });
    connect(actLog,&QAction::triggered,this,[this](){ui->Page->setCurrentIndex(1); });
    connect(actNew,&QAction::triggered,this,[this](){ui->Page->setCurrentIndex(2); });
    connect(ui->next_page_of_log,&QPushButton::clicked,this,&Face::nextLogPage);
}

Face::~Face()
{
    delete ui;
}


void Face::nextLogPage() {
    static int page = 0;
    struct log_info info[10];

    int size = read_log(info,10,page * 10);

    if (size < 0) {
        return;
    }

    if (size == 0) {
        page = 0;
        return;
    }

    ui->log_table->setRowCount(size);
    for (int i = 0; i < size; i++) {
        ui->log_table->setItem(i, 0, new QTableWidgetItem(QString::number(info[i].id)));
        ui->log_table->setItem(i, 1, new QTableWidgetItem(info[i].time));
        ui->log_table->setItem(i, 2, new QTableWidgetItem(info[i].passed));
    }
    page++;
}









