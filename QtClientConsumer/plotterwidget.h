#ifndef PLOTTERWIDGET_H
#define PLOTTERWIDGET_H

#include <QWidget>
#include <QColor>
#include <QStringList>

class PlotterWidget : public QWidget
{
    Q_OBJECT
private:
    QColor penColor;
    QColor brushColor;
    QStringList data;
protected:
    void paintEvent(QPaintEvent *event);

public:
    explicit PlotterWidget(QWidget *parent = 0);
    void setPenColor(int r, int g, int b);
    void setBrushColor(int r, int g, int b);
    void setData(QStringList);
    QStringList getData();
};

#endif // PLOTTERWIDGET_H
