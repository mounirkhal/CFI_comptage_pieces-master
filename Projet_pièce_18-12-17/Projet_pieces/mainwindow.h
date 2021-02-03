#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <string.h>
#include <math.h>

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Mat calcHistrogram(Mat source);
    Vec3i calcMoyHist(Mat source);
    Vec2i calcStatTeinte(Mat source);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
