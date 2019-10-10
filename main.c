//
//  main.c
//  
//	Sample uses for the random functions
//
//

#include <stdio.h>
#include "ramdom.c"

int main(){
	//set the "seed"
	//by definition, undefined behavior cannot be
	//seeded or predicted. However, changing this value
	//will affect the pattern of output.
	ramseed = 35796;
	printf("ramseed = %d\n",ramseed);

	// ======= demonstration ==========
	
	const int min = 1;
	const int max = 100;
	const int runs = 250;
	int dist[max-min] = {0};
	
	//run the experiment, print each
	//value and update the histogram
	for (int i = 0; i < 250; i++){
		int v = ramdom_range(min,max);
		printf("%d ",v);
		dist[v-min] ++;
	}
	printf("\n");

	//print the histogram
	for (int i = min; i < max; i++){
		printf("%d: ",i);
		for (int j = 0; j < dist[i-min]; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

