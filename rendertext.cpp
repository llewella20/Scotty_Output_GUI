#include "rendertext.h"

#include <QPainter>

RenderText::RenderText(const QPainterPath &path, QWidget *parent)
    :QWidget(parent), path(path)
{
    setBackgroundRole(QPalette::Base);
}

//voor grootte window
QSize RenderText::minimumSizeHint() const
{
    return QSize(510, 360);
}

QSize RenderText::sizeHint() const
{
    return QSize(1020, 720);
}

//
// eventuele in-app variabelen komen hier (zie renderactive.cpp )
//

//actual painting
void RenderText::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.scale(width() / 1020.0, height() / 720.0);
    painter.translate(510.0, 360.0);
    painter.translate(-510.0, -360.0);

    painter.setPen(QPen(QColor(0,0,0), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(QBrush(QColor(0, 0, 0))); //set color of shape
    painter.drawPath(path);

}
