#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QPainterPath>
#include <QWidget>


class RenderArea: public QWidget
{
    Q_OBJECT

public:
    explicit RenderArea(const QPainterPath &path, QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    //void setFillColor(const QColor &colorF);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QPainterPath path;
    int penWidth;
    QColor penColor;
};

#endif // RENDERAREA_H
