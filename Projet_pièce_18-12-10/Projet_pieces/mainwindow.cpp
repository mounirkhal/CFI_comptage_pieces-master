#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // read an image
    cv::Mat source = cv::imread("plusieurs_pieces.JPG", 1);
    // create image window named "Image Source"
    cv::namedWindow("Image Source");

    // Redimensionnement de l'image
    cv::resize(source, source, cv::Size(), 0.25, 0.25);
    // show the image on window
    cv::imshow("Image Source", source);




    // On transforme l'image en niveaux de gris pour réduire les informations superflues pour la détection de formes
    cv::Mat gray;
    cv::cvtColor(source, gray, COLOR_BGR2GRAY);
    imshow("En gris", gray);

    // On applique un filtre médian pour réduire le niveau de détail et améliorer la détection des cercles
    cv::Mat grayBlur;
    medianBlur(gray, grayBlur, 5);
    imshow("En gris flou", grayBlur);

    // Détection des cercles par la transformée de Hough circulaire
    vector<Vec3f> circles;
    HoughCircles(grayBlur, circles, HOUGH_GRADIENT, 1,
                 grayBlur.rows/10,  // change this value to detect circles with different distances to each other
                 100, 30, 30, 100 // change the last two parameters
            // (min_radius & max_radius) to detect larger circles
    );

    // Tracage des cercles détectés
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        // centre du cercle
        circle( source, center, 1, Scalar(0,100,100), 3, LINE_AA);
        // contour du cercle
        int radius = c[2];
        circle( source, center, radius, Scalar(0,255,0), 3, LINE_AA);
    }
    imshow("detected circles", source);
    waitKey();


}

MainWindow::~MainWindow()
{
    delete ui;
}
