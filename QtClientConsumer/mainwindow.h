#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openConnection();
    void closeConnection();
    void updateServerList();
    void startFetchingData();
    void stopFetchingData();
    void changeTimingOutput(int);

private:
    Ui::MainWindow *ui;
    int slider_offset;
};

#endif // MAINWINDOW_H
