#include "renderline.h"

#include <QPainter>

RenderLine::RenderLine(const QPainterPath &path, QWidget *parent)
    :QWidget(parent), path(path)
{
    //penWidth = 1;
    setBackgroundRole(QPalette::Base);
}


QSize RenderLine::minimumSizeHint() const
{
    return QSize(510, 360);
}

QSize RenderLine::sizeHint() const
{
    return QSize(1020, 720);
}

//
// eventuele in-app variabelen komen hier (zie renderactive.cpp )
//

//actual painting
void RenderLine::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.scale(width() / 1020.0, height() / 720.0);
    painter.translate(510.0, 360.0);
    painter.translate(-510.0, -360.0);

    painter.setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawPath(path);

}
