#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTcpSocket>
#include <QSlider>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    bool isConnected();
    void styleLCD(QLCDNumber *);
    void initialSetup();
    void manageButtonsOnConnection();
    void setSliderDefaults(QSlider *);

    ~MainWindow();

public slots:
    void openConnection();
    void closeConnection();
    void sendData();
    void startSendingData();
    void stopSendingData();
    void changeMinLCD(int);
    void changeMaxLCD(int);
    void changeTimingOutput(int);


private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTimer *timer;
    int slider_offset;
};

#endif // MAINWINDOW_H
