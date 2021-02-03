/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pbAcquerir;
    QToolButton *tbSource;
    QLineEdit *leSource;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *le1Centime;
    QPushButton *pbCompter;
    QLineEdit *le2Centime;
    QLineEdit *le5Centime;
    QLineEdit *le10Centime;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *le50Centime;
    QLineEdit *le1Euro;
    QLabel *label_12;
    QLineEdit *le2Euro;
    QLabel *label_13;
    QLineEdit *le20Centime;
    QLabel *label_14;
    QLineEdit *leSomme;
    QLabel *lPhotoCFI;
    QLabel *l1Centime;
    QLabel *l2Centime;
    QLabel *l5Centime;
    QLabel *l10Centime;
    QLabel *l20Centime;
    QLabel *l50Centime;
    QLabel *l1Euro;
    QLabel *l2Euro;
    QCheckBox *cbDetail;
    QLineEdit *leIndexCamera;
    QLabel *label_7;
    QLabel *lPhotoBase;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1370, 1076);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 1371, 41));
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QStringLiteral("Algerian"));
        font.setPointSize(32);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        pbAcquerir = new QPushButton(centralWidget);
        pbAcquerir->setObjectName(QStringLiteral("pbAcquerir"));
        pbAcquerir->setGeometry(QRect(580, 930, 101, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(14);
        pbAcquerir->setFont(font1);
        tbSource = new QToolButton(centralWidget);
        tbSource->setObjectName(QStringLiteral("tbSource"));
        tbSource->setGeometry(QRect(580, 870, 101, 40));
        QFont font2;
        font2.setPointSize(14);
        tbSource->setFont(font2);
        leSource = new QLineEdit(centralWidget);
        leSource->setObjectName(QStringLiteral("leSource"));
        leSource->setGeometry(QRect(160, 870, 411, 40));
        QFont font3;
        font3.setPointSize(12);
        leSource->setFont(font3);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 870, 101, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Calibri"));
        font4.setPointSize(16);
        label_2->setFont(font4);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(910, 280, 31, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(910, 390, 31, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(910, 500, 31, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(910, 610, 31, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(850, 180, 471, 41));
        label_8->setFont(font4);
        label_8->setAlignment(Qt::AlignCenter);
        le1Centime = new QLineEdit(centralWidget);
        le1Centime->setObjectName(QStringLiteral("le1Centime"));
        le1Centime->setGeometry(QRect(940, 270, 81, 30));
        le1Centime->setFont(font3);
        le1Centime->setReadOnly(true);
        pbCompter = new QPushButton(centralWidget);
        pbCompter->setObjectName(QStringLiteral("pbCompter"));
        pbCompter->setGeometry(QRect(970, 830, 241, 61));
        QFont font5;
        font5.setFamily(QStringLiteral("Calibri"));
        font5.setPointSize(18);
        pbCompter->setFont(font5);
        le2Centime = new QLineEdit(centralWidget);
        le2Centime->setObjectName(QStringLiteral("le2Centime"));
        le2Centime->setGeometry(QRect(940, 380, 81, 30));
        le2Centime->setFont(font3);
        le2Centime->setReadOnly(true);
        le5Centime = new QLineEdit(centralWidget);
        le5Centime->setObjectName(QStringLiteral("le5Centime"));
        le5Centime->setGeometry(QRect(940, 490, 81, 30));
        le5Centime->setFont(font3);
        le5Centime->setReadOnly(true);
        le10Centime = new QLineEdit(centralWidget);
        le10Centime->setObjectName(QStringLiteral("le10Centime"));
        le10Centime->setGeometry(QRect(940, 600, 81, 30));
        le10Centime->setFont(font3);
        le10Centime->setReadOnly(true);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1210, 280, 31, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1210, 610, 31, 16));
        le50Centime = new QLineEdit(centralWidget);
        le50Centime->setObjectName(QStringLiteral("le50Centime"));
        le50Centime->setGeometry(QRect(1240, 380, 81, 30));
        le50Centime->setFont(font3);
        le50Centime->setReadOnly(true);
        le1Euro = new QLineEdit(centralWidget);
        le1Euro->setObjectName(QStringLiteral("le1Euro"));
        le1Euro->setGeometry(QRect(1240, 490, 81, 30));
        le1Euro->setFont(font3);
        le1Euro->setReadOnly(true);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(1210, 500, 31, 16));
        le2Euro = new QLineEdit(centralWidget);
        le2Euro->setObjectName(QStringLiteral("le2Euro"));
        le2Euro->setGeometry(QRect(1240, 600, 81, 30));
        le2Euro->setFont(font3);
        le2Euro->setReadOnly(true);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(1210, 390, 31, 16));
        le20Centime = new QLineEdit(centralWidget);
        le20Centime->setObjectName(QStringLiteral("le20Centime"));
        le20Centime->setGeometry(QRect(1240, 270, 81, 30));
        le20Centime->setFont(font3);
        le20Centime->setReadOnly(true);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(960, 710, 111, 31));
        label_14->setFont(font4);
        leSomme = new QLineEdit(centralWidget);
        leSomme->setObjectName(QStringLiteral("leSomme"));
        leSomme->setGeometry(QRect(1070, 710, 141, 40));
        leSomme->setFont(font3);
        leSomme->setReadOnly(true);
        lPhotoCFI = new QLabel(centralWidget);
        lPhotoCFI->setObjectName(QStringLiteral("lPhotoCFI"));
        lPhotoCFI->setGeometry(QRect(1170, 10, 191, 91));
        QFont font6;
        font6.setPointSize(8);
        lPhotoCFI->setFont(font6);
        l1Centime = new QLabel(centralWidget);
        l1Centime->setObjectName(QStringLiteral("l1Centime"));
        l1Centime->setGeometry(QRect(850, 260, 81, 61));
        l2Centime = new QLabel(centralWidget);
        l2Centime->setObjectName(QStringLiteral("l2Centime"));
        l2Centime->setGeometry(QRect(850, 370, 81, 61));
        l5Centime = new QLabel(centralWidget);
        l5Centime->setObjectName(QStringLiteral("l5Centime"));
        l5Centime->setGeometry(QRect(850, 480, 81, 61));
        l10Centime = new QLabel(centralWidget);
        l10Centime->setObjectName(QStringLiteral("l10Centime"));
        l10Centime->setGeometry(QRect(830, 580, 81, 71));
        l20Centime = new QLabel(centralWidget);
        l20Centime->setObjectName(QStringLiteral("l20Centime"));
        l20Centime->setGeometry(QRect(1150, 260, 81, 61));
        l50Centime = new QLabel(centralWidget);
        l50Centime->setObjectName(QStringLiteral("l50Centime"));
        l50Centime->setGeometry(QRect(1150, 370, 81, 61));
        l1Euro = new QLabel(centralWidget);
        l1Euro->setObjectName(QStringLiteral("l1Euro"));
        l1Euro->setGeometry(QRect(1150, 480, 81, 61));
        l2Euro = new QLabel(centralWidget);
        l2Euro->setObjectName(QStringLiteral("l2Euro"));
        l2Euro->setGeometry(QRect(1150, 590, 81, 61));
        cbDetail = new QCheckBox(centralWidget);
        cbDetail->setObjectName(QStringLiteral("cbDetail"));
        cbDetail->setGeometry(QRect(950, 890, 261, 51));
        cbDetail->setLayoutDirection(Qt::RightToLeft);
        leIndexCamera = new QLineEdit(centralWidget);
        leIndexCamera->setObjectName(QStringLiteral("leIndexCamera"));
        leIndexCamera->setGeometry(QRect(510, 930, 61, 40));
        leIndexCamera->setFont(font3);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(340, 930, 171, 41));
        label_7->setFont(font4);
        lPhotoBase = new QLabel(centralWidget);
        lPhotoBase->setObjectName(QStringLiteral("lPhotoBase"));
        lPhotoBase->setGeometry(QRect(20, 100, 750, 750));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1370, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", " Compteur de pi\303\250ce", nullptr));
        pbAcquerir->setText(QApplication::translate("MainWindow", "Acquerir", nullptr));
        tbSource->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Source :", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "=", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "=", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "=", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "=", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Nombre de pi\303\250ce :", nullptr));
        pbCompter->setText(QApplication::translate("MainWindow", "Compter", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "=", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "=", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "=", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "=", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Somme :", nullptr));
        lPhotoCFI->setText(QApplication::translate("MainWindow", " Photo CFI", nullptr));
        l1Centime->setText(QApplication::translate("MainWindow", "1Centime", nullptr));
        l2Centime->setText(QApplication::translate("MainWindow", "2Centime", nullptr));
        l5Centime->setText(QApplication::translate("MainWindow", "5Centime", nullptr));
        l10Centime->setText(QApplication::translate("MainWindow", " 10Centime", nullptr));
        l20Centime->setText(QApplication::translate("MainWindow", " 20Centime", nullptr));
        l50Centime->setText(QApplication::translate("MainWindow", " 50Centime", nullptr));
        l1Euro->setText(QApplication::translate("MainWindow", "1Euro", nullptr));
        l2Euro->setText(QApplication::translate("MainWindow", "2Euro", nullptr));
        cbDetail->setText(QApplication::translate("MainWindow", "Afficher le d\303\251tail du traitement d'image", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Index cam\303\251ra : ", nullptr));
        lPhotoBase->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
