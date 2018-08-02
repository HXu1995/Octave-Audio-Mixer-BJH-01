#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#ifdef WIN32
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <fstream>
#include <time.h>
#include <cmath>

#include "portaudio\include\portaudio.h"

#include "dll\doFilterf2k6k\doFilterf2k6k.h"
#include "dll\doFilterf2k6k\doFilterf2k6k_initialize.h"
#include "dll\doFilterf2k6k\doFilterf2k6k_terminate.h"

#include "dll\doFilterf6k22k\doFilterf6k22k.h"
#include "dll\doFilterf6k22k\doFilterf6k22k_initialize.h"
#include "dll\doFilterf6k22k\doFilterf6k22k_terminate.h"

#include "dll\doFilterf2502k\doFilterf2502k.h"
#include "dll\doFilterf2502k\doFilterf2502k_initialize.h"
#include "dll\doFilterf2502k\doFilterf2502k_terminate.h"

#include "dll\doFilterf60250\doFilterf60250.h"
#include "dll\doFilterf60250\doFilterf60250_initialize.h"
#include "dll\doFilterf60250\doFilterf60250_terminate.h"

#include "dll\doFilterf060\doFilterf060.h"
#include "dll\doFilterf060\doFilterf060_initialize.h"
#include "dll\doFilterf060\doFilterf060_terminate.h"

#include "effects\trem_scr\trem_scr.h"
#include "effects\trem_scr\trem_scr_initialize.h"
#include "effects\trem_scr\trem_scr_terminate.h"

#include "LPF/LowPassFilter.hpp"
#include "LPF/LowPassFilter.cpp"

#include "fx_var.h"
//#include "fx_var.cpp"

using namespace std;
#define SAMPLE_RATE       (44100) 
#define FRAMES_PER_BUFFER   (512)
#define NUM_SECONDS          (180) //Not needed, used to limit the end of audio recording, this project uses continuous recording
#define PA_SAMPLE_TYPE  paFloat32
#define SAMPLE_SIZE (4)
#define SAMPLE_SILENCE  (0.0f)
#define PRINTF_S_FORMAT "%.8f"

fx_var varobj;
fx_var* varobjptr;



float * read_buffer(char *buffer1)
{
	float new_array[FRAMES_PER_BUFFER];
	char* buffpnter = buffer1;
	for (int x = 0; x < 2048 / 4; x++)
	{
		new_array[x] = (float)*buffpnter;
		buffpnter += 3;
	}
	return new_array;
}

void gain_mod(float *sample, float gain)
{
	for (int x = 0; x < FRAMES_PER_BUFFER; x++)
	{
		sample[x] = sample[x] * gain;
	}
}

void audio_add(float *output, float *sample1, float *sample2, float *sample3, float *sample4, float *sample5)
{
	for (int x = 0; x < FRAMES_PER_BUFFER; x++)
	{
		output[x] = (sample1[x] + sample2[x] + sample3[x] + sample4[x] + sample5[x])/5;
	}
}

void array_copy(float *input, float *output)
{
	for (int x = 0; x < FRAMES_PER_BUFFER; x++)
	{
		output[x] = input[x];
	}
}

void master_volume(float *input, float volume)
{
	for (int x = 0; x < FRAMES_PER_BUFFER; x++)
	{
		input[x] = volume * input[x];
	}
}

void print_txt(float *data, ofstream& txt_file)
{
	for (int x = 0; x < FRAMES_PER_BUFFER; x++)
	{
		txt_file << data[x] << " ";
	}
}

clock_t test_trem(float *data, clock_t start_timer, clock_t tend_timer, float freq, float gain)
{
	for (int i = 0; i < FRAMES_PER_BUFFER; i++)
	{
		//cout << clock() - start_timer << "\n";
		//  Current Time - (Delay between cycles) - start time
		//cout << ((clock() - (clock() - tend_timer) - start_timer) / 1000) << "\n";
		data[i] = ((float)cos(6.28318548F * freq * ((clock() - (clock() - tend_timer) - start_timer) / CLOCKS_PER_SEC)) * data[i]);
	}
	tend_timer = clock();
	return tend_timer;
}

void echo_fx(float *input, float *output, float *echo_buffer, float echo_delay, float echo_gain) //echo effect with 3 seconds buffer 
{
	int start_sample = echo_delay * SAMPLE_RATE;
	for (int x = 0; x < FRAMES_PER_BUFFER; x++) //setting the current input block into the buffer
	{
		echo_buffer[x] += input[x];
	}
	for (int x = 0; x < 132300 - start_sample; x++) //adding the echo to buffer
	{
		if (x + start_sample<132300)
		{
			echo_buffer[x + start_sample] = (echo_buffer[x + start_sample] + echo_gain * echo_buffer[x]) / 2;
		}
	}
	for (int x = 0; x < FRAMES_PER_BUFFER; x++) //setting the output as the first FRAMES_PER_BUFFER samples of buffer
	{
		output[x] = echo_buffer[x];

	}
	for (int x = FRAMES_PER_BUFFER; x < 132300; x++)
	{
		echo_buffer[x - FRAMES_PER_BUFFER] = echo_buffer[x];
	}
	for (int x = 132300 - FRAMES_PER_BUFFER; x < 132300; x++)
	{
		echo_buffer[x] = 0;
	}
}

void resample(float *input, float *output, int L, int M)
{
	float *extend_array = (float *)malloc((FRAMES_PER_BUFFER * (L - 1)) + FRAMES_PER_BUFFER);
	int j = 0;
	for (int x = 0; x < FRAMES_PER_BUFFER; x++)
	{
		extend_array[j] = input[x];
		j++;
		for (int y = 0; y < L - 1; y++)
		{
			extend_array[j] = 0;
			j++;
		}
	}
	LowPassFilter lpf(L / (2 * 3.141592));
	float *filt_extend_array = (float *)malloc((FRAMES_PER_BUFFER * (L - 1)) + FRAMES_PER_BUFFER);
	for (int x = 0; x < ((FRAMES_PER_BUFFER * (L - 1)) + FRAMES_PER_BUFFER); x++)
	{
		filt_extend_array[x] = lpf.update(extend_array[x]);
		if (x % M == 0 && x >= M)
		{
			output[x / M] = filt_extend_array[x];
		}
	}
	free(extend_array);
	free(filt_extend_array);
}

void SOLA(float factor, float *input, float *output)
{
	float *split_array_1 = (float *)malloc(FRAMES_PER_BUFFER / 4);
	float *split_array_2 = (float *)malloc(FRAMES_PER_BUFFER / 4);
	float *split_array_3 = (float *)malloc(FRAMES_PER_BUFFER / 4);
	float *split_array_4 = (float *)malloc(FRAMES_PER_BUFFER / 4);
	for (int x = 0; x < FRAMES_PER_BUFFER / 4; x++) //splitting array
	{
		split_array_1[x] = input[x];
		split_array_2[x] = input[x + (FRAMES_PER_BUFFER / 4)];
		split_array_3[x] = input[x + 2 * (FRAMES_PER_BUFFER / 4)];
		split_array_3[x] = input[x + 3 * (FRAMES_PER_BUFFER / 4)];
	}

	float *scaled_split_array_1 = (float *)malloc((FRAMES_PER_BUFFER / 4)*factor);
	float *scaled_split_array_2 = (float *)malloc((FRAMES_PER_BUFFER / 4)*factor);
	float *scaled_split_array_3 = (float *)malloc((FRAMES_PER_BUFFER / 4)*factor);
	float *scaled_split_array_4 = (float *)malloc((FRAMES_PER_BUFFER / 4)*factor);

	int j = 0;
	for (int x = 0; x < FRAMES_PER_BUFFER / 4; x++) //scaling by adding 0
	{
		scaled_split_array_1[j] = split_array_1[x];
		scaled_split_array_2[j] = split_array_2[x];
		scaled_split_array_3[j] = split_array_3[x];
		scaled_split_array_4[j] = split_array_4[x];
		j++;
		for (int y = 0; y < factor - 1; y++)
		{
			scaled_split_array_1[j] = 0;
			scaled_split_array_2[j] = 0;
			scaled_split_array_3[j] = 0;
			scaled_split_array_4[j] = 0;
			j++;
		}
	}
	//interpolation 
	LowPassFilter lpf2205(SAMPLE_RATE / (2 * 3.141592));
	for (int x = 0; x < (FRAMES_PER_BUFFER / 4) * factor; x++)
	{
		scaled_split_array_1[x] = lpf2205.update(scaled_split_array_1[x]);
		scaled_split_array_2[x] = lpf2205.update(scaled_split_array_2[x]);
		scaled_split_array_3[x] = lpf2205.update(scaled_split_array_3[x]);
		scaled_split_array_4[x] = lpf2205.update(scaled_split_array_4[x]);
	}

	//cross correlation
	int km1 = 0;
	float rmax1 = 0;
	int km2 = 0;
	float rmax2 = 0;
	int km3 = 0;
	float rmax3 = 0;
	for (int x = 0; x < 32; x++)
	{
		float rm1 = 0;
		float rm2 = 0;
		float rm3 = 0;
		for (int y = 0; y < 32 - x - 1; y++)
		{
			rm1 += scaled_split_array_1[y] * scaled_split_array_2[y + x];
			rm2 += scaled_split_array_2[y] * scaled_split_array_3[y + x];
			rm3 += scaled_split_array_3[y] * scaled_split_array_4[y + x];

			if (rm1 > rmax1)
			{
				rmax1 = rm1;
				km1 = x;
			}
			if (rm2 > rmax2)
			{
				rmax2 = rm2;
				km2 = x;
			}
			if (rm3 > rmax3)
			{
				rmax3 = rm3;
				km3 = x;
			}
		}
	}
	//fading out
	for (int x = ((FRAMES_PER_BUFFER / 4)*factor) - km1; x < (FRAMES_PER_BUFFER / 4) *factor; x++)
	{
		scaled_split_array_1[x] = (((-1 / km1) * (x - (((FRAMES_PER_BUFFER / 4)*factor) - km1))) + 1) * scaled_split_array_1[x];
	}

	for (int x = ((FRAMES_PER_BUFFER / 4)*factor) - km2; x < (FRAMES_PER_BUFFER / 4) *factor; x++)
	{
		scaled_split_array_2[x] = (((-1 / km2) * (x - (((FRAMES_PER_BUFFER / 4)*factor) - km2))) + 1) * scaled_split_array_2[x];
	}
	for (int x = ((FRAMES_PER_BUFFER / 4)*factor) - km3; x < (FRAMES_PER_BUFFER / 4) *factor; x++)
	{
		scaled_split_array_3[x] = (((-1 / km3) * (x - (((FRAMES_PER_BUFFER / 4)*factor) - km3))) + 1) * scaled_split_array_3[x];
	}

	//fading in
	for (int x = 0; x < ((FRAMES_PER_BUFFER / 4)*factor) - km1; x++)
	{
		scaled_split_array_2[x] = (1 / (((FRAMES_PER_BUFFER / 4)*factor) - km1) * x) * scaled_split_array_2[x];
	}
	for (int x = 0; x < ((FRAMES_PER_BUFFER / 4)*factor) - km2; x++)
	{
		scaled_split_array_3[x] = (1 / (((FRAMES_PER_BUFFER / 4)*factor) - km2) * x) * scaled_split_array_3[x];
	}
	for (int x = 0; x < ((FRAMES_PER_BUFFER / 4)*factor) - km3; x++)
	{
		scaled_split_array_4[x] = (1 / (((FRAMES_PER_BUFFER / 4)*factor) - km3) * x) * scaled_split_array_4[x];
	}

	//adding the sections
	float *summed_array = (float *)malloc((512 * factor) - 96);
	for (int x = 0; x < (FRAMES_PER_BUFFER / 4) * factor; x++)
	{
		if (x >= (FRAMES_PER_BUFFER / 4 * factor) - 32)
		{
			summed_array[x] = scaled_split_array_1[x] + scaled_split_array_2[(int)(x - ((FRAMES_PER_BUFFER / 4 * factor) - 32))];
		}
		else
		{
			summed_array[x] = scaled_split_array_1[x];
		}
	}
	for (int x = 0; x < ((FRAMES_PER_BUFFER / 4) * factor) - 32; x++)
	{
		if (x >= (FRAMES_PER_BUFFER / 4 * factor) - 32)
		{
			summed_array[(int)(((FRAMES_PER_BUFFER / 4)*factor) + x - 32)] = scaled_split_array_2[x + 32] + scaled_split_array_3[(int)(x - ((FRAMES_PER_BUFFER / 4 * factor) - 32))];
		}
		else
		{
			summed_array[(int)(((FRAMES_PER_BUFFER / 4)*factor) + x - 32)] = scaled_split_array_2[x + 32];
		}
	}
	for (int x = 0; x < ((FRAMES_PER_BUFFER / 4) * factor) - 32; x++)
	{
		if (x >= (FRAMES_PER_BUFFER / 4 * factor) - 32)
		{
			summed_array[(int)(2 * ((FRAMES_PER_BUFFER / 4)*factor) + x - 64)] = scaled_split_array_3[x + 32] + scaled_split_array_4[(int)(x - ((FRAMES_PER_BUFFER / 4 * factor) - 32))];
		}
		else
		{
			summed_array[(int)(2 * ((FRAMES_PER_BUFFER / 4)*factor) + x - 64)] = scaled_split_array_3[x + 32];
		}
	}
	for (int x = 32; x < ((FRAMES_PER_BUFFER / 4) * factor); x++)
	{
		summed_array[(int)(3 * ((FRAMES_PER_BUFFER / 4)*factor) + x - 96)] = scaled_split_array_4[x];
	}
	free(split_array_1);
	free(split_array_2);
	free(split_array_3);
	free(split_array_4);
	free(scaled_split_array_1);
	free(scaled_split_array_2);
	free(scaled_split_array_3);
	free(scaled_split_array_4);
	free(summed_array);

}
void pitch_shift(float pitch_shift_factor, float *input, float *output)
{
	float resampledBlock[FRAMES_PER_BUFFER] = { 0 };
	//resample(input, resampledBlock, 3,2);
	SOLA(1.5, input, output);
}

static int start_fx(MainWindow& w, PaDeviceIndex inputdevicenum) 
{
	/*Generating device parameters for PortAudio streams,
	all variable types and functions starting with Pa is PortAudio defined*/
	PaStreamParameters inputParameters, outputParameters; //Define input output devices, can add more devices here
	PaStream *stream = NULL; //Data streaming pointer
	PaError err; //PortAudio stream
	const PaDeviceInfo* inputInfo; //Input device info
	const PaDeviceInfo* outputInfo; //Output device info

	int i;
	int numBytes; //Number of bytes used for memory allocation of the sampleBlock
	int numChannels; //number of channels determined by the input and output devices, used for memory allocation
	clock_t start_timer;
	clock_t tend_timer;


	doFilterf2k6k_initialize();
	doFilterf6k22k_initialize();
	doFilterf2502k_initialize();
	doFilterf60250_initialize();
	doFilterf060_initialize();



	//echo_scr_initialize();
	//trem_scr_initialize();
	/*
	ofstream infile1, infile2, infile3, infile4, infile5, infileo;
	infile1.open("f060.txt");
	infile2.open("f60250.txt");
	infile3.open("f2502k.txt");
	infile4.open("f2k6k.txt");
	infile5.open("f6k22k.txt");
	infileo.open("original.txt");
	*/
	//err = Pa_Initialize(); //Initialize the Pa stream
	//if (err != paNoError) goto error2;

	//Define input device
	inputParameters.device = inputdevicenum; /* System default input device */
	printf("Input device # %d.\n", inputParameters.device);
	inputInfo = Pa_GetDeviceInfo(inputParameters.device);
	// Print the device name and input latency info
	printf("    Name: %s\n", inputInfo->name);
	//printf("      LL: %g s\n", inputInfo->defaultLowInputLatency);
	//printf("      HL: %g s\n", inputInfo->defaultHighInputLatency);
	

	//Define output device
	outputParameters.device = Pa_GetDefaultOutputDevice(); /* System default output device */
	printf("Output device # %d.\n", outputParameters.device);
	outputInfo = Pa_GetDeviceInfo(outputParameters.device);
	
	printf("   Name: %s\n", outputInfo->name);
	//printf("     LL: %g s\n", outputInfo->defaultLowOutputLatency);
	//printf("     HL: %g s\n", outputInfo->defaultHighOutputLatency);
	

	numChannels = 1; /*inputInfo->maxInputChannels < outputInfo->maxOutputChannels //if maxInputChannel<maxOutputChannel
					 ? inputInfo->maxInputChannels : outputInfo->maxOutputChannels; */ //then numChannels=maxInputChannels, else =maxOutputChannels

	inputParameters.channelCount = 1;//numChannels; //Setting the number of channels
	inputParameters.sampleFormat = PA_SAMPLE_TYPE; //Setting the sample type, as defined above in the constants (PaFloat32)
	inputParameters.suggestedLatency = inputInfo->defaultLowInputLatency; //Default to low latency mode
	inputParameters.hostApiSpecificStreamInfo = NULL; //Api stream info for feeding audio from external software into Portaudio, not used

	outputParameters.channelCount = numChannels;
	outputParameters.sampleFormat = PA_SAMPLE_TYPE;
	outputParameters.suggestedLatency = outputInfo->defaultLowOutputLatency;
	outputParameters.hostApiSpecificStreamInfo = NULL;

	//Start audio stream, there are also flags that can be used, refer to portaudio.h line 653
	err = Pa_OpenStream(
		&stream,
		&inputParameters,
		&outputParameters,
		SAMPLE_RATE,
		FRAMES_PER_BUFFER,
		NULL,
		NULL, //No callback function causes Stream to run in read write block mode
		NULL); //no user data input to callback function
	if (err != paNoError) goto error2;

	numBytes = FRAMES_PER_BUFFER * numChannels * SAMPLE_SIZE; //Defining the number of bytes
															  //sampleBlock = (char *)malloc(numBytes); //Allocating memory, CONVERT THIS TO CUDA SHARED MEMORY
	float sampleBlock[FRAMES_PER_BUFFER] = { 0 };
	float modifiedBlock[FRAMES_PER_BUFFER] = { 0 };


	float echo_buffer[132300] = { 0 }; //10 seconds echo buffer
									   //float *echo_buffer = (float *)malloc(441000);
									   //memset(echo_buffer, SAMPLE_SILENCE, 441000);

	float filtBlock1[FRAMES_PER_BUFFER] = { 0 };
	float filtBlock2[FRAMES_PER_BUFFER] = { 0 };
	float filtBlock3[FRAMES_PER_BUFFER] = { 0 };
	float filtBlock4[FRAMES_PER_BUFFER] = { 0 };
	float filtBlock5[FRAMES_PER_BUFFER] = { 0 };

	if (sampleBlock == NULL || modifiedBlock == NULL)
	{
		printf("Could not allocate record array.\n");
		goto error1;
	}


	err = Pa_StartStream(stream); //Start stream
	if (err != paNoError) goto error1;

	/*
	while True()
	{
	//Look into CPU multithreading for having GUI Update and user input at the same time while processing audio
	//https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm
	//https://www.geeksforgeeks.org/multithreading-in-cpp/
	//ALLOW THE USER TO SET EFFECTS VARIABLES (KEYBOARD, OR CONTROLLER)
	//GUI UPDATES


	err = Pa_ReadStream(stream, sampleBlock, FRAMES_PER_BUFFER);
	if( err ) goto xrun;

	//---------------CUDA PROCESSING-----------------------------
	modifiedBlock = filterx(sampleBlock, filt_gain_x) + filterx()......; //Combined signal of filters
	cudasynchronize() //wait for all filters to finish before proceeding
	modifiedBlock = echo() + tremolo() + p_shift() + vibr(); //Combined signal after effects processing
	cudasynchronize()

	//Apply any audio smoothing or other algorithms here
	//-----------------------------------------------------------

	err = Pa_WriteStream( stream, modifedBlock, FRAMES_PER_BUFFER );
	if( err ) goto xrun;

	free(sampleBlock); //CONVERT TO CUDA
	free(modifedBlock);

	if (keyboard input, or close window) exit loop
	}
	Pa_Terminate();
	return 0

	*/

	printf("Wire on. "); fflush(stdout);
	start_timer = clock();
	tend_timer = clock();
	
	//for (i = 0; i<(NUM_SECONDS*SAMPLE_RATE) / FRAMES_PER_BUFFER; ++i)
	while(TRUE)
	{
		fx_var varobj = w.pass_var();
		// You may get underruns or overruns if the output is not primed by PortAudio.
		
		doFilterf060(sampleBlock, filtBlock1);
		doFilterf60250(sampleBlock, filtBlock2);
		doFilterf2502k(sampleBlock, filtBlock3);
		doFilterf2k6k(sampleBlock, filtBlock4);
		doFilterf6k22k(sampleBlock, filtBlock5);
		gain_mod(filtBlock1, varobj.get_fgain_1());
		gain_mod(filtBlock2, varobj.get_fgain_2());
		gain_mod(filtBlock3, varobj.get_fgain_3());
		gain_mod(filtBlock4, varobj.get_fgain_4());
		gain_mod(filtBlock5, varobj.get_fgain_5());
		audio_add(modifiedBlock, filtBlock1, filtBlock2, filtBlock3, filtBlock4, filtBlock5);
		
		//cout << "Current Time: " << clock() << " Trem End Timer: " << tend_timer << "\n";
		//tend_timer = test_trem(modifiedBlock, start_timer, tend_timer);

		if (varobj.get_trem_toggle() == 1)
		{
			tend_timer = test_trem(modifiedBlock, start_timer, tend_timer, varobj.get_trem_freq(), varobj.get_trem_gain());
		}
		echo_fx(modifiedBlock, modifiedBlock, echo_buffer, varobj.get_echo_delay(), varobj.get_echo_gain());
		master_volume(modifiedBlock, varobj.get_volume());

		//pitch_shift(1, sampleBlock, modifiedBlock);



		err = Pa_WriteStream(stream, modifiedBlock, FRAMES_PER_BUFFER);
		if (err) goto xrun;
		err = Pa_ReadStream(stream, sampleBlock, FRAMES_PER_BUFFER);

		if (err) goto xrun;
	}
	
	printf("Wire off.\n"); fflush(stdout);
	err = Pa_StopStream(stream);
	if (err != paNoError) goto error1;


	printf("Hit ENTER to stop program.\n");
	getchar();
	/*
	Pa_Terminate();
	infile1.close();
	infile2.close();
	infile3.close();
	infile4.close();
	infile5.close();
	infileo.close();
	*/
	doFilterf2k6k_terminate();
	doFilterf6k22k_terminate();
	doFilterf2502k_terminate();
	doFilterf60250_terminate();
	doFilterf060_terminate();

	//echo_scr_terminate();
	//trem_scr_terminate();
	return 0;
	//REMOVE ---------------------------------------------------------------------------
	/*Error functions, goto x, run x*/
xrun:
	printf("err = %d\n", err); fflush(stdout);
	if (stream) {
		Pa_AbortStream(stream);
		Pa_CloseStream(stream);
	}
	free(sampleBlock);
	Pa_Terminate();
	if (err & paInputOverflow)
		fprintf(stderr, "Input Overflow.\n");
	if (err & paOutputUnderflow)
		fprintf(stderr, "Output Underflow.\n");
	return -2;
error1:
	free(sampleBlock);
error2:
	if (stream) {
		Pa_AbortStream(stream);
		Pa_CloseStream(stream);
	}
	Pa_Terminate();
	fprintf(stderr, "An error occured while using the portaudio stream\n");
	fprintf(stderr, "Error number: %d\n", err);
	fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
	return -1;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow w, q;

	//w.setChannelTitle(title1);
	//fx_var varobj = w.pass_var();

	
	//------------------------------------------------------------ PRINT DEVICE LIST
	PaError err;
	int     i, numDevices, defaultDisplayed;
	const   PaDeviceInfo *deviceInfo;
	PaStreamParameters inputParameters, outputParameters;
	
	err = Pa_Initialize();
	if (err != paNoError)
	{
		printf("ERRORL Pa_Initialize returned 0x%08X\n", err);
		goto error;
	}

	//printf("PortAudio version: 0x%08X\n", Pa_GetVersion());
	//printf("Version text: '%s'\n", Pa_GetVersionInfo()->versionText);

	numDevices = Pa_GetDeviceCount();
	if (numDevices < 0)
	{
		printf("ERROR: Pa_GetDeviceCount returned 0x%x\n", numDevices);
		err = numDevices;
		goto error;
	}

	printf("Number of devices = %d\n", numDevices);
	for (i = 0; i < numDevices; i++)
	{
		deviceInfo = Pa_GetDeviceInfo(i);
		printf("--------------------------------------- device #%d\n", i);

		// Mark global and API specific default devices 
		defaultDisplayed = 0;
		if (i == Pa_GetDefaultInputDevice())
		{
			printf("[ Default Input");
			defaultDisplayed = 1;
		}
		else if (i == Pa_GetHostApiInfo(deviceInfo->hostApi)->defaultInputDevice)
		{
			const PaHostApiInfo *hostInfo = Pa_GetHostApiInfo(deviceInfo->hostApi);
			printf("[ Default %s Input", hostInfo->name);
			defaultDisplayed = 1;
		}

		if (i == Pa_GetDefaultOutputDevice())
		{
			printf((defaultDisplayed ? "," : "["));
			printf(" Default Output");
			defaultDisplayed = 1;
		}
		else if (i == Pa_GetHostApiInfo(deviceInfo->hostApi)->defaultOutputDevice)
		{
			const PaHostApiInfo *hostInfo = Pa_GetHostApiInfo(deviceInfo->hostApi);
			printf((defaultDisplayed ? "," : "["));
			printf(" Default %s Output", hostInfo->name);
			defaultDisplayed = 1;
		}

		if (defaultDisplayed)
			printf(" ]\n");

		// print device info fields 
#ifdef WIN32
		{   // Use wide char on windows, so we can show UTF-8 encoded device names 
			wchar_t wideName[MAX_PATH];
			MultiByteToWideChar(CP_UTF8, 0, deviceInfo->name, -1, wideName, MAX_PATH - 1);
			wprintf(L"Name                        = %s\n", wideName);
		}
#else
		printf("Name                        = %s\n", deviceInfo->name);
#endif
	}

	cout << "Enter the number of input channels (Max 2):\n";
	int numChannels;

	while (!(cin >> numChannels) || numChannels > 2)
	{
		cout << "Enter a valid value!\n";
		cin.clear();
	}
	PaStreamParameters inputdevices[2];
	PaDeviceIndex inputdevicevalue[2];
	for (int x = 0; x < numChannels; x++)
	{
		printf("Enter input device #: ");
		while (!(cin >> inputdevicevalue[x]) || inputdevicevalue[x] > numDevices)
		{
			cout << "Enter a valid value!\n";
			cin.clear();
		}
		inputdevices[x].device = inputdevicevalue[x];
	}
	
	if (numChannels ==2)
	{
		const PaDeviceInfo* input1info = Pa_GetDeviceInfo(inputdevices[0].device);
		QString title1 = input1info->name;
		const PaDeviceInfo* input2info = Pa_GetDeviceInfo(inputdevices[1].device);
		QString title2 = input1info->name;
		//MainWindow w;
		//MainWindow q;
		w.setChannelTitle(title1);
		q.setChannelTitle(title2);
		w.show();
		q.show();
		thread audio_fx(start_fx, ref(w), inputdevicevalue[0]);
		thread audio_fx2(start_fx, ref(q), inputdevicevalue[1]);
		audio_fx.detach();
		audio_fx2.detach();
	}
	
	else 
	{
	const PaDeviceInfo* input1info = Pa_GetDeviceInfo(inputdevices[0].device);
	QString title1 = input1info->name;
	//MainWindow w;
	w.setChannelTitle(title1);
	w.setWindowTitle(title1);
	w.show();
	thread audio_fx(start_fx, ref(w), inputdevicevalue[0]);
	audio_fx.detach();
		
		//start_fx(ref(w), inputdevicevalue[0]);
	}
	

	//inputParameters.device = inputdevicenum; /* System default input device */
	//printf("Input device # %d.\n", inputParameters.device);

	//-------------------------------------------------------------------------------------
	
	//QThread audio;
	//QObject::connect(&audio, SIGNAL(finished()), &a, SLOT(quit()));
	//audio.start();

	return a.exec();	
	//--------------------------------------------------------------------TEST
	
error:
	Pa_Terminate();
	fprintf(stderr, "Error number: %d\n", err);
	fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
	getchar();
	return err;
	
}
