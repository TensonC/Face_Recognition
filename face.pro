QT += widgets
CONFIG += c++11

SOURCES += main.cpp

INCLUDEPATH += $$SDKTARGETSYSROOT/usr/include/opencv4

LIBS += -lopencv_core 
        -lopencv_imgproc 
        -lopencv_highgui 
        -lopencv_imgcodecs 
        -lopencv_videoio
