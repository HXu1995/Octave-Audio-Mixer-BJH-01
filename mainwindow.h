#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fx_var.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	fx_var channel1;
	fx_var& pass_var();
	void setChannelTitle(QString x);




private slots:
    void on_Volume1_valueChanged(int value);

    void on_reset_vol1_clicked();

    void on_eqH1_valueChanged(int value);

    void on_eqMH1_valueChanged(int value);

    void on_eqM1_valueChanged(int value);

    void on_eqML1_valueChanged(int value);

    void on_eqL1_valueChanged(int value);

    void on_reset_eq1_clicked();

	void on_pitch_shifter1_valueChanged(int value);

	void on_reset_pitchshift1_clicked();
	void on_echo1_gain_valueChanged(int value);
	void on_echo1_delay_valueChanged(int value);
	void on_echo1_num_currentIndexChanged(int index);
	void on_echo1_reset_clicked();
	void on_trem1_amp_valueChanged(int value);
	void on_trem1_freq_valueChanged(int value);
	void on_trem1_reset_clicked();
	void on_trem1_toggle_clicked();
	void on_reset_ch1_clicked();
	void on_actionExit_1_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
