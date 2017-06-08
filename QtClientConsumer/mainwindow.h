#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSlider>
#include <QListWidget>
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
    void initialSetup();
    void manageButtonsOnConnection();
    void setSliderDefaults(QSlider *);
    void displayMessageBox(QString);

    ~MainWindow();

public slots:
    void openConnection();
    void closeConnection();
    bool writeOnSocket(QString, int);
    void updateServerList();
    void fetchData(QString);
    void startFetchingData();
    void stopFetchingData();
    void changeTimingOutput(int);
    void currentServerChanged(QListWidgetItem*,QListWidgetItem*);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTimer *timer;
    int slider_offset;
};

#endif // MAINWINDOW_H
