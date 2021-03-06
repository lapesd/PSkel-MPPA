#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <math.h>
#include <omp.h>
#include "include/interface_mppa.h"
#include "include/PSkel.h"

#define PSKEL_MPPA
#define MPPA_SLAVE
//#define DEBUG

#define BARRIER_SYNC_MASTER "/mppa/sync/128:1"
#define BARRIER_SYNC_SLAVE "/mppa/sync/[0..15]:2"


#define HEIGHT 128
#define WIDTH 128

//#define ITERATIONS 1000

using namespace std;
using namespace PSkel;


struct Arguments
{
	int externCircle;
	int internCircle;
	float power;
};

void stencilKernel(Array2D<int> input,Array2D<int> output,Mask2D<int> mask, Arguments arg, size_t h, size_t w){
    int numberA = 0;
    int numberI = 0;
    // #define INPUT(x, y, w, h) input[(y+w)*WIDTH + (x+h)]

	numberA += input(w+(-1), h+(-1));
	numberA += input(w+(-1), h+0);
	numberA += input(w+(-1), h+1);
	numberA += input(w+0, h+(-1));
	numberA += input(w+0, h+1);
	numberA += input(w+1, h+(-1));
	numberA += input(w+1, h+0);
	numberA += input(w+1, h+1);

	numberI += input(w+(-2), h+(-2));
	numberI += input(w+(-2), h+(-1));
	numberI += input(w+(-2), h+0);
	numberI += input(w+(-2), h+1);
	numberI += input(w+(-2), h+2);
	numberI += input(w+(-1), h+(-2));
	numberI += input(w+(-1), h+2);
	numberI += input(w+0, h+2);
	numberI += input(w+0, h+2);
	numberI += input(w+1, h+2);
	numberI += input(w+1, h+2);
	numberI += input(w+2, h+(-2));
	numberI += input(w+2, h+(-1));
	numberI += input(w+2, h+0);
	numberI += input(w+2, h+1);
	numberI += input(w+2, h+2);

    //printf("A: %d\n", numberA);
    float totalPowerI = numberI*(arg.power);// The power of Inhibitors
    //printf("Power of I: %f\n", totalPowerI);
    if(numberA - totalPowerI < 0) {
		output(h,w) = 0; //without color and inhibitor
    } else if(numberA - totalPowerI > 0) {
		output(h,w) = 1;//with color and active
    } else {
		output(h,w) = input(h,w);//doesn't change
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
	 /**************Mask for test porpuses****************/
	int level = 1;
	int power = 2;
	int internCircle = pow(CalcSize(level), 2) - 1;
	int externCircle = pow(CalcSize(2*level), 2) - 1 - internCircle;
	int size = internCircle + externCircle;
	Mask2D<int> mask(size);
	int count = 0;
	for (int x = (level-2*level); x <= level; x++) {
		for (int y = (level-2*level); y <= level; y++) {
	  		if (x != 0 || y != 0) {
	      		mask.set(count, x, y);
	      		count++;
	  		}
		}
	}

	for (int x = (2*level-4*level); x <= 2*level; x++) {
		for (int y = (2*level-4*level); y <= 2*level; y++) {
	  		if (x != 0 || y != 0) {
	    		if (!(x <= level && x >= -1*level && y <= level && y >= -1*level)) {
	      			mask.set(count, x, y);
	      			count++;
	    		}
	  		}
		}
	}
	/*************************************************/

	/*********************Arg************************/
	Arguments arg;
	arg.power = power;
	arg.internCircle = internCircle;
	arg.externCircle = externCircle;
	/***********************************************/

	Array2D<int> input(WIDTH, HEIGHT);
	Array2D<int> output(WIDTH, HEIGHT);

	omp_set_num_threads(16);
	
	for (unsigned long int it = 0; it < ITERATIONS; it++) {
		#pragma omp parallel for
		for (int h = 0; h < HEIGHT; h++){
		  	for (int w = 0; w < WIDTH; w++){
	    		stencilKernel(input,output, mask, arg, h, w);
			}
		}
	}
	return 0;
}
