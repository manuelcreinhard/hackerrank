#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int heap[1000][2];
int heapSize;

void Init()
{
        heapSize = 0;
        heap[0][0] = ~0;
}

void Insert(int element,int t)
{
        heapSize++;
        heap[heapSize][0] = element; /*Insert in the last place*/
        heap[heapSize][1] = t;
        /*Adjust its position*/
        int now = heapSize;
        while(heap[now/2][0] > element) 
        {
                heap[now][0] = heap[now/2][0];
                heap[now][1] = heap[now/2][1];
                now /= 2;
        }
        heap[now][0] = element;
        heap[now][1] = t;
}

int * DeleteMin()
{
        /* heap[1] is the minimum element. So we remove heap[1]. Size of the heap is decreased. 
           Now heap[1] has to be filled. We put the last element in its place and see if it fits.
           If it does not fit, take minimum element among both its children and replaces parent with it.
           Again See if the last element fits in that place.*/
        int *minElement,lastElement,lastT,child,now;
        minElement = heap[1];
        lastElement = heap[heapSize--][0];
        lastT = heap[heapSize][1];
        /* now refers to the index at which we are now */
        for(now = 1; now*2 <= heapSize ;now = child)
        {
                /* child is the index of the element which is minimum among both the children */ 
                /* Indexes of children are i*2 and i*2 + 1*/
                child = now*2;
                /*child!=heapSize beacuse heap[heapSize+1] does not exist, which means it has only one 
                  child */
                if(child != heapSize && heap[child+1][0] < heap[child][0] ) 
                {
                        child++;
                }
                /* To check if the last element fits ot not it suffices to check if the last element
                   is less than the minimum element among both the children*/
                if(lastElement > heap[child][0])
                {
                        heap[now][0] = heap[child][0];
                        heap[now][1] = heap[child][1];
                        
                }
                else /* It fits there */
                {
                        break;
                }
        }
        heap[now][0] = lastElement;
        heap[now][1] = lastT;
        return minElement;
}
/*
int main(void) {
   
   int jobs;
   scanf("%d", &jobs);
   int _ar[_ar_size], _ar_i;
   for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
	   scanf("%d", &_ar[_ar_i]);
   }

partition(_ar_size, _ar);
   
   return 0;
}
* 
*/
int main()
{
        int number_of_elements;
        scanf("%d",&number_of_elements);
        int iter, element, t;
        Init();
        int i;
        for(iter = 0;iter < number_of_elements;iter++)
        {
                scanf("%d %d",&element,&t);
                //scanf("%d\n",&t);
                printf("inserting element: %d at time: %d\n",element,t);
                Insert(element,t);
                for(i= 0;i< heapSize;i++){
					printf("Value: %d   Time: %d\n",heap[i][0],heap[i][1]);
				}
        }
        for(iter = 0;iter < number_of_elements;iter++)
        {
			int * min = DeleteMin();
                printf("val; %d   time: %d\n",min[0],min[1]);
        }
        printf("\n");
        return 0;
}
