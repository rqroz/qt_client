#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->slider_offset = 1;
    changeTimingOutput(0);

    connect(ui->connect_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(openConnection()));

    connect(ui->disconnect_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(closeConnection()));

    connect(ui->update_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(updateServerList()));

    connect(ui->start_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(startFetchingData()));

    connect(ui->stop_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopFetchingData()));

    connect(ui->timing_slider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(changeTimingOutput(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openConnection(){

}

void MainWindow::closeConnection(){

}

void MainWindow::updateServerList(){

}

void MainWindow::startFetchingData(){

}

void MainWindow::stopFetchingData(){

}


void MainWindow::changeTimingOutput(int value){
    ui->timing_output->setText(QString::number(value+this->slider_offset) + "s");
}
