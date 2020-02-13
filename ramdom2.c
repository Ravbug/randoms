//
//  ramdom2.c
//
//      An RNG implementation which leverages undefined
//      behavior when creating uninitialized variables.
//
//      Author: Ravbug (https://github.com/ravbug)
//

#include <stdlib.h>

/**
 Generates a random number between 0 and 1 using undefined behavior
 @return a float on interval [0,1)
 */
float ramdom2(){
	int arr[] = {5};
	int y = abs(*(arr+1));
	return (float)(y / 100000 + y % 1000000) / 1000000;
}

/**
 Use ramdom2() to generate a value on interval [min,max)
 @param min the smallest possible value
 @param max the largest possible value (exclusive)
 @return the [0,1) float remapped to [min,max)
 */

float ramdom2_range(float min, float max){
        return ramdom2() * (max-min) + min;
}
