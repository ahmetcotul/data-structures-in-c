/*
 *
 * Array Insertion Algorithm
 *
 * n=array length, k<=n 
 * 
 *
1. Start
2. Set J = N
3. Set N = N+1
4. Repeat steps 5 and 6 while J >= K
5. Set LA[J+1] = LA[J]
6. Set J = J-1
7. Set LA[K] = ITEM
8. Stop
*/

#include<stdio.h>
int main(){
	int LA[] = {1,3,4,5,7};
	int i=0, n=5,item=19;
	int k=3,j=n;
	printf("The array elements before insertion:\n");
	for(i=0;i<n;i++){
		printf("LA[%d]=%d\n",i,LA[i]);
		
	}
	n=n+1;
	while(j>=k){
		LA[j+1]=LA[j];
		j=j-1;

	}
	
	LA[k]=item;
	printf("The array elements after insertion:\n");
	for(i=0;i<n;i++){
		printf("LA[%d]=%d\n",i,LA[i]);
	}

}
