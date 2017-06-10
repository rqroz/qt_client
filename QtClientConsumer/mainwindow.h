#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QListWidget>
#include <QTimer>

/**
 * @date June 9th, 2017
 * @brief Main UI used to fetch data from a server
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

    bool isConnected(); /**< Returns whether the socket is connected or not */

    /**
     * @brief initialSetup
     * @details Initializes pointers and set defaults for QWidgets used
     */
    void initialSetup();

    /**
     * @brief manageButtonsOnConnection
     * @details Define buttons state according to the socket connectivity state
     * @see isConnected()
     */
    void manageButtonsOnConnection();

    /**
     * @brief displayMessageBox
     * @details Displays a message to the user using QMessageBox
     */
    void displayMessageBox(QString);

    ~MainWindow(); /**< Class destructor. Deletes all pointers */

public slots:
    /**
     * @brief openConnection
     * @details Connects to a server using the combinations of serverdomain:port defined by the user
     * on server_input and port_input widgets. When connected, it updates the servers list on server_lview
     * widget.
     * @see updateServerList()
     */
    void openConnection();

    /**
     * @brief closeConnection
     * @details Closes a connection once opened with openConnection()
     * @see openConnection()
     */
    void closeConnection();

    /**
     * @brief writeOnSocket
     * @details Uses the QString received to write data on socket and then wait x seconds for further procedures
     * @return QAbstractSocket::waitForReadyRead(int msecs = 30000)
     */
    bool writeOnSocket(QString, int);

    /**
     * @brief updateServerList
     * @details Uses the bytes on socket to create the rows on server_lview with server urls
     */
    void updateServerList();

    /**
     * @brief fetchData
     * @details Uses the string held by currentGet to define the server from which the data
     * will be fetched, perform desired requests to the connected server in order to get the inputs sent
     * by currentGet and plot the graph on plotter.
     */
    void fetchData();

    /**
     * @brief startFetchingData
     * @details Sets the value for currentGet according to the selected row on server_lview and starts
     * the timer (which is connected with fetchData())
     * @see MainWindow(QWidget *parent = 0)
     * @see fetchData()
     */
    void startFetchingData();

    /**
     * @brief stopFetchingData
     * @details Stop the timer and, therefore, the plotting.
     */
    void stopFetchingData();

    /**
     * @brief changeTimingOutput
     * @details Changes the output of the timing slider (1s, 10s, ...) and the timeInterval for timer,
     * if timer is active.
     */
    void changeTimingOutput(int);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket; /**< Performs TCP/IP connections */
    QTimer *timer; /**< QTimer to fetch data from time to time */
    QString currentGet; /**< Holds the current server ulr to get the data on the connected server */
};


#endif // MAINWINDOW_H
