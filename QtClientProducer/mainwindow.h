#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>

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
    void startSendingData();
    void stopSendingData();
    void changeMinLCD(int);
    void changeMaxLCD(int);
    void changeTimingOutput(int);

private:
    Ui::MainWindow *ui;
    int slider_offset;
    void styleLCD(QLCDNumber *);
    void initialSetup();
};

#endif // MAINWINDOW_H
