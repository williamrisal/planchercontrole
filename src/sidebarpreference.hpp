#ifndef SIDEBARPREFERENCE_HPP
#define SIDEBARPREFERENCE_HPP


#include <QWidget>
#include <QObject>
#include <iostream>
#include <ostream>
#include <iostream>
#include <QLineEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include "QGroupBox"
#include <QFormLayout>
#include "QtGui/qevent.h"
#include "QtWidgets/qslider.h"
#include "QSidePanel/PanelRightSide.hpp"
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qslider.h"
#include "QtCore/qobject.h"
#include "QtWidgets/qwidget.h"
#include "qmessagebox.h"
#include "CheckPixel.hpp"

class SideBarPreference : public QWidget
{
    Q_OBJECT
public:
    QSlider* SliderAltitude();
    SideBarPreference(QWidget *parent = nullptr);
    QVBoxLayout *BoxPosition();
signals:
    void sliderValueChanged(int value);

};

#endif // SIDEBARPREFERENCE_HPP
