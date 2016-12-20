#include "renderactive.h"

#include <QPainter>

RenderActive::RenderActive(const QPainterPath &path, QWidget *parent)
    : QWidget(parent), path(path)
{
    penWidth = 1;
    penColor = QColor(255, 0, 0);
    setBackgroundRole(QPalette::Base);
}

//voor grootte window
QSize RenderActive::minimumSizeHint() const
{
    return QSize(510, 360);
}

QSize RenderActive::sizeHint() const
{
    return QSize(1020, 720);
}

//in-app variabelen aanpassen
void RenderActive::setPenWidth(int width)
{
    penWidth = width;
    update();
}

void RenderActive::setPenColor(const QColor &color)
{
    penColor = color;
    update();
}


//actual painting
void RenderActive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //resizing and scaling of window
    painter.scale(width() / 1020.0, height() / 720.0);
    painter.translate(510.0, 360.0);
    //painter.rotate(-rotationAngle);       //deze is niet nodig
    painter.translate(-510.0, -360.0);      //daarom deze ook niet?

    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(Qt::NoBrush);
    painter.drawPath(path);

}
