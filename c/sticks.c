#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void cutSticks(int * stick, int count){
	//printf("started cutSticks\n");
	int min = - 1;
	int i = 0;
	while(i < count){
		if((stick[i] < min) || (min < 0)){
			min = stick[i];
		}
		i++;
	}
	int sticks_left = count;
	int cuts = 0;
	int new_min = -1;
	while(sticks_left > 0){
		//printf("Cutting sticks...\n");
		sticks_left = 0;
		for(i=0;i < count; i++){
			if(stick[i] > 0){
				cuts++;
				//printf("stick[i] bc: %d\n",stick[i]); 
				stick[i] -= min;
				//printf("stick[i] ac: %d\n",stick[i]);
				if(stick[i]>0){
					//printf("sticks_left++\n");
					sticks_left++;
					if((new_min > stick[i]) || new_min < 0){
						new_min = stick[i];
					} 
				}
			}
		}
		printf("%d\n",cuts);
		cuts = 0;
		min = new_min;
		new_min = -1;
	}
}

int main() {
	int count;
	scanf("%d",&count);
	int stick[count];
	int i = 0;
	while(i<count){
		scanf("%d",&stick[i]);
		i++;
	}
	cutSticks(stick,count);
    return 0;
}
