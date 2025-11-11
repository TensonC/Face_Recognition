#include "main_window.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication face_app(argc,argv);
    Face win;
    win.show();
    return face_app.exec();

}
