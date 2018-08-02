/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit_1;
    QWidget *centralWidget;
    QGroupBox *Channel1;
    QGroupBox *ch1_volume;
    QSlider *Volume1;
    QPushButton *reset_vol1;
    QGroupBox *ch1_eq;
    QDial *eqH1;
    QLabel *eqH1_l;
    QLabel *eqMH1_l;
    QDial *eqMH1;
    QLabel *eqM1_l;
    QDial *eqM1;
    QLabel *eqML1_l;
    QDial *eqML1;
    QLabel *eqL1_l;
    QDial *eqL1;
    QPushButton *reset_eq1;
    QGroupBox *ch1_trem;
    QDial *trem1_amp;
    QDial *trem1_freq;
    QLabel *trem1_amp_l;
    QLabel *trem1_freq_l;
    QPushButton *trem1_reset;
    QPushButton *trem1_toggle;
    QGroupBox *ch1_echo;
    QDial *echo1_gain;
    QDial *echo1_delay;
    QLabel *echo1_gain_l;
    QLabel *echo1_delay_l;
    QPushButton *echo1_reset;
    QComboBox *echo1_num;
    QLabel *echo1_num_l;
    QGroupBox *PitchShifting1;
    QDial *pitch_shifter1;
    QPushButton *reset_pitchshift1;
    QPushButton *reset_ch1;
    QMenuBar *menuBar;
    QMenu *Exit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(309, 485);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionExit_1 = new QAction(MainWindow);
        actionExit_1->setObjectName(QStringLiteral("actionExit_1"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Channel1 = new QGroupBox(centralWidget);
        Channel1->setObjectName(QStringLiteral("Channel1"));
        Channel1->setGeometry(QRect(10, 10, 281, 421));
        ch1_volume = new QGroupBox(Channel1);
        ch1_volume->setObjectName(QStringLiteral("ch1_volume"));
        ch1_volume->setGeometry(QRect(10, 20, 61, 251));
        Volume1 = new QSlider(ch1_volume);
        Volume1->setObjectName(QStringLiteral("Volume1"));
        Volume1->setGeometry(QRect(11, 20, 41, 191));
        Volume1->setMouseTracking(true);
        Volume1->setMaximum(100);
        Volume1->setValue(50);
        Volume1->setOrientation(Qt::Vertical);
        Volume1->setInvertedAppearance(false);
        Volume1->setTickPosition(QSlider::TicksBelow);
        reset_vol1 = new QPushButton(ch1_volume);
        reset_vol1->setObjectName(QStringLiteral("reset_vol1"));
        reset_vol1->setGeometry(QRect(10, 220, 41, 23));
        ch1_eq = new QGroupBox(Channel1);
        ch1_eq->setObjectName(QStringLiteral("ch1_eq"));
        ch1_eq->setGeometry(QRect(80, 20, 191, 151));
        eqH1 = new QDial(ch1_eq);
        eqH1->setObjectName(QStringLiteral("eqH1"));
        eqH1->setGeometry(QRect(10, 40, 51, 41));
        eqH1->setMinimumSize(QSize(41, 0));
        eqH1->setMouseTracking(true);
        eqH1->setMinimum(0);
        eqH1->setMaximum(100);
        eqH1->setPageStep(10);
        eqH1->setValue(50);
        eqH1->setSliderPosition(50);
        eqH1->setWrapping(false);
        eqH1->setNotchesVisible(true);
        eqH1_l = new QLabel(ch1_eq);
        eqH1_l->setObjectName(QStringLiteral("eqH1_l"));
        eqH1_l->setGeometry(QRect(10, 20, 51, 16));
        eqH1_l->setMinimumSize(QSize(47, 0));
        eqH1_l->setAlignment(Qt::AlignCenter);
        eqMH1_l = new QLabel(ch1_eq);
        eqMH1_l->setObjectName(QStringLiteral("eqMH1_l"));
        eqMH1_l->setGeometry(QRect(70, 20, 51, 16));
        eqMH1_l->setMinimumSize(QSize(47, 0));
        eqMH1_l->setAlignment(Qt::AlignCenter);
        eqMH1 = new QDial(ch1_eq);
        eqMH1->setObjectName(QStringLiteral("eqMH1"));
        eqMH1->setGeometry(QRect(70, 40, 51, 41));
        eqMH1->setMinimumSize(QSize(41, 0));
        eqMH1->setMouseTracking(true);
        eqMH1->setMinimum(0);
        eqMH1->setMaximum(100);
        eqMH1->setValue(50);
        eqMH1->setSliderPosition(50);
        eqMH1->setWrapping(false);
        eqMH1->setNotchesVisible(true);
        eqM1_l = new QLabel(ch1_eq);
        eqM1_l->setObjectName(QStringLiteral("eqM1_l"));
        eqM1_l->setGeometry(QRect(130, 20, 51, 16));
        eqM1_l->setMinimumSize(QSize(47, 0));
        eqM1_l->setAlignment(Qt::AlignCenter);
        eqM1 = new QDial(ch1_eq);
        eqM1->setObjectName(QStringLiteral("eqM1"));
        eqM1->setGeometry(QRect(130, 40, 51, 41));
        eqM1->setMinimumSize(QSize(41, 0));
        eqM1->setMouseTracking(true);
        eqM1->setMinimum(0);
        eqM1->setMaximum(100);
        eqM1->setValue(50);
        eqM1->setSliderPosition(50);
        eqM1->setWrapping(false);
        eqM1->setNotchesVisible(true);
        eqML1_l = new QLabel(ch1_eq);
        eqML1_l->setObjectName(QStringLiteral("eqML1_l"));
        eqML1_l->setGeometry(QRect(10, 80, 51, 16));
        eqML1_l->setMinimumSize(QSize(47, 0));
        eqML1_l->setAlignment(Qt::AlignCenter);
        eqML1 = new QDial(ch1_eq);
        eqML1->setObjectName(QStringLiteral("eqML1"));
        eqML1->setGeometry(QRect(10, 100, 51, 41));
        eqML1->setMinimumSize(QSize(41, 0));
        eqML1->setMouseTracking(true);
        eqML1->setMaximum(100);
        eqML1->setSliderPosition(50);
        eqML1->setWrapping(false);
        eqML1->setNotchesVisible(true);
        eqL1_l = new QLabel(ch1_eq);
        eqL1_l->setObjectName(QStringLiteral("eqL1_l"));
        eqL1_l->setGeometry(QRect(70, 80, 51, 16));
        eqL1_l->setMinimumSize(QSize(47, 0));
        eqL1_l->setAlignment(Qt::AlignCenter);
        eqL1 = new QDial(ch1_eq);
        eqL1->setObjectName(QStringLiteral("eqL1"));
        eqL1->setGeometry(QRect(70, 100, 51, 41));
        eqL1->setMinimumSize(QSize(41, 0));
        eqL1->setMouseTracking(true);
        eqL1->setMaximum(100);
        eqL1->setSliderPosition(50);
        eqL1->setWrapping(false);
        eqL1->setNotchesVisible(true);
        reset_eq1 = new QPushButton(ch1_eq);
        reset_eq1->setObjectName(QStringLiteral("reset_eq1"));
        reset_eq1->setGeometry(QRect(130, 110, 41, 23));
        reset_eq1->setLayoutDirection(Qt::LeftToRight);
        ch1_trem = new QGroupBox(Channel1);
        ch1_trem->setObjectName(QStringLiteral("ch1_trem"));
        ch1_trem->setGeometry(QRect(140, 270, 131, 111));
        trem1_amp = new QDial(ch1_trem);
        trem1_amp->setObjectName(QStringLiteral("trem1_amp"));
        trem1_amp->setGeometry(QRect(10, 20, 51, 41));
        trem1_amp->setMinimumSize(QSize(41, 0));
        trem1_amp->setMouseTracking(true);
        trem1_amp->setMaximum(100);
        trem1_amp->setSliderPosition(50);
        trem1_amp->setWrapping(false);
        trem1_amp->setNotchesVisible(true);
        trem1_freq = new QDial(ch1_trem);
        trem1_freq->setObjectName(QStringLiteral("trem1_freq"));
        trem1_freq->setGeometry(QRect(70, 20, 51, 41));
        trem1_freq->setMinimumSize(QSize(41, 0));
        trem1_freq->setMouseTracking(true);
        trem1_freq->setMinimum(1);
        trem1_freq->setMaximum(4);
        trem1_freq->setPageStep(1);
        trem1_freq->setValue(1);
        trem1_freq->setSliderPosition(1);
        trem1_freq->setWrapping(false);
        trem1_freq->setNotchesVisible(true);
        trem1_amp_l = new QLabel(ch1_trem);
        trem1_amp_l->setObjectName(QStringLiteral("trem1_amp_l"));
        trem1_amp_l->setGeometry(QRect(10, 60, 51, 16));
        trem1_amp_l->setMinimumSize(QSize(47, 0));
        trem1_amp_l->setAlignment(Qt::AlignCenter);
        trem1_freq_l = new QLabel(ch1_trem);
        trem1_freq_l->setObjectName(QStringLiteral("trem1_freq_l"));
        trem1_freq_l->setGeometry(QRect(70, 60, 51, 16));
        trem1_freq_l->setMinimumSize(QSize(47, 0));
        trem1_freq_l->setAlignment(Qt::AlignCenter);
        trem1_reset = new QPushButton(ch1_trem);
        trem1_reset->setObjectName(QStringLiteral("trem1_reset"));
        trem1_reset->setGeometry(QRect(20, 80, 41, 23));
        trem1_toggle = new QPushButton(ch1_trem);
        trem1_toggle->setObjectName(QStringLiteral("trem1_toggle"));
        trem1_toggle->setGeometry(QRect(70, 80, 41, 23));
        ch1_echo = new QGroupBox(Channel1);
        ch1_echo->setObjectName(QStringLiteral("ch1_echo"));
        ch1_echo->setGeometry(QRect(10, 270, 121, 141));
        echo1_gain = new QDial(ch1_echo);
        echo1_gain->setObjectName(QStringLiteral("echo1_gain"));
        echo1_gain->setGeometry(QRect(10, 20, 51, 41));
        echo1_gain->setMinimumSize(QSize(41, 0));
        echo1_gain->setMouseTracking(true);
        echo1_gain->setMaximum(40);
        echo1_gain->setSliderPosition(40);
        echo1_gain->setWrapping(false);
        echo1_gain->setNotchesVisible(true);
        echo1_delay = new QDial(ch1_echo);
        echo1_delay->setObjectName(QStringLiteral("echo1_delay"));
        echo1_delay->setGeometry(QRect(60, 20, 51, 41));
        echo1_delay->setMinimumSize(QSize(41, 0));
        echo1_delay->setMouseTracking(true);
        echo1_delay->setMaximum(100);
        echo1_delay->setValue(0);
        echo1_delay->setSliderPosition(0);
        echo1_delay->setWrapping(false);
        echo1_delay->setNotchesVisible(true);
        echo1_gain_l = new QLabel(ch1_echo);
        echo1_gain_l->setObjectName(QStringLiteral("echo1_gain_l"));
        echo1_gain_l->setGeometry(QRect(10, 60, 51, 16));
        echo1_gain_l->setMinimumSize(QSize(47, 0));
        echo1_gain_l->setAlignment(Qt::AlignCenter);
        echo1_delay_l = new QLabel(ch1_echo);
        echo1_delay_l->setObjectName(QStringLiteral("echo1_delay_l"));
        echo1_delay_l->setGeometry(QRect(60, 60, 51, 16));
        echo1_delay_l->setMinimumSize(QSize(47, 0));
        echo1_delay_l->setAlignment(Qt::AlignCenter);
        echo1_reset = new QPushButton(ch1_echo);
        echo1_reset->setObjectName(QStringLiteral("echo1_reset"));
        echo1_reset->setGeometry(QRect(40, 110, 41, 23));
        echo1_num = new QComboBox(ch1_echo);
        echo1_num->addItem(QString());
        echo1_num->addItem(QString());
        echo1_num->addItem(QString());
        echo1_num->addItem(QString());
        echo1_num->setObjectName(QStringLiteral("echo1_num"));
        echo1_num->setGeometry(QRect(70, 80, 31, 22));
        echo1_num_l = new QLabel(ch1_echo);
        echo1_num_l->setObjectName(QStringLiteral("echo1_num_l"));
        echo1_num_l->setGeometry(QRect(20, 80, 47, 13));
        PitchShifting1 = new QGroupBox(Channel1);
        PitchShifting1->setObjectName(QStringLiteral("PitchShifting1"));
        PitchShifting1->setGeometry(QRect(80, 170, 91, 101));
        pitch_shifter1 = new QDial(PitchShifting1);
        pitch_shifter1->setObjectName(QStringLiteral("pitch_shifter1"));
        pitch_shifter1->setGeometry(QRect(20, 20, 51, 41));
        pitch_shifter1->setMinimumSize(QSize(41, 0));
        pitch_shifter1->setMouseTracking(true);
        pitch_shifter1->setMaximum(100);
        pitch_shifter1->setSliderPosition(50);
        pitch_shifter1->setWrapping(false);
        pitch_shifter1->setNotchesVisible(true);
        reset_pitchshift1 = new QPushButton(PitchShifting1);
        reset_pitchshift1->setObjectName(QStringLiteral("reset_pitchshift1"));
        reset_pitchshift1->setGeometry(QRect(20, 70, 51, 23));
        reset_ch1 = new QPushButton(Channel1);
        reset_ch1->setObjectName(QStringLiteral("reset_ch1"));
        reset_ch1->setGeometry(QRect(140, 390, 131, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 309, 21));
        Exit = new QMenu(menuBar);
        Exit->setObjectName(QStringLiteral("Exit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        eqH1_l->setBuddy(eqH1);
        eqMH1_l->setBuddy(eqMH1);
        eqM1_l->setBuddy(eqM1);
        eqML1_l->setBuddy(eqML1);
        eqL1_l->setBuddy(eqL1);
        echo1_gain_l->setBuddy(echo1_gain);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(Volume1, reset_vol1);
        QWidget::setTabOrder(reset_vol1, eqH1);
        QWidget::setTabOrder(eqH1, eqMH1);
        QWidget::setTabOrder(eqMH1, eqM1);
        QWidget::setTabOrder(eqM1, eqML1);
        QWidget::setTabOrder(eqML1, eqL1);
        QWidget::setTabOrder(eqL1, reset_eq1);
        QWidget::setTabOrder(reset_eq1, pitch_shifter1);
        QWidget::setTabOrder(pitch_shifter1, reset_pitchshift1);
        QWidget::setTabOrder(reset_pitchshift1, echo1_gain);
        QWidget::setTabOrder(echo1_gain, echo1_delay);
        QWidget::setTabOrder(echo1_delay, echo1_num);
        QWidget::setTabOrder(echo1_num, echo1_reset);
        QWidget::setTabOrder(echo1_reset, trem1_amp);
        QWidget::setTabOrder(trem1_amp, trem1_freq);
        QWidget::setTabOrder(trem1_freq, trem1_reset);
        QWidget::setTabOrder(trem1_reset, reset_ch1);

        menuBar->addAction(Exit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        Exit->addSeparator();
        Exit->addSeparator();
        Exit->addAction(actionExit_1);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionExit_1->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        Channel1->setTitle(QApplication::translate("MainWindow", "Channel 1", nullptr));
        ch1_volume->setTitle(QApplication::translate("MainWindow", "Volume", nullptr));
        reset_vol1->setText(QApplication::translate("MainWindow", "Mute", nullptr));
        ch1_eq->setTitle(QApplication::translate("MainWindow", "Equaliser", nullptr));
        eqH1_l->setText(QApplication::translate("MainWindow", "High", nullptr));
        eqMH1_l->setText(QApplication::translate("MainWindow", "Mid-High", nullptr));
        eqM1_l->setText(QApplication::translate("MainWindow", "Mid", nullptr));
        eqML1_l->setText(QApplication::translate("MainWindow", "Mid-Low", nullptr));
        eqL1_l->setText(QApplication::translate("MainWindow", "Low", nullptr));
        reset_eq1->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        ch1_trem->setTitle(QApplication::translate("MainWindow", "Tremolo", nullptr));
        trem1_amp_l->setText(QApplication::translate("MainWindow", "Amplitude", nullptr));
        trem1_freq_l->setText(QApplication::translate("MainWindow", "Frequency", nullptr));
        trem1_reset->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        trem1_toggle->setText(QApplication::translate("MainWindow", "Toggle", nullptr));
        ch1_echo->setTitle(QApplication::translate("MainWindow", "Echo", nullptr));
        echo1_gain_l->setText(QApplication::translate("MainWindow", "Gain", nullptr));
        echo1_delay_l->setText(QApplication::translate("MainWindow", "Delay", nullptr));
        echo1_reset->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        echo1_num->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        echo1_num->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        echo1_num->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));
        echo1_num->setItemText(3, QApplication::translate("MainWindow", "4", nullptr));

        echo1_num_l->setText(QApplication::translate("MainWindow", "# of Echos", nullptr));
        PitchShifting1->setTitle(QApplication::translate("MainWindow", "Pitch Shifting", nullptr));
        reset_pitchshift1->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        reset_ch1->setText(QApplication::translate("MainWindow", "Reset Channel 1", nullptr));
        Exit->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
