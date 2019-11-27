
#include <stdio.h>
#include <stdlib.h>

/**
Generates a random number between 0 and 1 using /dev/random
@note This function only works on systems where /dev/random exists and behaves as expected
@return a float on interval [0,1)
*/
float devrand(){
	// open /dev/random
	FILE* file = fopen("/dev/random","r");
	
	//declare amount of data to use
	int amt = 2;
	int data[amt];

	// read in the data
	fread(&data, 1, amt, file);
		
	//release resources
	fclose(file);

	int prec = 10;
	int val = 0;
	
	//sum
	for (int i = 0; i < amt; i++){
		val += data[i] * prec;
		prec *= 10;
	}
	
	//take the middle values
	prec = 10000;
	val = val % prec;

	//convert to [0,1)
	return (float)val/prec;
}

/**
 Use devrand() to generate a value on the interval [min,max)
 @param min the smallest possible value
 @param max the largest possible value (exclusive)
 @return a random float on [0,1)
*/
float devrand_range(int min, int max){
	return devrand() * (max-min) + min;
}
