#include "plotterwidget.h"
#include <QPainter>
#include <QDateTime>
#include <QDebug>
#include <QColor>

PlotterWidget::PlotterWidget(QWidget *parent) : QWidget(parent){}

void PlotterWidget::setData(QStringList data){
    this->data = data;
    repaint();
}


void PlotterWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setColor(QColor(218, 227, 242));
    brush.setStyle(Qt::SolidPattern);

    QPen pen;
    pen.setColor(QColor(86, 93, 94));
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(0,0, this->width(), this->height());
    painter.drawLine(0, height(), width(), height());

    if(!this->data.empty()){
        QStringList tmp;
        QDateTime dt;
        int heightDivider = 2;
        qint64 previous_x = 0, previous_y = height()/heightDivider, current_x, current_y;

        for (QStringList::iterator it = this->data.begin(); it != this->data.end(); ++it) {
            QString current = *it;
            tmp = current.split(" ");
            if(tmp.size() == 2){
                dt = QDateTime::fromString(tmp.at(0), Qt::ISODate);
                current_x = dt.toTime_t() % width();

                if(current_x <= previous_x){
                    previous_x = 0;
                    if(heightDivider == 2){
                        previous_y *= 2;
                        heightDivider = 1;
                    }else{
                        previous_y /= 2;
                        heightDivider = 2;
                        painter.drawRect(0, 0, width(), height());
                    }
                }

                current_y = height()/heightDivider - tmp.at(1).toFloat();

                painter.drawLine(previous_x, previous_y, current_x, current_y);
                previous_x = current_x;
                previous_y = current_y;
            }
        }
    }
}

