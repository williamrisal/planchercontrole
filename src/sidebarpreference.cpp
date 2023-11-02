#include "sidebarpreference.hpp"
#include "QtGui/qshortcut.h"
#include "QtWidgets/qlabel.h"
#include "QtWidgets/qpushbutton.h"
#include <qpainter.h>
#include "QCheckBox"
#include <QSplitter>


SideBarPreference::SideBarPreference(QWidget *parent)
{
    PanelRightSide* panelRight = new PanelRightSide(this);
    panelRight->setOpenEasingCurve(QEasingCurve::Type::OutExpo);
    panelRight->setCloseEasingCurve(QEasingCurve::Type::InExpo);
    panelRight->setPanelSize(260);
    panelRight->init();

    QVBoxLayout* rightLayout = new QVBoxLayout;
    QVBoxLayout* leftLayout = new QVBoxLayout;

    // Créez le widget "Points culminants"
    QWidget* pointCulminanteWidget = new QWidget(this);
    QVBoxLayout* pointCulminanteLayout = new QVBoxLayout;
    pointCulminanteLayout->addLayout(DisablePointCulminante());
    pointCulminanteLayout->addLayout(ButtonStrategiquePoint());
    pointCulminanteWidget->setLayout(pointCulminanteLayout);

    // Créez le widget "Choix radar"
    QWidget* chooseRadarWidget = new QWidget(this);
    QHBoxLayout* chooseRadarLayout = new QHBoxLayout;
    chooseRadarLayout->addWidget(SliderAltitude());
    chooseRadarLayout->addLayout(ButtonChooseRadar());
    chooseRadarWidget->setLayout(chooseRadarLayout);



    rightLayout->addWidget(pointCulminanteWidget); // Ajoutez les "Points culminants"
    rightLayout->addWidget(chooseRadarWidget); // Ajoutez le "Choix radar"
    rightLayout->addLayout(ButtonAdmin()); // Ajoutez le reste

    QWidget* rightWidget = new QWidget(this);
    QWidget* leftWidget = new QWidget(this);

    rightWidget->setLayout(rightLayout);
    leftWidget->setLayout(leftLayout);

    // Créez un QSplitter pour mettre leftWidget à gauche de rightWidget
    QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(leftWidget);
    splitter->addWidget(rightWidget);

    // Définissez la taille initiale de leftWidget et rightWidget
    splitter->setStretchFactor(0, 1); // leftWidget prend 1 part
    splitter->setStretchFactor(1, 2); // rightWidget prend 2 parts

    panelRight->setWidgetResizable(true);
    panelRight->setWidget(splitter); // Utilisez le QSplitter comme contenu de panelRight

    QShortcut* Shortcut = new QShortcut(QKeySequence("Ctrl+W"), this);
    connect(Shortcut, &QShortcut::activated, this, &SideBarPreference::buttonActive);
}


QVBoxLayout* SideBarPreference::BoxPosition()
{
    QVBoxLayout* layout = new QVBoxLayout;

    QGroupBox* groupBox = new QGroupBox("Position Aeronef");
    QVBoxLayout* groupLayout = new QVBoxLayout(groupBox);

    QFormLayout* formLayout = new QFormLayout;

    lineEdit1 = new QLineEdit(this);
    lineEdit2 = new QLineEdit(this);

    formLayout->addRow("Latitude :", lineEdit1);
    formLayout->addRow("Longitude :", lineEdit2);

    groupLayout->addLayout(formLayout);

    layout->addWidget(groupBox);

    QPushButton* button = new QPushButton("Envoyer", this);

    layout->addWidget(button);


    lineEdit1->setPlaceholderText("Ex : N44°11'54.51'");
    lineEdit2->setPlaceholderText("Ex : E5°56'22.607");

    return layout;
}

//Latitude: "N43°17'33.641'"
//Longitude: "E5°34'3.513"
//N44°11'54.51' E5°56'22.607"E

QWidget* SideBarPreference::SliderAltitude()
{
    const int targetValues[6] = { 582, 1082, 1582, 2082, 5082, 10082 };
    const QStringList labels = { "582", "1082", "1582", "2082", "5082", "10082" };

    QSlider* slider = new QSlider(Qt::Vertical);

    slider->setMinimum(0);
    slider->setMaximum(5);
    slider->setTickInterval(1);
    slider->setTickPosition(QSlider::TicksBothSides);

    QLabel* altitudeLabel = new QLabel(labels[0]);
    altitudeLabel->setAlignment(Qt::AlignCenter);

    connect(slider, &QSlider::valueChanged, this, [this, targetValues, slider, labels, altitudeLabel](int value) {
        QPixmap cursorPixmap(32, 32);
        cursorPixmap.fill(Qt::transparent);

        QPainter painter(&cursorPixmap);
        QFont font;
        font.setPointSize(24);
        painter.setFont(font);

        switch (value) {

        case 1:
            painter.drawText(cursorPixmap.rect(), Qt::AlignCenter, "🕊️");
            break;
        case 2:
            painter.drawText(cursorPixmap.rect(), Qt::AlignCenter, "🚁");
            break;
        case 3:
            painter.drawText(cursorPixmap.rect(), Qt::AlignCenter, "🛩️");
            break;
        case 4:
            painter.drawText(cursorPixmap.rect(), Qt::AlignCenter, "🚀");
            break;
        case 5:
            painter.drawText(cursorPixmap.rect(), Qt::AlignCenter, "🛰️");
            break;
        default:
            painter.drawText(cursorPixmap.rect(), Qt::AlignCenter, "🐝");
            break;
        }

        QCursor cursor(cursorPixmap);
        slider->setCursor(cursor);

        altitudeLabel->setText(labels[value]);

        emit sliderValueChanged(targetValues[value]);
    });

    slider->setTickPosition(QSlider::TicksBothSides);
    slider->setTickInterval(1);
    slider->setSingleStep(1);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(altitudeLabel);

    QWidget* widget = new QWidget;
    widget->setLayout(layout);

    return widget;
}



void SideBarPreference::CompletePositionBox(QString Position_Aeronef)
{
    int separatorIndex = Position_Aeronef.indexOf("E") - 1;
    QString lat = Position_Aeronef.left(separatorIndex);
    QString lon = Position_Aeronef.mid(separatorIndex + 1);

    lat.remove(' ');
    lon.remove(' ');

    qDebug() << "SetPointAeronefMouse : " << lat << " lon :" << lon ;
    lineEdit1->setText(lat);
    lineEdit2->setText(lon);
}

QVBoxLayout* SideBarPreference::ButtonChooseRadar()
{
    QVBoxLayout* layout = new QVBoxLayout;

    QList<QCheckBox*> checkBoxes;

    checkBoxes << new QCheckBox("RO Narbonne");
    checkBoxes << new QCheckBox("DS Salon de Provence");
    checkBoxes << new QCheckBox("RS Sainte Baume");
    checkBoxes << new QCheckBox("DI Istres");
    checkBoxes << new QCheckBox("GV Vitrolles");
    checkBoxes << new QCheckBox("JO Montpellier");
    checkBoxes << new QCheckBox("JX Ventoux");

    for (QCheckBox* checkBox : checkBoxes) {
        layout->addWidget(checkBox);

        connect(checkBox, &QCheckBox::stateChanged, this, [this, checkBox](int state) {
            emit checkBoxRadarStateChanged(checkBox->text(), state);
        });
    }

    return layout;
}


QVBoxLayout* SideBarPreference::DisablePointCulminante(){
    QVBoxLayout* layout = new QVBoxLayout;
    QCheckBox *CheckBoxPC = new QCheckBox("Disable Point Culminante");
    CheckBoxPC->setChecked(true);

    layout->addWidget(CheckBoxPC);
    connect(CheckBoxPC, &QCheckBox::stateChanged, this, [this, CheckBoxPC](int state) {
        emit checkBoxStateChangedCulminante(state);
    });
    return layout;
}

QVBoxLayout* SideBarPreference::ButtonAdmin() {

    QStringList buttonLabels = { "<", ">", "^", "v", "+", "-" };

    for (int i = 0; i < buttonLabels.size(); ++i) {
        QPushButton* button = new QPushButton(buttonLabels[i], this);
        button->hide();
        Adminlayout->addWidget(button);
        buttonsadmin.append(button);

        connect(button, &QPushButton::clicked, this, [ i, this]() {
            emit buttonClickedSignal(i);
        });
    }

    return Adminlayout;
}


QVBoxLayout* SideBarPreference::ButtonStrategiquePoint() {

    QVBoxLayout* layout = new QVBoxLayout;
    QCheckBox *CheckBoxPC = new QCheckBox("Disable Strategique Point");
    CheckBoxPC->setChecked(true);

    layout->addWidget(CheckBoxPC);
    connect(CheckBoxPC, &QCheckBox::stateChanged, this, [this, CheckBoxPC](int state) {
        emit checkBoxStateChangedStrategique(state);
    });
    return layout;

}




QVBoxLayout* SideBarPreference::ButtonPerimetre() {

    QStringList buttonLabels = { "Perimetre A", "Perimetre B", "Perimetre C", "Perimetre D", "Perimetre E", "Perimetre F" };

    for (int i = 0; i < buttonLabels.size(); ++i) {
        QPushButton* button = new QPushButton(buttonLabels[i], this);
        button->hide();
        Adminlayout->addWidget(button);
        buttonsadmin.append(button);

        connect(button, &QPushButton::clicked, this, [ i, this]() {
            emit buttonClickedSignal(i);
        });
    }

    return Adminlayout;
}
