#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <math.h>
#include <omp.h>
#include "hr_time.h"
#define PSKEL_MPPA
#define MPPA_SLAVE
#define DEBUG
// #define PRINT_OUT
// #define TIME_EXEC
// #define TIME_SEND
#define BARRIER_SYNC_MASTER "/mppa/sync/128:1"
#define BARRIER_SYNC_SLAVE "/mppa/sync/[0..15]:2"
#define INPUT(x, y, w, h)\
				input[(y+w)*4 + (x+h)]
// #include "../../../include/PSkel.h"

using namespace std;
// using namespace PSkel;

struct Arguments
{
	int externCircle;
	int internCircle;
	float power;
};

// namespace PSkel{
void stencilKernel(int* input,int* output,int* mask, int size_mask, Arguments arg, size_t h, size_t w){
	int level = 1;
	int numberA = 0;
	int numberI = 0;
	int auxH = h;
	int auxW = w;
	// for (int z = 0; z < size_mask; z++) {
	// int count = 0;
	// for (int x = (level-2*level); x <= level; x++) {
	// 	for (int y = (level-2*level); y <= level; y++) {
	// 		if (x != 0 || y != 0) {
	// 				//mask.set(count, x, y);
	// 				numberA += input[(y+w)*128+(x+h)];
	// 				count++;
	// 		}
	// 	}
	// }
	// for (int x = (2*level-4*level); x <= 2*level; x++) {
	// 	for (int y = (2*level-4*level); y <= 2*level; y++) {
	// 		if (x != 0 || y != 0) {
	// 			if (!(x <= level && x >= -1*level && y <= level && y >= -1*level)) {
	// 				//mask.set(count, x, y);
	// 				numberI += input[(y+w)*128+(x+h)];
	// 				count++;
	// 			}
	// 		}
	// 	}
	// }
	// }
	// numberA += input[(-1+w)*128+(-1+h)];
	// numberA += input[(0+w)*128+(-1+h)];
	// numberA += input[(1+w)*128+(-1+h)];
	// numberA += input[(-1+w)*128+(0+h)];
	// numberA += input[(1+w)*128+(0+h)];
	// numberA += input[(-1+w)*128+(1+h)];
	// numberA += input[(0+w)*128+(1+h)];
	// numberA += input[(1+w)*128+(1+h)];

	numberA += INPUT(-1, -1, w, h);
	numberA += INPUT(-1, 0, w, h);
	numberA += INPUT(-1, 1, w, h);
	numberA += INPUT(0, -1, w, h);
	numberA += INPUT(0, 1, w, h);
	numberA += INPUT(1, -1, w, h);
	numberA += INPUT(1, 0, w, h);
	numberA += INPUT(1, 1, w, h);


	// numberI += input[(-2+w)*128+(-2+h)];
	// numberI += input[(-1+w)*128+(-2+h)];
	// numberI += input[(0+w)*128+(-2+h)];
	// numberI += input[(1+w)*128+(-2+h)];
	// numberI += input[(2+w)*128+(-2+h)];
	// numberI += input[(-2+w)*128+(-1+h)];
	// numberI += input[(2+w)*128+(-1+h)];
	// numberI += input[(2+w)*128+(0+h)];
	// numberI += input[(2+w)*128+(0+h)];
	// numberI += input[(2+w)*128+(1+h)];
	// numberI += input[(2+w)*128+(1+h)];
	// numberI += input[(-2+w)*128+(2+h)];
	// numberI += input[(-1+w)*128+(2+h)];
	// numberI += input[(0+w)*128+(2+h)];
	// numberI += input[(1+w)*128+(2+h)];
	// numberI += input[(2+w)*128+(2+h)];

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
	#ifdef DEBUG
	cout << "Slave Begin!" << endl;
	hr_timer_t totTimerSlave;
	hrt_start(&totTimerSlave);
	#endif
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

	int nb_tiles = atoi(argv[0]);
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int cluster_id = atoi(argv[3]);
	int nb_threads = atoi(argv[4]);
	int iterations = atoi(argv[5]);
	int outteriterations = atoi(argv[6]);
	int itMod = atoi(argv[7]);
	

	int subIterations = 1;
	int h = 128;
	int w = 128;
	int d = 1;

	// tmp.mppaAlloc(w,h,d);
	int* tmp = (int*) malloc((h*w)*sizeof(int*));



		// inputTmp.mppaAlloc(w,h,d);
	int* inputTmp = (int*) calloc(h*w, sizeof(int*));
	// inputTmp[0] = 0;
	// inputTmp[1] = 1;
	// inputTmp[2] = 0;
	// inputTmp[3] = 1;
	// inputTmp[4] = 0;
	// inputTmp[5] = 0;
	// inputTmp[6] = 0;
	// inputTmp[7] = 0;
	// inputTmp[8] = 1;
	// inputTmp[9] = 0;
	// inputTmp[10] = 1;
	// inputTmp[11] = 0;
	// inputTmp[12] = 1;
	// inputTmp[13] = 1;
	// inputTmp[14] = 1;
	// inputTmp[15] = 0;
	// outputTmp.mppaAlloc(w,h,d);
	int* outputTmp = (int*) calloc(h*w, sizeof(int*));
	#ifdef DEBUG
		cout << "Arrays allocated" << endl;
	#endif


	// this->runIterativeMPPA(inputTmp, outputTmp, subIterations, nb_threads);

	omp_set_num_threads(16);
	#pragma omp parallel for
	for (int h = 0; h < 128; h++){
	for (int w = 0; w < 128; w++){
		stencilKernel(inputTmp,outputTmp, mask, size, arg, h, w);
	}}

	// Array fTmp;

	// tmp.mppaFree();
	// tmp.auxFree();

	// inputTmp.mppaFree();
	// inputTmp.auxFree();

	// outputTmp.mppaFree();
	// outputTmp.auxFree();
	#ifdef DEBUG
	hrt_stop(&totTimerSlave);
	cout<<"Slave Time: " << hrt_elapsed_time(&totTimerSlave) << endl;
	#endif
	// mppa_exit(0);
	return 0;
}
