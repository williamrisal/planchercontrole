#include "sidebarpreference.hpp"


SideBarPreference::SideBarPreference(QWidget *parent)
{
    auto* panelRight = new PanelRightSide(this);
    panelRight->setOpenEasingCurve(QEasingCurve::Type::OutExpo);
    panelRight->setCloseEasingCurve(QEasingCurve::Type::InExpo);
    panelRight->setPanelSize(200);
    panelRight->init();

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(SliderAltitude());
    rightLayout->addLayout(BoxPosition());

    QWidget* rightWidget = new QWidget(this);
    rightWidget->setLayout(rightLayout);

    panelRight->setWidgetResizable(true);
    panelRight->setWidget(rightWidget);
}

QVBoxLayout* SideBarPreference::BoxPosition()
{
    QVBoxLayout* layout = new QVBoxLayout;

    // Créer un groupe avec un titre
    QGroupBox* groupBox = new QGroupBox("Position Aeronef");
    QVBoxLayout* groupLayout = new QVBoxLayout(groupBox);

    QFormLayout* formLayout = new QFormLayout;

    QLineEdit *lineEdit1 = new QLineEdit(this);
    QLineEdit *lineEdit2 = new QLineEdit(this);

    // Ajouter les champs de saisie avec les libellés correspondants
    formLayout->addRow("latitute", lineEdit1);
    formLayout->addRow("longitude", lineEdit2);

    // Ajouter le QFormLayout au layout du groupe
    groupLayout->addLayout(formLayout);

    // Ajouter le groupe au layout principal
    layout->addWidget(groupBox);

    return layout;
}



QSlider* SideBarPreference::SliderAltitude()
{
    const int targetValues[6] = {582, 1082, 1582, 2082, 5082,10082};

    QSlider* slider = new QSlider(Qt::Vertical);

    slider->setMinimum(0);
    slider->setMaximum(5);
    slider->setTickInterval(1);
    slider->setTickPosition(QSlider::TicksBothSides);

    connect(slider, &QSlider::valueChanged, this, [this, targetValues](int value) {
          emit sliderValueChanged(targetValues[value]);
      });
    return slider;
}

