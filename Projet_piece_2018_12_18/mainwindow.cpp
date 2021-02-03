#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
using namespace std;


int MainWindow::numero = 0;
bool photoPrise = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

  // Photos dans l'interface

{
using namespace cv;
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->scene()->addItem(&pixmap);


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


void MainWindow::on_tbSource_clicked()
{
    QString str;
    QFileInfo file(QFileDialog::getOpenFileName(this, tr("Open File"), "/home",tr("Images (*.png *.xpm *.jpg)"))); // récupérer le nom d'un fichier(avec l'extension) il faut utiliser QFileInfo
    QString nomfichier = file.fileName();
    this->ui->leSource->setText(nomfichier);                             // afficher le lien dans leSource


    /*dimentionner l'image au label correspondant
    QString scaled;
    QPixmap pix2=nomfichier.scaled(QSize(511,381),Qt::IgnoreAspectRatio);
    */

}

void MainWindow::on_pbCompter_clicked()
{

    if (this->ui->cbDetail->isChecked()) // si on coche la check box plus la case compter, on affiche l'interface 2
    {
        Interface_2->show();            // fonction pour afficher l'interface
    }
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
void MainWindow::on_pbAcquerir_clicked()
{
    using namespace cv;
    QImage qimg ;



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
photoPrise = 0;
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

                    pixmap.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()));//bgr to rgb
                    ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
                    if (!photoPrise && video.isOpened())
                    {
                        video.release();
                        QString nomFichier ="savedImage"+QString::number(MainWindow::numero)+".png";
                        QFile file (nomFichier);
                        cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
                        file.open(QIODevice::WriteOnly);
                        qimg.save(&file,nullptr,99);
                        file.close();
                        photoPrise = 1;
                        MainWindow::numero++;
                        return;

                    }



                }

                qApp->processEvents();
             }

   // MainWindow::numero ++;

}
