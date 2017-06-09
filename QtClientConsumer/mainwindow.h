#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSlider>
#include <QListWidget>
#include <QTimer>
#include <QStringList>

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
    void displayMessageBox(QString);

    ~MainWindow();

public slots:
    void displayData();
    void openConnection();
    void closeConnection();
    bool writeOnSocket(QString, int);
    void updateServerList();
    void startFetchingData();
    void stopFetchingData();
    void changeTimingOutput(int);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTimer *timer;
    int slider_offset;
    QStringList data;
};


#endif // MAINWINDOW_H
