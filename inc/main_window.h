#ifndef _MAIN_WINDOW_
#define _MAIN_WINDOW_

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Face; }
QT_END_NAMESPACE

class Face : public QMainWindow
{
    Q_OBJECT

public:
    Face(QWidget *parent = nullptr);
    ~Face();

private slots:
    void nextLogPage();
private:
    Ui::Face *ui;
};

#endif //_MAIN_WINDOW_
