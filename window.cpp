#include "window.h"
#include "renderarea.h"
#include "renderline.h"
#include "renderactive.h"
#include "rendertext.h"

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
    //ALU.addRoundedRect(QRectF(200, 240, 120, 250), 10, 10);

    // voor enkel bovenste hoeken rounded:
    // http://stackoverflow.com/questions/15288708/drawing-rectangle-with-only-2-corners-rounded-in-qt
    // extra: http://stackoverflow.com/questions/29196610/qt-drawing-a-filled-rounded-rectangle-with-border

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

//begin text

    QFont timesFont("Segoe UI", 15);
    timesFont.setStyleStrategy(QFont::ForceOutline);

    QPainterPath txtALU;
    txtALU.addText(115, 360, timesFont, tr("ALU"));

    QPainterPath txtControl;
    txtControl.addText(520, 360, timesFont, tr("Control Section"));

    QPainterPath txtRAM;
    txtRAM.addText(855, 360, timesFont, tr("RAM"));

    QPainterPath txtMAR;
    txtMAR.addText(855, 95, timesFont, tr("MAR"));

    QPainterPath txtReg0;
    txtReg0.addText(487, 135, timesFont, tr("R0"));
    QPainterPath txtReg1;
    txtReg1.addText(544, 135, timesFont, tr("R1"));
    QPainterPath txtReg2;
    txtReg2.addText(601, 135, timesFont, tr("R2"));
    QPainterPath txtReg3;
    txtReg3.addText(658, 135, timesFont, tr("R3"));

    QPainterPath txtTMP;
    txtTMP.addText(147, 152, timesFont, tr("TMP"));

    QPainterPath txtBus1;
    txtBus1.addText(142, 207, timesFont, tr("bus 1"));



    QPainterPath textPath;
    //QFont timesFont("Times", 12);
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
    reg0set.moveTo(480, 165);
    reg0set.lineTo(485, 160);
    reg0set.lineTo(490, 165);
    QPainterPath reg0enable;
    reg0enable.moveTo(515, 160);
    reg0enable.lineTo(515, 240);
    reg0enable.moveTo(510, 165);
    reg0enable.lineTo(515, 160);
    reg0enable.lineTo(520, 165);

    QPainterPath reg1set;
    reg1set.moveTo(542, 160);
    reg1set.lineTo(542, 240);
    reg1set.moveTo(537, 165);
    reg1set.lineTo(542, 160);
    reg1set.lineTo(547, 165);
    QPainterPath reg1enable;
    reg1enable.moveTo(572, 160);
    reg1enable.lineTo(572, 240);
    reg1enable.moveTo(567, 165);
    reg1enable.lineTo(572, 160);
    reg1enable.lineTo(577, 165);

    QPainterPath reg2set;
    reg2set.moveTo(599, 160);
    reg2set.lineTo(599, 240);
    reg2set.moveTo(594, 165);
    reg2set.lineTo(599, 160);
    reg2set.lineTo(604, 165);
    QPainterPath reg2enable;
    reg2enable.moveTo(629, 160);
    reg2enable.lineTo(629, 240);
    reg2enable.moveTo(624, 165);
    reg2enable.lineTo(629, 160);
    reg2enable.lineTo(634, 165);

    QPainterPath reg3set;
    reg3set.moveTo(656, 160);
    reg3set.lineTo(656, 240);
    reg3set.moveTo(651, 165);
    reg3set.moveTo(651, 165);
    reg3set.lineTo(656, 160);
    reg3set.lineTo(661, 165);
    QPainterPath reg3enable;
    reg3enable.moveTo(686, 160);
    reg3enable.lineTo(686, 240);
    reg3enable.moveTo(681, 165);
    reg3enable.lineTo(686, 160);
    reg3enable.lineTo(691, 165);

    QPainterPath ALUtoACC;
    ALUtoACC.moveTo(135, 490);
    ALUtoACC.lineTo(135, 555);
    ALUtoACC.moveTo(130, 550);
    ALUtoACC.lineTo(135, 555);
    ALUtoACC.lineTo(140, 550);

    QPainterPath controlToMAR;
    controlToMAR.moveTo(726, 240);
    controlToMAR.lineTo(726, 120);
    controlToMAR.lineTo(810, 120);
    controlToMAR.moveTo(805, 115);
    controlToMAR.lineTo(810, 120);
    controlToMAR.lineTo(805, 125);

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
    controlToEnableRAM.moveTo(805, 575);
    controlToEnableRAM.lineTo(810, 580);
    controlToEnableRAM.lineTo(805, 585);

    QPainterPath IARset;
    IARset.moveTo(502, 490);
    IARset.lineTo(502, 555);
    IARset.moveTo(497, 550);
    IARset.lineTo(502, 555);
    IARset.lineTo(507, 550);

    QPainterPath IARenable;
    IARenable.moveTo(532, 490);
    IARenable.lineTo(532, 555);
    IARenable.moveTo(527, 550);
    IARenable.lineTo(532, 555);
    IARenable.lineTo(537, 550);

    QPainterPath IRset;
    IRset.moveTo(648, 490);
    IRset.lineTo(648, 565);
    IRset.lineTo(638, 565);
    IRset.moveTo(643, 560);
    IRset.lineTo(638, 565);
    IRset.lineTo(643, 570);

    QPainterPath IRtoControl;
    IRtoControl.moveTo(592, 555);
    IRtoControl.lineTo(592, 490);
    IRtoControl.moveTo(590, 495);
    IRtoControl.lineTo(592, 490);
    IRtoControl.lineTo(594, 495);

    IRtoControl.moveTo(598, 555);
    IRtoControl.lineTo(598, 490);
    IRtoControl.moveTo(596, 495);
    IRtoControl.lineTo(598, 490);
    IRtoControl.lineTo(600, 495);

    IRtoControl.moveTo(604, 555);
    IRtoControl.lineTo(604, 490);
    IRtoControl.moveTo(602, 495);
    IRtoControl.lineTo(604, 490);
    IRtoControl.lineTo(606, 495);

    IRtoControl.moveTo(610, 555);
    IRtoControl.lineTo(610, 490);
    IRtoControl.moveTo(608, 495);
    IRtoControl.lineTo(610, 490);
    IRtoControl.lineTo(612, 495);

    IRtoControl.moveTo(616, 555);
    IRtoControl.lineTo(616, 490);
    IRtoControl.moveTo(614, 495);
    IRtoControl.lineTo(616, 490);
    IRtoControl.lineTo(618, 495);

    IRtoControl.moveTo(622, 555);
    IRtoControl.lineTo(622, 490);
    IRtoControl.moveTo(620, 495);
    IRtoControl.lineTo(622, 490);
    IRtoControl.lineTo(624, 495);

    IRtoControl.moveTo(628, 555);
    IRtoControl.lineTo(628, 490);
    IRtoControl.moveTo(626, 495);
    IRtoControl.lineTo(628, 490);
    IRtoControl.lineTo(630, 495);

    IRtoControl.moveTo(634, 555);
    IRtoControl.lineTo(634, 490);
    IRtoControl.moveTo(632, 495);
    IRtoControl.lineTo(634, 490);
    IRtoControl.lineTo(636, 495);

    QPainterPath TMPset;
    TMPset.moveTo(455, 240);
    TMPset.lineTo(455, 125);
    TMPset.lineTo(190, 125);
    TMPset.moveTo(195, 120);
    TMPset.lineTo(190, 125);
    TMPset.lineTo(195, 130);

    QPainterPath controlToBus1;
    controlToBus1.moveTo(445, 240);
    controlToBus1.lineTo(445, 200);
    controlToBus1.lineTo(190, 200);
    controlToBus1.moveTo(195, 195);
    controlToBus1.lineTo(190, 200);
    controlToBus1.lineTo(195, 205);

    QPainterPath opLines;
    opLines.moveTo(195, 280);
    opLines.lineTo(425, 280);
    opLines.moveTo(200, 277);
    opLines.lineTo(195, 280);
    opLines.lineTo(200, 283);
    opLines.moveTo(195, 290);
    opLines.lineTo(425, 290);
    opLines.moveTo(200, 287);
    opLines.lineTo(195, 290);
    opLines.lineTo(200, 293);
    opLines.moveTo(195, 300);
    opLines.lineTo(425, 300);
    opLines.moveTo(200, 297);
    opLines.lineTo(195, 300);
    opLines.lineTo(200, 303);

    QPainterPath carryOut;
    carryOut.moveTo(195, 380);
    carryOut.lineTo(285, 380);
    carryOut.moveTo(280, 375);
    carryOut.lineTo(285, 380);
    carryOut.lineTo(280, 385);
    QPainterPath aLarger;
    aLarger.moveTo(195, 410);
    aLarger.lineTo(285, 410);
    aLarger.moveTo(280, 405);
    aLarger.lineTo(285, 410);
    aLarger.lineTo(280, 415);
    QPainterPath equalLine;
    equalLine.moveTo(195, 440);
    equalLine.lineTo(285, 440);
    equalLine.moveTo(280, 435);
    equalLine.lineTo(285, 440);
    equalLine.lineTo(280, 445);
    QPainterPath zeroLine;
    zeroLine.moveTo(195, 470);
    zeroLine.lineTo(285, 470);
    zeroLine.moveTo(280, 465);
    zeroLine.lineTo(285, 470);
    zeroLine.lineTo(280, 475);

    QPainterPath carryIn;
    carryIn.moveTo(335, 380);
    carryIn.lineTo(425, 380);
    carryIn.moveTo(380, 380);
    carryIn.lineTo(380, 330);
    carryIn.lineTo(195, 330);
    carryIn.moveTo(420, 375);
    carryIn.lineTo(425, 380);
    carryIn.lineTo(420, 385);
    carryIn.moveTo(200, 325);
    carryIn.lineTo(195, 330);
    carryIn.lineTo(200, 335);
    QPainterPath aLargertoControl;
    aLargertoControl.moveTo(335, 410);
    aLargertoControl.lineTo(425, 410);
    aLargertoControl.moveTo(420, 405);
    aLargertoControl.lineTo(425, 410);
    aLargertoControl.lineTo(420, 415);
    QPainterPath equalToControl;
    equalToControl.moveTo(335, 440);
    equalToControl.lineTo(425, 440);
    equalToControl.moveTo(420, 435);
    equalToControl.lineTo(425, 440);
    equalToControl.lineTo(420, 445);
    QPainterPath zeroToControl;
    zeroToControl.moveTo(335, 470);
    zeroToControl.lineTo(425, 470);
    zeroToControl.moveTo(420, 465);
    zeroToControl.lineTo(425, 470);
    zeroToControl.lineTo(420, 475);

    QPainterPath controlToFlagSet;
    controlToFlagSet.moveTo(445, 490);
    controlToFlagSet.lineTo(445, 530);
    controlToFlagSet.lineTo(335, 530);
    controlToFlagSet.moveTo(340, 525);
    controlToFlagSet.lineTo(335, 530);
    controlToFlagSet.lineTo(340, 535);

    QPainterPath ACCset;
    ACCset.moveTo(455, 490);
    ACCset.lineTo(455, 565);
    ACCset.lineTo(160, 565);
    ACCset.moveTo(165, 560);
    ACCset.lineTo(160, 565);
    ACCset.lineTo(165, 570);
    QPainterPath ACCenable;
    ACCenable.moveTo(465, 490);
    ACCenable.lineTo(465, 595);
    ACCenable.lineTo(160, 595);
    ACCenable.moveTo(165, 590);
    ACCenable.lineTo(160, 595);
    ACCenable.lineTo(165, 600);


    renderAreas.push_back(new RenderArea(ALU));
    //renderAreas.push_back(new RenderArea(textPath));
    //renderAreas.push_back(new RenderArea(txtALU));
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
    //renderLines.push_back(new RenderLine(busLine));
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
    //text
    renderText.push_back(new RenderText(txtALU));
    renderText.push_back(new RenderText(txtControl));
    renderText.push_back(new RenderText(txtRAM));
    renderText.push_back(new RenderText(txtMAR));
    renderText.push_back(new RenderText(txtReg0));
    renderText.push_back(new RenderText(txtReg1));
    renderText.push_back(new RenderText(txtReg2));
    renderText.push_back(new RenderText(txtReg3));
    renderText.push_back(new RenderText(txtTMP));
    renderText.push_back(new RenderText(txtBus1));

    //active
    renderActive.push_back(new RenderActive(busLine));
    renderActive.push_back(new RenderActive(ALU));


    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(2, 20);

    penWidthLabel = new QLabel(tr("&Pen Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penColorComboBox = new QComboBox;
    populateWithColors(penColorComboBox);
    penColorComboBox->setCurrentIndex(penColorComboBox->findText("red"));

    penColorLabel = new QLabel(tr("Pen &Color:"));
    penColorLabel->setBuddy(penColorComboBox);

    connect(penColorComboBox, SIGNAL(activated(int)), this, SLOT(penColorChanged()));


//  insert for loop for every in-app changeable class. [penWidth]
    for(QList<RenderActive*>::iterator it = renderActive.begin(); it != renderActive.end(); it++)
    {
        connect(penWidthSpinBox, SIGNAL(valueChanged(int)), *it, SLOT(setPenWidth(int)));
    }
//  [penWidth]

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
    for(QList<RenderActive*>::iterator it = renderActive.begin(); it != renderActive.end(); it++, i++)
    {
        topLayout->addWidget(*it, 0, 1);
    }
    for(QList<RenderText*>::iterator it = renderText.begin(); it != renderText.end(); it++, i++)
    {
        topLayout->addWidget(*it, 0, 1);
    }

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(topLayout, 0, 0, 1, 4);
    mainLayout->addWidget(penWidthLabel, 1, 0);
    mainLayout->addWidget(penWidthSpinBox, 1, 1, 1, 2);
    mainLayout->addWidget(penColorLabel, 2, 0);
    mainLayout->addWidget(penColorComboBox, 2, 1, 1, 3);
    //topLayout->setGeometry(QRect(QPoint(10, 10), QSize(40.0, 40.0)));
    setLayout(mainLayout);

    penWidthSpinBox->setValue(2);

    //label = new QLabel("de ALU natuurlijk", this);
    //label->setGeometry(QRect(QPoint(70, 200), QSize(500, 20)));

    setWindowTitle(tr("Scotty Processor"));

}

void Window::penColorChanged()
{
    QColor color = qvariant_cast<QColor>(currentItemData(penColorComboBox));

//  insert for loop for every in-app changeable class. [penColor]
    for(QList<RenderActive*>::iterator it = renderActive.begin(); it != renderActive.end(); ++it)
    {
        (*it)->setPenColor(color);
    }
//  [penColor]
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
