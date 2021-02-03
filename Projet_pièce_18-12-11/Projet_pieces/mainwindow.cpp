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
    Mat source = imread("plusieurs_pieces.JPG", 1);
    // create image window named "Image Source"
    namedWindow("Image Source");

    // Redimensionnement de l'image
    cv::resize(source, source, cv::Size(), 0.25, 0.25);
    // show the image on window
    imshow("Image Source", source);

    /********************************* Egalisation de l'Intensité *********************************/

    // conversion de l'image RGB de base en LAB (Lightness Green-Red Blue-Yellow)
    Mat lab;
    cvtColor(source, lab, COLOR_BGR2Lab);

    vector<Mat> lab_planes;
    split(lab, lab_planes);

    // Application d'un CLAHE (Contrast Limited Adaptive Histogram Equalization) à la Litghness
    Ptr<CLAHE> clahe = createCLAHE();
    clahe->setClipLimit(4);

    clahe->apply(lab_planes[0], lab_planes[0]);

    merge(lab_planes,lab);

    // conversion de l'image LAB en RGB
    Mat bgr;
    cvtColor(lab, bgr, COLOR_Lab2BGR);
    imshow("Histogramme egalise", bgr);

    /********************************* Détection des cercles *********************************/

    // On transforme l'image en niveaux de gris
    Mat gray;
    cvtColor(source, gray, COLOR_BGR2GRAY);
    imshow("En gris", gray);

    // On applique un filtre médian pour réduire le niveau de détail et améliorer la détection des cercles
    Mat grayBlur;
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
    //waitKey();


     /********************************* Détection des contours *********************************/

    // On transforme l'image égalisée en niveaux de gris
    Mat grayH;
    cvtColor(bgr, grayH, COLOR_BGR2GRAY);
    imshow("En gris egalise", grayH);

    // On applique un filtre médian pour réduire le niveau de détail et améliorer la détection des cercles
    Mat grayGauss;
    GaussianBlur(grayH, grayGauss, Size(3,3), 0,0);
    imshow("En gris flou Gaussien", grayGauss);

    //A finir, multiples gauss successifs
    for (int i=0; i<4; i++)
    {
        GaussianBlur(grayH, grayGauss, Size(3,3), 0,0);
        imshow("En gris flou Gaussien", grayGauss);
    }

    // Filtre de Canny
    Mat edgesC;
    Canny(grayGauss, edgesC, 100, 200);
    imshow("Contours Canny", edgesC);

    //Filtre de Sobel
    Mat edgesS;
    Sobel(grayGauss, edgesS, CV_16S, 0, 1);

    /// Generate grad_x and grad_y
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    int ddepth = CV_16S;

    /// Gradient X
    Sobel( grayGauss, grad_x, ddepth, 1, 0);
    convertScaleAbs( grad_x, abs_grad_x );

    /// Gradient Y
    Sobel( grayGauss, grad_y, ddepth, 0, 1);
    convertScaleAbs( grad_y, abs_grad_y );

    /// Total Gradient (approximate)
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, edgesS );

    imshow("Contours Sobel", edgesS);




}

MainWindow::~MainWindow()
{
    delete ui;
}
