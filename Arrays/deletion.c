/*
 *
 *
 * Algorithm
 * LA is linear array with N elements and K <= N
 1. Start
 2. Set J = K
 3. Repeat steps 4 and 5 while J < N
 4. Set LA[J] = LA[J + 1]
 5. Set J = J+1
 6. Set N = N-1
 7. Stop
 * 
 *
 *
 * */
#include<stdio.h>
int main(){
	int LA[]={1,2,3,6,7};
	int n=5,k=4;
	int j=k;
	printf("The original array elements:\n");
	for(int i=0;i<n;i++){
		printf("LA[%d]=%d\n",i,LA[i]);
	}
	while(j<n){
		LA[j]=LA[j+1];
		j=j+1;
	
	}
	n=n-1;
	printf("After Deletion:\n");
	for(int i=0;i<n;i++){
	
		printf("LA[%d]=%d\n",i,LA[i]);
	}










}
