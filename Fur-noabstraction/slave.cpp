#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <math.h>
#include <omp.h>
#include "interface_mppa.h"

#define PSKEL_MPPA
#define MPPA_SLAVE
//#define DEBUG

#define BARRIER_SYNC_MASTER "/mppa/sync/128:1"
#define BARRIER_SYNC_SLAVE "/mppa/sync/[0..15]:2"


#define HEIGHT 128
#define WIDTH 128
//#define ITERATIONS 1000

#define INPUT(x, y, w, h) input[(y+w)*WIDTH + (x+h)]

using namespace std;

struct Arguments
{
	int externCircle;
	int internCircle;
	float power;
};

void stencilKernel(int* input,int* output,int* mask, int size_mask, Arguments arg, size_t h, size_t w){
	int numberA = 0;
	int numberI = 0;

	numberA += INPUT(-1, -1, w, h);
	numberA += INPUT(-1, 0, w, h);
	numberA += INPUT(-1, 1, w, h);
	numberA += INPUT(0, -1, w, h);
	numberA += INPUT(0, 1, w, h);
	numberA += INPUT(1, -1, w, h);
	numberA += INPUT(1, 0, w, h);
	numberA += INPUT(1, 1, w, h);

	numberI += INPUT(-2, -2, w, h);
	numberI += INPUT(-2, -1, w, h);
	numberI += INPUT(-2, 0, w, h);
	numberI += INPUT(-2, 1, w, h);
	numberI += INPUT(-2, 2, w, h);
	numberI += INPUT(-1, -2, w, h);
	numberI += INPUT(-1, 2, w, h);
	numberI += INPUT(0, 2, w, h);
	numberI += INPUT(0, 2, w, h);
	numberI += INPUT(1, 2, w, h);
	numberI += INPUT(1, 2, w, h);
	numberI += INPUT(2, -2, w, h);
	numberI += INPUT(2, -1, w, h);
	numberI += INPUT(2, 0, w, h);
	numberI += INPUT(2, 1, w, h);
	numberI += INPUT(2, 2, w, h);

	
	float totalPowerI = numberI*(arg.power);// The power of Inhibitors
	if(numberA - totalPowerI < 0) {
		output[h+w] = 0; //without color and inhibitor
	} else if(numberA - totalPowerI > 0) {
		output[h+w] = 1;//with color and active
	} else {
		output[h+w] = input[h+w];//doesn't change
		}
}


int CalcSize(int level){
	if (level == 1) {
		return 3;
	}
	if (level >= 1) {
		return CalcSize(level-1) + 2;
	}
	return 0;
}


int main(int argc,char **argv) {

	/**************Mask for test porpuses****************/
	int level = 1;
	int power = 2;
	int internCircle = pow(CalcSize(level), 2) - 1;
	int externCircle = pow(CalcSize(2*level), 2) - 1 - internCircle;
	int size = internCircle + externCircle;
	//Mask2D<int> mask(size);
	int mask[size];

	/*************************************************/

	/*********************Arg************************/
	Arguments arg;
	arg.power = power;
	arg.internCircle = internCircle;
	arg.externCircle = externCircle;
	/***********************************************/
	
	int* tmp = (int*) malloc((HEIGHT*WIDTH)*sizeof(int));
	assert(tmp != NULL);

	int* inputTmp = (int*) calloc(HEIGHT*WIDTH, sizeof(int));
	assert(inputTmp != NULL);

	int* outputTmp = (int*) calloc(HEIGHT*WIDTH, sizeof(int));
	assert(outputTmp != NULL);

	#ifdef DEBUG
		cout << "Arrays allocated" << endl;
	#endif

	omp_set_num_threads(16);
	
	for (unsigned long int it = 0; it < ITERATIONS; it++) {
		#pragma omp parallel for
		for (int h = 0; h < HEIGHT; h++){
		  for (int w = 0; w < WIDTH; w++){
		    stencilKernel(inputTmp,outputTmp, mask, size, arg, h, w);
	    }}
	}
	return 0;
}
