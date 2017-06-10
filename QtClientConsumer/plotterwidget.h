#ifndef PLOTTERWIDGET_H
#define PLOTTERWIDGET_H

#include <QWidget>
#include <QStringList>

/**
 * @date June 9th, 2017
 * @brief Custom QWidget created in order to display graphs using a list of data
 */

class PlotterWidget : public QWidget
{
    Q_OBJECT
private:
    QStringList data; /**< Holds a list of strings with data for the x and y axis */
protected:
    /**
     * @brief paintEvent
     * @param event
     * @details Overwrites default paintEvent for QWidget in order to display the desired graph
     * using data private var.
     */
    void paintEvent(QPaintEvent *event);

public:
    explicit PlotterWidget(QWidget *parent = 0); /**< Default Constructor */

    /**
     * @brief setData
     * @param stringList QStringList with strings on "datetimestr value" pattern
     * datetimestr must be according to Qt::ISODate format and value must be an integer value.
     * After allocating new value, repaints the widget.
     * @see paintEvent()
     */
    void setData(QStringList);
};

#endif // PLOTTERWIDGET_H
