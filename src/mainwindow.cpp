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

    connect(sidebar, &SideBarPreference::sliderValueChanged, map, &MapImage::setAltitude);

    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(map, 0, 0, 1, 4);

    mainLayout->addWidget(sidebar, 0, 3);

    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);


   /* Position_Aeronef point_position;
    double *position = new double[3];
    position = point_position.Position_point();

    double scaleFactor = 0.15;
    double scaledX = std::round(position[0] * scaleFactor / (1280 / 2));
    double scaledY = std::round(position[1] * scaleFactor / (720 / 2));

    double x_final = scaledX + 640;
    double y_final = abs((scaledY + 360) - 720);

    std::cout << "Scaled coordinates:" << std::endl;
    std::cout << "x: " << x_final << std::endl;
    std::cout << "y: " << y_final << std::endl;

    bluepoint->move(x_final, y_final);
*/

    setCentralWidget(mainWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}
