#ifndef RENDERTEXT_H
#define RENDERTEXT_H

#include <QPainterPath>
#include <QWidget>

class RenderText: public QWidget
{
    Q_OBJECT

public:
    explicit RenderText(const QPainterPath &path, QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    // enkel nodig bij in-app aanpassingen (zie renderactive.h )

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QPainterPath path;

};

#endif // RENDERTEXT_H
