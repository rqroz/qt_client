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
        qint64 previous_x = 0, previous_y = height(), current_x, current_y, normalizedX;
        int i = 0, j = 10;
        for (QStringList::iterator it = this->data.begin(); it != this->data.end(); ++it) {
            QString current = *it;
            tmp = current.split(" ");
            if(tmp.size() == 2){
                dt = QDateTime::fromString(tmp.at(0), Qt::ISODate);

                current_x = dt.currentMSecsSinceEpoch();
                current_y = height() - tmp.at(1).toFloat();
                if(it == this->data.begin()){
                    normalizedX = current_x;
                }
                qDebug() << "dt: " << dt.toString("dd.MM.yyyy hh:mm:ss") << " - " << dt.currentMSecsSinceEpoch();
                qDebug() << "p_x: " << (float) previous_x/normalizedX  << " | p_y: " << previous_y;
                qDebug() << "c_x: " << (float) current_x/normalizedX  << " | c_y: " << current_y;
                qDebug() << "a_x: " << current_x << " | n_x: " << normalizedX << "\n";

                painter.drawLine(i, previous_y, j, current_y);
                previous_x = current_x;
                previous_y = current_y;

                i = j;
                j = j + 10;
            }
        }
    }
}

