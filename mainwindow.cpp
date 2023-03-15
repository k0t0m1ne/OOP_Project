#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    buys = BuyMassive();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_clicked()
{
    std::string name = ui->Name->text().toStdString();
    double weight = ui->Weight->text().toDouble();
    double price = ui->Price->text().toDouble();
    Buy tmp = Buy();
    tmp.setName(name);
    tmp.setWeight(weight);
    tmp.setPrice(price);
    tmp.setSum(1);
    buys.add(tmp);
    Update();
}

void MainWindow::on_Remove_clicked()
{
    std::string name = ui->Name->text().toStdString();
    double weight = ui->Weight->text().toDouble();
    double price = ui->Price->text().toDouble();
    Buy tmp = Buy();
    tmp.setName(name);
    tmp.setWeight(weight);
    tmp.setPrice(price);
    tmp.setSum(1);
    buys.remove(tmp);
    ui->Name->clear();
    ui->Weight->clear();
    ui->Price->clear();
    Update();
}


void MainWindow::on_Clear_clicked()
{
    buys.removeAll();
    Update();
}


void MainWindow::Update() {
    ui->listWidget->clear();
    for (int i = 0; i < buys.size(); i++) {
        Buy tmp = buys.get(i);
        QString item =
                QString::fromStdString(tmp.getName()) + ' ' +
                QString::number(tmp.getWeight()) + ' ' +
                QString::number(tmp.getSumPrice());
        ui->listWidget->addItem(item);
        QString item2 =
                QString::fromStdString("Общая цена:") + ' ' +
                QString::number(buys.getFullPrice());
        ui->listWidget->addItem(item2);

    }
}

void MainWindow::on_actionSave_triggered()
{
    QString file_name =
            QFileDialog::getSaveFileName(this, "Save the file");
    buys.printInFile(file_name.toStdString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name =
            QFileDialog::
            getOpenFileName(this, "Open the file");
    buys.getFromFile(file_name.toStdString());
    Update();
}


