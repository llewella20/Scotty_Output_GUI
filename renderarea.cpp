#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(const QPainterPath &path, QWidget *parent)
    : QWidget(parent), path(path)
{
    //penWidth = 1;
    setBackgroundRole(QPalette::Base);
}

//voor grootte window
QSize RenderArea::minimumSizeHint() const
{
    return QSize(510, 360);
}

QSize RenderArea::sizeHint() const
{
    return QSize(1020, 720);
}

//
// eventuele in-app variabelen komen hier (zie renderactive.cpp )
//

//actual painting
void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.scale(width() / 1020.0, height() / 720.0);
    painter.translate(510.0, 360.0);
    painter.translate(-510.0, -360.0);

    painter.setPen(QPen(QColor(0,0,0), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(QBrush(QColor(192, 192, 192))); //set color of shape
    painter.drawPath(path);


}
