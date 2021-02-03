#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDir>

/******************************************* Méthode de calcul de l'histogramme *******************************************/
Mat MainWindow::calcHistrogram(Mat source)
{
    Mat src = source;

    // Séparation des canaux de couleur
    vector<Mat> bgr_planes;
    split(src, bgr_planes );

    // Obtention de la taille de l'image
    Size taille = source.size();
    int lignes = taille.height;
    int colonnes = taille.width;

    // Création du masque circulaire
    Mat masque;
    masque.zeros(lignes, colonnes, CV_8UC1); // Type : matrice d'entier non signés (U) avec 1 canal codé en 8-bit

    Point centre = Point(lignes/2, colonnes/2); // coordonnées du centre du cercle

    cv::circle(masque, centre, 60, 255, -1); // le masque est un cercle

    // déclaration des autres paramètres pour le calcul de l'histogramme
    int histSize = 256;
    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange = { range };
    bool uniform = true, accumulate = false;
    Mat b_hist, g_hist, r_hist;

    calcHist( &bgr_planes[0], 1, 0, masque, b_hist, 1, &histSize, &histRange, uniform, accumulate ); // Calcul de l'histogramme du canal bleu
    calcHist( &bgr_planes[1], 1, 0, masque, g_hist, 1, &histSize, &histRange, uniform, accumulate ); // Calcul de l'histogramme du canal vert
    calcHist( &bgr_planes[2], 1, 0, masque, r_hist, 1, &histSize, &histRange, uniform, accumulate ); // Calcul de l'histogramme du canal rouge

    int hist_w = 512, hist_h = 400;
    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

    // normalisation des histogrammes
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

    // On transforme les 3 histogrammes en une seule matrice de 3*256 lignes
    Mat histogramme;

    histogramme.push_back(b_hist);
    histogramme.push_back(g_hist);
    histogramme.push_back(r_hist);

    return histogramme;
}

/****************************************************************************************************************************************/
/****************************************************************************************************************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // read an image
    Mat source = imread("plusieur_pieces_2.jpg", 1);
    // create image window named "Image Source"
    namedWindow("Image Source");

    // Obtention de la taille de l'image
    Size tailleImage = source.size();
    int lignes1 = tailleImage.height;

    double echelle1 = 750/(double) lignes1;

    // Redimensionnement de l'image
    cv::resize(source, source, cv::Size(), echelle1, echelle1);

    // show the image on window
    imshow("Image Source", source);

    calcHistrogram(source);

    /********************************* Egalisation de l'Intensité *********************************/

    // conversion de l'image RGB de base en LAB (Lightness Green-Red Blue-Yellow)
    Mat lab;
    cvtColor(source, lab, COLOR_BGR2Lab);

    vector<Mat> lab_planes;
    split(lab, lab_planes);

    // Application d'un CLAHE (Contrast Limited Adaptive Histogram Equalization) à la Litghness
    Ptr<CLAHE> clahe = createCLAHE();
    clahe->setClipLimit(2);
    clahe->setTilesGridSize(Size(8,8));

    clahe->apply(lab_planes[0], lab_planes[0]);

    merge(lab_planes,lab);

    // conversion de l'image LAB en RGB
    Mat bgr;
    cvtColor(lab, bgr, COLOR_Lab2BGR);
    imshow("Histogramme egalise", bgr);

    /*****************************************************************************************/
    /********************************* Détection des cercles *********************************/
    /*****************************************************************************************/

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
                 grayBlur.rows/10,  // cette valeur détermine la distance minimale entre les centres de 2 cercles détectés?
                 100, 30, 30, 100 // changer les 2 dernières valeurs (rayon min & rayon max) pour détecter des cercles plus larges.
    );

    // Traçage des cercles détectés
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
    imshow("Cercles detectes", source);

    /******************************************************************************************/
    /********************************* Détection des contours *********************************/
    /******************************************************************************************/
/*
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
*/
    /***************************************************************************************************/
    /********************************* Reconnaissance du type de pièce *********************************/
    /***************************************************************************************************/

    /********************************* Enregistrement des données d'entrainement *********************************/
/*
    // localiser les images échantillons
    QDir echantillon_cuivre("echantillons/cuivre");
    QDir echantillon_bronze("echantillons/bronze");
    QDir echantillon_euro1("echantillons/euro1");
    QDir echantillon_euro2("echantillons/euro2");

    // déclaration des données d'entrainement et des labels
    Mat X;
    Mat y;

    // calcul et stocke les données d'entrainement et les labels

    // Pour les pièces de cuivre
    QFileInfoList liste_cuivre = echantillon_cuivre.entryInfoList();
    for (int i = 0; i < liste_cuivre.size(); ++i)
    {
        QFileInfo fileInfo = liste_cuivre.at(i);
        std::string nomImage = fileInfo.fileName().toLocal8Bit().constData(); // cast du QString fileName en std::string pour la lecture de l'image avec imread

        // lire l'image
        Mat image = imread(nomImage, 1);

        X.push_back(calcHistrogram(image));
        y.push_back("cuivre");
    }

    // Pour les pièces de bronze
    QFileInfoList liste_bronze = echantillon_bronze.entryInfoList();
    for (int i = 0; i < liste_bronze.size(); ++i)
    {
        QFileInfo fileInfo = liste_bronze.at(i);
        std::string nomImage = fileInfo.fileName().toLocal8Bit().constData(); // cast du QString fileName en std::string pour la lecture de l'image avec imread

        // lire l'image
        Mat image = imread(nomImage, 1);

        X.push_back(calcHistrogram(image));
        y.push_back("bronze");
    }

    // Pour les pièces de 1 euro
    QFileInfoList liste_euro1 = echantillon_euro1.entryInfoList();
    for (int i = 0; i < liste_euro1.size(); ++i)
    {
        QFileInfo fileInfo = liste_euro1.at(i);
        std::string nomImage = fileInfo.fileName().toLocal8Bit().constData(); // cast du QString fileName en std::string pour la lecture de l'image avec imread

        // lire l'image
        Mat image = imread(nomImage, 1);

        X.push_back(calcHistrogram(image));
        y.push_back("euro1");
    }

    // Pour les pièces de 2 euro
    QFileInfoList liste_euro2 = echantillon_euro2.entryInfoList();
    for (int i = 0; i < liste_euro2.size(); ++i)
    {
        QFileInfo fileInfo = liste_euro2.at(i);
        std::string nomImage = fileInfo.fileName().toLocal8Bit().constData(); // cast du QString fileName en std::string pour la lecture de l'image avec imread

        // lire l'image
        Mat image = imread(nomImage, 1);

        X.push_back(calcHistrogram(image));
        y.push_back("euro2");
    }
*/

    /********************************* Comparaison des diamètres *********************************/

    // Mise à l'échelle par rapport au plus grand cercle détecté, suposé être une pièce de 2 euros
    double max = 0;
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Vec3i c = circles[i];
        int rayon = c[2]; // rayon du cercle

        if (rayon > max)
        {
            max = rayon;
        }
     }

    double reference = 25.75; //taille d'une pièce de 2 euros
    double echelle = max / reference;

    // Obtention de la taille de l'image
    Size taille = source.size();
    int lignes = taille.height;
    int colonnes = taille.width;

    //Affichage de la taille
    QMessageBox Msg;
    Msg.setText("Echelle : " + QString::number(echelle) + "Taille : " + QString::number(lignes) + " ; " + QString::number(colonnes) );
    Msg.exec();

    // Détermination de la valeur de la pièce par rapport à leur diamètre

    vector<int> valeurPiece; // sauvegarde des valeurs monétaires de chauqe cercle

    double epsilon = 1; // marge d'erreur de la mesure de la pièce
    //tailles de toutes les pièces
    double taille2euro = 25.75;
    double taille1euro = 23.25;
    double taille50cent = 24.25;
    double taille20cent = 22.25;
    double taille10cent = 19.75;
    double taille5cent = 21.25;
    double taille2cent = 18.75;
    double taille1cent = 16.25;

    // Epsilon par pièce
    double e200 = (taille2euro - taille50cent) * echelle;
    double e50 = (taille50cent - taille1euro) * echelle;
    double e100 = (taille1euro - taille20cent) * echelle;
    double e20 = (taille20cent - taille5cent) * echelle;
    double e5 = (taille5cent - taille10cent) * echelle;
    double e10 = (taille10cent - taille2cent) * echelle;
    double e2 = (taille2cent - taille1cent) * echelle;
    double e1 = (e200 + e100 + e50 + e20 + e10 + e5 + e2) / 7;

    for( size_t i = 0; i < circles.size(); i++ )
    {
        Vec3i c = circles[i];
        double rayon = c[2]; // rayon du cercle
/*
        //Affichage
        QMessageBox Msg4;
        Msg4.setText("rayon : " + QString::number(rayon)
                     + "\n2 euro : " + QString::number(taille2euro * echelle)
                     + "\n1 euro : " + QString::number(taille1euro * echelle)
                     + "\n50 cent : " + QString::number(taille50cent * echelle)
                     + "\n20 cent : " + QString::number(taille20cent * echelle)
                     + "\n10 cent : " + QString::number(taille10cent * echelle)
                     + "\n5 cent : " + QString::number(taille5cent * echelle)
                     + "\n12 cent : " + QString::number(taille2cent * echelle)
                     + "\n1 cent : " + QString::number(taille1cent * echelle));
        Msg4.exec();
*/
        if      (abs(rayon - taille2euro * echelle)  < epsilon * e200) { valeurPiece.push_back(200); }
        else if (abs(rayon - taille50cent * echelle) < epsilon * e50) { valeurPiece.push_back(50); }
        else if (abs(rayon - taille1euro * echelle)  < epsilon * e100) { valeurPiece.push_back(100); }
        else if (abs(rayon - taille20cent * echelle) < epsilon * e20) { valeurPiece.push_back(20); }
        else if (abs(rayon - taille5cent * echelle)  < epsilon * e5) { valeurPiece.push_back(5); }
        else if (abs(rayon - taille10cent * echelle) < epsilon * e10) { valeurPiece.push_back(10); }
        else if (abs(rayon - taille2cent * echelle)  < epsilon * e2) { valeurPiece.push_back(2); }
        else if (abs(rayon - taille1cent * echelle)  < epsilon * e1) { valeurPiece.push_back(1); }
        else { valeurPiece.push_back(0); }
     }

    // Ecriture des valeurs des pièces sur l'image
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Vec3i c = circles[i];
        Point centre = Point(c[0], c[1]); // centre du cercle

        // Détermination de la valeur à afficher
        std::string etiquette;
        if      (valeurPiece[i] == 200) { etiquette = "2 euro"; }
        else if (valeurPiece[i] == 100) { etiquette = "1 euro"; }
        else if (valeurPiece[i] == 500) { etiquette = "50 centime"; }
        else if (valeurPiece[i] == 20)  { etiquette = "20 centime"; }
        else if (valeurPiece[i] == 10)  { etiquette = "10 centime"; }
        else if (valeurPiece[i] == 5)   { etiquette = "5 centime"; }
        else if (valeurPiece[i] == 2)   { etiquette = "2 centime"; }
        else if (valeurPiece[i] == 1)   { etiquette = "1 centime"; }

        putText(source, etiquette, centre, FONT_HERSHEY_DUPLEX , 0.5, Scalar(255, 0, 0), 1, LINE_AA);

    }
    imshow("Source etiquette", source);

}

MainWindow::~MainWindow()
{
    delete ui;
}
