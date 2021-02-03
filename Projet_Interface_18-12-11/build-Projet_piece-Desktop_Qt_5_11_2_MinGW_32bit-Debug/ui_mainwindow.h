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
    QLabel *lPhotoBase;
    QPushButton *pbAcquerir;
    QToolButton *tbSource;
    QLineEdit *leSource;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QPushButton *pbCompter;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLabel *label_12;
    QLineEdit *lineEdit_9;
    QLabel *label_13;
    QLineEdit *lineEdit_10;
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
    QCheckBox *cbDetaille;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1125, 701);
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
        label->setGeometry(QRect(390, 20, 451, 41));
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
        font.setFamily(QStringLiteral("Source Code Pro"));
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        lPhotoBase = new QLabel(centralWidget);
        lPhotoBase->setObjectName(QStringLiteral("lPhotoBase"));
        lPhotoBase->setGeometry(QRect(10, 110, 511, 381));
        QFont font1;
        font1.setPointSize(8);
        lPhotoBase->setFont(font1);
        pbAcquerir = new QPushButton(centralWidget);
        pbAcquerir->setObjectName(QStringLiteral("pbAcquerir"));
        pbAcquerir->setGeometry(QRect(90, 600, 121, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(12);
        pbAcquerir->setFont(font2);
        tbSource = new QToolButton(centralWidget);
        tbSource->setObjectName(QStringLiteral("tbSource"));
        tbSource->setGeometry(QRect(300, 540, 61, 31));
        leSource = new QLineEdit(centralWidget);
        leSource->setObjectName(QStringLiteral("leSource"));
        leSource->setGeometry(QRect(90, 540, 201, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 530, 81, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(14);
        label_2->setFont(font3);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(680, 170, 31, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(680, 250, 31, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(680, 330, 31, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(680, 410, 31, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(770, 90, 211, 41));
        label_8->setFont(font3);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(710, 170, 61, 21));
        lineEdit->setReadOnly(true);
        pbCompter = new QPushButton(centralWidget);
        pbCompter->setObjectName(QStringLiteral("pbCompter"));
        pbCompter->setGeometry(QRect(940, 560, 131, 41));
        pbCompter->setFont(font2);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(710, 250, 61, 21));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(710, 330, 61, 21));
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(710, 410, 61, 21));
        lineEdit_4->setReadOnly(true);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(960, 170, 31, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(960, 410, 31, 16));
        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(990, 250, 61, 21));
        lineEdit_7->setReadOnly(true);
        lineEdit_8 = new QLineEdit(centralWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(990, 330, 61, 21));
        lineEdit_8->setReadOnly(true);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(960, 330, 31, 16));
        lineEdit_9 = new QLineEdit(centralWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(990, 410, 61, 21));
        lineEdit_9->setReadOnly(true);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(960, 250, 31, 16));
        lineEdit_10 = new QLineEdit(centralWidget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(990, 170, 61, 21));
        lineEdit_10->setReadOnly(true);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(730, 490, 91, 31));
        label_14->setFont(font3);
        leSomme = new QLineEdit(centralWidget);
        leSomme->setObjectName(QStringLiteral("leSomme"));
        leSomme->setGeometry(QRect(820, 490, 141, 31));
        leSomme->setReadOnly(true);
        lPhotoCFI = new QLabel(centralWidget);
        lPhotoCFI->setObjectName(QStringLiteral("lPhotoCFI"));
        lPhotoCFI->setGeometry(QRect(960, 0, 171, 81));
        lPhotoCFI->setFont(font1);
        l1Centime = new QLabel(centralWidget);
        l1Centime->setObjectName(QStringLiteral("l1Centime"));
        l1Centime->setGeometry(QRect(620, 150, 81, 61));
        l2Centime = new QLabel(centralWidget);
        l2Centime->setObjectName(QStringLiteral("l2Centime"));
        l2Centime->setGeometry(QRect(620, 230, 81, 61));
        l5Centime = new QLabel(centralWidget);
        l5Centime->setObjectName(QStringLiteral("l5Centime"));
        l5Centime->setGeometry(QRect(620, 310, 81, 61));
        l10Centime = new QLabel(centralWidget);
        l10Centime->setObjectName(QStringLiteral("l10Centime"));
        l10Centime->setGeometry(QRect(600, 380, 81, 71));
        l20Centime = new QLabel(centralWidget);
        l20Centime->setObjectName(QStringLiteral("l20Centime"));
        l20Centime->setGeometry(QRect(900, 150, 81, 61));
        l50Centime = new QLabel(centralWidget);
        l50Centime->setObjectName(QStringLiteral("l50Centime"));
        l50Centime->setGeometry(QRect(900, 230, 81, 61));
        l1Euro = new QLabel(centralWidget);
        l1Euro->setObjectName(QStringLiteral("l1Euro"));
        l1Euro->setGeometry(QRect(900, 310, 81, 61));
        l2Euro = new QLabel(centralWidget);
        l2Euro->setObjectName(QStringLiteral("l2Euro"));
        l2Euro->setGeometry(QRect(900, 390, 81, 61));
        cbDetaille = new QCheckBox(centralWidget);
        cbDetaille->setObjectName(QStringLiteral("cbDetaille"));
        cbDetaille->setGeometry(QRect(810, 600, 261, 51));
        cbDetaille->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1125, 26));
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
        lPhotoBase->setText(QApplication::translate("MainWindow", "                                           Photo Base", nullptr));
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
        cbDetaille->setText(QApplication::translate("MainWindow", "Afficher le d\303\251taille du traitement d'image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
