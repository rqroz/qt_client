#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QColor>

class Plotter : public QWidget
{
  Q_OBJECT
private:
  QColor fundo;

public:
  explicit Plotter(QWidget *parent = 0);
  void paintEvent(QPaintEvent *e);
  void setFundo(int r, int g, int b);

signals:
  void posicao(int, int);

public slots:

};

#endif // PLOTTER_H
