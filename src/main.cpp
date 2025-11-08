#include <QApplication>
#include "main_window.h"

int main(int argc, char* argv[]) {
    QApplication face_recognition_application(argc,argv);
    Face win;
    win.show();
    return face_recognition_application.exec();

}
