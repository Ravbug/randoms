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
#include <time.h>

int main(){
	//set the "seed"
	//by definition, undefined behavior cannot be
	//seeded or predicted. However, changing this value
	//will affect the pattern of output.
	
	clock_t time_1 = clock();
	ramseed = time_1;
	printf("ramseed = %d\n",ramseed);

	// ======= demonstration ==========
	
	const int min = 1;
	const int max = 100;
	const int runs = 250;
	{
	int dist[max-min];
	printf("Running ramdom\n");
	for (int i = 0; i < (max-min); i++){
		dist[i]=0;
	}
	
	//run the experiment, print each
	//value and update the histogram
	for (int i = 0; i < runs; i++){
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
	}
	{
		printf("\nRunning devrand\n");
		int dist[max-min];
		for (int i = 0; i < (max-min); i++){
			dist[i]=0;
		}
		for(int i = min; i < runs; i++){
			int v = devrand_range(min,max);
			printf("%d ",v);
			dist[v-min] ++;
		}
		printf("\n");
		for (int i = min; i < max; i++){
			printf("%d: ",i);
			for (int j = 0; j < dist[i-min]; j++){
				printf("*");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

