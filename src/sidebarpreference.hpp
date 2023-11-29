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

enum class Visibility : bool {
    Show = true,
    Hide = false
};

class SideBarPreference : public QWidget
{
    Q_OBJECT
public:
    QWidget* SliderAltitude();
    SideBarPreference(QWidget *parent = nullptr);
    QVBoxLayout *BoxPosition();
    void CompletePositionBox(QString Position_Aeronef);
    QVBoxLayout* ButtonChooseRadar();
    QVBoxLayout* ButtonChooseRadio();
    QVBoxLayout* DisablePointCulminante();
    QVBoxLayout* ButtonAdmin();
    void confirmClose(QShortcut *Shortcut);
    QVBoxLayout* ButtonStrategiquePoint();
    QVBoxLayout* CheckBoxesForPolygones();
    QVBoxLayout *ButtonPolygones();
    void showAdditionalPanel();
    void hideAdditionalPanel();
    QVBoxLayout* ButtonClosePolygones();
    QWidget* createCheckBoxOptionWidget();
    QWidget* createChooseRadarWidget();
    QVBoxLayout* createAdminLayout();
    QVBoxLayout* createPolygonesLayout(Visibility visibility);
    QWidget* createCheckBoxPolygoneWidget();
    QWidget* createChooseRadioWidget();
    void createLayouts();
    MapImage map;


public slots:
    void buttonActive(){
        if (ButtonAdminBool == false) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Fermeture", "Voulez-vous vraiment ouvrir le Mode Edition ?", QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                for (QPushButton* button : buttonsadmin) {
                    button->show();
                    ButtonAdminBool = true;
                }
            }
            return;
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
    void checkBoxRadioStateChanged(const QString& checkBoxText, int state);

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
    PanelRightSide* panelSubRight = new PanelRightSide(this);
    QLineEdit* lineEdit1;
    QLineEdit* lineEdit2;
    bool ButtonAdminBool = false;
};

#endif // SIDEBARPREFERENCE_HPP
