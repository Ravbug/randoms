//
//  main.c
//
//	Sample uses for the random functions
//
//

#include <stdio.h>
#include <stdlib.h>
#include "ramdom.c"
#include "devrandom.c"
#include "middlesquared.c"
#include <time.h>

#define array_size(a) (sizeof(a)/sizeof(a[0]))

/**
Sets values in an array to 0
@param array the array to set
@param size the length of the array 
*/
void clear(int array[], int size){
	for (int i = 0; i < size; i++){
		array[i] = 0;
	}
}

/**
Prints the histogram for a run array
@param array the array containing the histogram
@param size the size of the array
*/
void print_dist(int array[],int size){
	for(int i = 0; i < size; i++){
		printf("%d: ",i);
		for (int j = 0; j < array[i]; j++){
			printf("*");
		}
		printf("\n");
	}
}

/**
Runs a random range function N times and writes to an array
@param *f pointer to the function that takes floats args
@param dist[] array to write values to (must be correct size)
@param runs the number of runs to test
*/
void run_test(float(*f)(float,float), int dist[], int runs, int min, int max){
	for (int i = 0; i < runs; i++){
		int v = (*f)(min, max);
		dist[v-min] ++;
		printf("%d ", v);
	}
	printf("\n");
}

int main(){
	//set the "seed"
	//by definition, undefined behavior cannot be
	//seeded or predicted. However, changing this value
	//will affect the pattern of output.
	printf("========= [Running random functions] =========\n");
	clock_t time_1 = clock();
	ramseed = time_1;
	printf("ramseed = %d\n",ramseed);

	// ======= demonstration ==========
	const int min = 1;
	const int max = 100;
	const int runs = 250;
	printf("min = %d, max = %d, runs = %d\n", min, max, runs);
	const int dist[max-min];
	{
		printf("Running ramdom\n");
		clear(dist, array_size(dist));
		//run the experiment, print each
		//value and update the histogram
		run_test(ramdom_range, dist, runs, min, max);
		printf("\n");
		//print the histogram
		print_dist(dist, array_size(dist));
	}
	{
		printf("\nRunning devrand\n");
		clear(dist, array_size(dist));
		run_test(devrand_range, dist, runs, min, max);
		printf("\n");
		print_dist(dist, array_size(dist));
	}
	{
		printf("\nRunning msrand\n");
		clear(dist, array_size(dist));
		run_test(msrand_range, dist, runs, min, max);
		printf("\n");
		print_dist(dist, array_size(dist));
	}
	return 0;
}
