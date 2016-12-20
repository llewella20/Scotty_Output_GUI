#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QGridLayout>

class RenderArea;
class RenderLine;
class RenderActive;
class RenderText;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

private slots:
    void penColorChanged();

private:
    void populateWithColors(QComboBox *comboBox);
    QVariant currentItemData(QComboBox *comboBox);

    QList<RenderArea*> renderAreas;
    QList<RenderLine*> renderLines;
    QList<RenderActive*> renderActive;
    QList<RenderText*> renderText;
    QLabel *penWidthLabel;
    QLabel *penColorLabel;
    QSpinBox *penWidthSpinBox;
    QComboBox *penColorComboBox;
    QLabel *label;

};

#endif // WINDOW_H
