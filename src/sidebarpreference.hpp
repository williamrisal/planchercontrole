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
#include "src/mapimage.hpp"
#include <QPushButton>


class SideBarPreference : public QWidget
{
    Q_OBJECT
public:
    QWidget* SliderAltitude();
    SideBarPreference(QWidget *parent = nullptr);
    QVBoxLayout *BoxPosition();
    void CompletePositionBox(QString Position_Aeronef);
    QVBoxLayout* ButtonChooseRadar();
    QVBoxLayout* DisablePointCulminante();
    QVBoxLayout* ButtonAdmin();
    QVBoxLayout* ButtonStrategiquePoint();
    QVBoxLayout* CheckBoxesForPolygones();
    MapImage map;


public slots:
    void buttonActive(){
        if (ButtonAdminBool == false) {
            for (QPushButton* button : buttonsadmin) {
                button->show();
                ButtonAdminBool = true;

            }
        }
        else
            for (QPushButton* button : buttonsadmin) {
                button->hide();
                ButtonAdminBool = false;
                panelRight->setStyleSheet("");

            }

    }


signals:
    void checkBoxRadarStateChanged(const QString& checkBoxText, int state);
    void checkBoxStateChangedCulminante(int state);
    void checkBoxStateChangedStrategique(int state);
    void CheckBoxesForPeriemetre(bool state, int a);


    void sliderValueChanged(int value);
    void radarChanged(const QString& radar, bool isChecked);
    void buttonClickedSignal(int i);
    void combinaisonCtrlMActivated();

private:
    QMap<QString, QCheckBox*> radarCheckboxes;
    QVBoxLayout* Adminlayout = new QVBoxLayout;
    QVector<QPushButton*> buttonsadmin;
    PanelRightSide* panelRight = new PanelRightSide(this);
    QLineEdit* lineEdit1;
    QLineEdit* lineEdit2;
    bool ButtonAdminBool = false;
};

#endif // SIDEBARPREFERENCE_HPP
