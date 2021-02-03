#include "interface2.h"
#include "ui_interface2.h"

Interface2::Interface2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interface2)
{
    ui->setupUi(this);
}

Interface2::~Interface2()
{
    delete ui;
}
