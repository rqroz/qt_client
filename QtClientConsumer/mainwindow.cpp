#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTcpSocket>
#include <QMessageBox>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->initialSetup();

    changeTimingOutput(0);

    connect(ui->connect_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(openConnection()));

    connect(ui->disconnect_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(closeConnection()));

    connect(ui->server_lview,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this,
            SLOT(changeTimingOutput(int)));

    connect(ui->update_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(updateServerList()));

    connect(ui->timing_slider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(changeTimingOutput(int)));

    connect(ui->start_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(startFetchingData()));

    connect(ui->stop_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopFetchingData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::isConnected(){
    return this->socket->state() == QAbstractSocket::ConnectedState;
}

void MainWindow::setSliderDefaults(QSlider *qsl){
    qsl->setMinimum(this->slider_offset);
    qsl->setMaximum(qsl->maximum()+this->slider_offset);
}


void MainWindow::manageButtonsOnConnection(){
    bool connected = this->isConnected();

    this->ui->connect_btn->setEnabled(!connected);
    this->ui->disconnect_btn->setEnabled(connected);
    this->ui->update_btn->setEnabled(connected);
    this->ui->start_btn->setEnabled(false);
    this->ui->stop_btn->setEnabled(false);
    if(!connected){
        this->ui->server_lview->clear();
    }
}

void MainWindow::initialSetup(){
    this->slider_offset = 1;

    this->socket = new QTcpSocket(this);
    this->ui->server_input->setPlaceholderText("www.example.com");
    this->ui->server_input->setText("127.0.0.1");
    this->ui->port_input->setPlaceholderText("port");
    this->ui->port_input->setText("1234");

    setSliderDefaults(this->ui->timing_slider);
    this->changeTimingOutput(this->ui->timing_slider->value());

    this->ui->server_lview->setSpacing(2);

    manageButtonsOnConnection();
}

void MainWindow::openConnection(){
    QString message;
    QString serverUrl(this->ui->server_input->text());
    if(!serverUrl.isEmpty()){
        int port = this->ui->port_input->text().toInt();
        if(port == 0){
            port = 8000;
        }

        this->socket->connectToHost(serverUrl, port);

        QString fullServerPath(serverUrl + ":" + QString::number(port));

        if(this->socket->waitForConnected(3*1000)){
            qDebug() << "Connected";
            message = "Conexão com " + fullServerPath + " estabelecida.";
        }else{
            qDebug() << "Could not connect";
            message = "Não foi possível estabelecer conexão com " + fullServerPath +  " ...";
        }
        this->manageButtonsOnConnection();
    }else{
        message = "Insira uma URL para iniciar conexão...";
    }

    QMessageBox mb;
    mb.setText(message);
    mb.exec();
}

void MainWindow::closeConnection(){
    this->socket->close();
    this->manageButtonsOnConnection();
    qDebug() << "Disconnected";
}

void MainWindow::updateServerList(){
    if(this->isConnected()){
        socket->write("list");
    }
}

void MainWindow::currentServerChanged(QListWidgetItem*,QListWidgetItem*){

}

void MainWindow::startFetchingData(){

}

void MainWindow::stopFetchingData(){

}


void MainWindow::changeTimingOutput(int value){
    ui->timing_output->setText(QString::number(value+this->slider_offset) + "s");
}
