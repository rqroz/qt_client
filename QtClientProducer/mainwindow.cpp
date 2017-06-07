#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QLCDNumber>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->servers_lview->setSpacing(5);

    this->slider_offset = 1;
    this->initialSetup();

    connect(ui->connect_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(openConnection()));

    connect(ui->disconnect_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(closeConnection()));

    connect(ui->start_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(startSendingData()));

    connect(ui->stop_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopSendingData()));

    connect(ui->min_slider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(changeMinLCD(int)));

    connect(ui->max_slider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(changeMaxLCD(int)));

    connect(ui->timing_slider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(changeTimingOutput(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::styleLCD(QLCDNumber *lcd){
    lcd->setSegmentStyle(QLCDNumber::Flat);
}

void MainWindow::initialSetup(){
    this->styleLCD(ui->maxlcd_display);
    this->styleLCD(ui->minlcd_display);
    changeMaxLCD(0);
    changeMinLCD(0);
    changeTimingOutput(0);
}

void MainWindow::openConnection(){
    ui->servers_lview->addItem("openConnection");
}

void MainWindow::closeConnection(){
    ui->servers_lview->addItem("closeConnection");
}

void MainWindow::startSendingData(){
    ui->servers_lview->addItem("startSendingData");
}

void MainWindow::stopSendingData(){
    ui->servers_lview->addItem("stopSendingData");
}

void MainWindow::changeMinLCD(int value){
    ui->minlcd_display->display(value+this->slider_offset);
}

void MainWindow::changeMaxLCD(int value){
    ui->maxlcd_display->display(value+this->slider_offset);
}

void MainWindow::changeTimingOutput(int value){
    ui->timing_output->setText(QString::number(value+this->slider_offset) + "s");
}
