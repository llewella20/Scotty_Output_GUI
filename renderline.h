#ifndef RENDERLINE_H
#define RENDERLINE_H

#include <QPainterPath>
#include <QWidget>

//zowel deze als renderarea kunnen met overerving werken van een baseclass
//maar ik probeer het even zo


class RenderLine: public QWidget
{
    Q_OBJECT

public:
    explicit RenderLine(const QPainterPath &path, QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    void setPenWidth(int width);
    void setPenColor(const QColor &color);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QPainterPath path;
    int penWidth;
    QColor penColor;

};

#endif // RENDERLINE_H
