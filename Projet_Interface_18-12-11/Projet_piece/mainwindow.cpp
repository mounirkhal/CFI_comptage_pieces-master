#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

  // Photos dans l'interface
{
    ui->setupUi(this);
    QPixmap PhotoBase("fond_1.jpg");       //Photo de fond
    this->ui->lPhotoBase->setPixmap(PhotoBase);

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

}
//fin des photos dans l'interface



MainWindow::~MainWindow()
{
    delete ui;
}  


void MainWindow::on_tbSource_clicked()
{
    QString str;
    QFileInfo file(QFileDialog::getOpenFileName(this, "titre", "/home")); // récupérer le nom d'un fichier(avec l'extension) il faut utiliser QFileInfo
    QString nomfichier = file.fileName();
    this->ui->leSource->setText(nomfichier);                             // afficher le lien dans leSource
    this->ui->lPhotoBase->setPixmap(nomfichier);                         // afficher la photo

}

