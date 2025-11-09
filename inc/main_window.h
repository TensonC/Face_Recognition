#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QMainWindow>
#include <QStackedWidget>
#include <QMenuBar>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <thread>
#include <atomic>

class Face : public QMainWindow
{
    Q_OBJECT

public:
    Face(QWidget *parent = nullptr);
    ~Face();

private:
    QStackedWidget *Page;

    QWidget *page_face;
    QLabel *face_label;

    QWidget *page_log;
    QTableWidget *log_table;
    QPushButton *btn_next;

    QWidget *page_new_face;
    QLabel *new_face_label;
    QPushButton *btn_face;
    QPushButton *btn_log;
    QPushButton *btn_new;
    QPushButton *btn_ok;
};

#endif // _MAIN_WINDOW_H_
