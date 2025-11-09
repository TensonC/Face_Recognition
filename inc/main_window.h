#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace UI { class Face; }
QT_END_NAMESPACE

class Face : public QMainWindow
{
    Q_OBJECT

public:
    Face(QWidget *parent = nullptr);
    ~Face();

private:
    UI::Face* ui;

};

#endif // _MAIN_WINDOW_H_
