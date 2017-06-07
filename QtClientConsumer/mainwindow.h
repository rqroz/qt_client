#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSlider>
#include <QListWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    bool isConnected();
    void initialSetup();
    void manageButtonsOnConnection();
    void setSliderDefaults(QSlider *);

    ~MainWindow();

public slots:
    void openConnection();
    void closeConnection();
    void updateServerList();
    void startFetchingData();
    void stopFetchingData();
    void changeTimingOutput(int);
    void currentServerChanged(QListWidgetItem*,QListWidgetItem*);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    int slider_offset;
};

#endif // MAINWINDOW_H
