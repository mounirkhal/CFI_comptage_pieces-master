#include "mainwindow.h"
#include "ui_mainwindow.h"



int MainWindow::numero = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Déclaration de la taille du label d'affichage
    taillePhotoBaseH = 750;
    taillePhotoBaseL = 750;

    // Photos dans l'interface

    ui->setupUi(this);

    // Image de fond
    Mat Fond = imread("fond_1.jpg", 1);
    Mat imageFond = redimensionnerLabel(Fond, taillePhotoBaseH, taillePhotoBaseL);

    QImage qimg(imageFond.data,
                imageFond.cols,
                imageFond.rows,
                imageFond.step,
                QImage::Format_RGB888);

    QPixmap pix (QPixmap::fromImage(qimg.rgbSwapped()));
    this->ui->lPhotoBase->setPixmap(pix);

    QPixmap PhotoCFI("Logo_CFI.jpg");      // Logo du CFI
    this->ui->lPhotoCFI->setPixmap(PhotoCFI);

    QPixmap Centime_1("1_centime.png");   //Photo de 1 centime
    this->ui->l1Centime->setPixmap(Centime_1);

    QPixmap Centime_2("2_centime.png");   //Photo de 2 centime
    this->ui->l2Centime->setPixmap(Centime_2);

    QPixmap Centime_5("5_centime.png");   //Photo de 5 centime
    this->ui->l5Centime->setPixmap(Centime_5);

    QPixmap Centime_10("10_centime.png");   //Photo de 10 centime
    this->ui->l10Centime->setPixmap(Centime_10);

    QPixmap Centime_20("20_centime.png");   //Photo de 20 centime
    this->ui->l20Centime->setPixmap(Centime_20);

    QPixmap Centime_50("50_centime.png");   //Photo de 50 centime
    this->ui->l50Centime->setPixmap(Centime_50);

    QPixmap Euro_1("1_euro.png");   //Photo de 1 euro
    this->ui->l1Euro->setPixmap(Euro_1);

    QPixmap Euro_2("2_euro.png");   //Photo de 2 euro
    this->ui->l2Euro->setPixmap(Euro_2);

    //fin des photos dans l'interface

    //Interface_2 = new Interface2;

}

MainWindow::~MainWindow()
{
    delete ui;
}


/******************************************* Acquisition de l'image depuis un fichier *******************************************/
/********************************************************************************************************************************/
void MainWindow::on_tbSource_clicked()
{
    QString str;
    QFileInfo file(QFileDialog::getOpenFileName(this, "titre", "/home")); // récupérer le nom d'un fichier(avec l'extension) il faut utiliser QFileInfo
    QString nomfichier = file.fileName();
    this->ui->leSource->setText(nomfichier);                             // afficher le lien dans leSource

    // lire une image
    // l'image doit se trouver dans le dossier build du programme.
    source = imread(file.fileName().toStdString(), 1);
    Mat imageAffiche = redimensionnerLabel(source, taillePhotoBaseH, taillePhotoBaseL);

    QImage qimg(imageAffiche.data,
                imageAffiche.cols,
                imageAffiche.rows,
                imageAffiche.step,
                QImage::Format_RGB888);

    QPixmap pix (QPixmap::fromImage(qimg.rgbSwapped()));
    this->ui->lPhotoBase->setPixmap(pix);
    this->ui->lPhotoBase->setPixmap(pix);



}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(video.isOpened())
    {
        QMessageBox::warning(this,
                             "Warning",
                             "Stop the video before closing the application!");
        event->ignore();
    }
    else
    {
        event->accept();
    }
}


/******************************************* Acquisition de l'image par la caméra *******************************************/
/****************************************************************************************************************************/
void MainWindow::on_pbAcquerir_clicked()
{
    bool isCamera;
    int cameraIndex = ui->leIndexCamera->text().toInt(&isCamera);
    if(isCamera)

    {

        if(!video.open(cameraIndex))
        {
            QMessageBox::critical(this,
                                  "Camera Error",
                                  "Make sure you entered a correct camera index,"
                                  "<br>or that the camera is not being accessed by another program!");
            return;
        }
    }
    //int index =0 ;
    //video.open(index);
    Mat frame;
    bool photoPrise = 0;
    while(video.isOpened())
    {
        video >> frame;
        if(!frame.empty())
        {
            QImage qimg(frame.data,
                        frame.cols,
                        frame.rows,
                        frame.step,
                        QImage::Format_RGB888);

            QPixmap pix (QPixmap::fromImage(qimg.rgbSwapped()));
            this->ui->lPhotoBase->setPixmap(pix);

            if (!photoPrise && video.isOpened())
            {
                video.release();


                QString nomFichier ="savedImage"+QString::number(MainWindow::numero)+".png";
                QFile file (nomFichier);
                cvtColor(frame, frame, COLOR_BGR2RGB);
                file.open(QIODevice::WriteOnly);
                qimg.save(&file,nullptr,99);
                file.close();
                photoPrise = 1;

                cvtColor(frame, frame, COLOR_RGB2BGR);
                source = frame; //enregistrement pour traitment de l'image par le logiciel

                MainWindow::numero++;
                return;

            }



        }

        qApp->processEvents();
    }

}

/****************************************** Redimensionnement de l'image affichée ******************************************/
/***************************************************************************************************************************/
Mat MainWindow::redimensionnerLabel(Mat image, int hauteur, int largeur)
{
    // Redimensionnement de l'image à afficher dans le Qlabel

    Mat imageAffiche;

    double echelle1 = hauteur/ static_cast<double>(image.rows);
    double echelle2 = largeur/ static_cast<double>(image.cols);
    double echelle;

    if (echelle1 <= echelle2)
    {
        echelle = echelle1;
    } else {
        echelle = echelle2;
    }

    cv::resize(image, imageAffiche, cv::Size(), echelle, echelle);


    return imageAffiche;
}

/*************************************** Méthode de calcul des statistiques de teinte ***************************************/
/****************************************************************************************************************************/
Vec2i MainWindow::calcStatTeinte(Mat source)
{
    // conversion de l'image RGB de base en HSV (Hue Saturation Value / Teinte Saturation Luminance)
    Mat hsv;
    cvtColor(source, hsv, COLOR_BGR2HSV);

    vector<Mat> hsv_planes;
    split(hsv, hsv_planes);

    // Obtention de la taille de l'image
    Size taille = hsv.size();
    int lignes = taille.height;
    int colonnes = taille.width;

    // Création du masque circulaire
    Mat masque;
    masque.zeros(lignes, colonnes, CV_8UC1); // Type : matrice d'entier non signés (U) avec 1 canal codé en 8-bit

    Point centre = Point(lignes/2, colonnes/2); // coordonnées du centre du cercle

    cv::circle(masque, centre, 60, 255, -1); // le masque est un cercle

    // déclaration des autres paramètres pour le calcul de l'histogramme
    int histSize = 361;
    float range[] = { 0, 361 }; //the upper boundary is exclusive
    const float* histRange = { range };
    bool uniform = true, accumulate = false;
    Mat h_hist;

    calcHist( &hsv_planes[0], 1, 0, masque, h_hist, 1, &histSize, &histRange, uniform, accumulate );

    int hist_w = 512, hist_h = 400;
    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

    // normalisation des histogrammes
    normalize(h_hist, h_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

    float total_pixels = 0;
    float arrondi = 0.5;

    // Calcul de la moyenne de l'histogramme
    float h_hist_sum = 0;
    int h_hist_moy = 0;

    for (int i=0 ; i<361 ; i++)
    {
        h_hist_sum += i * h_hist.at<float>(i) ;
        total_pixels += h_hist.at<float>(i);
    }

    h_hist_moy = static_cast<int>((h_hist_sum / total_pixels) + arrondi) ;

    // Calcul de la moyenne de la saturation de l'image
    float s_hist_sum = 0;
    int s_hist_moy = 0;

    // Obtention de la taille de l'image
    float nbPixels = float(hsv_planes[1].rows * hsv_planes[1].cols);

    for (int i=0 ; i<hsv_planes[1].rows ; i++)
    {
        for (int j=0 ; j<hsv_planes[1].cols ; j++)
        {
            s_hist_sum += hsv.at<Vec3b>(Point(i, j))[1];
        }
    }

    s_hist_moy = static_cast<int>((s_hist_sum / nbPixels)) ;


    Vec2i h_stats;
    h_stats[0] = h_hist_moy;
    h_stats[1] = s_hist_moy;

    return h_stats;
}

/*************************************************** Comptage des pièces ***************************************************/
/***************************************************************************************************************************/
void MainWindow::on_pbCompter_clicked()
{

    if (this->ui->cbDetail->isChecked()) // si on coche la check box plus la case compter, on affiche l'interface 2
    {
        Interface_2->show();            // fonction pour afficher l'interface
    }

    source = redimensionnerLabel(source, 750, 750);

    /***********************************************************************************************************/
    /****************************************** Détection des cercles ******************************************/
    /***********************************************************************************************************/

    //image de base pour la détection de cercles
    Mat detectionCercle = source.clone();
    Mat CercleTrace = source.clone();

    // On transforme l'image en niveaux de gris
    Mat gray;
    cvtColor(detectionCercle, gray, COLOR_BGR2GRAY);
    //imshow("En gris", gray);

    // On applique un filtre médian pour réduire le niveau de détail et améliorer la détection des cercles
    Mat grayBlur;
    medianBlur(gray, grayBlur, 5);
    //imshow("En gris flou", grayBlur);

    // Détection des cercles par la transformée de Hough circulaire
    vector<Vec3f> circles;
    HoughCircles(grayBlur, circles, HOUGH_GRADIENT, 1,
                 grayBlur.rows/10,  // cette valeur détermine la distance minimale entre les centres de 2 cercles détectés.
                 100, 30, 30, 60 // changer les 2 dernières valeurs (rayon min & rayon max) pour détecter des cercles plus larges.
                );

    // Traçage des cercles détectés
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        // centre du cercle
        circle( CercleTrace, center, 1, Scalar(0,100,100), 3, LINE_AA);
        // contour du cercle
        int radius = c[2];
        circle( CercleTrace, center, radius, Scalar(0,255,0), 2, LINE_AA);
    }
    //imshow("Cercles detectes", CercleTrace);

    /*********************************************************************************************************************/
    /****************************************** Reconnaissance du type de pièce ******************************************/
    /*********************************************************************************************************************/

    // la reconnaissance se fait par le diamètre de la pièce, sa teinte moyenne et sa saturation moyenne

    // Mise à l'échelle par rapport au plus grand cercle détecté, dans notre cas, une pièce de 5 francs
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

    double reference = 31.11; //taille d'une pièce 5 francs
    double echelle = max / reference;


    // Détermination de la valeur de la pièce par rapport à leur diamètre
    vector<int> valeurPiece; // sauvegarde des valeurs monétaires de chaque cercle

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

    double e200 = (taille2euro - taille50cent)  * echelle ;

    double e50  = (taille50cent - taille20cent) * echelle ;
    double e20  = (taille50cent - taille20cent) * echelle ;
    double e10  = (taille20cent - taille10cent) * echelle ;
    double e5   = (taille5cent - taille2cent) * echelle ;
    double e2   = (taille2cent - taille1cent)  * echelle ;

    for( size_t i = 0; i < circles.size(); i++ )
    {
        Vec3i c = circles[i];
        int rayon = c[2]; // rayon du cercle
        int x = c[0]; // coordonnée x du centre
        int y = c[1]; // coordonnée y du centre
        int xOrigin = x - static_cast<int>(rayon/2);
        int yOrigin = y - static_cast<int>(rayon/2);

        /************************************* Extractions des données de teinte et saturation *************************************/
        //Détermination de la zone à étudier ne contenant qu'une pièce
        Mat roi(source, Rect(xOrigin, yOrigin, rayon, rayon));

        // Calcul de la moyenne de l'histogramme de teinte
        Vec2i teinte_stats = calcStatTeinte(roi);

        /******************************************* Attribution des valeurs des pièces *******************************************/
        if (rayon == max)
        {
            valeurPiece.push_back(0);
        }
        else if ((teinte_stats[0] - 17) < 0 && (teinte_stats[1] - 100) > 0) // si la teinte est inférieure à 15 (rouge) et saturation supérieure à 100
        {
            if      (abs(rayon - taille5cent * echelle)  < e5)   { valeurPiece.push_back(5); }
            else if (abs(rayon - taille2cent * echelle)  < e2)   { valeurPiece.push_back(2); }
            else                                                 { valeurPiece.push_back(1); }
        }
        else if ((teinte_stats[1] - 50) < 0) // si la teinte n'est pas rouge et que la saturation est inférieure à 60
        {
            valeurPiece.push_back(100);
        }
        else if ((teinte_stats[0] - 23) < 0 && (teinte_stats[1] - 90) < 0) // si la teinte est inférieure à 23 (jaune) et saturation inférieure à 90
        {
            valeurPiece.push_back(200);
        }
        else if ((teinte_stats[0] - 23) < 0 && (teinte_stats[1] - 90) > 0) // si la teinte est inférieure à 23 (jaune) et saturation supérieure à 90
        {
            if (abs(rayon - taille10cent * echelle) < e10)                                        { valeurPiece.push_back(10); }
            else if (rayon < taille20cent * echelle || abs(rayon - taille20cent * echelle) < e20) { valeurPiece.push_back(50); }
            else if (rayon > taille20cent * echelle || abs(rayon - taille50cent * echelle) < e50) { valeurPiece.push_back(20); }
        }
        else { valeurPiece.push_back(0); }

        /*************************************** Ecriture des valeurs des pièces sur l'image ***************************************/

        Point centre = Point(x, y); // centre du cercle

        // Etiquettage en fonction de la valeur de la pièce
        std::string etiquette;
        if      (valeurPiece[i] == 200) { etiquette = "2 euro " + std::to_string(i); }
        else if (valeurPiece[i] == 100) { etiquette = "1 euro " + std::to_string(i); }
        else if (valeurPiece[i] == 50) { etiquette = "50 centime " + std::to_string(i); }
        else if (valeurPiece[i] == 20)  { etiquette = "20 centime " + std::to_string(i); }
        else if (valeurPiece[i] == 10)  { etiquette = "10 centime " + std::to_string(i); }
        else if (valeurPiece[i] == 5)   { etiquette = "5 centime " + std::to_string(i); }
        else if (valeurPiece[i] == 2)   { etiquette = "2 centime " + std::to_string(i); }
        else if (valeurPiece[i] == 1)   { etiquette = "1 centime " + std::to_string(i); }
        else if (valeurPiece[i] == 0)   { etiquette = std::to_string(i); }

        putText(CercleTrace, etiquette, centre, FONT_HERSHEY_DUPLEX , 0.5, Scalar(0, 0, 255), 1, LINE_AA);
    }

    /********************************************* Affichage des valeurs comptées *********************************************/

    int somme = 0, somme200 = 0, somme100 = 0, somme50 = 0, somme20 = 0, somme10 = 0, somme5 = 0, somme2 = 0, somme1 = 0;
    double total = 0;

    for (size_t i = 0 ; i < valeurPiece.size() ; i++)
    {
        switch (valeurPiece[i])
        {
            case 200 : somme200 += 1 ; break;
            case 100 : somme100 += 1 ; break;
            case 50  : somme50  += 1 ; break;
            case 20  : somme20  += 1 ; break;
            case 10  : somme10  += 1 ; break;
            case 5   : somme5   += 1 ; break;
            case 2   : somme2   += 1 ; break;
            case 1   : somme1   += 1 ; break;
        }

        somme += valeurPiece[i];
    }

    total = (somme /100.00);

    // Affichage des résultats dans l'interface

    this->ui->le2Euro->setText(QString::number(somme200));
    this->ui->le1Euro->setText(QString::number(somme100));
    this->ui->le50Centime->setText(QString::number(somme50));
    this->ui->le20Centime->setText(QString::number(somme20));
    this->ui->le10Centime->setText(QString::number(somme10));
    this->ui->le5Centime->setText(QString::number(somme5));
    this->ui->le2Centime->setText(QString::number(somme2));
    this->ui->le1Centime->setText(QString::number(somme1));

    this->ui->leSomme->setText(QString::number(total));

    Mat imageAffiche = redimensionnerLabel(CercleTrace, taillePhotoBaseH, taillePhotoBaseL);

    QImage qimg(imageAffiche.data,
                imageAffiche.cols,
                imageAffiche.rows,
                imageAffiche.step,
                QImage::Format_RGB888);

    QPixmap pix (QPixmap::fromImage(qimg.rgbSwapped()));
    this->ui->lPhotoBase->setPixmap(pix);
    this->ui->lPhotoBase->setPixmap(pix);
}

