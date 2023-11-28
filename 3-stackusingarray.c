#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//#include<stdbool.h>
//bool de tanımlayabiliriz..



struct stack{
	int top;
	unsigned capacity;
	int *array;
};

struct stack *createStack(unsigned  capacity){
	struct stack *yeni= (struct stack *)malloc(sizeof(struct stack));
	yeni->top=-1;
	yeni->capacity = capacity;
	yeni->array = (int*)malloc(yeni->capacity * sizeof(int));
	return yeni;
}

int isEmpty(struct stack *stk){
	return (stk->top==-1);
}
int isFull(struct stack *stk){
	return (stk->top==stk->capacity-1);
}
void push(struct stack *stk,int x){
	if(isFull(stk)){
		printf("eklenemez full çünkü\n");
		return;
	}
	stk->array[++stk->top]=x;

}
int pop(struct stack *stk){
	if(isEmpty(stk)){
		printf("silinecek bir şey yok stack boş!");
		return INT_MIN;
	}else{
	return (stk->array[stk->top--]);
	}

}

void print(struct stack *stk) {
    if (isEmpty(stk)) {
        printf("yığın boş");
    } else {
        int i = stk->top;
        while (i != -1) {
            printf("%d\n", stk->array[i]);
            i--;
        }
    }
}



int main(){
	struct stack *stk= createStack(2);
	push(stk,1);
	push(stk,2);
	push(stk,3);
	print(stk);
	printf("\nsilindi:%d\n\n",pop(stk));
	print(stk);
	return 0;
}
