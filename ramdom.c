//
//  ramdom.c
//
//	An RNG implementation which leverages undefined
// 	behavior when creating uninitialized variables.
//
//	Author: Ravbug (https://github.com/ravbug)
//

#include <stdio.h>
#include <stdlib.h>

unsigned short ramseed;

/**
 Generates a random number between 0 and 1 using undefined behavior
 @return a float on interval [0,1)
 */
float ramdom(){
	//create an array of uninitialized values
	unsigned short val[ramseed];
	//overrun the array
	unsigned short res = (val[++ramseed+1]) * ramseed;
	//to prevent returning 0 too often, try a maximum of
	//7 times to generate a nonzero value
	int i = 0;
	while (res == 0 || i > 7){
		unsigned short t[ramseed];
		res = (val[++ramseed+1]) * ramseed;
		i++;
	}
	//extract the middle 3 digits from the short
	//return the value as a [0,1)
	return ((float)(res % 1000)/1000.0);
}

/**
 Use ramdom() to generate a value on interval [min,max)
 @param min the smallest possible value
 @param max the largest possible value (exclusive)
 @return the [0,1) float remapped to [min,max)
 */
float ramdom_range(float min, float max){
	return ramdom() * (max-min) + min;
}
