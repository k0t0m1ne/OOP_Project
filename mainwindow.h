#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "BuyMassive.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Clear_clicked();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();
private:
    void Update();
    BuyMassive buys;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
