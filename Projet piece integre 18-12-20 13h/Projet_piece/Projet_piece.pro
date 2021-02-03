QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencvtest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    interface2.cpp

HEADERS  += mainwindow.h \
    interface2.h

FORMS    += mainwindow.ui \
    interface2.ui


INCLUDEPATH += D:\opencv\build\include

LIBS += D:\opencv-build\bin\libopencv_core400.dll
LIBS += D:\opencv-build\bin\libopencv_highgui400.dll
LIBS += D:\opencv-build\bin\libopencv_imgcodecs400.dll
LIBS += D:\opencv-build\bin\libopencv_imgproc400.dll
LIBS += D:\opencv-build\bin\libopencv_features2d400.dll
LIBS += D:\opencv-build\bin\libopencv_calib3d400.dll
LIBS += D:\opencv-build\bin\libopencv_video400.dll
LIBS += D:\opencv-build\bin\libopencv_videoio400.dll
#LIBS += D:\opencv-build\bin\libopencv_videostab400.dll



# more correct variant, how set includepath and libs for mingw
# add system variable: OPENCV_SDK_DIR=D:/opencv/build
# read http://doc.qt.io/qt-5/qmake-variable-reference.html#libs

#INCLUDEPATH += $$(OPENCV_SDK_DIR)/include

#LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \
#        -lopencv_core400        \
#        -lopencv_highgui400     \
#        -lopencv_imgcodecs400   \
#        -lopencv_imgproc400     \
#        -lopencv_features2d400  \
#        -lopencv_calib3d400
