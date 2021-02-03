/********************************************************************************
** Form generated from reading UI file 'interface2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE2_H
#define UI_INTERFACE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface2
{
public:
    QLabel *label;
    QLabel *lTraitement1;
    QLabel *label_8;
    QLabel *lTraitement2;
    QLabel *label_9;
    QLabel *lTraitement3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *lTraitement5;
    QLabel *lTraitement4;
    QLabel *label_12;
    QLabel *lTraitement6;
    QLabel *label_13;

    void setupUi(QWidget *Interface2)
    {
        if (Interface2->objectName().isEmpty())
            Interface2->setObjectName(QStringLiteral("Interface2"));
        Interface2->resize(1125, 765);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Interface2->setPalette(palette);
        label = new QLabel(Interface2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 10, 701, 41));
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
        lTraitement1 = new QLabel(Interface2);
        lTraitement1->setObjectName(QStringLiteral("lTraitement1"));
        lTraitement1->setGeometry(QRect(20, 100, 311, 291));
        label_8 = new QLabel(Interface2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(110, 60, 141, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(14);
        label_8->setFont(font1);
        lTraitement2 = new QLabel(Interface2);
        lTraitement2->setObjectName(QStringLiteral("lTraitement2"));
        lTraitement2->setGeometry(QRect(420, 100, 311, 291));
        label_9 = new QLabel(Interface2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(510, 60, 141, 41));
        label_9->setFont(font1);
        lTraitement3 = new QLabel(Interface2);
        lTraitement3->setObjectName(QStringLiteral("lTraitement3"));
        lTraitement3->setGeometry(QRect(810, 100, 311, 291));
        label_10 = new QLabel(Interface2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(910, 60, 131, 41));
        label_10->setFont(font1);
        label_11 = new QLabel(Interface2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(900, 410, 131, 41));
        label_11->setFont(font1);
        lTraitement5 = new QLabel(Interface2);
        lTraitement5->setObjectName(QStringLiteral("lTraitement5"));
        lTraitement5->setGeometry(QRect(420, 460, 311, 291));
        lTraitement4 = new QLabel(Interface2);
        lTraitement4->setObjectName(QStringLiteral("lTraitement4"));
        lTraitement4->setGeometry(QRect(20, 460, 311, 291));
        label_12 = new QLabel(Interface2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(510, 410, 141, 41));
        label_12->setFont(font1);
        lTraitement6 = new QLabel(Interface2);
        lTraitement6->setObjectName(QStringLiteral("lTraitement6"));
        lTraitement6->setGeometry(QRect(810, 460, 311, 291));
        label_13 = new QLabel(Interface2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(100, 410, 141, 41));
        label_13->setFont(font1);

        retranslateUi(Interface2);

        QMetaObject::connectSlotsByName(Interface2);
    } // setupUi

    void retranslateUi(QWidget *Interface2)
    {
        Interface2->setWindowTitle(QApplication::translate("Interface2", "Form", nullptr));
        label->setText(QApplication::translate("Interface2", "D\303\251tail du traitement de l'image :", nullptr));
        lTraitement1->setText(QApplication::translate("Interface2", "                     Traitement1", nullptr));
        label_8->setText(QApplication::translate("Interface2", "Traitement 1:", nullptr));
        lTraitement2->setText(QApplication::translate("Interface2", "                    Traitement2", nullptr));
        label_9->setText(QApplication::translate("Interface2", "Traitement 2:", nullptr));
        lTraitement3->setText(QApplication::translate("Interface2", "                        Traitement3", nullptr));
        label_10->setText(QApplication::translate("Interface2", "Traitement 3:", nullptr));
        label_11->setText(QApplication::translate("Interface2", "Traitement 6:", nullptr));
        lTraitement5->setText(QApplication::translate("Interface2", "                    Traitement5", nullptr));
        lTraitement4->setText(QApplication::translate("Interface2", "                     Traitement4", nullptr));
        label_12->setText(QApplication::translate("Interface2", "Traitement 5:", nullptr));
        lTraitement6->setText(QApplication::translate("Interface2", "                        Traitement6", nullptr));
        label_13->setText(QApplication::translate("Interface2", "Traitement 4:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interface2: public Ui_Interface2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE2_H
