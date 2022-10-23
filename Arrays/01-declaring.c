#include<stdio.h>
void main(){
	int arr[10], i;
	for(i=0;i<10;i++){
			printf("Enter the %d number \n",i+1);
			scanf("%d",&arr[i]);
	}
	for(i=0;i<10;i++)
	printf("number %d is %d\n",i+1,arr[i]);
}
