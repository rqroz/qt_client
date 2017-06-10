#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTcpSocket>
#include <QSlider>
#include <QTimer>

/**
 * @date June 9th, 2017
 * @brief Main UI used to send data to a server
 * @details MainWindow holds all of the QWidgets and actions enabled via user-interaction (signals)
 */

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Excplicit Constructor
    /*! Defines connections between QWidgets and its singals */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief initialSetup
     * @details Initializes pointers and set defaults for QWidgets used
     */
    void initialSetup();

    bool isConnected(); /**< Returns whether the socket is connected or not */

    /**
     * @brief styleLCD
     * @details styles the QLCDNumber received in a fixed pattern.
     * @see initialSetup()
     */
    void styleLCD(QLCDNumber *);

    /**
     * @brief manageButtonsOnConnection
     * @details Define buttons state according to the socket connectivity state
     * @see isConnected()
     */
    void manageButtonsOnConnection();

    /**
     * @brief setSliderDefaults
     * @details set the default minimum and maximum for a received slider (1 and 100, respectively)
     */
    void setSliderDefaults(QSlider *);

    ~MainWindow(); /**< Class destructor. Deletes all pointers */

public slots:
    /**
     * @brief openConnection
     * @details Connects to a server using the combinations of serverdomain:port defined by the user
     * on server_input and port_input widgets.
     */
    void openConnection();

    /**
     * @brief closeConnection
     * @details Closes a connection once opened with openConnection()
     * @see openConnection()
     */
    void closeConnection();

    /**
     * @brief sendData
     * @details Writes on socket and updates the list of commands sent on server_lview
     */
    void sendData();

    /**
     * @brief startSendingData
     * @details Starts timer and handles the state of start_btn and stop_btn
     */
    void startSendingData();

    /**
     * @brief stopSendingData
     * @details Stop the timer and, therefore, the writting on socket.
     */
    void stopSendingData();

    /**
     * @brief changeMinLCD
     * @details Sets the value for minlcd_display to display
     */
    void changeMinLCD(int);

    /**
     * @brief changeMaxLCD
     * @details Sets the value for maxlcd_display to display
     */
    void changeMaxLCD(int);

    /**
     * @brief changeTimingOutput
     * @details Changes the text of timing_output and the timeInterval of timer, if timer is active
     */
    void changeTimingOutput(int);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket; /**< Performs TCP/IP connections */
    QTimer *timer; /**< QTimer to send data from time to time */
};

#endif // MAINWINDOW_H
