#pragma once

class fx_var
{
    float volume;

    float filt_gain_1;
    float filt_gain_2;
    float filt_gain_3;
    float filt_gain_4;
    float filt_gain_5;

	float trem_toggle;

    /*Echo variables*/
    float echo_delay;
    int echo_num;
    float echo_gain; // <1 for diminishing volume

                           /*Tremolo variables*/
    float trem_gain; //Sinusoidal amplitude
    float trem_freq; //Sinusoidal frequency


                         /*Pitch Shifting variables*/
    float pitch_shift_factor; //Frequency factor (multiply)

                                  /*Vibrato*/
    float pitch_gain; //Sinusoidal amplitude
    int pitch_freq; //Sinusoidal frequency
public:
    fx_var();
    fx_var(float vol, float gain1, float gain2, float gain3, float gain4, float gain5, float echo_d, float echo_g, float trem_g, float trem_t, float trem_freq, float pitch_f);
    float get_volume();
    void set_volume(float x);

    float get_fgain_1();
    float get_fgain_2();
    float get_fgain_3();
    float get_fgain_4();
    float get_fgain_5();

    void set_fgain_1(float x);
    void set_fgain_2(float x);
    void set_fgain_3(float x);
    void set_fgain_4(float x);
    void set_fgain_5(float x);

    float get_echo_delay();
    void set_echo_delay(float x);

    float get_echo_gain();
    void set_echo_gain(float x);

    int get_echo_num();
    void set_echo_num(int x);

    float get_trem_gain();
    void set_trem_gain(float x);

	void set_trem_toggle();
	float get_trem_toggle();

    float get_trem_freq();
    void set_trem_freq(float x);

    float get_pitch_shift_factor();
    void set_pitch_shift_factor(float x);

    void initial();

    void mute();
    void reset_eq();
    void reset_trem();
    void reset_pitch_shifting();
    void reset_echo();
//    void reset_distortion();


};

