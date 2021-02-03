#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <interface2.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_tbSource_clicked();

    void on_pbCompter_clicked();

private:
    Ui::MainWindow *ui;
    Interface2 * Interface_2;

};

#endif // MAINWINDOW_H
