#include "fx_var.h"

fx_var::fx_var()
{
    volume = 0.5;
    filt_gain_1 = 1;
    filt_gain_2 = 1;
    filt_gain_3 = 1;
    filt_gain_4 = 1;
    filt_gain_5 = 1;

	trem_toggle = -1;

    echo_delay = 0;
    echo_gain = 1;
    echo_num = 1;

    trem_gain = 1;
    trem_freq = 1;

    pitch_shift_factor = 1;
}
fx_var::fx_var(float vol, float gain1, float gain2, float gain3, float gain4, float gain5, float echo_d, float echo_g, float trem_g, float trem_t, float trem_f, float pitch_f)
{
    volume = vol;
    filt_gain_1 = gain1;
    filt_gain_2 = gain2;
    filt_gain_3 = gain3;
    filt_gain_4 = gain4;
    filt_gain_5 = gain5;

	trem_toggle = trem_t;

    echo_delay = echo_d;
    echo_gain = echo_g;

    trem_gain = trem_g;
    trem_freq = trem_f;

    pitch_shift_factor = pitch_f;
}

float fx_var::get_volume()
{
    return volume;
}
void fx_var::set_volume(float x)
{
    volume = x;
}

void fx_var::set_trem_toggle()
{
	trem_toggle = trem_toggle * -1; 
}

float fx_var::get_trem_toggle()
{
	return trem_toggle;
}


float fx_var::get_fgain_1()
{
    return filt_gain_1;
}
float fx_var::get_fgain_2()
{
    return filt_gain_2;
}
float fx_var::get_fgain_3()
{
    return filt_gain_3;
}
float fx_var::get_fgain_4()
{
    return filt_gain_4;
}
float fx_var::get_fgain_5()
{
    return filt_gain_5;
}


void fx_var::set_fgain_1(float x)
{
    filt_gain_1 = x;
}
void fx_var::set_fgain_2(float x)
{
    filt_gain_2 = x;
}
void fx_var::set_fgain_3(float x)
{
    filt_gain_3 = x;
}
void fx_var::set_fgain_4(float x)
{
    filt_gain_4 = x;
}
void fx_var::set_fgain_5(float x)
{
    filt_gain_5 = x;
}

float fx_var::get_echo_delay()
{
    return echo_delay;
}
void fx_var::set_echo_delay(float x)
{
    echo_delay = x;
}

float fx_var::get_echo_gain()
{
    return echo_gain;
}
void fx_var::set_echo_gain(float x)
{
    echo_gain = x;
}

int fx_var::get_echo_num()
{
    return echo_num;
}
void fx_var::set_echo_num(int x)
{
    echo_num = x;
}

float fx_var::get_trem_gain()
{
    return trem_gain;
}
void fx_var::set_trem_gain(float x)
{
    trem_gain = x;
}

float fx_var::get_trem_freq()
{
    return trem_freq;
}
void fx_var::set_trem_freq(float x)
{
    trem_freq = x;
}

float fx_var::get_pitch_shift_factor()
{
    return pitch_shift_factor;
}
void fx_var::set_pitch_shift_factor(float x)
{
    pitch_shift_factor = x;
}

void fx_var::initial()
{
    volume = 0.5;
    filt_gain_1 = 1;
    filt_gain_2 = 1;
    filt_gain_3 = 1;
    filt_gain_4 = 1;
    filt_gain_5 = 1;

    echo_delay = 0;
    echo_num = 1;
    echo_gain = 1;

    trem_gain = 1;
    trem_freq = 1;
	trem_toggle = -1;

    pitch_shift_factor = 1;
}

void fx_var::mute()
{
    set_volume(0);
}

void fx_var::reset_eq()
{
    set_fgain_1(1);
    set_fgain_2(1);
    set_fgain_3(1);
    set_fgain_4(1);
    set_fgain_5(1);
}

void fx_var::reset_trem()
{
    set_trem_gain(1);
    set_trem_freq(1);
	trem_toggle = -1;
}

void fx_var::reset_pitch_shifting()
{
    set_pitch_shift_factor(1);
}
void fx_var::reset_echo()
{
    set_echo_delay(1);
    set_echo_gain(1);
    set_echo_num(1);
}

//void fx_var::reset_distortion()
//{
//    set_distortion(1);
//}


/*
fx_var::~fx_var()
{
}
*/
