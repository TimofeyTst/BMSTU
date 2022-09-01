#ifndef CLASSES_H
#define CLASSES_H

#include <QGraphicsItem>
#include <QPolygon>
#include <QtMath>

#include "qgraphicsscene.h"
#include "qbrush.h"
#include "qpen.h"

class figure
{
public:
    qreal x,y,r;
    QGraphicsScene *scene;
    QBrush my_brush;
    QPen my_pen;

    figure(qreal ix = 0, qreal iy = 0, qreal ir = 0,QGraphicsScene *iscene = nullptr,
           QBrush imy_brush = QBrush(), QPen imy_pen = QPen());
    void reset(qreal ix = 0, qreal iy = 0, qreal ir = 0);
    virtual void draw(QPen imy_pen = QPen(), QBrush imy_brush = QBrush()) = 0;
};


class Circle: public figure
{
public:
    Circle(qreal ix = 0, qreal iy = 0, qreal ir = 0, QGraphicsScene *iscene = nullptr,
           QBrush imy_brush = QBrush(), QPen imy_pen = QPen());
    void draw (QPen imy_pen = QPen(), QBrush imy_brush = QBrush()) override;
};

class Ygolnik: public figure
{
public:
    Ygolnik (qreal ix = 0, qreal iy = 0, qreal ir = 0, QGraphicsScene *iscene = nullptr,
             QBrush imy_brush = QBrush(), QPen imy_pen = QPen());
    void draw (QPen imy_pen = QPen(), QBrush imy_brush = QBrush()) override;
};

class Astroida:public figure
{
public:
    Astroida (qreal ix = 0, qreal iy = 0, qreal ir = 0, QGraphicsScene *iscene = nullptr,
              QBrush imy_brush = QBrush(), QPen imy_pen = QPen());
    void draw (QPen imy_pen = QPen(), QBrush imy_brush = QBrush()) override;
};

#endif // CLASSES_H
