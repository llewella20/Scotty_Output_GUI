#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(const QPainterPath &path, QWidget *parent)
    : QWidget(parent), path(path)
{
    penWidth = 1;
    setBackgroundRole(QPalette::Base);
}


//voor grootte window (me thinks)
QSize RenderArea::minimumSizeHint() const
{
    return QSize(510, 360);
}

QSize RenderArea::sizeHint() const
{
    return QSize(1020, 720);
}


//variabelen die je kan aanpassen in app-window
void RenderArea::setPenWidth(int width)
{
    penWidth = width;
    update();
}

void RenderArea::setPenColor(const QColor &color)
{
    penColor = color;
    update();
}


//actual painting
void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //resizing and scaling of window
    painter.scale(width() / 1020.0, height() / 720.0);
    painter.translate(510.0, 360.0);
    //painter.rotate(-rotationAngle);      //deze is niet nodig
    painter.translate(-510.0, -360.0);     //daarom deze ook niet?

    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(QBrush(QColor(192, 192, 192))); //set color of shape
    painter.drawPath(path);


}
