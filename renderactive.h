#ifndef RENDERACTIVE_H
#define RENDERACTIVE_H

#include <QWidget>
#include <QPainterPath>

class RenderActive: public QWidget
{
    Q_OBJECT

public:
    explicit RenderActive(const QPainterPath &path, QWidget *parent = 0);

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

#endif // RENDERACTIVE_H
