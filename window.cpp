#include "window.h"
#include "renderarea.h"
#include "renderline.h"

#include <QWidget>
#include <cmath>
#include <QCoreApplication>
#include <QLayout>

//const float Pi = 3.14159f;  //eventueel nodig voor rondingen en cirkels

Window::Window(QWidget *parent)
    : QWidget(parent)
{


//begin drawing of areas
    QPainterPath ALU;
    ALU.addRect(75.0, 240.0, 120.0, 250.0);
   // ALU.moveTo(50.0, 470.0);
   // ALU.lineTo(180.0, 470.0);
   // ALU.lineTo(180.0, 220.0);
   // ALU.lineTo(50.0, 220.0);
   // ALU.closeSubpath();

    QPainterPath controlSection;
    controlSection.addRect(425.0, 240.0, 321.0, 250.0);

    QPainterPath RAM;
    RAM.addRect(810.0, 135.0, 135.0, 565.0);

    QPainterPath MAR;
    MAR.addRect(810.0, 40.0, 135.0, 95);

    QPainterPath reg0;
    reg0.addRect(475.0, 110.0, 50.0, 50.0);

    QPainterPath reg1;
    reg1.addRect(532.0, 110.0, 50.0, 50.0);

    QPainterPath reg2;
    reg2.addRect(589.0, 110.0, 50.0, 50.0);

    QPainterPath reg3;
    reg3.addRect(646.0, 110.0, 50.0, 50.0);

    QPainterPath TMParea;
    TMParea.addRect(140.0, 110.0, 50.0, 50.0);

    QPainterPath bus1;
    bus1.addRect(140.0, 185.0, 50.0, 30.0);

    QPainterPath ACC;
    ACC.addRect(110, 555, 50, 50);

    QPainterPath IAR;
    IAR.addRect(492, 555, 50, 50);

    QPainterPath IR;
    IR.addRect(588, 555, 50, 50);

    QPainterPath flagC;
    flagC.addRect(285, 365, 50, 30);
    QPainterPath flagA;
    flagA.addRect(285, 395, 50, 30);
    QPainterPath flagE;
    flagE.addRect(285, 425, 50, 30);
    QPainterPath flagZ;
    flagZ.addRect(285, 455, 50, 30);
    QPainterPath flagSet;
    flagSet.addRect(285, 485, 50, 60);




    QPainterPath textPath;
    QFont timesFont("Times", 12);
    timesFont.setStyleStrategy(QFont::ForceOutline);
    textPath.addText(10, 70, timesFont, tr("Shtef"));


//begin drawing of lines

    QPainterPath busLine;
    //hoofdlijn
    busLine.moveTo(810,70);
    busLine.lineTo(50, 70);
    busLine.lineTo(50,670);
    busLine.lineTo(810, 670);
    //to ALU line
    busLine.moveTo(105, 70);
    busLine.lineTo(105, 240);
    //to R0, R1, R2, R3 lines
    busLine.moveTo(500, 70);
    busLine.lineTo(500, 110);
    busLine.moveTo(557, 70);
    busLine.lineTo(557, 110);
    busLine.moveTo(614, 70);
    busLine.lineTo(614, 110);
    busLine.moveTo(671, 70);
    busLine.lineTo(671, 110);
    //from ACC line
    busLine.moveTo(135, 670);
    busLine.lineTo(135, 605);
    //from IAR line
    busLine.moveTo(517, 670);
    busLine.lineTo(517, 605);
    //from IR line
    busLine.moveTo(613, 670);
    busLine.lineTo(613, 605);
    //to TMP line
    busLine.moveTo(165, 70);
    busLine.lineTo(165, 110);

    QPainterPath TMPtoBus1;
    TMPtoBus1.moveTo(165, 160);
    TMPtoBus1.lineTo(165, 185);

    QPainterPath bus1ToALU;
    bus1ToALU.moveTo(165, 215);
    bus1ToALU.lineTo(165, 240);

    QPainterPath reg0set;
    reg0set.moveTo(485, 160);
    reg0set.lineTo(485, 240);
    QPainterPath reg0enable;
    reg0enable.moveTo(515, 160);
    reg0enable.lineTo(515, 240);

    QPainterPath reg1set;
    reg1set.moveTo(542, 160);
    reg1set.lineTo(542, 240);
    QPainterPath reg1enable;
    reg1enable.moveTo(572, 160);
    reg1enable.lineTo(572, 240);

    QPainterPath reg2set;
    reg2set.moveTo(599, 160);
    reg2set.lineTo(599, 240);
    QPainterPath reg2enable;
    reg2enable.moveTo(629, 160);
    reg2enable.lineTo(629, 240);

    QPainterPath reg3set;
    reg3set.moveTo(656, 160);
    reg3set.lineTo(656, 240);
    QPainterPath reg3enable;
    reg3enable.moveTo(686, 160);
    reg3enable.lineTo(686, 240);

    QPainterPath ALUtoACC;
    ALUtoACC.moveTo(135, 490);
    ALUtoACC.lineTo(135, 555);

    QPainterPath controlToMAR;
    controlToMAR.moveTo(726, 240);
    controlToMAR.lineTo(726, 120);
    controlToMAR.lineTo(810, 120);

    QPainterPath controlToSetRAM;
    controlToSetRAM.moveTo(726, 490);
    controlToSetRAM.lineTo(726, 555);
    controlToSetRAM.lineTo(810, 555);
    controlToSetRAM.moveTo(805, 550);
    controlToSetRAM.lineTo(810, 555);
    controlToSetRAM.lineTo(805, 560);

    QPainterPath controlToEnableRAM;
    controlToEnableRAM.moveTo(716, 490);
    controlToEnableRAM.lineTo(716, 580);
    controlToEnableRAM.lineTo(810, 580);

    QPainterPath IARset;
    IARset.moveTo(502, 490);
    IARset.lineTo(502, 555);

    QPainterPath IARenable;
    IARenable.moveTo(532, 490);
    IARenable.lineTo(532, 555);

    QPainterPath IRset;
    IRset.moveTo(648, 490);
    IRset.lineTo(648, 565);
    IRset.lineTo(638, 565);

    QPainterPath IRtoControl;
    IRtoControl.moveTo(592, 555);
    IRtoControl.lineTo(592, 490);
    IRtoControl.moveTo(598, 555);
    IRtoControl.lineTo(598, 490);
    IRtoControl.moveTo(604, 555);
    IRtoControl.lineTo(604, 490);
    IRtoControl.moveTo(610, 555);
    IRtoControl.lineTo(610, 490);
    IRtoControl.moveTo(616, 555);
    IRtoControl.lineTo(616, 490);
    IRtoControl.moveTo(622, 555);
    IRtoControl.lineTo(622, 490);
    IRtoControl.moveTo(628, 555);
    IRtoControl.lineTo(628, 490);
    IRtoControl.moveTo(634, 555);
    IRtoControl.lineTo(634, 490);

    QPainterPath TMPset;
    TMPset.moveTo(455, 240);
    TMPset.lineTo(455, 125);
    TMPset.lineTo(190, 125);

    QPainterPath controlToBus1;
    controlToBus1.moveTo(445, 240);
    controlToBus1.lineTo(445, 200);
    controlToBus1.lineTo(190, 200);

    QPainterPath opLines;
    opLines.moveTo(195, 280);
    opLines.lineTo(425, 280);
    opLines.moveTo(195, 290);
    opLines.lineTo(425, 290);
    opLines.moveTo(195, 300);
    opLines.lineTo(425, 300);

    QPainterPath carryOut;
    carryOut.moveTo(195, 380);
    carryOut.lineTo(285, 380);
    QPainterPath aLarger;
    aLarger.moveTo(195, 410);
    aLarger.lineTo(285, 410);
    QPainterPath equalLine;
    equalLine.moveTo(195, 440);
    equalLine.lineTo(285, 440);
    QPainterPath zeroLine;
    zeroLine.moveTo(195, 470);
    zeroLine.lineTo(285, 470);

    QPainterPath carryIn;
    carryIn.moveTo(335, 380);
    carryIn.lineTo(425, 380);
    carryIn.moveTo(380, 380);
    carryIn.lineTo(380, 330);
    carryIn.lineTo(195, 330);
    QPainterPath aLargertoControl;
    aLargertoControl.moveTo(335, 410);
    aLargertoControl.lineTo(425, 410);
    QPainterPath equalToControl;
    equalToControl.moveTo(335, 440);
    equalToControl.lineTo(425, 440);
    QPainterPath zeroToControl;
    zeroToControl.moveTo(335, 470);
    zeroToControl.lineTo(425, 470);

    QPainterPath controlToFlagSet;
    controlToFlagSet.moveTo(445, 490);
    controlToFlagSet.lineTo(445, 530);
    controlToFlagSet.lineTo(335, 530);

    QPainterPath ACCset;
    ACCset.moveTo(455, 490);
    ACCset.lineTo(455, 565);
    ACCset.lineTo(160, 565);
    QPainterPath ACCenable;
    ACCenable.moveTo(465, 490);
    ACCenable.lineTo(465, 595);
    ACCenable.lineTo(160, 595);


    renderAreas.push_back(new RenderArea(ALU));
    //renderAreas.push_back(new RenderArea(textPath));
    renderAreas.push_back(new RenderArea(controlSection));
    renderAreas.push_back(new RenderArea(RAM));
    renderAreas.push_back(new RenderArea(MAR));
    renderAreas.push_back(new RenderArea(reg0));
    renderAreas.push_back(new RenderArea(reg1));
    renderAreas.push_back(new RenderArea(reg2));
    renderAreas.push_back(new RenderArea(reg3));
    renderAreas.push_back(new RenderArea(TMParea));
    renderAreas.push_back(new RenderArea(bus1));
    renderAreas.push_back(new RenderArea(ACC));
    renderAreas.push_back(new RenderArea(IAR));
    renderAreas.push_back(new RenderArea(IR));
    renderAreas.push_back(new RenderArea(flagC));
    renderAreas.push_back(new RenderArea(flagA));
    renderAreas.push_back(new RenderArea(flagE));
    renderAreas.push_back(new RenderArea(flagZ));
    renderAreas.push_back(new RenderArea(flagSet));
    //lijntjes
    renderLines.push_back(new RenderLine(busLine));
    renderLines.push_back(new RenderLine(TMPtoBus1));
    renderLines.push_back(new RenderLine(bus1ToALU));
    renderLines.push_back(new RenderLine(reg0set));
    renderLines.push_back(new RenderLine(reg0enable));
    renderLines.push_back(new RenderLine(reg1set));
    renderLines.push_back(new RenderLine(reg1enable));
    renderLines.push_back(new RenderLine(reg2set));
    renderLines.push_back(new RenderLine(reg2enable));
    renderLines.push_back(new RenderLine(reg3set));
    renderLines.push_back(new RenderLine(reg3enable));
    renderLines.push_back(new RenderLine(ALUtoACC));
    renderLines.push_back(new RenderLine(controlToMAR));
    renderLines.push_back(new RenderLine(controlToSetRAM));
    renderLines.push_back(new RenderLine(controlToEnableRAM));
    renderLines.push_back(new RenderLine(IARset));
    renderLines.push_back(new RenderLine(IARenable));
    renderLines.push_back(new RenderLine(IRset));
    renderLines.push_back(new RenderLine(IRtoControl));
    renderLines.push_back(new RenderLine(TMPset));
    renderLines.push_back(new RenderLine(controlToBus1));
    renderLines.push_back(new RenderLine(opLines));
    renderLines.push_back(new RenderLine(carryOut));
    renderLines.push_back(new RenderLine(aLarger));
    renderLines.push_back(new RenderLine(equalLine));
    renderLines.push_back(new RenderLine(zeroLine));
    renderLines.push_back(new RenderLine(carryIn));
    renderLines.push_back(new RenderLine(aLargertoControl));
    renderLines.push_back(new RenderLine(equalToControl));
    renderLines.push_back(new RenderLine(zeroToControl));
    renderLines.push_back(new RenderLine(controlToFlagSet));
    renderLines.push_back(new RenderLine(ACCset));
    renderLines.push_back(new RenderLine(ACCenable));



    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);

    penWidthLabel = new QLabel(tr("&Pen Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penColorComboBox = new QComboBox;
    populateWithColors(penColorComboBox);
    penColorComboBox->setCurrentIndex(penColorComboBox->findText("black"));

    penColorLabel = new QLabel(tr("Pen &Color:"));
    penColorLabel->setBuddy(penColorComboBox);

    connect(penColorComboBox, SIGNAL(activated(int)), this, SLOT(penColorChanged()));


    for(QList<RenderArea*>::iterator it = renderAreas.begin(); it != renderAreas.end(); it++)
    {
        connect(penWidthSpinBox, SIGNAL(valueChanged(int)), *it, SLOT(setPenWidth(int)));
    }

    for(QList<RenderLine*>::iterator it = renderLines.begin(); it != renderLines.end(); it++)
    {
        connect(penWidthSpinBox, SIGNAL(valueChanged(int)), *it, SLOT(setPenWidth(int)));
    }


    QGridLayout *topLayout = new QGridLayout;

    int i = 0;
    for(QList<RenderArea*>::iterator it = renderAreas.begin(); it != renderAreas.end(); it++, i++)
    {
        topLayout->addWidget(*it, 0, 1);
    }
    for(QList<RenderLine*>::iterator it = renderLines.begin(); it != renderLines.end(); it++, i++)
    {
        topLayout->addWidget(*it, 0, 1);
    }

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(topLayout, 0, 0, 1, 4);
    mainLayout->addWidget(penWidthLabel, 1, 0);
    mainLayout->addWidget(penWidthSpinBox, 1, 1, 1, 3);
    mainLayout->addWidget(penColorLabel, 2, 0);
    mainLayout->addWidget(penColorComboBox, 2, 1, 1, 3);
    //topLayout->setGeometry(QRect(QPoint(10, 10), QSize(40.0, 40.0)));
    setLayout(mainLayout);

    penWidthSpinBox->setValue(2);

    label = new QLabel("de ALU natuurlijk", this);
    label->setGeometry(QRect(QPoint(70, 200), QSize(500, 20)));

    setWindowTitle(tr("Scotty Processor"));

}

void Window::penColorChanged()
{
    QColor color = qvariant_cast<QColor>(currentItemData(penColorComboBox));

    for(QList<RenderArea*>::iterator it = renderAreas.begin(); it != renderAreas.end(); ++it)
    {
        (*it)->setPenColor(color);
    }
    for(QList<RenderLine*>::iterator it = renderLines.begin(); it != renderLines.end(); ++it)
    {
        (*it)->setPenColor(color);
    }
}

void Window::populateWithColors(QComboBox *comboBox)
{
    QStringList colorNames = QColor::colorNames();
    foreach (QString name, colorNames) {
        comboBox->addItem(name, QColor(name));
    }
}

QVariant Window::currentItemData(QComboBox *comboBox)
{
    return comboBox->itemData(comboBox->currentIndex());
}

Window::~Window()
{

}
