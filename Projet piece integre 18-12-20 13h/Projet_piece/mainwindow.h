#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <interface2.h>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

#include <opencv2/opencv.hpp>
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
    Mat redimensionnerLabel(Mat image, int hauteur, int largeur);
    Vec2i calcStatTeinte(Mat source);

protected:
    void closeEvent(QCloseEvent *event);

private slots:

    void on_tbSource_clicked();

    void on_pbCompter_clicked();

    void on_pbAcquerir_clicked();

private:
    Ui::MainWindow *ui;
    Interface2 * Interface_2;
    static int numero ;
    QGraphicsPixmapItem pixmap;
    cv::VideoCapture video;
    Mat source;
    int taillePhotoBaseH;
    int taillePhotoBaseL;

};

#endif // MAINWINDOW_H






/*
private slots:
    void on_startBtn_pressed();

    void on_startBtn_clicked();
*/


