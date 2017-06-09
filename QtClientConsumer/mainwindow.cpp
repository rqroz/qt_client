#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTcpSocket>
#include <QMessageBox>
#include <QListWidget>
#include <QTimer>
#include <QDateTime>

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
    this->timer = new QTimer(this);
    this->socket = new QTcpSocket(this);

    this->ui->server_input->setPlaceholderText("www.example.com");
    this->ui->server_input->setText("127.0.0.1");
    this->ui->port_input->setPlaceholderText("port");
    this->ui->port_input->setText("1234");

    this->ui->timing_slider->setMinimum(3);
    this->ui->timing_slider->setMaximum(100);
    this->changeTimingOutput(this->ui->timing_slider->value());

    this->ui->server_lview->setSpacing(2);

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
            this->manageButtonsOnConnection();
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
        QStringList server_list;
        while(socket->bytesAvailable()){
            server_list.append(socket->readLine().replace("\n", "").replace("\r", ""));
        }
        server_list.removeDuplicates();

        this->ui->server_lview->addItems(server_list);

        if(this->ui->server_lview->count() > 0){
            this->ui->server_lview->setCurrentRow(0);
            if(!this->ui->stop_btn->isEnabled() && !this->ui->server_lview->currentItem()->text().contains("host")){
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


void MainWindow::fetchData(){
    if(this->currentGet.isEmpty()){
        this->stopFetchingData();
        this->displayMessageBox("Servidor não identificado");
    }else{
        QString cmd = "get " + this->currentGet + "\r\n";
        qDebug() << "Server cmd: " << cmd;
        QStringList data;
        if(this->writeOnSocket(cmd, 1.5)){
            qDebug() << "wrote on socket";
            qDebug() << "bytes available: " << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                data.append(socket->readLine().replace("\n", "").replace("\r", ""));
            }

            this->ui->plotter->setData(data);
            this->ui->plotter->repaint();
        }else{
            this->stopFetchingData();
            this->displayMessageBox("Conexão não pôde estabelecida...");
        }
    }

}

void MainWindow::startFetchingData(){
    QString serverURL = this->ui->server_lview->currentItem()->text();
    if(!serverURL.isEmpty() && !serverURL.contains("host")){
        this->ui->start_btn->setEnabled(false);
        this->ui->stop_btn->setEnabled(true);
        this->currentGet = serverURL;

        connect(this->timer,
                SIGNAL(timeout()),
                this,
                SLOT(fetchData()));

        this->timer->start(this->ui->timing_slider->value()*1000);
    }else{
        this->displayMessageBox("Selecione um servidor para conectar.");
    }
}

void MainWindow::stopFetchingData(){
    this->timer->stop();
    this->currentGet.clear();
    this->ui->start_btn->setEnabled(true);
    this->ui->stop_btn->setEnabled(false);
}


void MainWindow::changeTimingOutput(int value){
    ui->timing_output->setText(QString::number(value) + "s");

    if(this->timer->isActive()){
        this->timer->setInterval(value);
    }
}

