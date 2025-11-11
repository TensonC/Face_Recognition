QT += widgets sql
CONFIG += c++11

OBJECTS_DIR = $$OUT_PWD/obj
DESTDIR = $$OUT_PWD/bin

SOURCES += $$files(src/*.cpp, true) \
           $$files(src/*.c, true)

HEADERS += $$files(inc/*.h, true) \
           $$files(inc/*.hpp, true)

INCLUDEPATH += $$SDKTARGETSYSROOT/usr/include/opencv4 \
               $$PWD/inc

LIBS += -lopencv_core       \ 
        -lopencv_imgproc    \
        -lopencv_highgui    \
        -lopencv_imgcodecs  \
        -lopencv_videoio
