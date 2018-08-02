#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fx_var.h"
#include <QtCore>
#include <QtGui>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	fx_var channel1;
}




MainWindow::~MainWindow()
{
    delete ui;
}

fx_var& MainWindow::pass_var()
{
	return channel1;
}

void MainWindow::setChannelTitle(QString x)
{
	ui->Channel1->setTitle(x);
}

void MainWindow::on_actionExit_1_triggered()
{
    close();
}

// Defining Channel actions
// Resets everything back to default
void MainWindow::on_reset_ch1_clicked()
{
    channel1.initial();
	ui->Volume1->setValue(50);
    ui->eqH1->setValue(50);
    ui->eqMH1->setValue(50);
    ui->eqM1->setValue(50);
    ui->eqML1->setValue(50);
    ui->eqL1->setValue(50);

    ui->pitch_shifter1->setValue(50);
    //ui->g_distortion1->setValue(1);
    ui->echo1_delay->setValue(0);
    ui->echo1_gain->setValue(50);
    //ui->echo1_num-set
    ui->trem1_amp->setValue(50);
    ui->trem1_freq->setValue(1);
}

void MainWindow::on_Volume1_valueChanged(int value)
{
    float vol = (float) value;
    channel1.set_volume(vol/100);
}
void MainWindow::on_reset_vol1_clicked()
{
    channel1.mute();
    ui->Volume1->setValue(0);
}

void MainWindow::on_trem1_toggle_clicked()
{
	channel1.set_trem_toggle();
}

// Equaliser combo
void MainWindow::on_eqH1_valueChanged(int value)
{
    float eq = (float) value;
    channel1.set_fgain_5(eq/50);
}

void MainWindow::on_eqMH1_valueChanged(int value)
{
    float eq = (float) value;
    channel1.set_fgain_4(eq/50);
}

void MainWindow::on_eqM1_valueChanged(int value)
{
    float eq = (float) value;
    channel1.set_fgain_3(eq/50);
}

void MainWindow::on_eqML1_valueChanged(int value)
{
    float eq = (float) value;
    channel1.set_fgain_2(eq/50);
}

void MainWindow::on_eqL1_valueChanged(int value)
{
    float eq = (float) value;
    channel1.set_fgain_1(eq/50);
}

void MainWindow::on_reset_eq1_clicked()
{
    channel1.reset_eq();
    ui->eqH1->setValue(50);
    ui->eqMH1->setValue(50);
    ui->eqM1->setValue(50);
    ui->eqML1->setValue(50);
    ui->eqL1->setValue(50);
}

// Pitch Shifter
void MainWindow::on_pitch_shifter1_valueChanged(int value)
{
    float psf = (float) value;
    channel1.set_pitch_shift_factor(psf/50);
}


void MainWindow::on_reset_pitchshift1_clicked()
{
    channel1.reset_pitch_shifting();
    ui->pitch_shifter1->setValue(50);
}


// Echo
void MainWindow::on_echo1_gain_valueChanged(int value)
{
    float e_g = (float) value;
    channel1.set_echo_gain(e_g/50);
}

void MainWindow::on_echo1_delay_valueChanged(int value)
{
    float e_d = (float) value;
    channel1.set_echo_delay(e_d/50);
}

void MainWindow::on_echo1_num_currentIndexChanged(int index)
{
    channel1.set_echo_num(index);
}

void MainWindow::on_echo1_reset_clicked()
{
    channel1.reset_echo();
    ui->echo1_delay->setValue(50);
    ui->echo1_gain->setValue(50);
    // ui->echo1_num->set;
}

//
void MainWindow::on_trem1_amp_valueChanged(int value)
{
    float tr_a = (float) value;
    channel1.set_trem_gain(tr_a/50);
}

void MainWindow::on_trem1_freq_valueChanged(int value)
{
    float tr_d = (float) value;
    channel1.set_trem_freq(tr_d/10);
}

void MainWindow::on_trem1_reset_clicked()
{
    channel1.reset_trem();
    ui->trem1_amp->setValue(50);
    ui->trem1_freq->setValue(1);
}


