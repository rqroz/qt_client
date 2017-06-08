#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTcpSocket>
#include <QMessageBox>
#include <QListWidget>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->initialSetup();

    connect(ui->connect_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(openConnection()));

    connect(ui->disconnect_btn,
            SIGNAL(clicked(bool)),
            this,
            SLOT(closeConnection()));

//    connect(ui->server_lview,
//            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
//            this,
//            SLOT(changeTimingOutput(QListWidgetItem*,QListWidgetItem*)));

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
    delete socket;
    delete timer;
    delete ui;
}


bool MainWindow::isConnected(){
    return this->socket->state() == QAbstractSocket::ConnectedState;
}

void MainWindow::setSliderDefaults(QSlider *qsl){
    qsl->setMinimum(this->slider_offset);
    qsl->setMaximum(qsl->maximum()+this->slider_offset);
}

void MainWindow::displayMessageBox(QString message){
    QMessageBox mb;
    mb.setText(message);
    mb.exec();
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
    this->timer = new QTimer(this);
    this->socket = new QTcpSocket(this);

    this->ui->server_input->setPlaceholderText("www.example.com");
    this->ui->server_input->setText("127.0.0.1");
    this->ui->port_input->setPlaceholderText("port");
    this->ui->port_input->setText("1234");

    this->setSliderDefaults(this->ui->timing_slider);
    this->changeTimingOutput(this->ui->timing_slider->value());

    this->ui->server_lview->setSpacing(2);

    this->changeTimingOutput(this->slider_offset);
    this->manageButtonsOnConnection();
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

        this->manageButtonsOnConnection();
        if(this->socket->waitForConnected(3*1000)){
            qDebug() << "Connected";
            this->updateServerList();
            message = "Conexão com " + fullServerPath + " estabelecida.";
        }else{
            qDebug() << "Could not connect";
            message = "Não foi possível estabelecer conexão com " + fullServerPath +  " ...";
        }
    }else{
        message = "Insira uma URL para iniciar conexão...";
    }

    this->displayMessageBox(message);
}

void MainWindow::closeConnection(){
    this->socket->close();
    this->manageButtonsOnConnection();
    qDebug() << "Disconnected";
}

void MainWindow::updateServerList(){
    if(this->writeOnSocket("list", 1.5)){
        this->ui->server_lview->clear();
        while(socket->bytesAvailable()){
            this->ui->server_lview->addItem(socket->readLine().replace("\n", "").replace("\r", ""));
        }
        if(this->ui->server_lview->count() > 0){
            this->ui->server_lview->setCurrentRow(0);
            if(!this->ui->stop_btn->isEnabled()){
                qDebug() << "wtf";
                this->ui->start_btn->setEnabled(true);
            }
        }
    }else{
        this->displayMessageBox("Conexão não estabelecida...");
    }
}

bool MainWindow::writeOnSocket(QString str, int timeoutInterval){
    if(this->isConnected()){
        socket->write(str.toStdString().c_str());
        socket->waitForBytesWritten(timeoutInterval*1000);
        socket->waitForReadyRead(timeoutInterval*1000);
        return true;
    }
    return false;
}

void MainWindow::fetchData(QString serverURL){
    if(this->writeOnSocket(serverURL, 1.5)){
        int index = 0;
        while(socket->bytesAvailable()){
            qDebug() << index << ": " << socket->readLine().replace("\n", "").replace("\r", "");
            index++;
        }
    }else{
        this->displayMessageBox("Conexão não estabelecida...");
    }
}

void MainWindow::startFetchingData(){
    qDebug() << this->ui->server_lview->currentItem()->text();
    return;
    QString serverURL;
    serverURL = "get " +
            QString::number(1) +
            "\r\n";

    this->ui->start_btn->setEnabled(false);
    this->ui->stop_btn->setEnabled(true);

    connect(this->timer,
            SIGNAL(timeout()),
            this,
            SLOT(fetchData(serverURL)));
    this->timer->start(this->ui->timing_slider->value()*1000);

}

void MainWindow::stopFetchingData(){
    this->timer->stop();
    this->ui->start_btn->setEnabled(true);
    this->ui->stop_btn->setEnabled(false);
}


void MainWindow::changeTimingOutput(int value){
    ui->timing_output->setText(QString::number(value+this->slider_offset) + "s");
}

void MainWindow::currentServerChanged(QListWidgetItem *current, QListWidgetItem *previous){
    bool enabled = true;
    qDebug() << current->text();
    if(current->text().isEmpty() || current->text().contains("host")){
        enabled = false;
    }

    this->ui->start_btn->setEnabled(enabled);
}
