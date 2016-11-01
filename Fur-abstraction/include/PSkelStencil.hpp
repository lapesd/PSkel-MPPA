//-------------------------------------------------------------------------------
// Copyright (c) 2015, Alyson D. Pereira <alyson.deives@outlook.com>,
//					   Rodrigo C. O. Rocha <rcor.cs@gmail.com>
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//-------------------------------------------------------------------------------
// TILES: 32 64 128
// SIZE: 512 1024 2048
// ITERATIONS: 50
// CLUSTERS: 16
#ifndef PSKEL_STENCIL_HPP
#define PSKEL_STENCIL_HPP
//#define BARRIER_SYNC_MASTER "/mppa/sync/128:1"
//#define BARRIER_SYNC_SLAVE "/mppa/sync/[0..15]:2"
#include <cmath>
#include <algorithm>
#include <iostream>
#include "hr_time.h"

#include <iostream>
<<<<<<< HEAD
=======
<<<<<<< HEAD

using namespace std;
=======
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
#include <unistd.h>

using namespace std;
#ifdef PSKEL_CUDA
  #include <ga/ga.h>
  #include <ga/std_stream.h>
#endif
<<<<<<< HEAD
=======
>>>>>>> ee5501bdba3333d6dabd9b409c3bad5e35140a47
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76

#define ARGC_SLAVE 11

namespace PSkel{

#ifdef PSKEL_CUDA
//********************************************************************************************
// Kernels CUDA. Chama o kernel implementado pelo usuario
//********************************************************************************************

<<<<<<< HEAD
template<typename T1, typename T2, class Args>
__global__ void stencilTilingCU(Array<T1> input,Array<T1> output,Mask<T2> mask,Args args, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth);

template<typename T1, typename T2, class Args>
__global__ void stencilTilingCU(Array2D<T1> input,Array2D<T1> output,Mask2D<T2> mask,Args args, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth);

template<typename T1, typename T2, class Args>
__global__ void stencilTilingCU(Array3D<T1> input,Array3D<T1> output,Mask3D<T2> mask,Args args, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth);
=======
//template<typename T1, typename T2, class Args>
//__global__ void stencilTilingCU(Array<T1> input,Array<T1> output,Mask<T2> mask,Args args, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth);

//template<typename T1, typename T2, class Args>
//__global__ void stencilTilingCU(Array2D<T1> input,Array2D<T1> output,Mask2D<T2> mask,Args args, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth);

//template<typename T1, typename T2, class Args>
//__global__ void stencilTilingCU(Array3D<T1> input,Array3D<T1> output,Mask3D<T2> mask,Args args, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76


//********************************************************************************************
// Kernels CUDA. Chama o kernel implementado pelo usuario
//********************************************************************************************
<<<<<<< HEAD
=======
template<typename T>
struct SharedMemory
{
    // Should never be instantiated.
    // We enforce this at compile time.
    __device__ T* GetSharedPointer( void )
    {
        extern __device__ void error( void );
        error();
        return NULL;
    }
};

// specializations for types we use
template<>
struct SharedMemory<float>
{
   __device__ float* GetSharedPointer(){
  	extern __shared__ float sh_float[];    
        // printf( "sh_float=%p\n", sh_float );
        return sh_float;
    } 
};

template<>
struct SharedMemory<bool>
{
   __device__ bool* GetSharedPointer(){
  	extern __shared__ bool sh_bool[];    
        // printf( "sh_float=%p\n", sh_float );
        return sh_bool;
    } 
};


/*
__device__ size_t Tonvcc -O3 -gencode arch=compute_20,code=sm_20 -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=\"sm_35,compute_35\" -m64 -lineinfo -Xcompiler -ftree-vectorize -Xcompiler -march=native -Xcompiler -mtune=native -Xcompiler -O3  -o ../../bin/cloudsim_pskel_shared cloudsim_pskel.cu -Xcompiler -fopenmp -lgomp -I../../pskel/include -I/home/alyson/galib247/ -L/home/alyson/galib247/ga -lga -lm  -Xptxas -v --keep --keep-dir nvcc -DPSKEL_SHARED
GlobalRow( int gidRow, int lszRow, int lidRow ){
    return gidRow * lszRow + lidRow;
}

__device__ size_t ToGlobalCol( int gidCol, int lszCol, int lidCol ){
    return gidCol * lszCol + lidCol;
}

__device__ int ToFlatIdx( int row, int col, int rowWidth ){
    // assumes input coordinates and dimensions are logical (without halo)
    // and a halo width of 1
    return (row+1)*(rowWidth + 2) + (col+1);
}
*/

/*
template<typename T1, typename T2, class Args>
__global__ void StencilKernel(Array2D<T> input, Array2D<T> output, Args, args, int alignment, int nStripItems){
    // determine our location in the coordinate system
    // see the comment in operator() at the definition of the dimGrid
    // and dimBlock dim3s to understand why .x == row and .y == column.
    int gidRow = blockIdx.x;
    int gidCol = blockIdx.y;
    // int gszRow = gridDim.x;
    int gszCol = gridDim.y;
    int lidRow = threadIdx.x;
    int lidCol = threadIdx.y;
    int lszRow = nStripItems;
    int lszCol = blockDim.y;

    // determine our logical global data coordinates (without halo)
    int gRow = ToGlobalRow( gidRow, lszRow, lidRow );
    int gCol = ToGlobalCol( gidCol, lszCol, lidCol );

    // determine pitch of rows (without halo)
    int nCols = gszCol * lszCol + 2;     // assume halo is there for computing padding
    int nPaddedCols = nCols + (((nCols % alignment) == 0) ? 0 : (alignment - (nCols % alignment)));
    int gRowWidth = nPaddedCols - 2;    // remove the halo

    // Copy my global data item to a shared local buffer.
    // That local buffer is passed to us.
    // We assume it is large enough to hold all the data computed by
    // our thread block, plus a halo of width 1.
    SharedMemory<T> shobj;
    T* sh = shobj.GetPointer();
    int lRowWidth = lszCol;
    for( int i = 0; i < (lszRow + 2); i++ )
    {
        int lidx = ToFlatIdx( lidRow - 1 + i, lidCol, lRowWidth );
        int gidx = ToFlatIdx( gRow - 1 + i, gCol, gRowWidth );
        sh[lidx] = data[gidx];
    }

    // Copy the "left" and "right" halo rows into our local memory buffer.
    // Only two threads are involved (first column and last column).
    if( lidCol == 0 ){
        for( int i = 0; i < (lszRow + 2); i++ ){
            int lidx = ToFlatIdx(lidRow - 1 + i, lidCol - 1, lRowWidth );
            int gidx = ToFlatIdx(gRow - 1 + i, gCol - 1, gRowWidth );
            sh[lidx] = data[gidx];
        }
    } else if( lidCol == (lszCol - 1) ){
        for( int i = 0; i < (lszRow + 2); i++ ) {
            int lidx = ToFlatIdx(lidRow - 1 + i, lidCol + 1, lRowWidth );
            int gidx = ToFlatIdx(gRow - 1 + i, gCol + 1, gRowWidth );
            sh[lidx] = data[gidx];
        }
    }

    // let all those loads finish
    __syncthreads();

    // do my part of the smoothing operation
    for( int i = 0; i < lszRow; i++ ) {
        int cidx  = ToFlatIdx( lidRow     + i, lidCol    , lRowWidth );
        int nidx  = ToFlatIdx( lidRow - 1 + i, lidCol    , lRowWidth );
        int sidx  = ToFlatIdx( lidRow + 1 + i, lidCol    , lRowWidth );
        int eidx  = ToFlatIdx( lidRow     + i, lidCol + 1, lRowWidth );
        int widx  = ToFlatIdx( lidRow     + i, lidCol - 1, lRowWidth );
        int neidx = ToFlatIdx( lidRow - 1 + i, lidCol + 1, lRowWidth );
        int seidx = ToFlatIdx( lidRow + 1 + i, lidCol + 1, lRowWidth );
        int nwidx = ToFlatIdx( lidRow - 1 + i, lidCol - 1, lRowWidth );
        int swidx = ToFlatIdx( lidRow + 1 + i, lidCol - 1, lRowWidth );

        T centerValue = sh[cidx];
        T cardinalValueSum = sh[nidx] + sh[sidx] + sh[eidx] + sh[widx];
        T diagonalValueSum = sh[neidx] + sh[seidx] + sh[nwidx] + sh[swidx];

        newData[ToFlatIdx(gRow + i, gCol, gRowWidth)] = wCenter * centerValue +
                wCardinal * cardinalValueSum +
                wDiagonal * diagonalValueSum;
    }
}*/

>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76

template<typename T1, typename T2, class Args>
__global__ void stencilTilingCU(Array<T1> input,Array<T1> output,Mask<T2> mask,Args args, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth){
	size_t i = blockIdx.x*blockDim.x+threadIdx.x;
	#ifdef PSKEL_SHARED_MASK
	extern __shared__ int shared[];
 	if(threadIdx.x<(mask.size*mask.dimension))
		shared[threadIdx.x] = mask.deviceMask[threadIdx.x];
	__syncthreads();
	mask.deviceMask = shared;
	#endif
	if(i>=widthOffset && i<(widthOffset+tilingWidth)){
		stencilKernel(input, output, mask, args, i);
	}
}

<<<<<<< HEAD
template<typename T1, typename T2, class Args>
__global__ void stencilTilingCU(Array2D<T1> input,Array2D<T1> output,Mask2D<T2> mask,Args args, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth){
	size_t w = blockIdx.x*blockDim.x+threadIdx.x;
	size_t h = blockIdx.y*blockDim.y+threadIdx.y;
	#ifdef PSKEL_SHARED_MASK
	extern __shared__ int shared[];
  	if(threadIdx.x<(mask.size*mask.dimension))
		shared[threadIdx.x] = mask.deviceMask[threadIdx.x];
	__syncthreads();
	mask.deviceMask = shared;
	#endif
	if(w>=widthOffset && w<(widthOffset+tilingWidth) && h>=heightOffset && h<(heightOffset+tilingHeight) ){
=======
/* Shared memory kernel development */
#ifdef PSKEL_SHARED
#define TIME_TILE_SIZE 2

//extern __shared__ float sh_input[];

template<typename T1, typename T2, class Args>
//__global__ void stencilTilingCU(T1 *input,T1 *output,Args args, size_t maskRange, size_t timeTileSize, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth){
__global__ void stencilTilingCU(Array2D<T1> input,Array2D<T1> output,Mask2D<T2> mask,Args args, size_t maskRange, size_t timeTileSize, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth){
 // Determine our start position
    int offsetI = blockIdx.y * (blockDim.y-2*(timeTileSize-1)) + threadIdx.y - 2*(timeTileSize-1);
    //int offsetI = blockIdx.y * blockDim.y + threadIdx.y - timeTileSize;
    //offsetI -= timeTileSize-1;
    int offsetJ = blockIdx.x * (blockDim.x-2*(timeTileSize-1)) + threadIdx.x - 2*(timeTileSize-1);
    //int offsetJ = blockIdx.x * blockDim.x + threadIdx.x - timeTileSize;
    //offsetJ -= timeTileSize-1;

    //T1* sh_input = mask.GetSharedPointer();
    #ifdef PSKEL_DEBUG
    printf("STEP 1 - offset %d %d\n",offsetI,offsetJ);
    #endif
    //__shared__ T1 sh_input[(BLOCK_SIZE + 2*(TIME_TILE_SIZE-1))*(BLOCK_SIZE + 2*(TIME_TILE_SIZE-1))];
    SharedMemory<T1> shobj;
    T1* sh_input = shobj.GetSharedPointer();
    sh_input[threadIdx.y*blockDim.x+threadIdx.x] = ((offsetI >= 0) && (offsetI < tilingHeight) &&
    (offsetJ >= 0) && (offsetJ < tilingWidth)) ? input(offsetI,offsetJ) : 0.0f; //sh_input[threadIdx.y*blockDim.y+threadIdx.x];
    
    #ifdef PSKEL_DEBUG
    //printf("STEP 2 - sh_intput[%d] = %f\n",threadIdx.y*blockDim.y+threadIdx.x,sh_input[threadIdx.y*blockDim.y+threadIdx.x]);
    #endif
    __syncthreads();
  
    
    for(int t = 0; t < TIME_TILE_SIZE; t++) {
	//stencilComputation
	//printf("Computing it %d\n",t);
         
	/*
		T1 l = (threadIdx.y >= t) ? sh_input[(threadIdx.y-1)*blockDim.y+threadIdx.x] : 0.0f;
		T1 r = (threadIdx.y < blockDim.y-t) ? sh_input[(threadIdx.y+1)*blockDim.y+threadIdx.x] : 0.0f;
		T1 t = (threadIdx.x >= t) ? sh_input[threadIdx.y*blockDim.y+threadIdx.x-1] : 0.0f;
		T1 b = (threadIdx.x < blockDim.x-t) ? sh_input[threadIdx.y*blockDim.y+threadIdx.x+1] : 0.0f;
        */
	#ifdef JACOBI_KERNEL
	T1 n = ((threadIdx.y-1 >= 0) && (threadIdx.y-1 <= (blockDim.y-1)) && (threadIdx.x >= 0)  && (threadIdx.x <= (blockDim.x-1))) ? 
		sh_input[(threadIdx.y-1)*blockDim.x+threadIdx.x] : 0.0f;
                 
	T1 e = ((threadIdx.y >= 0) && (threadIdx.y <= (blockDim.y-1)) && (threadIdx.x+1 >= 0) && (threadIdx.x+1 <= (blockDim.x-1))) ? 
		sh_input[threadIdx.y*blockDim.x+threadIdx.x+1] : 0.0f;
	
	T1 w = ((threadIdx.y >= 0) && (threadIdx.y <= (blockDim.y-1)) && (threadIdx.x-1 >= 0) && (threadIdx.x-1 <= (blockDim.x-1))) ? 
		sh_input[threadIdx.y*blockDim.x+threadIdx.x-1] : 0.0f;
        
	T1 s = ((threadIdx.y+1 >= 0) && (threadIdx.y+1 <= (blockDim.y-1)) && (threadIdx.x >= 0) && (threadIdx.x <= (blockDim.x-1))) ? 
		sh_input[(threadIdx.y+1)*blockDim.x+threadIdx.x] : 0.0f;
        
	T1 val = 0.25f * (n + e + w + s - args.h);
	#else
	#ifdef CLOUDSIM_KERNEL

	T1 c = sh_input[threadIdx.y*blockDim.x+threadIdx.x];
	
	T1 n = ((threadIdx.y-1 >= 0) && (threadIdx.y-1 <= (blockDim.y-1)) && (threadIdx.x >= 0)  && (threadIdx.x <= (blockDim.x-1))) ? 
		sh_input[(threadIdx.y-1)*blockDim.x+threadIdx.x] : c;
                 
	T1 e = ((threadIdx.y >= 0) && (threadIdx.y <= (blockDim.y-1)) && (threadIdx.x+1 >= 0) && (threadIdx.x+1 <= (blockDim.x-1))) ? 
		sh_input[threadIdx.y*blockDim.x+threadIdx.x+1] : c;
	
	T1 w = ((threadIdx.y >= 0) && (threadIdx.y <= (blockDim.y-1)) && (threadIdx.x-1 >= 0) && (threadIdx.x-1 <= (blockDim.x-1))) ? 
		sh_input[threadIdx.y*blockDim.x+threadIdx.x-1] : c;
        
	T1 s = ((threadIdx.y+1 >= 0) && (threadIdx.y+1 <= (blockDim.y-1)) && (threadIdx.x >= 0) && (threadIdx.x <= (blockDim.x-1))) ? 
		sh_input[(threadIdx.y+1)*blockDim.x+threadIdx.x] : c;
        
	T1 sum =  4*c - (n + e + w + s);
 	T1 numNeighbor = 0.25f;
        
	T1 xwind = ((offsetI >= 0) && (offsetI < (tilingHeight)) &&
    		       (offsetJ >= 0) && (offsetJ < (tilingWidth))) ? args.wind_x(offsetI,offsetJ) : c;
        T1 ywind = ((offsetI >= 0) && (offsetI < (tilingHeight)) &&
                       (offsetJ >= 0) && (offsetJ < (tilingWidth))) ? args.wind_y(offsetI,offsetJ) : c;
        
	int xfactor = (xwind>0)?1:-1;
        int yfactor = (ywind>0)?1:-1;
	   
        T1 componenteVentoY = yfactor * ywind;
        T1 componenteVentoX = xfactor * xwind;
    	
	T1 temperaturaNeighborX = (threadIdx.x >= 0 && (threadIdx.x+xfactor) < blockDim.x) 
                                    ? sh_input[threadIdx.y*blockDim.x+threadIdx.x+xfactor] : c;
	T1 temperaturaNeighborY = (threadIdx.y >= 0 && (threadIdx.y+yfactor) < blockDim.y) 
                                    ? sh_input[(threadIdx.y+yfactor)*blockDim.x+threadIdx.x] : c;	

        T1 temp_wind = (-componenteVentoX * ((c - temperaturaNeighborX)*10.0f)) -
                       ( componenteVentoY * ((c - temperaturaNeighborY)*10.0f));
                      
        T1 temperatura_conducao = -0.0243f*(sum*numNeighbor) * args.deltaT;
        T1 result = c + temperatura_conducao;
        T1 val = result + temp_wind * args.deltaT;
	#else 
	#ifdef GOL_KERNEL
      	T1 nw = (((threadIdx.y-1) >= 0) && ((threadIdx.y-1) <= (blockDim.y-1)) && ((threadIdx.x-1) >= 0) && ((threadIdx.x-1) <= (blockDim.x-1)))
                ? sh_input[(threadIdx.y-1)*blockDim.x+(threadIdx.x-1)] : 0.0f;
        
	T1 n  = ((threadIdx.y-1 >= 0) && (threadIdx.y-1 <= (blockDim.y-1)) && 
		(threadIdx.x >= 0)    && (threadIdx.x <= (blockDim.x-1))) 
		? sh_input[(threadIdx.y-1)*blockDim.x+threadIdx.x] : 0.0f;
     	
	T1 ne = (((threadIdx.y-1) >= 0) && ((threadIdx.y-1) <= (blockDim.y-1)) && ((threadIdx.x+1) >= 0) && ((threadIdx.x+1) <= (blockDim.x-1)))
                 ? sh_input[(threadIdx.y-1)*blockDim.x+(threadIdx.x+1)] : 0.0f;
 		
	T1 w = ((threadIdx.y >= 0) && (threadIdx.y <= (blockDim.y-1)) && (threadIdx.x-1 >= 0) && (threadIdx.x-1 <= (blockDim.x-1)))
		? sh_input[threadIdx.y*blockDim.x+threadIdx.x-1] : 0.0f;
 	
	T1 c = sh_input[threadIdx.y*blockDim.x+threadIdx.x];
                                  
	T1 e = ((threadIdx.y >= 0) && (threadIdx.y <= (blockDim.y-1)) && (threadIdx.x+1 >= 0) &&  (threadIdx.x+1 <= (blockDim.x-1)))  
		? sh_input[threadIdx.y*blockDim.x+threadIdx.x+1] : 0.0f;
  	
	T1 s = ((threadIdx.y+1 >= 0) &&  (threadIdx.y+1 <= (blockDim.y-1)) && (threadIdx.x >= 0) && (threadIdx.x <= (blockDim.x-1))) 
		? sh_input[(threadIdx.y+1)*blockDim.x+threadIdx.x] : 0.0f;
                 
 	T1 sw = (((threadIdx.y+1) >= 0) && ((threadIdx.y+1) <= (blockDim.y-1)) && ((threadIdx.x-1) >= 0) && ((threadIdx.x-1) <= (blockDim.x-1)))
        	? sh_input[(threadIdx.y+1)*blockDim.x+(threadIdx.x-1)] : 0.0f;
                
	T1 se = ((threadIdx.y+1 >= 0) && ((threadIdx.y+1) <= (blockDim.y-1)) && ((threadIdx.x+1) >= 0) && ((threadIdx.x+1) <= (blockDim.x-1)))
        	? sh_input[(threadIdx.y+1)*blockDim.x+(threadIdx.x+1)] : 0.0f;
        
	 /*T1 tl = ((offsetI-1 >= 0) && (offsetI-1 <= (blockDim.y-1)) && (offsetJ-1 >= 0) && (offsetJ-1 <= (blockDim.x-1)))
                ? sh_input[(offsetI-1)*blockDim.y+(offsetJ-1)] : 0.0f;
                 
		T1 tr = ((offsetI+1 >= 0) && (offsetI+1 <= (blockDim.y-1)) && (offsetJ+1 >= 0) && (offsetJ+1 <= (blockDim.x-1)))
                 ? sh_input[(offsetI+1)*blockDim.y+(offsetJ+1)] : 0.0f;
                 
		T1 bl = ((offsetI-1 >= 0) && (offsetI-1 <= (blockDim.y-1)) && (offsetJ+1 >= 0) && (offsetJ+1 <= (blockDim.x-1)))
                 ? sh_input[(offsetI-1)*blockDim.y+(offsetJ+1)] : 0.0f;
                 
		T1 br = ((offsetI+1 >= 0) && (offsetI+1 <= (blockDim.y-1)) && (offsetJ-1 >= 0) && (offsetJ-1 <= (blockDim.x-1)))
                 ? sh_input[(offsetI+1)*blockDim.y+(offsetJ-1)] : 0.0f;
        */        

        /*
        T1 tl = (threadIdx.y >= timeTileSize && threadIdx.x > t) ? sh_input[(threadIdx.y-1)*blockDim.y+(threadIdx.x-1)] : 0.0f;
        T1 tr = (threadIdx.y < blockDim.y-timeTileSize && threadIdx.y < blockDim.x-timeTileSize) ? 
                 sh_input[(threadIdx.y+1)*blockDim.y+(threadIdx.x+1)] : 0.0f;
        T1 bl = (threadIdx.y >= timeTileSize && threadIdx.x < blockDim.x-timeTileSize) ? 
                 sh_input[(threadIdx.y-1)*blockDim.y+(threadIdx.x+1)] : 0.0f;
        T1 br = (threadIdx.y < blockDim.y-timeTileSize && threadIdx.x >= timeTileSize) ? 
                 sh_input[(threadIdx.y+1)*blockDim.y+(threadIdx.x-1)] : 0.0f;
        */
	T1 sum = nw + n + ne + w + e + sw + s + se;
        T1 val = (sum == 3.0f || (sum == 2.0f && c  == 1.0f))?1.0f:0.0f;
	#endif
	#endif
	#endif
		
	#ifdef PSKEL_DEBUG
	//printf("STEP 3 - val: %f\n",val);
	#endif
	/*T1 val = 0.25f * (sh_input[(threadIdx.y+1)*blockDim.y+(threadIdx.x)] + 
			  sh_input[(threadIdx.y-1)*blockDim.y+(threadIdx.x)] + 
			  sh_input[(threadIdx.y)*blockDim.y+(threadIdx.x+1)] + 
						  sh_input[(threadIdx.y)*blockDim.y+(threadIdx.x-1)] + 
						  - args.h)
		*/
	__syncthreads();
		
	sh_input[threadIdx.y*blockDim.x+threadIdx.x] = ((offsetI >= 0) && (offsetI < (tilingHeight)) &&	(offsetJ >= 0) && (offsetJ < (tilingWidth))) 
		? val : sh_input[threadIdx.y*blockDim.x+threadIdx.x];
        	 //((threadIdx.x >= (timeTileSize)) && (threadIdx.x < (blockDim.x-(timeTileSize))) &&
                // (threadIdx.y >= (timeTileSize)) && (threadIdx.y < (blockDim.y-(timeTileSize)))) ? val : sh_input[threadIdx.y*blockDim.y+threadIdx.x];
        
	#ifdef PSKEL_DEBUG
		//printf("STEP 4 - sh_intput[%d] = %f\n",threadIdx.y*blockDim.y+threadIdx.x,sh_input[threadIdx.y*blockDim.y+threadIdx.x]);
        #endif
        // Sync before re-reading shared
        __syncthreads();
	}
	
       if(
         (threadIdx.x >= (timeTileSize-1))
	 && (threadIdx.x < (blockDim.x-(timeTileSize-1)))
         &&  (threadIdx.y >= (timeTileSize-1)) 
	 && (threadIdx.y < (blockDim.y-(timeTileSize-1))) 
         && (offsetI >= 0) && (offsetI < tilingHeight) && (offsetJ >= 0) && (offsetJ < tilingWidth)
	 //offsetI >= (blockIdx.y*blockDim.y+timeTileSize) && offsetI < (blockIdx.y*blockDim.y+blockDim.y-timeTileSize) && offsetI < tilingHeight &&
	 //offsetJ >= (blockIdx.x*blockDim.x+timeTileSize) && offsetJ < (blockIdx.x*blockDim.x+blockDim.x-timeTileSize) && offsetJ < tilingWidth
	 ){
        //output(offsetI,offsetJ) 
        output(offsetI,offsetJ) = sh_input[threadIdx.y*blockDim.x+threadIdx.x];
        #ifdef PSKEL_DEBUG
        //printf("STEP 5 - [%d,%d] output(%d,%d) = %f\n",blockIdx.y*blockDim.y+threadIdx.y,blockIdx.x*blockDim.x+threadIdx.x,offsetII,offsetJJ,output(offsetII,offsetJJ));
        #endif
	}
}
/* This is not better than naive pskel
template<typename T1, typename T2, class Args>
__global__ void stencilTilingCU(Array2D<T1> input,Array2D<T1> output,Mask2D<T2> mask,Args args, size_t maskRange, size_t iteration, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth, size_t border_cols, size_t border_rows){
	//size_t w = blockIdx.x*blockDim.x+threadIdx.x;
	//size_t h = blockIdx.y*blockDim.y+threadIdx.y;
	__shared__ T1 sh_input[BLOCK_SIZE][BLOCK_SIZE];
	__shared__ T1 sh_output[BLOCK_SIZE][BLOCK_SIZE]; //temporary output
	
	int bx = blockIdx.x;
	int by = blockIdx.y;

	int tx=threadIdx.x;
	int ty=threadIdx.y;
	
	 // calculate the small block size
	int small_block_rows = BLOCK_SIZE-iteration*2;//EXPAND_RATE
	int small_block_cols = BLOCK_SIZE-iteration*2;//EXPAND_RATE

	// calculate the boundary for the block according to 
	// the boundary of its small block
	int blkY = small_block_rows*by-border_rows;
	int blkX = small_block_cols*bx-border_cols;
	int blkYmax = blkY+BLOCK_SIZE-1;
	int blkXmax = blkX+BLOCK_SIZE-1;
	
	// calculate the global thread coordination
	int yidx = blkY+ty;
	int xidx = blkX+tx;

	// load data if it is within the valid input range
	int loadYidx=yidx;
	int loadXidx=xidx;
	//int index = loadYidx*tilingWidth + loadXidx;
	
	if(IN_RANGE(loadYidx, 0, tilingHeight-1) && IN_RANGE(loadXidx, 0, tilingWidth-1)){
		sh_input[ty][tx] = input(loadXidx,loadYidx);  // Load the temperature data from global memory to shared memory
		//power_on_cuda[ty][tx] = power[index];// Load the power data from global memory to shared memory
	}
	__syncthreads();
	
	// effective range within this block that falls within 
	// the valid range of the input data
	// used to rule out computation outside the boundary.
	int validYmin = (blkY < 0) ? -blkY : 0;
	int validYmax = (blkYmax > tilingHeight-1) ? BLOCK_SIZE-1-(blkYmax-tilingHeight+1) : BLOCK_SIZE-1;
	int validXmin = (blkX < 0) ? -blkX : 0;
	int validXmax = (blkXmax > tilingWidth-1) ? BLOCK_SIZE-1-(blkXmax-tilingWidth+1) : BLOCK_SIZE-1;
	
	/ Offset, need to check how this will be implemented. Get function maybe?
	//int N = ty-1;
	//int S = ty+1;
	//int W = tx-1;
	//int E = tx+1;
	
	//N = (N < validYmin) ? validYmin : N;
	//S = (S > validYmax) ? validYmax : S;
	//W = (W < validXmin) ? validXmin : W;
	//E = (E > validXmax) ? validXmax : E;
	
	bool computed;
	for (int i=0; i<iteration ; i++){ 
		computed = false;
		if( IN_RANGE(tx, i+1, BLOCK_SIZE-i-2) &&  \
			IN_RANGE(ty, i+1, BLOCK_SIZE-i-2) &&  \
			IN_RANGE(tx, validXmin, validXmax) && \
			IN_RANGE(ty, validYmin, validYmax) ) {
			computed = true;
			//stencilKernel(sh_input, sh_output, args, ty, tx);
			//stencilKernel(sh_input, sh_output, args, ty, tx);
			sh_output[ty][tx] = 0.25f * (sh_input[ty][tx-1] + sh_input[ty][tx+1] + sh_input[ty-1][tx] + sh_input[ty+1][tx] - args.h);
		}
		__syncthreads();
		if(i==iteration-1)
			break;
		if(computed)	 //Assign the computation range
			sh_input[ty][tx]= sh_output[ty][tx];
		__syncthreads();
	}

	// update the global memory
	// after the last iteration, only threads coordinated within the 
	// small block perform the calculation and switch on ``computed''
	if (computed){
	  output(loadXidx,loadYidx) = sh_output[ty][tx];		
	}
}
*/
#else
template<typename T1, typename T2, class Args>
__global__ void stencilTilingCU(Array2D<T1> input,Array2D<T1> output,Mask2D<T2> mask,Args args, size_t maskRange, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth){
	size_t w = blockIdx.x*blockDim.x+threadIdx.x;
	size_t h = blockIdx.y*blockDim.y+threadIdx.y;
	if(w>=maskRange && w<(tilingWidth-maskRange) && h>=maskRange && h<(tilingHeight-maskRange) ){
		#ifdef PSKEL_SHARED
		//extern __shared__ int shared[];
		//if(threadIdx.x<(mask.size*mask.dimension))
		//	shared[threadIdx.x] = mask.deviceMask[threadIdx.x];
		//__syncthreads();
		//mask.deviceMask = shared;
		//#endif
		//SharedMemory<T1> shobj;
		//T1* shared = mask.GetPointer(blockDim.x,maskRange);
		T1* shared = mask.GetSharedPointer();
		size_t index;
		/*
		if(threadIdx.x < maskRange){
			shared[threadIdx.x*blockDim.x+threadIdx.y] = input(h-maskRange,w);
		}
		if(threadIdx.y < maskRange){
			shared[threadIdx.x*blockDim.x+threadIdx.y] = input(h,w-maskRange);
		}
		if(threadIdx.x > blockDim.x-maskRange){
			shared[threadIdx.x*blockDim.x+threadIdx.y] = input(h+maskRange,w);
		}
		if(threadIdx.y > blockDim.y-maskRange){
			shared[threadIdx.x*blockDim.x+threadIdx.y] = input(h,w+maskRange);
		}
		*/
		//Copy the left and right halo rows into shared shared memory
		if(threadIdx.x == 0){ //first col of the block
			for(size_t i=0;i<maskRange;i++){
				index = (threadIdx.y+i)*(blockDim.x+2*maskRange)+(threadIdx.x);
				shared[index] = input(h,w-1);
				//printf("blx %d bly %d tx %d ty %d: index: %d\n",blockDim.x,blockDim.y,threadIdx.x,threadIdx.y,index);
			}
		}
		else if(threadIdx.x == blockDim.x-1){ //last col of the block
			for(size_t i=1;i<=maskRange;i++){
				index = (threadIdx.y+i)*(blockDim.x+2*maskRange)+(threadIdx.x+maskRange+i);
				//printf("blx %d bly %d tx %d ty %d: index: %d\n",blockDim.x,blockDim.y,threadIdx.x,threadIdx.y,index);
				shared[index] = input(h,w+1);
			}
		}
		if(threadIdx.y == 0){ //first row of the block
			for(size_t i=0;i<maskRange;i++){
				index = (threadIdx.y)*(blockDim.x+2*maskRange)+(threadIdx.x+i);
				//printf("blx %d bly %d tx %d ty %d: index: %d\n",blockDim.x,blockDim.y,threadIdx.x,threadIdx.y,index);
				shared[index] = input(h-1,w);
			}
		}
		if(threadIdx.y == blockDim.y-1){//last row of the block
			for(size_t i=1;i<=maskRange;i++){
				index = (threadIdx.y+maskRange+i)*(blockDim.x+2*maskRange)+(threadIdx.x+i);
				//printf("blx %d bly %d tx %d ty %d: index: %d\n",blockDim.x,blockDim.y,threadIdx.x,threadIdx.y,index);
				shared[index] = input(h+1,w);
			}
		}		
		
		index = (threadIdx.y+maskRange)*(blockDim.x+2*maskRange)+(threadIdx.x+maskRange);
		//printf("%d position\n",index);
		shared[index] = input(h,w);
		__syncthreads();
		
		/*
		if(threadIdx.x==0 && threadIdx.y==0){
			for(size_t j = 0;j<(blockDim.y+2*maskRange);j++){
				for(size_t i = 0;i<(blockDim.x+2*maskRange);i++){
					index = j*(blockDim.x+2*maskRange)+i;
					printf("id (%d,%d) %d value %f \n",index, shared[index]);
				}
			}
		}*/
			
		stencilKernel(input, output, shared, args, h, w, threadIdx.x, threadIdx.y);
		#else
		stencilKernel(input, output, mask, args, h, w);
		#endif
	}
}
#endif


template<typename T1, typename T2, class Args>
__global__ void stencilTilingCU(Array2D<T1> input,Array2D<T1> output,Mask2D<T2> mask,Args args, size_t maskRange, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth){
	size_t w = blockIdx.x*blockDim.x+threadIdx.x;
	size_t h = blockIdx.y*blockDim.y+threadIdx.y;
	/* TimeTiling solution works
	#ifdef PSKEL_SHARED_MASK
	T1* shared = mask.GetSharedPointer();
	if(threadIdx.x < maskRange){
		shared[(threadIdx.x-maskRange)*blockDim.x+threadIdx.y] = input(h-maskRange,w);
	}
	if(threadIdx.y < maskRange){
		shared[threadIdx.x*blockDim.x+(threadIdx.y-maskRange)] = input(h,w-maskRange);
	}
	if(threadIdx.x > blockDim.x-maskRange){
		shared[(threadIdx.x+maskRange)*blockDim.x+threadIdx.y] = input(h+maskRange,w);
	}
	if(threadIdx.y > blockDim.y-maskRange){
		shared[threadIdx.x*blockDim.x+(threadIdx.y+maskRange)] = input(h,w+maskRange);
	}
	shared[threadIdx.x*blockDim.x+threadIdx.y] = input(h,w);
	__syncthreads();
	#endif
	*/
     	//Ignores all borders except the lower one
	if(w>=(widthOffset+maskRange) && w<(widthOffset+tilingWidth-maskRange) && h>=(heightOffset+maskRange) && h<(heightOffset+tilingHeight) ){
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		stencilKernel(input, output, mask, args, h, w);
	}
}

template<typename T1, typename T2, class Args>
__global__ void stencilTilingCU(Array3D<T1> input,Array3D<T1> output,Mask3D<T2> mask,Args args, size_t widthOffset, size_t heightOffset, size_t depthOffset, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth){
	size_t w = blockIdx.x*blockDim.x+threadIdx.x;
	size_t h = blockIdx.y*blockDim.y+threadIdx.y;
	size_t d = blockIdx.z*blockDim.z+threadIdx.z;
	#ifdef PSKEL_SHARED_MASK
	extern __shared__ int shared[];
  	if(threadIdx.x<(mask.size*mask.dimension))
		shared[threadIdx.x] = mask.deviceMask[threadIdx.x];
	__syncthreads();
	mask.deviceMask = shared;
	#endif
  
	if(w>=widthOffset && w<(widthOffset+tilingWidth) && h>=heightOffset && h<(heightOffset+tilingHeight) && d>=depthOffset && d<(depthOffset+tilingDepth) ){
		stencilKernel(input, output, mask, args, h, w, d);
	}
}
#endif

//*******************************************************************************************
// Stencil Base
//*******************************************************************************************
#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runSequential(){
	this->runSeq(this->input, this->output);
}
#endif

//*******************************************************************************************
// MPPA
//*******************************************************************************************

#ifdef PSKEL_MPPA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::spawn_slaves(const char slave_bin_name[], size_t tilingHeight, size_t tilingWidth, int nb_clusters, int nb_threads, int iterations, int innerIterations){
	// Prepare arguments to send to slaves
	int i;
	int cluster_id;
	int pid;
	
	size_t wTiling = ceil(float(this->input.getWidth())/float(tilingWidth));
	size_t hTiling = ceil(float(this->input.getHeight())/float(tilingHeight));
	size_t totalSize = float(hTiling*wTiling);
	
	int tiles = totalSize/nb_clusters;
	//int wtiles = wTiling/nb_clusters;

	int itMod = totalSize % nb_clusters;

	int tilesSlave;
	int r;
	int outterIterations = ceil(float(iterations)/innerIterations);


	#ifdef DEBUG
	cout<<"MASTER: width="<<this->input.getWidth()<<" height="<<this->input.getWidth();
	cout<<" tilingHeight="<<tilingHeight <<" iterations="<<iterations;
	cout<<" inner_iterations="<<innerIterations<<" nbclusters="<<nb_clusters<<" nbthreads="<<nb_threads<<endl;
	cout<<"MASTER: tiles="<<tiles<<" itMod="<<itMod<<" outterIterations="<<outterIterations<<endl;
	#endif

	char **argv_slave = (char**) malloc(sizeof (char*) * ARGC_SLAVE);
	for (i = 0; i < ARGC_SLAVE - 1; i++)
	  argv_slave[i] = (char*) malloc (sizeof (char) * 11);
	 
	sprintf(argv_slave[1], "%d", tilingWidth);
	sprintf(argv_slave[2], "%d", tilingHeight);
	sprintf(argv_slave[4], "%d", nb_threads);
	sprintf(argv_slave[5], "%d", iterations);
	sprintf(argv_slave[6], "%d", outterIterations);
	sprintf(argv_slave[7], "%d", itMod);
	sprintf(argv_slave[8], "%d", this->input.getHeight());
	sprintf(argv_slave[9], "%d", this->input.getHeight());

	argv_slave[10] = NULL;

	  
	// Spawn slave processes
	for (cluster_id = 0; cluster_id < nb_clusters && cluster_id < totalSize; cluster_id++) {
		r = (cluster_id < itMod)?1:0;
		tilesSlave = tiles + r;

		sprintf(argv_slave[0], "%d", tilesSlave);
		sprintf(argv_slave[3], "%d", cluster_id);
	    pid = mppa_spawn(cluster_id, NULL, slave_bin_name, (const char **)argv_slave, NULL);
	    assert(pid >= 0);
	}
	for (i = 0; i < ARGC_SLAVE; i++)
		free(argv_slave[i]);
	free(argv_slave);
}
#endif


#ifdef PSKEL_MPPA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::mppaSlice(size_t tilingHeight, size_t tilingWidth, int nb_clusters, int iterations, int innerIterations) {
	
	size_t wTiling = ceil(float(this->input.getWidth())/float(tilingWidth));
	size_t hTiling = ceil(float(this->input.getHeight())/float(tilingHeight));
	size_t totalSize = float(hTiling*wTiling);
	int tiles = totalSize/nb_clusters;
    //int hTmod = float(this->input.getHeight())/float(tilingHeight)
    //int wTmod = float(this->input.getWidth())/float(tilingWidth)
	int itMod = totalSize % nb_clusters;



	//this->output.portalReadAlloc(nb_clusters, 0);
	size_t outterIterations;
	size_t heightOffset;
	size_t widthOffset;


	StencilTiling<Array, Mask>tiling(this->input, this->output, this->mask);

	barrier_t *barrierNbClusters;
	outterIterations = ceil(float(iterations)/innerIterations);
	Array inputCopy(this->input.getWidth(),this->input.getHeight());
    //Array outFinal(tilingWidth, totalSize*tilingHeight);
    this->output.portalReadAlloc(nb_clusters, 0);

	# if defined (DEBUG) || defined (TIME_EXEC)
	hr_timer_t totTimerMaster;
	hr_timer_t sendTimerMaster;
	hr_timer_t modTimerMaster;
	//timer
  	hrt_start(&totTimerMaster);
  	#endif

	for(size_t it = 0; it<outterIterations; it++){
		size_t subIterations = innerIterations;
		if(((it+1)*innerIterations)>iterations){
			subIterations = iterations-(it*innerIterations);
		}
		
		if(tiles == 0) {
			Array slice[totalSize];
			Array outputNumberHt[totalSize];
            Array tmp;
			////////////////////////////////Number of clusters are higher//////////////
			#ifdef DEBUG
				cout<<"MASTER ["<<it<<"]: number of clusters are higher than number of tilings"<<endl;
			#endif

			#ifdef DEBUG
				cout<<"MASTER["<<it<<"]: Barrier CREATED"<<endl;
			#endif
			barrierNbClusters = mppa_create_master_barrier(BARRIER_SYNC_MASTER, BARRIER_SYNC_SLAVE, totalSize);

			#ifdef DEBUG
				cout<<"MASTER["<<it<<"]: Barrier 1"<<endl;
			#endif
			mppa_barrier_wait(barrierNbClusters);

			for (int i = 0; i < totalSize; i++) {
				outputNumberHt[i].portalAuxWriteAlloc(i);
			}

			#ifdef DEBUG
				cout<<"MASTER["<<it<<"]: Barrier 2"<<endl;
			#endif
			mppa_barrier_wait(barrierNbClusters);

			int tS = 0;
			for (int ht = 0; ht < hTiling; ht++) {
				for (int wt = 0; wt < wTiling; wt++) {
					heightOffset = ht*tilingHeight;
					widthOffset = wt*tilingWidth;
					tiling.tile(subIterations, widthOffset, heightOffset, 0, tilingWidth, tilingHeight, 1);
					outputNumberHt[tS].hostSlice(tiling.input, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
					outputNumberHt[tS].setAux(heightOffset, widthOffset, it, subIterations, tiling.coreWidthOffset, tiling.coreHeightOffset, tiling.coreDepthOffset, tiling.coreWidth, tiling.coreHeight, tiling.coreDepth, outterIterations, tiling.height, tiling.width, tiling.depth, this->input.getWidth());
					outputNumberHt[tS].copyToAux();
					outputNumberHt[tS].waitAuxWrite();
					tS++;
				}
			}
			
			for (int i = 0; i < totalSize; i++) {
				outputNumberHt[i].closeAuxWritePortal();
			}
			// #ifdef DEBUG
			// 	cout<<"MASTER["<<it<<"]: Barrier 3"<<endl;
			// #endif
			// mppa_barrier_wait(barrierNbClusters);

			for (int i = 0; i < totalSize; i++) {
				slice[i].portalWriteAlloc(i);
			}
			#ifdef DEBUG
				cout<<"MASTER["<<it<<"]: Barrier 3"<<endl;
			#endif
			mppa_barrier_wait(barrierNbClusters);
			tS = 0;

			# if defined (DEBUG) || defined (TIME_EXEC)
  			hrt_start(&sendTimerMaster);
  			#endif
			// mppa_barrier_wait(barrierNbClusters);

			for(int ht = 0; ht < hTiling; ht++) {
				for(int wt = 0; wt < wTiling; wt++){
					heightOffset = ht*tilingHeight;
					widthOffset = wt*tilingWidth;
					tiling.tile(subIterations, widthOffset, heightOffset, 0, tilingWidth, tilingHeight, 1);
		   			tmp.hostSlice(tiling.input, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
                    //Array tmp(tiling.width, tiling.height);
                    //tmp.mppaMasterCopy(slice[tS]);
                    slice[tS].mppaMasterClone(tmp);
                    slice[tS].copyTo();
		   			slice[tS].waitWrite();
		   			tS++;
		   		}
			}
			# if defined (DEBUG) || defined (TIME_EXEC)
  			hrt_stop(&sendTimerMaster);
  			#endif
			// this->output.setTrigger(totalSize);
			// this->output.copyFrom();
            // mppa_barrier_wait(barrierNbClusters);
            this->output.setTrigger(tilingHeight);
            for (int i = 0; i < totalSize; i++) {
                this->output.copyFrom();
            }
			for (int i = 0; i < totalSize; i++) {
                slice[i].mppaFree();
				slice[i].closeWritePortal();
			}
			// #ifdef DEBUG
			// 	cout<<"MASTER["<<it<<"]: Barrier 4"<<endl;
			// #endif

			mppa_close_barrier(barrierNbClusters);
			# if defined (DEBUG) || defined (TIME_SEND)
			cout << "Master Send Time: " << hrt_elapsed_time(&sendTimerMaster) << " from iteration " << it << endl;
			#endif
		} else {
			///////////////////////////hTiling is higher///////////////////////////////
			#ifdef DEBUG
				cout<<"MASTER ["<<it<<"]: number of tiles are higher than number of clusters"<<endl;
			#endif
			int counter = 0;

			Array cluster[nb_clusters];
            Array tmp;
			#ifdef DEBUG
				cout<<"MASTER["<<it<<"]: Barrier CREATED"<<endl;
			#endif
			barrierNbClusters = mppa_create_master_barrier(BARRIER_SYNC_MASTER, BARRIER_SYNC_SLAVE, nb_clusters);

			Array outputNumberNb[nb_clusters];
			Array outputNumberMod[itMod];

            int baseItHt = 0;
            int baseItWt = 0;
            int auxHt = 0;
            int auxWt = 0;
            int ht = 0;
            int wt = 0;
			for(int i = 0; i < tiles; i++) {
				#ifdef DEBUG
					cout<<"MASTER["<<it<<"]: Barrier 1 from tile: "<< i <<endl;
				#endif
				mppa_barrier_wait(barrierNbClusters);
				
				for (int i = 0; i < nb_clusters; i++) {
					outputNumberNb[i].portalAuxWriteAlloc(i);
				}

				#ifdef DEBUG
					cout<<"MASTER["<<it<<"]: Barrier 2 from tile: " << i <<endl;
				#endif
				mppa_barrier_wait(barrierNbClusters);
                int tS = 0;

                auxHt = baseItHt;
                auxWt = baseItWt;
                if (auxWt == wTiling) {
                    auxHt++;
                    auxWt = 0;
                    //baseItWt = 0;
                }
                for (auxHt; auxHt < hTiling; auxHt++) {
                    //auxWt = baseItWt;
                    for (auxWt; auxWt < wTiling; auxWt++) {
    					heightOffset = auxHt*tilingHeight;
    					widthOffset = auxWt*tilingWidth;
    					tiling.tile(subIterations, widthOffset, heightOffset, 0, tilingWidth, tilingHeight, 1);
    					outputNumberNb[tS].hostSlice(tiling.input, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
      					outputNumberNb[tS].setAux(heightOffset, widthOffset, it, subIterations, tiling.coreWidthOffset, tiling.coreHeightOffset, tiling.coreDepthOffset, tiling.coreWidth, tiling.coreHeight, tiling.coreDepth, outterIterations, tiling.height, tiling.width, tiling.depth, this->input.getWidth());
    					outputNumberNb[tS].copyToAux();
    					outputNumberNb[tS].waitAuxWrite();
                        tS++;
                        if (tS >= nb_clusters) {
                            auxHt = hTiling;
                            auxWt = wTiling;
                        }
                    }
                    if (auxWt == wTiling) {
                        auxWt = 0;
                    }

				}

				for (int i = 0; i < nb_clusters; i++) {
					outputNumberNb[i].closeAuxWritePortal();
				}

				// #ifdef DEBUG
				// 	cout<<"MASTER["<<it<<"]: Barrier 3 from tile: "<< i <<endl;
				// #endif
				//mppa_barrier_wait(barrierNbClusters);

				for (int i = 0; i < nb_clusters; i++) {
					cluster[i].portalWriteAlloc(i);
				}
				#ifdef DEBUG
					cout<<"MASTER["<<it<<"]: Barrier 3 from tile: " << i <<endl;
				#endif
				mppa_barrier_wait(barrierNbClusters);
				//for (int j = 0; j < nb_clusters; j++) {
                tS = 0;
                ht = baseItHt;
                wt = baseItWt;
                if (wt == wTiling) {
                    ht++;
                    wt = 0;
                    //baseItWt = 0;
                }
                // #ifdef DEBUG
				// 	cout<<"MASTER["<<it<<"]: Barrier 5 from tile: " << i <<endl;
				// #endif
				//mppa_barrier_wait(barrierNbClusters);

                # if defined (DEBUG) || defined (TIME_EXEC)
  				hrt_start(&sendTimerMaster);
  				#endif
                for (ht; ht < hTiling; ht++) {
                    //wt = baseItWt;
                    for (wt; wt < wTiling; wt++) {
    					heightOffset = ht*tilingHeight;
                        widthOffset = wt*tilingWidth;
    					tiling.tile(subIterations, widthOffset, heightOffset, 0, tilingWidth, tilingHeight, 1);	
    					tmp.hostSlice(tiling.input, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
                        cluster[tS].mppaMasterClone(tmp);
    					cluster[tS].copyTo();
    					cluster[tS].waitWrite();
                        tS++;
                        if (tS >= nb_clusters) {
                            baseItHt = ht;
                            ht = hTiling;
                            baseItWt = wt + 1;
                            wt = wTiling;
                        }
                    }
                    if (wt == wTiling) {
                        wt = 0;
                    }

				}

				# if defined (DEBUG) || defined (TIME_EXEC)
  				hrt_stop(&sendTimerMaster);
  				#endif

                #ifdef DEBUG
					cout<<"MASTER["<<it<<"]: Waiting processed data from clusters"<<endl;
				#endif


				// #ifdef DEBUG
				// 	cout<<"MASTER["<<it<<"]: Barrier 6 from tile: " << i <<endl;
				// #endif
				//mppa_barrier_wait(barrierNbClusters);

                this->output.setTrigger(tilingHeight);
                for (int i = 0; i < nb_clusters; i++) { 
    				this->output.copyFrom();
                }
				#ifdef DEBUG
					cout<<"MASTER["<<it<<"]: Received processed data from clusters"<<endl;
				#endif
                

    			for (int i = 0; i < nb_clusters; i++) {
                    cluster[i].mppaFree();
    				cluster[i].closeWritePortal();
                }

  				# if defined (DEBUG) || defined (TIME_SEND)
				cout << "Master Send Time: " << hrt_elapsed_time(&sendTimerMaster) << " from iteration: " << it << " and tile: " << i << endl;
				#endif
		   	}
            int hTilingMod = hTiling;
            int wTilingMod = wTiling;
            if (itMod == 0) {
                hTilingMod = itMod;
                wTilingMod = itMod;
            }
			#ifdef DEBUG
				cout<<"MASTER["<<it<<"]: Barrier 4"<<endl;
			#endif
			mppa_barrier_wait(barrierNbClusters);

			for(int j = 0; j < itMod; j++) {
				outputNumberMod[j].portalAuxWriteAlloc(j);
			}
			
			#ifdef DEBUG
				cout<<"MASTER["<<it<<"]: Barrier 5"<<endl;
			#endif
			mppa_barrier_wait(barrierNbClusters);
            int tS = 0;
            auxHt = baseItHt;
            auxWt = baseItWt;
            if (auxWt == wTilingMod) {
                auxHt++;
                auxWt = 0;
                //baseItWt = 0;
            }
			for (auxHt; auxHt < hTilingMod; auxHt++) {
                for (auxWt; auxWt < wTilingMod; auxWt++) {
                    heightOffset = auxHt*tilingHeight;
                    widthOffset = auxWt*tilingWidth;
                    tiling.tile(subIterations, widthOffset, heightOffset, 0, tilingWidth, tilingHeight, 1);
                    outputNumberMod[tS].hostSlice(tiling.input, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
                    outputNumberMod[tS].setAux(heightOffset, widthOffset, it, subIterations, tiling.coreWidthOffset, tiling.coreHeightOffset, tiling.coreDepthOffset, tiling.coreWidth, tiling.coreHeight, tiling.coreDepth, outterIterations, tiling.height, tiling.width, tiling.depth, this->input.getWidth());
                    outputNumberMod[tS].copyToAux();
                    outputNumberMod[tS].waitAuxWrite();
                    tS++;
                }
                auxWt = 0;
            }
			
			for(int i = 0; i < itMod; i++) {
				outputNumberMod[i].closeAuxWritePortal();
			}

			// #ifdef DEBUG
			// 	cout<<"MASTER["<<it<<"]: Barrier 9"<<endl;
			// #endif
			//mppa_barrier_wait(barrierNbClusters);
			
			for(int j = 0; j < itMod; j++) {
				cluster[j].portalWriteAlloc(j);
			}

			#ifdef DEBUG
				cout<<"MASTER["<<it<<"]: Barrier 6"<<endl;
			#endif
			mppa_barrier_wait(barrierNbClusters);
            
            tS = 0;
            ht = baseItHt;
            wt = baseItWt;
            if (wt == wTiling) {
                ht++;
                wt = 0;
                //baseItWt = 0;
            }

            # if defined (DEBUG) || defined (TIME_EXEC)
  			hrt_start(&modTimerMaster);
  			#endif
			//mppa_barrier_wait(barrierNbClusters);
			for (ht; ht < hTilingMod; ht++) {
                for (wt; wt < wTilingMod; wt++) {
                    heightOffset = ht*tilingHeight;
                    widthOffset = wt*tilingWidth;
                    tiling.tile(subIterations, widthOffset, heightOffset, 0, tilingWidth, tilingHeight, 1);
                    cluster[tS].hostSlice(tiling.input, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
                    cluster[tS].copyTo();
                    cluster[tS].waitWrite();
                    tS++;
                }
                wt = 0;
			}
			# if defined (DEBUG) || defined (TIME_EXEC)
  			hrt_stop(&modTimerMaster);
  			#endif

			this->output.setTrigger(itMod);

			// mppa_barrier_wait(barrierNbClusters);

			this->output.copyFrom();

			#ifdef DEBUG
					cout<<"MASTER["<<it<<"]: Received processed data of remaining tiles from clusters"<<endl;
			#endif

			for (int i = 0; i < itMod; i++) {
				cluster[i].closeWritePortal();
			}
			for(int i = 0; i < itMod; i++) {
				outputNumberMod[i].auxFree();
			}
			#ifdef DEBUG
				cout<<"MASTER["<<it<<"]: Barrier CLOSED"<<endl;
			#endif
			mppa_close_barrier(barrierNbClusters);

	  		# if defined (DEBUG) || defined (TIME_SEND)
			cout << "Master Send Mod Time: "<< hrt_elapsed_time(&modTimerMaster) << " from iteration: " << it << endl;
			#endif
		}
		
		inputCopy.mppaMasterCopy(this->input);
		this->input.mppaMasterCopy(this->output);
		this->output.mppaMasterCopy(inputCopy);



	}

	# if defined (DEBUG) || defined (TIME_EXEC)
	hrt_stop(&totTimerMaster);
	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
	cout << "Master Total Time: "<< hrt_elapsed_time(&totTimerMaster) << endl;
	#endif

	inputCopy.mppaFree();
    this->output.closeReadPortal();
	this->output.mppaMasterCopy(this->input);
	

	#ifdef PRINT_OUT
	  
	for(size_t h=0;h<this->output.getHeight();h++) {
		for(size_t w=0;w<this->output.getWidth();w++) {
	    	printf("FinalOutput(%d,%d):%f\n",h,w, output(h,w));
	    }
	}
  
  	#endif
}
#endif




#ifdef PSKEL_MPPA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::waitSlaves(int nb_clusters, int tilingHeight, int tilingWidth) {
	size_t hTiling = ceil(float(this->input.getHeight())/float(tilingHeight));
	size_t wTiling = ceil(float(this->input.getHeight())/float(tilingWidth));
	size_t totalSize = float(hTiling*wTiling);
	int pid;
	if(totalSize < nb_clusters)
		nb_clusters = totalSize;
	for (pid = 0; pid < nb_clusters; pid++) {
    		mppa_waitpid(pid, NULL, 0);
	}
}
#endif


#ifdef PSKEL_MPPA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::scheduleMPPA(const char slave_bin_name[], int nb_clusters, int nb_threads, size_t tilingHeight, size_t tilingWidth, int iterations, int innerIterations){
	

	# if defined (DEBUG) || defined (TIME_EXEC)
	hr_timer_t scheduleTimerSpawn;
	hr_timer_t scheduleTimerSlice;
	hr_timer_t scheduleTimerWait;
	hr_timer_t scheduleTimer;
	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
  	hrt_start(&scheduleTimer);
  	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
  	hrt_start(&scheduleTimerSpawn);
  	#endif
	this->spawn_slaves(slave_bin_name, tilingHeight, tilingWidth, nb_clusters, nb_threads, iterations, innerIterations);
	# if defined (DEBUG) || defined (TIME_EXEC)
	hrt_stop(&scheduleTimerSpawn);
	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
	cout << "Schedule Time Spawn: "<< hrt_elapsed_time(&scheduleTimerSpawn) << endl;
	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
	hrt_start(&scheduleTimerSlice);
	#endif
	this->mppaSlice(tilingHeight, tilingWidth, nb_clusters, iterations, innerIterations);
	# if defined (DEBUG) || defined (TIME_EXEC)
  	hrt_stop(&scheduleTimerSlice);
  	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
	cout << "Schedule Slice Time: "<< hrt_elapsed_time(&scheduleTimerSlice) << endl;
	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
  	hrt_start(&scheduleTimerWait);
  	#endif
	this->waitSlaves(nb_clusters, tilingHeight, tilingWidth);
	# if defined (DEBUG) || defined (TIME_EXEC)
  	hrt_stop(&scheduleTimerWait);
  	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
  	hrt_stop(&scheduleTimer);
  	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
	cout << "Schedule Wait Time: "<< hrt_elapsed_time(&scheduleTimerWait) << endl;
	#endif

	# if defined (DEBUG) || defined (TIME_EXEC)
	cout << "Schedule Time: "<< hrt_elapsed_time(&scheduleTimer) << endl;
	#endif

}
#endif


#ifdef PSKEL_MPPA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runMPPA(int cluster_id, int nb_threads, int nb_tiles, int outterIterations, int itMod){
	Array finalArr;
	Array coreTmp;
	Array tmp;
	Array inputTmp;
	Array outputTmp;
	Array auxPortal;
	int *aux;
	# if defined (DEBUG) || defined (TIME_EXEC)
	hr_timer_t totTimerSlave;
	hr_timer_t compTimerSlave;
	hr_timer_t sendTimerSlave;
	//timer
  	hrt_start(&totTimerSlave);
  	#endif
	
	#ifdef DEBUG
	cout<<"SLAVE["<<cluster_id<<"]: opened finalArr portal in write mode"<<endl;
	#endif	

	for(int j = 0; j < outterIterations; j++) {
		barrier_t *global_barrier = mppa_create_slave_barrier(BARRIER_SYNC_MASTER, BARRIER_SYNC_SLAVE);
		for(int i = 0; i < nb_tiles; i++) {
			mppa_barrier_wait(global_barrier);
			//auxPortal.auxAlloc();
			
			if(i == 0) {
				auxPortal.portalAuxReadAlloc(1, cluster_id);
				finalArr.portalWriteAlloc(0);
				#ifdef DEBUG
				cout<<"SLAVE["<<cluster_id<<"]: opened auxPortal in read mode for iteration #"<<j<<endl;
				#endif
			}
			mppa_barrier_wait(global_barrier);

	
			auxPortal.copyFromAux();

			#ifdef DEBUG
			cout<<"SLAVE["<<cluster_id<<"]: copied data from auxPortal"<<endl;
			#endif
			
			aux = auxPortal.getAux();

			int heightOffset = aux[0];
			int it = aux[1];
			int subIterations = aux[2];
			// int subIterations = 1;
			int coreWidthOffset = aux[3];
			int coreHeightOffset = aux[4];
			int coreDepthOffset = aux[5];
			int coreWidth = aux[6];
			int coreHeight = aux[7];
			int coreDepth = aux[8];
			int h = aux[10];
			// int h = 128;
			int w = aux[11];
			// int w = 128;
			int d = aux[12];
			// int d = 1;
            int widthOffset = aux[13];
            int baseWidth = aux[14];


			#ifdef DEBUG
			// cout<< "SLAVE["<<cluster_id<<"]"<<endl;
			cout<<"SLAVE["<<cluster_id<<"]: values of h: " << h << " w: " << w << " d: " << d <<endl;
			#endif
			//mppa_barrier_wait(global_barrier);
			tmp.mppaAlloc(w,h,d);
			inputTmp.mppaAlloc(w,h,d);
			outputTmp.mppaAlloc(w,h,d);
			inputTmp.portalReadAlloc(1, cluster_id);
			mppa_barrier_wait(global_barrier);

			#ifdef DEBUG
			cout<<"SLAVE["<<cluster_id<<"]: opened inputTmp portal in read mode of iteration #"<<j<<endl;
			#endif
			



			//mppa_barrier_wait(global_barrier);
			inputTmp.copyFrom();

			#ifdef DEBUG
			cout<<"SLAVE["<<cluster_id<<"]: is processing tile of iteration #"<<j<<" with "<<subIterations<<" subIterations"<<endl;
			#endif
			//time
			# if defined (DEBUG) || defined (TIME_EXEC)
			hrt_start(&compTimerSlave);
			#endif


			this->runIterativeMPPA(inputTmp, outputTmp, subIterations, nb_threads);

			# if defined (DEBUG) || defined (TIME_EXEC)
			hrt_stop(&compTimerSlave);
			cout << "Slave["<< cluster_id << "] Computation Time: " << hrt_elapsed_time(&compTimerSlave) << endl;
			#endif

			#ifdef DEBUG
			cout<<"SLAVE["<<cluster_id<<"]: finished processing tile of iteration #"<<j<<endl;
			#endif

			if (subIterations%2==0) {
				tmp.mppaMemCopy(inputTmp);
			} else {
				tmp.mppaMemCopy(outputTmp);
			}

            Array fTmp;
			fTmp.hostSlice(tmp, coreWidthOffset, coreHeightOffset, coreDepthOffset, coreWidth, coreHeight, coreDepth);
            finalArr.mppaClone(fTmp);


            int slaveBaseHeight = 0;
            int tam = finalArr.getWidth()*finalArr.getDepth();
            int masterBaseWidth = (heightOffset*baseWidth) + widthOffset;
            # if defined (DEBUG) || defined (TIME_EXEC)
			hrt_start(&sendTimerSlave);
			#endif
            for (int i = 0; i < finalArr.getHeight(); i++) {
                finalArr.copyTo(slaveBaseHeight, masterBaseWidth, tam);
                slaveBaseHeight += finalArr.getWidth();
                masterBaseWidth += baseWidth;
            	finalArr.waitWrite();
            }
			# if defined (DEBUG) || defined (TIME_EXEC)
			hrt_stop(&sendTimerSlave);
			#endif
			//mppa_barrier_wait(global_barrier);

			tmp.mppaFree();
			tmp.auxFree();
			#ifdef DEBUG
			cout<<"SLAVE["<<cluster_id<<"]: copied tile data of iteration #"<<j<<" to master"<<endl;
			#endif
			

			inputTmp.mppaFree();
			inputTmp.auxFree();

			outputTmp.mppaFree();
			outputTmp.auxFree();

			//auxPortal.mppaFree();
            finalArr.mppaFree();
            finalArr.auxFree();
			inputTmp.closeReadPortal();
			#ifdef DEBUG
			cout<<"SLAVE["<<cluster_id<<"]: closed read portal of inputTmp for tile  of iteration #"<<j<<endl;
			#endif
			if (i == (nb_tiles-1)) {
				auxPortal.closeAuxReadPortal();
				finalArr.closeWritePortal();
				#ifdef DEBUG
				cout<<"SLAVE["<<cluster_id<<"]: closed read portal of auxPortal for iteration #"<<j<<endl;
				#endif
						
			}
		}
		if(cluster_id >= itMod) {

			#ifdef DEBUG
			cout<<"SLAVE["<<cluster_id<<"]: is insided InOut Barrier for iteration "<<j<<endl;
			#endif
			//mppa_barrier_wait(global_barrier);
			//mppa_barrier_wait(global_barrier);
			//mppa_barrier_wait(global_barrier);
			mppa_barrier_wait(global_barrier);
			mppa_barrier_wait(global_barrier);
			mppa_barrier_wait(global_barrier);
		}
		//finalArr.mppaFree();
		//finalArr.auxFree();
		mppa_close_barrier(global_barrier);
	}
	//time
	# if defined (DEBUG) || defined (TIME_EXEC)
	hrt_stop(&totTimerSlave);
	cout << "Slave["<< cluster_id << "] Total Time: "<< hrt_elapsed_time(&totTimerSlave) << endl;
	cout << "Slave["<< cluster_id << "] Send Time: " << hrt_elapsed_time(&sendTimerSlave) << endl;
	#endif

	#ifdef DEBUG
	cout<<"SLAVE["<<cluster_id<<"]: closed write portal for finalArr"<<endl;
	#endif
	
}
#endif

<<<<<<< HEAD
#ifdef PSKEL_MPPA
=======
#ifndef MPPA_MASTER
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativeMPPA(Array in, Array out, int iterations, size_t numThreads){
	for(int i = 0; i < iterations; i++) {
		if(i%2==0) {
			this->runOpenMP(in, out, numThreads);
		} else {
			this->runOpenMP(out, in, numThreads);

		}
	}

}
#endif
//*******************************************************************************************
//*******************************************************************************************
#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runCPU(size_t numThreads){
	numThreads = (numThreads==0)?omp_get_num_procs():numThreads;
<<<<<<< HEAD
	#ifdef PSKEL_TBB
		this->runTBB(this->input, this->output, numThreads);
	#else
		this->runOpenMP(this->input, this->output, numThreads);
=======
	size_t maskRange = this->mask.getRange();
	#ifdef PSKEL_TBB
		this->runTBB(this->input, this->output, numThreads);
	#else
		this->runOpenMP(this->input, this->output, this->input.getWidth(),this->input.getHeight(),this->input.getDepth,maskRange);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
	#endif
}
#endif

#ifdef PSKEL_CUDA
template<class Array, class Mask, class Args>
<<<<<<< HEAD
void StencilBase<Array, Mask,Args>::runGPU(size_t GPUBlockSize){
	if(GPUBlockSize==0){
=======
void StencilBase<Array, Mask,Args>::runGPU(size_t GPUBlockSizeX, size_t GPUBlockSizeY){
	if(GPUBlockSizeX==0){
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		int device;
		cudaGetDevice(&device);
		cudaDeviceProp deviceProperties;
		cudaGetDeviceProperties(&deviceProperties, device);
		//GPUBlockSize = deviceProperties.maxThreadsPerBlock/2;
<<<<<<< HEAD
		GPUBlockSize = deviceProperties.warpSize;
=======
		GPUBlockSizeX = GPUBlockSizeY = deviceProperties.warpSize;
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		//int minGridSize, blockSize;
		//cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, stencilTilingCU, 0, in.size());
		//GPUBlockSize = blockSize;
		//cout << "GPUBlockSize: "<<GPUBlockSize<<endl;
		//int maxActiveBlocks;
  		//cudaOccupancyMaxActiveBlocksPerMultiprocessor(&maxActiveBlocks, stencilTilingCU, GPUBlockSize, 0);
		//float occupancy = (maxActiveBlocks * GPUBlockSize / deviceProperties.warpSize) / 
                //    (float)(deviceProperties.maxThreadsPerMultiProcessor / 
                //            deviceProperties.warpSize);
		//printf("Launched blocks of size %d. Theoretical occupancy: %f\n", GPUBlockSize, occupancy);
	}
	input.deviceAlloc();
	output.deviceAlloc();
	mask.deviceAlloc();
	mask.copyToDevice();
	input.copyToDevice();
	//this->setGPUInputData();
<<<<<<< HEAD
	this->runCUDA(this->input, this->output, GPUBlockSize);
=======
	this->runCUDA(this->input, this->output, GPUBlockSizeX, GPUBlockSizeY);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
	//this->getGPUOutputData();
	output.copyToHost();
	input.deviceFree();
	output.deviceFree();
	mask.deviceFree();
}
#endif

#ifdef PSKEL_CUDA
template<class Array, class Mask, class Args>
<<<<<<< HEAD
void StencilBase<Array, Mask,Args>::runTilingGPU(size_t tilingWidth, size_t tilingHeight, size_t tilingDepth, size_t GPUBlockSize){
	if(GPUBlockSize==0){
=======
void StencilBase<Array, Mask,Args>::runTilingGPU(size_t tilingWidth, size_t tilingHeight, size_t tilingDepth, size_t GPUBlockSizeX, size_t GPUBlockSizeY){
	if(GPUBlockSizeX==0){
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		int device;
		cudaGetDevice(&device);
		cudaDeviceProp deviceProperties;
		cudaGetDeviceProperties(&deviceProperties, device);
		//GPUBlockSize = deviceProperties.maxThreadsPerBlock/2;
<<<<<<< HEAD
		GPUBlockSize = deviceProperties.warpSize;
=======
		GPUBlockSizeX = GPUBlockSizeY = deviceProperties.warpSize;
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		//int minGridSize, blockSize;
		//cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, stencilTilingCU, 0, in.size());
		//GPUBlockSize = blockSize;
		//cout << "GPUBlockSize: "<<GPUBlockSize<<endl;
		//int maxActiveBlocks;
  		//cudaOccupancyMaxActiveBlocksPerMultiprocessor(&maxActiveBlocks, stencilTilingCU, GPUBlockSize, 0);
		//float occupancy = (maxActiveBlocks * GPUBlockSize / deviceProperties.warpSize) / 
                //    (float)(deviceProperties.maxThreadsPerMultiProcessor / 
                //            deviceProperties.warpSize);
		//printf("Launched blocks of size %d. Theoretical occupancy: %f\n", GPUBlockSize, occupancy);
	}
	size_t wTiling = ceil(float(this->input.getWidth())/float(tilingWidth));
	size_t hTiling = ceil(float(this->input.getHeight())/float(tilingHeight));
	size_t dTiling = ceil(float(this->input.getDepth())/float(tilingDepth));
	mask.deviceAlloc();
	mask.copyToDevice();
	//setGPUMask();
	StencilTiling<Array, Mask> tiling(input, output, mask);
	Array inputTile;
	Array outputTile;
	Array tmp;
	for(size_t ht=0; ht<hTiling; ht++){
	 for(size_t wt=0; wt<wTiling; wt++){
	  for(size_t dt=0; dt<dTiling; dt++){
		size_t heightOffset = ht*tilingHeight;
		size_t widthOffset = wt*tilingWidth;
		size_t depthOffset = dt*tilingDepth;
		//CUDA input memory copy
		tiling.tile(1, widthOffset, heightOffset, depthOffset, tilingWidth, tilingHeight, tilingDepth);
		inputTile.hostSlice(tiling.input, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
		outputTile.hostSlice(tiling.output, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
		inputTile.deviceAlloc();
		outputTile.deviceAlloc();
		inputTile.copyToDevice();
		tmp.hostAlloc(tiling.width, tiling.height, tiling.depth);
		//this->setGPUInputDataIterative(inputCopy, output, innerIterations, widthOffset, heightOffset, depthOffset, tilingWidth, tilingHeight, tilingDepth);
		//CUDA kernel execution
<<<<<<< HEAD
		this->runIterativeTilingCUDA(inputTile, outputTile, tiling, GPUBlockSize);
=======
		this->runIterativeTilingCUDA(inputTile, outputTile, tiling, GPUBlockSizeX, GPUBlockSizeY);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		tmp.copyFromDevice(outputTile);
		Array coreTmp;
		Array coreOutput;
		coreTmp.hostSlice(tmp, tiling.coreWidthOffset, tiling.coreHeightOffset, tiling.coreDepthOffset, tiling.coreWidth, tiling.coreHeight, tiling.coreDepth);
		coreOutput.hostSlice(outputTile, tiling.coreWidthOffset, tiling.coreHeightOffset, tiling.coreDepthOffset, tiling.coreWidth, tiling.coreHeight, tiling.coreDepth);
		coreOutput.hostMemCopy(coreTmp);
		tmp.hostFree();
	}}}
	inputTile.deviceFree();
	outputTile.deviceFree();
	mask.deviceFree();
	cudaDeviceSynchronize();
}
#endif

#ifdef PSKEL_CUDA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runAutoGPU(size_t GPUBlockSize){
	size_t gpuMemFree, gpuMemTotal;
	//gpuErrchk( cudaDeviceSynchronize() );
	cudaMemGetInfo(&gpuMemFree, &gpuMemTotal);
	if((this->input.memSize()+this->output.memSize()+this->mask.memSize())<(0.998*gpuMemFree)){
		runGPU(GPUBlockSize);
	}else{
		size_t typeSize = this->input.memSize()/this->input.size();
		float div = float(this->input.memSize()+this->output.memSize())/((gpuMemFree-this->mask.memSize())*0.97);
		if(this->input.getHeight()==1){
			size_t width = floor(float(this->input.getWidth())/div);
			width = (width>0)?width:1;
			while( (((this->input.getHeight()*this->input.getDepth()+this->output.getHeight()*this->output.getDepth())*(2*this->mask.getRange() + width))*typeSize + this->mask.memSize()) > gpuMemFree*0.998 ){
				width+=2;
			}
			while( (((this->input.getHeight()*this->input.getDepth()+this->output.getHeight()*this->output.getDepth())*(2*this->mask.getRange() + width))*typeSize + this->mask.memSize()) > gpuMemFree*0.998 ){
				width--;
			}
			runTilingGPU(width, this->input.getHeight(), this->input.getDepth(), GPUBlockSize);
		}else{
			size_t height = floor(float(this->input.getHeight())/div);
			height = (height>0)?height:1;
			while( (((this->input.getWidth()*this->input.getDepth()+this->output.getWidth()*this->output.getDepth())*(2*this->mask.getRange() + height))*typeSize + this->mask.memSize()) < gpuMemFree*0.998 ){
				height+=2;
			}
			while( (((this->input.getWidth()*this->input.getDepth()+this->output.getWidth()*this->output.getDepth())*(2*this->mask.getRange() + height))*typeSize + this->mask.memSize()) > gpuMemFree*0.998 ){
				height--;
			}
			runTilingGPU(this->input.getWidth(), height, this->input.getDepth(), GPUBlockSize);
		}
	}
}
#endif

#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativeSequential(size_t iterations){
	Array inputCopy;
	inputCopy.hostClone(input);
	for(size_t it = 0; it<iterations; it++){
		if(it%2==0) this->runSeq(inputCopy, this->output);
		else this->runSeq(this->output, inputCopy);
	}
	if((iterations%2)==0) output.hostMemCopy(inputCopy);
	inputCopy.hostFree();
}
#endif

#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativeCPU(size_t iterations, size_t numThreads){
	numThreads = (numThreads==0)?omp_get_num_procs():numThreads;
<<<<<<< HEAD
	//cout << "numThreads: " << numThreads << endl;
	Array inputCopy;
	inputCopy.hostClone(input);
	for(size_t it = 0; it<iterations; it++){
		if(it%2==0){
			#ifdef PSKEL_TBB
				this->runTBB(inputCopy, this->output, numThreads);
			#else
				this->runOpenMP(inputCopy, this->output, numThreads);
			#endif
		}else {
			#ifdef PSKEL_TBB
				this->runTBB(this->output, inputCopy, numThreads);
			#else
				this->runOpenMP(this->output, inputCopy, numThreads);
			#endif
		}
	}
	if((iterations%2)==0) output.hostMemCopy(inputCopy);
	inputCopy.hostFree();
}
#endif

#ifdef PSKEL_CUDA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativeGPU(size_t iterations, size_t GPUBlockSize){
	if(GPUBlockSize==0){
=======
	omp_set_num_threads(numThreads);
	#ifdef PSKEL_TBB
	//tbb::task_scheduler_init::automatic; //(numThreads);
	#endif
	double start,end;

	size_t width = this->input.getWidth();
	size_t height = this->input.getHeight();
	size_t depth = this->input.getDepth();
	size_t maskRange = this->mask.getRange();
	//cout << "numThreads: " << numThreads << endl;
	//Array inputCopy;
	//inputCopy.hostClone(input);
	start = omp_get_wtime();
	for(size_t it = 0; it<iterations; it++){
		if(it%2==0){
			#ifdef PSKEL_TBB
				this->runTBB(input, this->output, numThreads);
			#else
				this->runOpenMP(input, this->output, width, height, depth, maskRange);
			#endif
		}else {
			#ifdef PSKEL_TBB
				this->runTBB(this->output, input, numThreads);
			#else
				this->runOpenMP(this->output, input, width, height, depth,  maskRange);
			#endif
		}
	}
	if((iterations%2)==0) output.hostMemCopy(input);
	end = omp_get_wtime();
	cout<<"CPU Time : "<<end-start<<endl;
	//inputCopy.hostFree();
}
#endif


#ifdef PSKEL_CUDA
/*Shared memory development*/
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativeGPU(size_t iterations, size_t pyramidHeight,size_t GPUBlockSizeX, size_t GPUBlockSizeY){
	if(GPUBlockSizeX==0){
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		int device;
		cudaGetDevice(&device);
		cudaDeviceProp deviceProperties;
		cudaGetDeviceProperties(&deviceProperties, device);
		//GPUBlockSize = deviceProperties.maxThreadsPerBlock/2;
<<<<<<< HEAD
		GPUBlockSize = deviceProperties.warpSize;
=======
		GPUBlockSizeX = deviceProperties.warpSize;
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		//int minGridSize, blockSize;
		//cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, stencilTilingCU, 0, in.size());
		//GPUBlockSize = blockSize;
		//cout << "GPUBlockSize: "<<GPUBlockSize<<endl;
		//int maxActiveBlocks;
  		//cudaOccupancyMaxActiveBlocksPerMultiprocessor(&maxActiveBlocks, stencilTilingCU, GPUBlockSize, 0);
		//float occupancy = (maxActiveBlocks * GPUBlockSize / deviceProperties.warpSize) / 
                //    (float)(deviceProperties.maxThreadsPerMultiProcessor / 
                //            deviceProperties.warpSize);
		//printf("Launched blocks of size %d. Theoretical occupancy: %f\n", GPUBlockSize, occupancy);
	}
	input.deviceAlloc();
	input.copyToDevice();
	mask.deviceAlloc();
	mask.copyToDevice();
	output.deviceAlloc();
<<<<<<< HEAD
=======
	size_t maskRange = mask.getRange();

	/* Hotspot method, bad performance */
	/*
	#define EXPAND_RATE 2// add one iteration will extend the pyramid base by 2 per each borderline
    size_t borderCols = (pyramidHeight)*EXPAND_RATE/2;
    size_t borderRows = (pyramidHeight)*EXPAND_RATE/2;
    size_t smallBlockCol = BLOCK_SIZE-(pyramidHeight)*EXPAND_RATE;
    size_t smallBlockRow = BLOCK_SIZE-(pyramidHeight)*EXPAND_RATE;
    size_t blockCols = input.getWidth()  /smallBlockCol+((input.getWidth() % smallBlockCol==0)?0:1);
    size_t blockRows = input.getHeight() /smallBlockRow+((input.getHeight()% smallBlockRow==0)?0:1);
    dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);

    dim3 dimGrid(blockCols, blockRows);

    printf("pyramidHeight: %d\ngridSize: [%d, %d]\nborder:[%d, %d]\nblockGrid:[%d, %d]\ntargetBlock:[%d, %d]\n",\
           pyramidHeight, input.getWidth(), input.getHeight(), borderCols, borderRows, blockCols, blockRows, smallBlockCol, smallBlockRow);  

	for(size_t t = 0; t<iterations; t+=pyramidHeight){
		size_t it = MIN(pyramidHeight, iterations-t);
		if((it%2)==0)
			stencilTilingCU<<<dimGrid, dimBlock>>>(this->input, this->output, this->mask,this->args,maskRange,it,input.getWidth(),input.getHeight(),input.getDepth(),borderCols,borderRows);
		else stencilTilingCU<<<dimGrid, dimBlock>>>(this->output, this->input, this->mask,this->args,maskRange,it,input.getWidth(),input.getHeight(),input.getDepth(),borderCols,borderRows);
 
	*/
	
	/*Howelinsk method */
	//dim3 dimGrid(input.getWidth() / GPUBlockSizeX, input.getHeight() / GPUBlockSizeY);
    dim3 dimBlock(GPUBlockSizeX, GPUBlockSizeY);
    //dim3 dimBlock(GPUBlockSizeX, GPUBlockSizeY);
    int EffectiveBlockSizeX = GPUBlockSizeX- 2*(pyramidHeight);
    int EffectiveBlockSizeY = GPUBlockSizeY- 2*(pyramidHeight);
    size_t HaloX = 2*(pyramidHeight)*(input.getWidth()/dimBlock.x) + ((input.getWidth()%GPUBlockSizeX== 0)?0:1);
    size_t HaloY = 2*(pyramidHeight)*(input.getHeight()/dimBlock.y) + ((input.getHeight()%GPUBlockSizeY == 0)?0:1);
    size_t gridX = input.getWidth() + HaloX;
    size_t gridY = input.getHeight() + HaloY;

    dim3 dimGrid((input.getWidth()+HaloX)  /GPUBlockSizeX  + ((input.getWidth()%dimBlock.x == 0)?0:1), 
                 (input.getHeight()+HaloY) /GPUBlockSizeY + ((input.getHeight()%dimBlock.y == 0)?0:1));
    //dim3 dimGrid = ( gridX/GPUBlockSizeX, gridY/GPUBlockSizeY );
    const int sharedMemSize = dimBlock.x * dimBlock.y * sizeof(input(0,0)); //need to get this size from somewhere
    
    #ifdef PSKEL_DEBUG
    printf("Input Size [%ld,%ld] Halo[%ld,%ld] Effective Block Size: [%d,%d] Block Size: [%d,%d] Grid Size: [%d,%d] Shared Mem Size: %d bytes\n",
        input.getWidth(), input.getHeight(), HaloX, HaloY, EffectiveBlockSizeX, EffectiveBlockSizeY,dimBlock.x,dimBlock.y,dimGrid.x,dimGrid.y,sharedMemSize);
    #endif

	
	size_t it = 0;
	for(size_t t = 0; t<iterations; t+=pyramidHeight){
		//size_t it = MIN(pyramidHeight, iterations-t);
		if((it%2)==0){
            #ifdef PSKEL_DEBUG
                printf("Odd Iteration %ld\n",it);
            #endif
			stencilTilingCU<<<dimGrid, dimBlock, sharedMemSize>>>(this->input, this->output, this->mask, this->args,maskRange,pyramidHeight,input.getWidth(),input.getHeight(),input.getDepth());
        }
        else{
            #ifdef PSKEL_DEBUG
                printf("Even Iteration %ld\n",it);
            #endif
            stencilTilingCU<<<dimGrid, dimBlock, sharedMemSize>>>(this->output, this->input, this->mask,this->args, maskRange,pyramidHeight,input.getWidth(),input.getHeight(),input.getDepth());
        }
        it++;
	}
    	gpuErrchk( cudaPeekAtLastError() );
	gpuErrchk( cudaDeviceSynchronize() );
	if((it%2)==1)
		output.copyToHost();
	else output.copyFromDevice(input);
	input.deviceFree();
	mask.deviceFree();
	output.deviceFree();
}
#endif


#ifdef PSKEL_CUDA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativeGPU(size_t iterations, size_t GPUBlockSizeX, size_t GPUBlockSizeY){
	if(GPUBlockSizeX==0){
		int device;
		cudaGetDevice(&device);
		cudaDeviceProp deviceProperties;
		cudaGetDeviceProperties(&deviceProperties, device);
		//GPUBlockSize = deviceProperties.maxThreadsPerBlock/2;
		GPUBlockSizeX = deviceProperties.warpSize;
		//int minGridSize, blockSize;
		//cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, stencilTilingCU, 0, in.size());
		//GPUBlockSize = blockSize;
		//cout << "GPUBlockSize: "<<GPUBlockSize<<endl;
		//int maxActiveBlocks;
  		//cudaOccupancyMaxActiveBlocksPerMultiprocessor(&maxActiveBlocks, stencilTilingCU, GPUBlockSize, 0);
		//float occupancy = (maxActiveBlocks * GPUBlockSize / deviceProperties.warpSize) / 
                //    (float)(deviceProperties.maxThreadsPerMultiProcessor / 
                //            deviceProperties.warpSize);
		//printf("Launched blocks of size %d. Theoretical occupancy: %f\n", GPUBlockSize, occupancy);
	}
	input.deviceAlloc();
	mask.deviceAlloc();
	output.deviceAlloc();

	double start = omp_get_wtime();
	mask.copyToDevice();
	input.copyToDevice();
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
	//output.copyToDevice();
	//this->setGPUInputData();
	for(size_t it = 0; it<iterations; it++){
		if((it%2)==0)
<<<<<<< HEAD
			this->runCUDA(this->input, this->output, GPUBlockSize);
		else this->runCUDA(this->output, this->input, GPUBlockSize);
=======
			this->runCUDA(this->input, this->output, GPUBlockSizeX, GPUBlockSizeY);
		else this->runCUDA(this->output, this->input, GPUBlockSizeX, GPUBlockSizeY);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
	}
	if((iterations%2)==1)
		output.copyToHost();
	else output.copyFromDevice(input);
<<<<<<< HEAD
=======
	double end = omp_get_wtime();
	cout<<"GPU Time: "<<end-start<<endl;
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
	input.deviceFree();
	mask.deviceFree();
	output.deviceFree();
	//this->getGPUOutputData();
}
#endif

<<<<<<< HEAD
#ifdef PSKEL_CUDA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativeTilingGPU(size_t iterations, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth, size_t innerIterations, size_t GPUBlockSize){
	if(GPUBlockSize==0){
=======
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativePartition(size_t iterations, float gpuFactor, size_t numThreads, size_t GPUBlockSizeX, size_t GPUBlockSizeY){
	numThreads = (numThreads==0)?omp_get_num_procs():numThreads;
	double start, startCPU, startGPU, end, endCPU,endGPU;
	if(GPUBlockSizeX==0){
		int device;
		cudaGetDevice(&device);
		cudaDeviceProp deviceProperties;
		cudaGetDeviceProperties(&deviceProperties, device);
		//GPUBlockSize = deviceProperties.maxThreadsPerBlock/2;
		GPUBlockSizeX = GPUBlockSizeY = deviceProperties.warpSize;
		//int minGridSize, blockSize;
		//cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, stencilTilingCU, 0, in.size());
		//GPUBlockSize = blockSize;
		//cout << "GPUBlockSize: "<<GPUBlockSize<<endl;
		//int maxActiveBlocks;
  		//cudaOccupancyMaxActiveBlocksPerMultiprocessor(&maxActiveBlocks, stencilTilingCU, GPUBlockSize, 0);
		//float occupancy = (maxActiveBlocks * GPUBlockSize / deviceProperties.warpSize) / 
                //    (float)(deviceProperties.maxThreadsPerMultiProcessor / 
                //            deviceProperties.warpSize);
		//printf("Launched blocks of size %d. Theoretical occupancy: %f\n", GPUBlockSize, occupancy);
	}
	mask.deviceAlloc();
	mask.copyToDevice();

	StencilTiling<Array, Mask> gpuTiling(this->input, this->output, this->mask);
	StencilTiling<Array, Mask> cpuTiling(this->input, this->output, this->mask);
	Array inputGPU;
	Array outputGPU;
	Array tmp;
	Array inputCPU;
	Array outputCPU;
	size_t maskRange = this->mask.getRange();
	if(this->input.getHeight()==1){
		
	}
	else{
		size_t gpuHeight = ceil(this->input.getHeight()*gpuFactor);
		size_t cpuHeight = this->input.getHeight()-gpuHeight;
		if(cpuHeight==0) 
			this->runIterativeGPU(iterations, GPUBlockSizeX,GPUBlockSizeY);
		else if(gpuHeight==0) 
			this->runIterativeCPU(iterations, numThreads);
		else{
			start = omp_get_wtime();
			omp_set_num_threads(2);
			omp_set_nested(1);
			//printf("Main thread %d starting parallel section\n",omp_get_thread_num());
			#pragma omp parallel sections
			{
				//printf("Thread %d entering parallel section\n",omp_get_thread_num());
				#pragma omp section         
				{//begin GPU
					//printf("Thread %d computing GPU Partition\n",omp_get_thread_num());
					startGPU = omp_get_wtime();
					gpuTiling.tile(iterations, 0,0,0, this->input.getWidth(), gpuHeight, this->input.getDepth());
					
					inputGPU.hostSlice(gpuTiling.input, gpuTiling.widthOffset, gpuTiling.heightOffset, gpuTiling.depthOffset, gpuTiling.width, gpuTiling.height, gpuTiling.depth);
					
					outputGPU.hostSlice(gpuTiling.output, gpuTiling.widthOffset, gpuTiling.heightOffset, gpuTiling.depthOffset, gpuTiling.width, gpuTiling.height, gpuTiling.depth);

					inputGPU.deviceAlloc();
					inputGPU.copyToDevice();
					
					outputGPU.deviceAlloc();
					tmp.hostAlloc(gpuTiling.width, gpuTiling.height, gpuTiling.depth);
					
					//CUDA kernel execution
					this->runIterativeTilingCUDA(inputGPU, outputGPU, gpuTiling, GPUBlockSizeX, GPUBlockSizeY);

					if(iterations%2==0)
						tmp.copyFromDevice(inputGPU);
					else	
						tmp.copyFromDevice(outputGPU);	
		
					endGPU = omp_get_wtime();
					//printf("%Thread %d finished GPU Partition\n",omp_get_thread_num());
				}//end GPU section
				
				#pragma omp section
				{//begin CPU
					//printf("Thread %d computing CPU Partition\n",omp_get_thread_num());
					//printf("%f Running CPU iterations\n",omp_get_wtime());
					//startCPU = omp_get_wtime();
					cpuTiling.tile(iterations, 0, gpuHeight, 0, this->input.getWidth(), cpuHeight, this->input.getDepth());
					
					inputCPU.hostSlice(cpuTiling.input, cpuTiling.widthOffset, cpuTiling.heightOffset, cpuTiling.depthOffset, cpuTiling.width, cpuTiling.height, cpuTiling.depth);
					//outputCPU.hostSlice(cpuTiling.output, cpuTiling.widthOffset, cpuTiling.heightOffset, cpuTiling.depthOffset, cpuTiling.width, cpuTiling.height, cpuTiling.depth);

					////inputCPU.hostSlice(this->input, 0, gpuHeight, 0, this->input.getWidth(), cpuHeight, this->input.getDepth());
					////outputCPU.hostSlice(this->output, 0, gpuHeight, 0, this->input.getWidth(), cpuHeight, this->input.getDepth());

					Array inputCopy;
					inputCopy.hostClone(inputCPU);
					size_t width = inputCPU.getWidth();
					size_t height = inputCPU.getHeight();
					size_t depth = inputCPU.getDepth();

					startCPU = omp_get_wtime();
					
					for(size_t it = 0; it<iterations; it++){
					  //cpuTiling.tile(iterations-it, 0, gpuHeight, 0, width, height, depth);
                                          inputCPU.hostSlice(cpuTiling.input, cpuTiling.widthOffset, cpuTiling.heightOffset+it, cpuTiling.depthOffset, cpuTiling.width, cpuTiling.height, cpuTiling.depth);
                                          outputCPU.hostSlice(cpuTiling.output, cpuTiling.widthOffset, cpuTiling.heightOffset+it, cpuTiling.depthOffset, cpuTiling.width, cpuTiling.height, cpuTiling.depth);
					   //cout<<"It "<<it<<" width "<<inputCPU.getWidthOffset()<<" height "<<inputCPU.getHeightOffset()<<endl;
						if(it%2==0){
							#ifdef PSKEL_TBB
								this->runTBB(inputCopy, outputCPU, numThreads);
							#else
								this->runOpenMP(inputCopy, outputCPU, width, height, depth, maskRange);
							#endif
						}else {
							#ifdef PSKEL_TBB
								this->runTBB(outputCPU, inputCopy, numThreads);
							#else
								this->runOpenMP(outputCPU, inputCopy, width, height, depth, maskRange);
							#endif
						}
					}//end for
					if((iterations%2)==0) outputCPU.hostMemCopy(inputCPU);
					//inputCopy.hostFree();
					endCPU = omp_get_wtime();
					//printf("Thread %d finished CPU iterations\n",omp_get_thread_num());
				}//end CPU section
			}//end parallel omp sections
			//printf("Main thread %d finished parallel section\n",omp_get_thread_num());
			//if(iterations%2==0)
			//	tmp.copyFromDevice(inputGPU);
			//else
			//	tmp.copyFromDevice(outputGPU);	
			Array coreTmp;
			Array coreOutput;
			coreTmp.hostSlice(tmp, gpuTiling.coreWidthOffset, gpuTiling.coreHeightOffset, gpuTiling.coreDepthOffset, gpuTiling.coreWidth, gpuTiling.coreHeight, gpuTiling.coreDepth);
			coreOutput.hostSlice(outputGPU, gpuTiling.coreWidthOffset, gpuTiling.coreHeightOffset, gpuTiling.coreDepthOffset, gpuTiling.coreWidth, gpuTiling.coreHeight, gpuTiling.coreDepth);
			coreOutput.hostMemCopy(coreTmp);
			//tmp.hostFree();
			end = omp_get_wtime();
		}//end if partitioned
	}//end if input.getHeight()
	//cudaDeviceSynchronize();
	cout<<"CPU Time: "<<endCPU-startCPU<<endl;
	cout<<"GPU Time: "<<endGPU-startGPU<<endl;
	cout<<"Total   : "<<end-start<<endl;
	tmp.hostFree();
	inputGPU.deviceFree();
	outputGPU.deviceFree();
	mask.deviceFree();
	
}

#ifdef PSKEL_CUDA
template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativeTilingGPU(size_t iterations, size_t tilingWidth, size_t tilingHeight, size_t tilingDepth, size_t innerIterations, size_t GPUBlockSizeX, size_t GPUBlockSizeY){
	if(GPUBlockSizeX==0){
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		int device;
		cudaGetDevice(&device);
		cudaDeviceProp deviceProperties;
		cudaGetDeviceProperties(&deviceProperties, device);
		//GPUBlockSize = deviceProperties.maxThreadsPerBlock/2;
<<<<<<< HEAD
		GPUBlockSize = deviceProperties.warpSize;
=======
		GPUBlockSizeX = GPUBlockSizeY = deviceProperties.warpSize;
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		//int minGridSize, blockSize;
		//cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, stencilTilingCU, 0, in.size());
		//GPUBlockSize = blockSize;
		//cout << "GPUBlockSize: "<<GPUBlockSize<<endl;
		//int maxActiveBlocks;
  		//cudaOccupancyMaxActiveBlocksPerMultiprocessor(&maxActiveBlocks, stencilTilingCU, GPUBlockSize, 0);
		//float occupancy = (maxActiveBlocks * GPUBlockSize / deviceProperties.warpSize) / 
                //    (float)(deviceProperties.maxThreadsPerMultiProcessor / 
                //            deviceProperties.warpSize);
		//printf("Launched blocks of size %d. Theoretical occupancy: %f\n", GPUBlockSize, occupancy);
	}
	Array inputCopy;
	inputCopy.hostClone(this->input);
	size_t wTiling = ceil(float(this->input.getWidth())/float(tilingWidth));
	size_t hTiling = ceil(float(this->input.getHeight())/float(tilingHeight));
	size_t dTiling = ceil(float(this->input.getDepth())/float(tilingDepth));
	mask.deviceAlloc();
	mask.copyToDevice();
	//setGPUMask();
	StencilTiling<Array, Mask> tiling(inputCopy, this->output, this->mask);
	Array inputTile;
	Array outputTile;
	Array tmp;
	size_t outterIterations = ceil(float(iterations)/innerIterations);
	for(size_t it = 0; it<outterIterations; it++){
		size_t subIterations = innerIterations;
		if(((it+1)*innerIterations)>iterations){
			subIterations = iterations-(it*innerIterations);
		}
		//cout << "Iteration: " << it << endl;
		//cout << "#SubIterations: " << subIterations << endl;
		for(size_t ht=0; ht<hTiling; ht++){
		 for(size_t wt=0; wt<wTiling; wt++){
		  for(size_t dt=0; dt<dTiling; dt++){
			size_t heightOffset = ht*tilingHeight;
			size_t widthOffset = wt*tilingWidth;
			size_t depthOffset = dt*tilingDepth;

			//CUDA input memory copy
			tiling.tile(subIterations, widthOffset, heightOffset, depthOffset, tilingWidth, tilingHeight, tilingDepth);
			inputTile.hostSlice(tiling.input, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
			outputTile.hostSlice(tiling.output, tiling.widthOffset, tiling.heightOffset, tiling.depthOffset, tiling.width, tiling.height, tiling.depth);
			inputTile.deviceAlloc();
			outputTile.deviceAlloc();
			tmp.hostAlloc(tiling.width, tiling.height, tiling.depth);
			//this->setGPUInputDataIterative(inputCopy, output, innerIterations, widthOffset, heightOffset, depthOffset, tilingWidth, tilingHeight, tilingDepth);
			if(it%2==0){
				inputTile.copyToDevice();
				//CUDA kernel execution
<<<<<<< HEAD
				this->runIterativeTilingCUDA(inputTile, outputTile, tiling, GPUBlockSize);
=======
				this->runIterativeTilingCUDA(inputTile, outputTile, tiling, GPUBlockSizeX, GPUBlockSizeY);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
				if(subIterations%2==0){
					tmp.copyFromDevice(inputTile);
				}else{
					tmp.copyFromDevice(outputTile);
				}
				Array coreTmp;
				Array coreOutput;
				coreTmp.hostSlice(tmp, tiling.coreWidthOffset, tiling.coreHeightOffset, tiling.coreDepthOffset, tiling.coreWidth, tiling.coreHeight, tiling.coreDepth);
				coreOutput.hostSlice(outputTile, tiling.coreWidthOffset, tiling.coreHeightOffset, tiling.coreDepthOffset, tiling.coreWidth, tiling.coreHeight, tiling.coreDepth);
				coreOutput.hostMemCopy(coreTmp);
				//this->copyTilingOutput(output, innerIterations, widthOffset, heightOffset, depthOffset, tilingWidth, tilingHeight, tilingDepth);
				tmp.hostFree();
			}else{
				outputTile.copyToDevice();
				//CUDA kernel execution
<<<<<<< HEAD
				this->runIterativeTilingCUDA(outputTile, inputTile, tiling, GPUBlockSize);
=======
				this->runIterativeTilingCUDA(outputTile, inputTile, tiling, GPUBlockSizeX, GPUBlockSizeY);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
				if(subIterations%2==0){
					tmp.copyFromDevice(outputTile);
				}else{
					tmp.copyFromDevice(inputTile);
				}
				Array coreTmp;
				Array coreInput;
				//cout << "[Computing iteration: " << it << "]" << endl;
				coreTmp.hostSlice(tmp, tiling.coreWidthOffset, tiling.coreHeightOffset, tiling.coreDepthOffset, tiling.coreWidth, tiling.coreHeight, tiling.coreDepth);
				coreInput.hostSlice(inputTile, tiling.coreWidthOffset, tiling.coreHeightOffset, tiling.coreDepthOffset, tiling.coreWidth, tiling.coreHeight, tiling.coreDepth);
				coreInput.hostMemCopy(coreTmp);
				tmp.hostFree();
			}
		}}}
	}
	inputTile.deviceFree();
	outputTile.deviceFree();
	mask.deviceFree();
	cudaDeviceSynchronize();

	if((outterIterations%2)==0) tiling.output.hostMemCopy(tiling.input);
	inputCopy.hostFree();
}
#endif

#ifdef PSKEL_CUDA
template<class Array, class Mask, class Args>
<<<<<<< HEAD
void StencilBase<Array, Mask,Args>::runCUDA(Array in, Array out, int GPUBlockSize){
	dim3 DimBlock(GPUBlockSize, GPUBlockSize, 1);
	dim3 DimGrid((in.getWidth() - 1)/GPUBlockSize + 1, (in.getHeight() - 1)/GPUBlockSize + 1, in.getDepth());

	#ifdef PSKEL_SHARED_MASK
	stencilTilingCU<<<DimGrid, DimBlock, (this->mask.size*this->mask.dimension)>>>(in, out, this->mask, this->args, 0,0,0,in.getWidth(),in.getHeight(),in.getDepth());
	#else
	stencilTilingCU<<<DimGrid, DimBlock>>>(in, out, this->mask, this->args, 0,0,0,in.getWidth(),in.getHeight(),in.getDepth());
=======
void StencilBase<Array, Mask,Args>::runCUDA(Array in, Array out, size_t GPUBlockSizeX, size_t GPUBlockSizeY){
	dim3 DimBlock(GPUBlockSizeX, GPUBlockSizeY, 1);
	dim3 DimGrid((in.getWidth() - 1)/GPUBlockSizeX + 1, (in.getHeight() - 1)/GPUBlockSizeY + 1, in.getDepth());
    size_t maskRange = mask.getRange();

	#ifdef PSKEL_SHARED
		size_t sharedSize = sizeof(float)*(GPUBlockSizeX+2*maskRange)*(GPUBlockSizeY+2*maskRange);
        stencilTilingCU<<<DimGrid, DimBlock,sharedSize>>>(in, out, this->mask, this->args, maskRange, in.getWidth(),in.getHeight(),in.getDepth());
	#else
        //stencilTilingCU<<<DimGrid, DimBlock>>>(in, out, this->mask, this->args, 0,0,0,in.getWidth(),in.getHeight(),in.getDepth());
        stencilTilingCU<<<DimGrid, DimBlock>>>(in, out, this->mask, this->args,maskRange,in.getWidth(),in.getHeight(),in.getDepth());
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
	#endif
	gpuErrchk( cudaPeekAtLastError() );
	gpuErrchk( cudaDeviceSynchronize() );
}
#endif

#ifdef PSKEL_CUDA
template<class Array, class Mask, class Args>
<<<<<<< HEAD
void StencilBase<Array, Mask,Args>::runIterativeTilingCUDA(Array in, Array out, StencilTiling<Array, Mask> tiling, size_t GPUBlockSize){
	dim3 DimBlock(GPUBlockSize,GPUBlockSize, 1);
	dim3 DimGrid((in.getWidth() - 1)/GPUBlockSize + 1, (in.getHeight() - 1)/GPUBlockSize + 1, 1);
=======
void StencilBase<Array, Mask,Args>::runIterativeTilingCUDA(Array in, Array out, StencilTiling<Array, Mask> tiling, size_t GPUBlockSizeX, size_t GPUBlockSizeY){
	dim3 DimBlock(GPUBlockSizeX,GPUBlockSizeY, 1);
	dim3 DimGrid((in.getWidth() - 1)/GPUBlockSizeX + 1, (in.getHeight() - 1)/GPUBlockSizeY + 1, 1);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
	//dim3 DimBlock(GPUBlockSize,GPUBlockSize, 1);
	//dim3 DimGrid((in.getWidth() - 1)/GPUBlockSize + 1, (in.getHeight() - 1)/GPUBlockSize + 1, 1);
	size_t maskRange = this->mask.getRange();
	for(size_t it=0; it<tiling.iterations; it++){
		//cout << "[Computing iteration: " << it << "]" << endl;
		//cout << "mask range: " <<maskRange << endl;
		//cout << "mask margin: " <<(maskRange*(tiling.iterations-(it+1))) << endl;
		size_t margin = (maskRange*(tiling.iterations-(it+1)));
		size_t widthOffset = 0;
		size_t extra = 0;
		if(tiling.coreWidthOffset>margin){
			widthOffset = tiling.coreWidthOffset-margin;
		}else extra = margin-widthOffset;
		//cout << "width extra: " << extra << endl;
		size_t width = tiling.coreWidth+margin*2 - extra;
		if((widthOffset+width)>=tiling.width){
			width = tiling.width-widthOffset;
		}
		size_t heightOffset = 0;
		extra = 0;
		if(tiling.coreHeightOffset>margin){
			heightOffset = tiling.coreHeightOffset-margin;
		}else extra = margin-heightOffset;
		//cout << "height extra: " << extra << endl;
		size_t height = tiling.coreHeight+margin*2-extra;
		if((heightOffset+height)>=tiling.height){
			height = tiling.height-heightOffset;
		}
		size_t depthOffset = 0;
		extra = 0;
		if(tiling.coreDepthOffset>margin){
			depthOffset = tiling.coreDepthOffset-margin;
		}else extra = margin-depthOffset;
		//cout << "depth extra: " << extra << endl;
		size_t depth = tiling.coreDepth+margin*2-extra;
		if((depthOffset+depth)>=tiling.depth){
			depth = tiling.depth-depthOffset;
		}
		
		//cout << "width-offset: " <<widthOffset << endl;
		//cout << "height-offset: " <<heightOffset << endl;
		//cout << "depth-offset: " <<depthOffset << endl;
		
		//cout << "width: " <<width << endl;
		//cout << "height: " <<height << endl;
		//cout << "depth: " <<depth << endl;
		if(it%2==0){
			#ifdef PSKEL_SHARED_MASK
			stencilTilingCU<<<DimGrid, DimBlock, (this->mask.size*this->mask.dimension)>>>(in, out, this->mask, this->args, widthOffset, heightOffset, depthOffset, width, height, depth);
			#else
<<<<<<< HEAD
			stencilTilingCU<<<DimGrid, DimBlock>>>(in, out, this->mask, this->args, widthOffset, heightOffset, depthOffset, width, height, depth);
=======
			stencilTilingCU<<<DimGrid, DimBlock>>>(in, out, this->mask, this->args, maskRange, widthOffset, heightOffset, depthOffset, width, height, depth);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
			#endif
		}else{
			#ifdef PSKEL_SHARED_MASK
			stencilTilingCU<<<DimGrid, DimBlock, (this->mask.size*this->mask.dimension)>>>(out, in, this->mask, this->args, widthOffset, heightOffset, depthOffset, width, height, depth);
			#else
<<<<<<< HEAD
			stencilTilingCU<<<DimGrid, DimBlock>>>(out, in, this->mask, this->args, widthOffset, heightOffset, depthOffset, width, height, depth);
=======
			stencilTilingCU<<<DimGrid, DimBlock>>>(out, in, this->mask, this->args, maskRange, widthOffset, heightOffset, depthOffset, width, height, depth);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
			#endif
		}
		gpuErrchk( cudaPeekAtLastError() );
		gpuErrchk( cudaDeviceSynchronize() );
	}
}
#endif

<<<<<<< HEAD
#ifdef PSKEL_CUDA
=======
#ifdef PSKEL_GA
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
struct TilingGPUGeneticEvaluationFunction{
    size_t iterations;
    size_t height;
    size_t width;
    size_t depth;
    size_t range;
    size_t typeSize;
    size_t memFree;
    size_t popsize;
    size_t ngen;
    size_t dw;
    size_t dt;
    size_t dh;
    float score;
};
TilingGPUGeneticEvaluationFunction tilingGPUEvaluator;

float objective2D(GAGenome &c){
	GABin2DecGenome &genome = (GABin2DecGenome &)c;
	
	float h = genome.phenotype(0);
	float it = genome.phenotype(1);
	size_t tileHeight = ((tilingGPUEvaluator.height<=(2*it*tilingGPUEvaluator.range + h))?tilingGPUEvaluator.height:(2*it*tilingGPUEvaluator.range + h));
 
	if(2*(tilingGPUEvaluator.width*tilingGPUEvaluator.depth*tileHeight*tilingGPUEvaluator.typeSize) > tilingGPUEvaluator.memFree)return 0;
	else {
		float val = h/tileHeight;
		return val*((it*h)/(tilingGPUEvaluator.height*tilingGPUEvaluator.iterations));
	}
}

void solve2D(unsigned int seed){
	int popsize = tilingGPUEvaluator.popsize;
	int ngen = tilingGPUEvaluator.ngen;
	float pmut = 0.01;
	float pcross = 0.6;
	
	float div = (2.0*(tilingGPUEvaluator.width*tilingGPUEvaluator.depth*tilingGPUEvaluator.height*tilingGPUEvaluator.typeSize))/(tilingGPUEvaluator.memFree*1.1);
	size_t maxHeight = ceil(float(tilingGPUEvaluator.height)/div);
	//Create a phenotype for two variables.  The number of bits you can use to
	//represent any number is limited by the type of computer you are using.  In
	//this case, we use 16 bits to represent a floating point number whose value
	//can range from -5 to 5, inclusive.  The bounds on x1 and x2 can be applied
	//here and/or in the objective function.
	GABin2DecPhenotype map;
	map.add(16, 1, maxHeight); //min/max boundaries, inclusive
	map.add(16, 1, tilingGPUEvaluator.iterations);

	//Create the template genome using the phenotype map we just made.
	GABin2DecGenome genome(map, objective2D);

	//Now create the GA using the genome and run it.  We'll use sigma truncation
	//scaling so that we can handle negative objective scores.
	GASimpleGA ga(genome);
	GASigmaTruncationScaling scaling;
	ga.populationSize(popsize);
	ga.nGenerations(ngen);
	ga.pMutation(pmut);
	ga.pCrossover(pcross);
	ga.scaling(scaling);
	ga.scoreFrequency(0);
	ga.flushFrequency(0); //stop flushing the record of the score of given generations
	//ga.scoreFilename(0); //stop recording the score of given generations
	ga.evolve(seed);

	//Obtains the best individual from the best population evolved
	genome = ga.statistics().bestIndividual();

	//cout << "the ga found an optimum at the point (";
	//cout << genome.phenotype(0) << ", " << genome.phenotype(1) << ")\n\n";
	//cout << "best of generation data are in '" << ga.scoreFilename() << "'\n";
	tilingGPUEvaluator.dw = tilingGPUEvaluator.width;
	tilingGPUEvaluator.dh = genome.phenotype(0);//height;
	tilingGPUEvaluator.dt = genome.phenotype(1);//subIterations;
	tilingGPUEvaluator.score = objective2D(genome);
}

float objective3D(GAGenome &c){
	GABin2DecGenome &genome = (GABin2DecGenome &)c;
	
	float w = genome.phenotype(0);
	float h = genome.phenotype(1);
	float t = genome.phenotype(2);
	float tileWidth = ((tilingGPUEvaluator.width<=(2*t*tilingGPUEvaluator.range + w))?tilingGPUEvaluator.width:(2*t*tilingGPUEvaluator.range + w));
	float tileHeight = ((tilingGPUEvaluator.height<=(2*t*tilingGPUEvaluator.range + h))?tilingGPUEvaluator.height:(2*t*tilingGPUEvaluator.range + h));
 
	if(2*(tileWidth*tileHeight*tilingGPUEvaluator.depth*tilingGPUEvaluator.typeSize) > tilingGPUEvaluator.memFree) return 0;
	else {
		float val = (w*h)/(tileWidth*tileHeight);
		return val*((w*h*t)/(tilingGPUEvaluator.width*tilingGPUEvaluator.height*tilingGPUEvaluator.iterations));
	}
}

void solve3D(unsigned int seed){
	int popsize = tilingGPUEvaluator.popsize;
	int ngen = tilingGPUEvaluator.ngen;
	float pmut = 0.01;
	float pcross = 0.6;
	
	//float div = (2.0*(tilingGPUEvaluator.width*tilingGPUEvaluator.depth*tilingGPUEvaluator.height*tilingGPUEvaluator.typeSize))/(tilingGPUEvaluator.memFree*1.1);
	//size_t maxHeight = ceil(float(tilingGPUEvaluator.height)/div);
	//Create a phenotype for two variables.  The number of bits you can use to
	//represent any number is limited by the type of computer you are using.  In
	//this case, we use 16 bits to represent a floating point number whose value
	//can range from -5 to 5, inclusive.  The bounds on x1 and x2 can be applied
	//here and/or in the objective function.
	GABin2DecPhenotype map;
	//map.add(16, 1, maxHeight); //min/max boundaries, inclusive
	map.add(16, 1, tilingGPUEvaluator.width);
	map.add(16, 1, tilingGPUEvaluator.height);
	map.add(16, 1, tilingGPUEvaluator.iterations);

	//Create the template genome using the phenotype map we just made.
	GABin2DecGenome genome(map, objective3D);

	//Now create the GA using the genome and run it.  We'll use sigma truncation
	//scaling so that we can handle negative objective scores.
	GASimpleGA ga(genome);
	GASigmaTruncationScaling scaling;
	ga.populationSize(popsize);
	ga.nGenerations(ngen);
	ga.pMutation(pmut);
	ga.pCrossover(pcross);
	ga.scaling(scaling);
	ga.scoreFrequency(0);
	ga.flushFrequency(0); //stop flushing the record of the score of given generations
	//ga.scoreFilename(0); //stop recording the score of given generations
	ga.evolve(seed);

	//Obtains the best individual from the best population evolved
	genome = ga.statistics().bestIndividual();

	//cout << "the ga found an optimum at the point (";
	//cout << genome.phenotype(0) << ", " << genome.phenotype(1) << ")\n\n";
	//cout << "best of generation data are in '" << ga.scoreFilename() << "'\n";
	tilingGPUEvaluator.dw = genome.phenotype(0);//width;
	tilingGPUEvaluator.dh = genome.phenotype(1);//height;
	tilingGPUEvaluator.dt = genome.phenotype(2);//subIterations;
	tilingGPUEvaluator.score = objective3D(genome);
}

template<class Array, class Mask, class Args>
void StencilBase<Array, Mask,Args>::runIterativeAutoGPU(size_t iterations, size_t GPUBlockSize){
	size_t gpuMemFree, gpuMemTotal;
	//gpuErrchk( cudaDeviceSynchronize() );
	cudaMemGetInfo(&gpuMemFree, &gpuMemTotal);
	if((this->input.memSize()+this->output.memSize()+this->mask.memSize())<(0.999*gpuMemFree)){
		runIterativeGPU(iterations, GPUBlockSize);
	}else if(this->input.getHeight()==1){
		//solving for a 'transposed matrix'
		tilingGPUEvaluator.typeSize = this->input.memSize()/this->input.size();
		tilingGPUEvaluator.iterations = iterations;
		tilingGPUEvaluator.width = this->input.getDepth(); //'transposed matrix'
		tilingGPUEvaluator.height = this->input.getWidth(); //'transposed matrix'
		tilingGPUEvaluator.depth = 1;
		tilingGPUEvaluator.range = this->mask.getRange();
		tilingGPUEvaluator.memFree = (gpuMemFree-this->mask.memSize())*0.999;//gpuMemFree*0.998;

		tilingGPUEvaluator.popsize = 100;
		tilingGPUEvaluator.ngen = 2500;

  		unsigned int seed = time(NULL);
		solve2D(seed);

		size_t subIterations = tilingGPUEvaluator.dt;
		size_t width = tilingGPUEvaluator.dh;
		//cout << "GPU Mem Total: "<< gpuMemTotal <<endl;
		//cout << "GPU Mem Free: "<< gpuMemFree <<endl;
		//cout << "sub iterations: "<< subIterations <<endl;
		//cout << "tiling height: "<<height<<endl;
		runIterativeTilingGPU(iterations, width, 1, this->input.getDepth(), subIterations, GPUBlockSize);
		
	}else {
		size_t typeSize = this->input.memSize()/this->input.size();
		tilingGPUEvaluator.typeSize = typeSize;
		tilingGPUEvaluator.iterations = iterations;
		tilingGPUEvaluator.width = this->input.getWidth();
		tilingGPUEvaluator.height = this->input.getHeight();
		tilingGPUEvaluator.depth = this->input.getDepth();
		tilingGPUEvaluator.range = this->mask.getRange();
		tilingGPUEvaluator.memFree = (gpuMemFree-this->mask.memSize())*0.999;//gpuMemFree*0.998;
		if( (2*(1+2*this->mask.getRange())*(this->input.getWidth()*this->input.getDepth())*typeSize+this->mask.memSize()) > (0.98*gpuMemFree) ){
			tilingGPUEvaluator.popsize = 100;
			tilingGPUEvaluator.ngen = 2500;
	  		unsigned int seed = time(NULL);
			solve3D(seed);

			size_t width = tilingGPUEvaluator.dw;
			size_t height = tilingGPUEvaluator.dh;
			size_t subIterations = tilingGPUEvaluator.dt;
			//cout << "GPU Mem Total: "<< gpuMemTotal <<endl;
			//cout << "GPU Mem Free: "<< gpuMemFree <<endl;
			//cout << "sub iterations: "<< subIterations <<endl;
			//cout << "tiling height: "<<height<<endl;
			runIterativeTilingGPU(iterations, width, height, this->input.getDepth(), subIterations, GPUBlockSize);
		}else{
			tilingGPUEvaluator.popsize = 100;
			tilingGPUEvaluator.ngen = 2500;
	  		unsigned int seed = time(NULL);
			solve2D(seed);

			size_t subIterations = tilingGPUEvaluator.dt;
			size_t height = tilingGPUEvaluator.dh;
			//cout << "GPU Mem Total: "<< gpuMemTotal <<endl;
			//cout << "GPU Mem Free: "<< gpuMemFree <<endl;
			//cout << "sub iterations: "<< subIterations <<endl;
			//cout << "tiling height: "<<height<<endl;
			runIterativeTilingGPU(iterations, this->input.getWidth(), height, this->input.getDepth(), subIterations, GPUBlockSize);
		}
	}
}
#endif

//*******************************************************************************************
// Stencil 3D
//*******************************************************************************************


template<class Array, class Mask, class Args>
Stencil3D<Array,Mask,Args>::Stencil3D(){}
	
template<class Array, class Mask, class Args>
Stencil3D<Array,Mask,Args>::Stencil3D(Array _input, Array _output, Mask _mask, Args _args){
	this->input = _input;
	this->output = _output;
	this->args = _args;
	this->mask = _mask;
}

#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
void Stencil3D<Array,Mask,Args>::runSeq(Array in, Array out){
	for (int h = 0; h < in.getHeight(); h++){
	for (int w = 0; w < in.getWidth(); w++){
	for (int d = 0; d < in.getDepth(); d++){
		stencilKernel(in,out,this->mask,this->args,h,w,d);
	}}}
}
#endif

#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
<<<<<<< HEAD
void Stencil3D<Array,Mask,Args>::runOpenMP(Array in, Array out, size_t numThreads){
	omp_set_num_threads(numThreads);
	#pragma omp parallel for
	for (int h = 0; h < in.getHeight(); h++){
	for (int w = 0; w < in.getWidth(); w++){
	for (int d = 0; d < in.getDepth(); d++){
=======
void Stencil3D<Array,Mask,Args>::runOpenMP(Array in, Array out, size_t width, size_t height, size_t depth, size_t maskRange){
	//omp_set_num_threads(numThreads);
	#pragma omp parallel for
	for (int h = 0; h < height; h++){
	for (int w = 0; w < width; w++){
	for (int d = 0; d < depth; d++){
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		stencilKernel(in,out,this->mask,this->args,h,w,d);
	}}}
}
#endif

#ifdef PSKEL_TBB
template<class Array, class Mask, class Args>
struct TBBStencil3D{
	Array input;
	Array output;
	Mask mask;
	Args args;
	TBBStencil3D(Array input, Array output, Mask mask, Args args){
		this->input = input;
		this->output = output;
		this->mask = mask;
		this->args = args;
	}
	void operator()(tbb::blocked_range<int> r)const{
		for (int h = r.begin(); h != r.end(); h++){
		for (int w = 0; w < this->input.getWidth(); w++){
		for (int d = 0; d < this->input.getDepth(); d++){
			stencilKernel(this->input,this->output,this->mask,this->args,h,w,d);
		}}}
	}
};

template<class Array, class Mask, class Args>
void Stencil3D<Array,Mask,Args>::runTBB(Array in, Array out, size_t numThreads){
	TBBStencil3D<Array, Mask, Args> tbbstencil(in, out, this->mask, this->args);
	tbb::task_scheduler_init init(numThreads);
	tbb::parallel_for(tbb::blocked_range<int>(0, in.getHeight()), tbbstencil);
}
#endif

//*******************************************************************************************
// Stencil 2D
//*******************************************************************************************

template<class Array, class Mask, class Args>
Stencil2D<Array,Mask,Args>::Stencil2D(){}

template<class Array, class Mask, class Args>
Stencil2D<Array,Mask,Args>::Stencil2D(Array _input, Array _output, Mask _mask, Args _args){
	this->input = _input;
	this->output = _output;
	this->args = _args;
	this->mask = _mask;
}

template<class Array, class Mask, class Args>
Stencil2D<Array,Mask,Args>::Stencil2D(Array _input, Array _output, Mask _mask){
	this->input = _input;
	this->output = _output;
	this->mask = _mask;
}


template<class Array, class Mask, class Args>
Stencil2D<Array,Mask,Args>::~Stencil2D(){
	#ifdef PSKEL_CUDA
		this->input.deviceFree();
		this->output.deviceFree();
	#endif
	#ifdef PSKEL_MPPA
		this->input.mppaFree();
		this->output.mppaFree();
	#endif
	#ifdef PSKEL_CPU
		this->input.hostFree();
		this->output.hostFree();
	#endif
}

#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
void Stencil2D<Array,Mask,Args>::runSeq(Array in, Array out){
<<<<<<< HEAD
	for (int h = 0; h < in.getHeight(); h++){
	for (int w = 0; w < in.getWidth(); w++){
=======
	size_t height = in.getHeight();
	size_t width = in.getWidth();
	for (size_t h = 0; h < height; h++){
	for (size_t w = 0; w < width; w++){
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		stencilKernel(in,out,this->mask, this->args,h,w);
	}}
}
#endif

#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
<<<<<<< HEAD
=======
<<<<<<< HEAD
inline __attribute__((always_inline)) void Stencil2D<Array,Mask,Args>::runOpenMP(Array in, Array out, size_t width, size_t height, size_t depth, size_t maskRange){
	//omp_set_num_threads(numThreads);
	//size_t height = in.getHeight();
	//size_t width = in.getWidth();
    	//size_t maskRange = this->mask.getRange();
	
  	#ifdef CACHE_BLOCK
	#define TH 15
	#define TW 15
	#pragma omp parallel for collapse(1) num_threads(11)
	for(size_t hh = maskRange; hh < height-maskRange;hh+=TH){
	for(size_t ww = maskRange; ww < width-maskRange; ww+=TW){
		for(size_t h = hh; h < MIN(hh+TH,height-maskRange);h++){
			__builtin_prefetch (&in(h-1,ww),0,3);
			__builtin_prefetch (&in(h,ww),0,3);		
			__builtin_prefetch (&in(h+1,ww),0,3);
			__builtin_prefetch (&out(h,ww),1,1);	
			#pragma omp simd
			for(size_t w = ww; w < MIN(ww+TW,width-maskRange);w++){
				//stencilKernel(in,out,this->mask, this->args,h,w);
				out(h,w) = 0.25f * (in(h-1,w) + in(h,w-1) + in(h,w+1) + in(h+1,w));
				//__builtin_prefetch (&in(h-1,w),0,1,2);
				//__builtin_prefetch (&in(h+1,w),0,1,2);
			}
			//__builtin_prefetch (&in(h,ww),0,1,3);
			//__builtin_prefetch (&in(h+1,ww),0,1,3);		
			//__builtin_prefetch (&in(h+2,ww),0,1,3);
		}	
	}}	
	#else
	
	#pragma omp parallel num_threads(11)
	{
	//printf("Thread %d computing CPU stencil kernel\n",omp_get_thread_num());
	#pragma omp for
	for (size_t h = maskRange; h < height-maskRange; h++){
	#pragma omp simd
	for (size_t w = maskRange; w < width-maskRange; w++){
		stencilKernel(in,out,this->mask,this->args,h,w);
		//#pragma omp simd
		//out(h,w) = 0.25f * (in(h-1,w) + in(h,w-1) + in(h,w+1) + in(h+1,w));
			
		//__builtin_prefetch (&in(h-1,w),0,1,2);
		//__builtin_prefetch (&in(h+1,w),0,1,2);
		//__builtin_prefetch (in(h,w),0,1,3);	
			}}
	}
	#endif
=======
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
void Stencil2D<Array,Mask,Args>::runOpenMP(Array in, Array out, size_t numThreads){
	// printf("SizeHeight: %d\n", in.getHeight());
	// printf("SizeWidth: %d\n", in.getWidth());
	omp_set_num_threads(numThreads);
	#pragma omp parallel for
	for (int h = 0; h < in.getHeight(); h++){
	for (int w = 0; w < in.getWidth(); w++){
		stencilKernel(in,out,this->mask, this->args,h,w);
	}}
<<<<<<< HEAD
=======
>>>>>>> ee5501bdba3333d6dabd9b409c3bad5e35140a47
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
}
#endif

#ifdef PSKEL_TBB
template<class Array, class Mask, class Args>
struct TBBStencil2D{
	Array input;
	Array output;
	Mask mask;
	Args args;
<<<<<<< HEAD
=======
	size_t maskRange;
	size_t width;
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
	TBBStencil2D(Array input, Array output, Mask mask, Args args){
		this->input = input;
		this->output = output;
		this->mask = mask;
		this->args = args;
<<<<<<< HEAD
	}
	void operator()(tbb::blocked_range<int> r)const{
		for (int h = r.begin(); h != r.end(); h++){
		for (int w = 0; w < this->input.getWidth(); w++){
=======
		this->maskRange = mask.getRange();
		this->width = input.getWidth();
	}
	void operator()(tbb::blocked_range<int> &r)const{
		for (int h = r.begin(); h != r.end(); h++){
		for (int w = maskRange; w < this->width-maskRange; w++){
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
			stencilKernel(this->input,this->output,this->mask, this->args,h,w);
		}}
	}
};

template<class Array, class Mask, class Args>
void Stencil2D<Array,Mask,Args>::runTBB(Array in, Array out, size_t numThreads){
	TBBStencil2D<Array, Mask, Args> tbbstencil(in, out, this->mask, this->args);
	tbb::task_scheduler_init init(numThreads);
<<<<<<< HEAD
	tbb::parallel_for(tbb::blocked_range<int>(0, in.getHeight()), tbbstencil);
=======
	size_t maskRange = this->mask.getRange();
	tbb::parallel_for(tbb::blocked_range<int>(maskRange, in.getHeight()-maskRange), tbbstencil);
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
}
#endif

//*******************************************************************************************
// Stencil 1D
//*******************************************************************************************


template<class Array, class Mask, class Args>
Stencil<Array,Mask,Args>::Stencil(){}
	
template<class Array, class Mask, class Args>
Stencil<Array,Mask,Args>::Stencil(Array _input, Array _output, Mask _mask, Args _args){
	this->input = _input;
	this->output = _output;
	this->args = _args;
	this->mask = _mask;
}

#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
void Stencil<Array,Mask,Args>::runSeq(Array in, Array out){
	for (int i = 0; i < in.getWidth(); i++){
		stencilKernel(in,out,this->mask, this->args,i);
	}
}
#endif

#ifndef MPPA_MASTER
template<class Array, class Mask, class Args>
<<<<<<< HEAD
void Stencil<Array,Mask,Args>::runOpenMP(Array in, Array out, size_t numThreads){
	omp_set_num_threads(numThreads);
	#pragma omp parallel for
	for (int i = 0; i < in.getWidth(); i++){
=======
void Stencil<Array,Mask,Args>::runOpenMP(Array in, Array out, size_t width, size_t height, size_t depth,size_t maskRange){
	//omp_set_num_threads(numThreads);
	#pragma omp parallel for
	for (int i = 0; i < width; i++){
>>>>>>> b9433c934dac6775f4c9992cd06902cb2dcb8e76
		stencilKernel(in,out,this->mask, this->args,i);
	}
}
#endif

#ifdef PSKEL_TBB
template<class Array, class Mask, class Args>
struct TBBStencil{
	Array input;
	Array output;
	Mask mask;
	Args args;
	TBBStencil(Array input, Array output, Mask mask, Args args){
		this->input = input;
		this->output = output;
		this->mask = mask;
		this->args = args;
	}
	void operator()(tbb::blocked_range<int> r)const{
		for (int i = r.begin(); i != r.end(); i++){
			stencilKernel(this->input,this->output,this->mask, this->args,i);
		}
	}
};

template<class Array, class Mask, class Args>
void Stencil<Array,Mask,Args>::runTBB(Array in, Array out, size_t numThreads){
	TBBStencil<Array, Mask, Args> tbbstencil(in, out, this->mask, this->args);
	tbb::task_scheduler_init init(numThreads);
	tbb::parallel_for(tbb::blocked_range<int>(0, in.getWidth()), tbbstencil);
}
#endif

}//end namespace


#endif
