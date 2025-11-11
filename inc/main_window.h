#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QMainWindow>
#include <QVector>
#include <QThread>
#include <QObject>
#include "log_thread.h"
#include "ui.h"


QT_BEGIN_NAMESPACE
namespace UI { class Face; }
QT_END_NAMESPACE

class Face : public QMainWindow
{
    Q_OBJECT
public:
    Face(QWidget *parent = nullptr);
    ~Face();
private slots:
    void showLogs(QVector<log_info> logs);
signals:
    void read_notification(int len);
private:
    UI::Face* ui;

    QThread writeLogThread;
    QThread readLogThread;

    LogDatabase *logdb;
    WriteLog *write_log;
    ReadLog *read_log;

};

#endif // _MAIN_WINDOW_H_
