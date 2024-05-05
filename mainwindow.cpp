#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QStringList stringlist;
    stringlist <<"one" << "two" << "three" << "four" << "пять";
    ui->setupUi(this);
    ui->pbutton_toggle->setCheckable(true);
    ui->comboBox->addItems(stringlist);

    connect(ui->pbutton_toggle, &QPushButton::toggled, this, &MainWindow::pbutton_toggle_toggled);

}

void MainWindow::pbutton_toggle_toggled(bool checked){
    if (checked){
         if(ui->progressBar->value() < ui->progressBar->maximum()){
             ui->progressBar->setValue(ui->progressBar->value()+1);
         }
         else{
             ui->progressBar->setValue(0);
         }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

