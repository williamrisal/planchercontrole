#include "mainwindow.h"
#include <iostream>
#include <cmath>
#include <iomanip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *redPoint = new QLabel(this);
    redPoint->setFixedSize(10, 10); 
    redPoint->setAutoFillBackground(true);
    redPoint->setStyleSheet("background-color: red; border-radius: 5px;");

    MapImage *map = new MapImage(this);
    SideBarPreference *sidebar = new SideBarPreference(this);

    connect(sidebar, &SideBarPreference::sliderValueChanged, map, &MapImage::setaltitude);
    connect(sidebar, &SideBarPreference::checkBoxRadarStateChanged, map, &MapImage::showOnlyRadar);
    connect(sidebar, &SideBarPreference::checkBoxRadioStateChanged, map, &MapImage::SowElementRadio);
    connect(sidebar, &SideBarPreference::checkBoxStateChangedCulminante, map, &MapImage::ShowElementCulminante);
    connect(sidebar, &SideBarPreference::checkBoxStateChangedStrategique, map, &MapImage::ShowElementStrategique);
    connect(sidebar, &SideBarPreference::CheckBoxesForPeriemetre, map, &MapImage::ShowElementPeriemetre);

    //position image (admin)
    connect(sidebar, &SideBarPreference::buttonClickedSignal, map, &MapImage::moveImage);

    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(map, 0, 0, 1, 4);

    mainLayout->addWidget(sidebar, 0, 3);

    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}
