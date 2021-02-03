#ifndef INTERFACE2_H
#define INTERFACE2_H

#include <QWidget>

namespace Ui {
class Interface2;
}

class Interface2 : public QWidget
{
    Q_OBJECT

public:
    explicit Interface2(QWidget *parent = nullptr);
    ~Interface2();

private:
    Ui::Interface2 *ui;
};

#endif // INTERFACE2_H
