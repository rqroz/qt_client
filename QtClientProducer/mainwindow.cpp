#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QLCDNumber>
#include <QString>
#include <QTcpSocket>
#include <QDateTime>
#include <QSlider>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->servers_lview->setSpacing(5);

    this->initialSetup();

    connect(this->timer,
            SIGNAL(timeout()),
            this,
            SLOT(sendData()));

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

bool MainWindow::isConnected(){
    return this->socket->state() == QAbstractSocket::ConnectedState;
}

void MainWindow::manageButtonsOnConnection(){
    bool connected = this->isConnected();

    this->ui->connect_btn->setEnabled(!connected);
    this->ui->disconnect_btn->setEnabled(connected);

    this->ui->start_btn->setEnabled(connected);
    this->ui->stop_btn->setEnabled(false);
}

void MainWindow::styleLCD(QLCDNumber *lcd){
    lcd->setSegmentStyle(QLCDNumber::Flat);
}

void MainWindow::setSliderDefaults(QSlider *qsl){
    qsl->setMinimum(1);
    qsl->setMaximum(100);
}

void MainWindow::initialSetup(){
    this->timer = new QTimer(this);
    this->socket = new QTcpSocket(this);

    this->ui->server_input->setPlaceholderText("www.example.com");
    this->ui->server_input->setText("127.0.0.1");
    this->ui->port_input->setPlaceholderText("port");
    this->ui->port_input->setText("1234");

    this->styleLCD(ui->maxlcd_display);
    this->styleLCD(ui->minlcd_display);

    setSliderDefaults(this->ui->timing_slider);
    setSliderDefaults(this->ui->min_slider);
    setSliderDefaults(this->ui->max_slider);
    this->ui->max_slider->setValue(this->ui->max_slider->maximum());

    this->changeMaxLCD(this->ui->max_slider->value());
    this->changeMinLCD(this->ui->min_slider->value());
    this->changeTimingOutput(this->ui->timing_slider->value());

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
    qDebug() << "Disconnected.";
}

void MainWindow::sendData(){
    int randomValue = qrand() % this->ui->max_slider->value() + this->ui->min_slider->value();

    QString str;
    str = "set " +
            QDateTime::currentDateTime().toString((Qt::ISODate)) +
            " " +
            QString::number(randomValue);
    qDebug() << str;
    qDebug() << socket->write(str.toStdString().c_str()) << " bytes written.";
    this->ui->servers_lview->addItem(str);
    this->ui->servers_lview->scrollToBottom();
    if(socket->waitForBytesWritten(1.5*1000)){
        qDebug() << "The data was written on socket.\n";
    }else{
        qDebug() << "Could not write data socket...\n";
    }
}

void MainWindow::startSendingData(){
    if(this->isConnected()){
        this->ui->start_btn->setEnabled(false);
        this->ui->stop_btn->setEnabled(true);

        srand(QTime::currentTime().elapsed());
        this->timer->start(this->ui->timing_slider->value()*1000);
    }
}

void MainWindow::stopSendingData(){
    if(this->isConnected() && this->socket->isOpen()){
        this->timer->stop();
        this->ui->start_btn->setEnabled(true);
        this->ui->stop_btn->setEnabled(false);
    }
}

void MainWindow::changeMinLCD(int value){
    ui->minlcd_display->display(value);
}

void MainWindow::changeMaxLCD(int value){
    ui->maxlcd_display->display(value);
}

void MainWindow::changeTimingOutput(int value){
    ui->timing_output->setText(QString::number(value) + "s");
    if(this->timer != NULL){
        this->timer->setInterval(value*1000);
    }
}

MainWindow::~MainWindow(){
    delete socket;
    delete timer;
    delete ui;
}
