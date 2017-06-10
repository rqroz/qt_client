#include "plotterwidget.h"
#include <QPainter>
#include <QDateTime>
#include <QDebug>

PlotterWidget::PlotterWidget(QWidget *parent) : QWidget(parent){
    this->setPenColor(86, 93, 94);
    this->setBrushColor(218, 227, 242);
}


void PlotterWidget::setData(QStringList data){
    this->data = data;
}

QStringList PlotterWidget::getData(){
    return this->data;
}

void PlotterWidget::setPenColor(int r, int g, int b){
    this->penColor.setRgb(r,g,b);
    repaint();
}

void PlotterWidget::setBrushColor(int r, int g, int b){
    this->brushColor.setRgb(r,g,b);
    repaint();
}


void PlotterWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setColor(this->brushColor);
    brush.setStyle(Qt::SolidPattern);

    QPen pen;
    pen.setColor(this->penColor);
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

        qDebug() << "width: " << width();
        for (QStringList::iterator it = this->data.begin(); it != this->data.end(); ++it) {
            QString current = *it;
            tmp = current.split(" ");
            if(tmp.size() == 2){
                dt = QDateTime::fromString(tmp.at(0), Qt::ISODate);
                int timestamp = dt.toTime_t();

                current_x = timestamp % width();
                if(current_x <= previous_x){
                    qDebug() << "on reset hd: " << heightDivider;
                    qDebug() << "on reset p: (" << previous_x << ", " << previous_y << ")";
                    qDebug() << "on reset c: (" << current_x << ", " << height()/heightDivider - tmp.at(1).toFloat() << ")\n";
                    previous_x = 0;
                    if(heightDivider == 2){
                        previous_y *= 2;
                        heightDivider = 1;
                    }else{
                        previous_y /= 2;
                        heightDivider = 2;
                        painter.drawRect(0, 0, width(), height());
                    }
                    qDebug() << "after proc hd: " << heightDivider;
                    qDebug() << "after proc p: (" << previous_x << ", " << previous_y << ")";
                    qDebug() << "after proc c: (" << current_x << ", " << height()/heightDivider - tmp.at(1).toFloat() << ")\n";

                }

                current_y = height()/heightDivider - tmp.at(1).toFloat();

                qDebug() << "dt: " << dt.toString("dd.MM.yyyy hh:mm:ss") << " - " << dt.toTime_t();
                qDebug() << "p_x: " << (float) previous_x  << " | p_y: " << previous_y;
                qDebug() << "c_x: " << (float) current_x  << " | c_y: " << current_y << "\n";

                painter.drawLine(previous_x, previous_y, current_x, current_y);
                previous_x = current_x;
                previous_y = current_y;
            }
        }
    }
}

