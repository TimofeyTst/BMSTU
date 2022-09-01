#include "classes.h"



figure::figure(qreal ix, qreal iy, qreal ir,QGraphicsScene *iscene, QBrush imy_brush, QPen imy_pen):
    x(ix), y(iy), r(ir), scene(iscene), my_brush(imy_brush),my_pen(imy_pen)
{

}

void figure::reset(qreal ix, qreal iy, qreal ir)
{
    x= ix;
    y = iy;
    r = ir;
}

Circle::Circle(qreal ix, qreal iy, qreal ir,QGraphicsScene *iscene, QBrush imy_brush, QPen imy_pen):figure(ix,iy,ir,iscene, imy_brush, imy_pen)
{

}

void Circle::draw(QPen imy_pen, QBrush imy_brush)
{
    my_pen = imy_pen;
    my_brush = imy_brush;
    this->scene->addEllipse(x, y, 2*r, 2*r, my_pen, my_brush);
}

Ygolnik::Ygolnik(qreal ix, qreal iy, qreal ir, QGraphicsScene *iscene, QBrush imy_brush, QPen imy_pen):figure(ix,iy,ir,iscene, imy_brush, imy_pen)
{

}

void Ygolnik::draw(QPen imy_pen, QBrush imy_brush)
{
    my_pen = imy_pen;
    my_brush = imy_brush;
    QPolygon polygon;

    polygon << QPoint(x+r,y) << QPoint (x+r/2, y - r * sqrt(3)/2) << QPoint (x - r/2, y - r * sqrt(3)/2)
            << QPoint(x - r, y) << QPoint (x - r/2, y + r * sqrt(3)/2) << QPoint (x+r/2, y + r * sqrt(3)/2);
    this->scene->addPolygon(polygon, my_pen, my_brush);
}

Astroida::Astroida(qreal ix, qreal iy, qreal ir, QGraphicsScene *iscene, QBrush imy_brush, QPen imy_pen):figure(ix,iy,ir,iscene, imy_brush, imy_pen)
{

}

void Astroida::draw(QPen imy_pen, QBrush imy_brush)
{
    my_pen = imy_pen;
    my_brush = imy_brush;
    QPolygon polygon;

    for (int i = 0; i < 361; ++i)
    {
        polygon << QPoint (x + r * pow(sin(qDegreesToRadians(i)),3), y + r * pow(cos(qDegreesToRadians(i)),3));
    }

    this->scene->addPolygon(polygon, my_pen, my_brush);

}
