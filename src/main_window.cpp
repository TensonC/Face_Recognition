#include "main_window.h"

Face::Face(QWidget *parent)
    : QMainWindow(parent)
    , ui(new UI::Face)
{
    ui->setupUI(this);
    
    logdb = new LogDatabase("/mnt/tf/recognition_log.db");
    write_log = new WriteLog;
    read_log = new ReadLog;

    write_log->moveToThread(&writeLogThread);
    read_log->moveToThread(&readLogThread);

    writeLogThread.start();
    readLogThread.start();

    connect(ui->btn_face, &QPushButton::clicked, 
            this, [=](){ ui->Page->setCurrentIndex(0); });
    connect(ui->btn_log, &QPushButton::clicked, 
            this, [=](){ ui->Page->setCurrentIndex(1); });
    connect(ui->btn_new, &QPushButton::clicked, 
            this, [=](){ ui->Page->setCurrentIndex(2); });

    //点击下一页发送读日志申请
    connect(ui->btn_next, &QPushButton::clicked,
            this, [=](){ emit read_notification(10); });
    //绑定读日志申请与读日志
    connect(this, &Face::read_notification,
            read_log, &ReadLog::readNextPageLogs);
    //读取完成显示ui
    connect(read_log, &ReadLog::LogsReady, 
            this, &Face::showLogs);
}

Face::~Face()
{
    delete ui;
    delete logdb;
    writeLogThread.quit();
    writeLogThread.wait();
    readLogThread.quit();
    readLogThread.wait();
}

void Face::showLogs(QVector<log_info> logs) {
    ui->log_table->clearContents();
    for (int i = 0; i < logs.size(); i++) {
        ui->log_table->setItem(i,0,new QTableWidgetItem(logs[i].time));
        ui->log_table->setItem(i,1,new QTableWidgetItem(logs[i].user));
        ui->log_table->setItem(i,2,new QTableWidgetItem(logs[i].passed));
    }
}









