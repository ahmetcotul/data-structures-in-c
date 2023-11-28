//güzel soru
//yerine göre eklicek mesela ondan küçük olcak yani sıraya göre eklicek
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};
void printNode(struct node *head){
	struct node *tmp = head;
	while(tmp!=NULL){
		printf("%d\t",tmp->data);
		tmp= tmp->next;	
	}
	printf("\n");

}

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node ));
	struct node *node1= (struct node *)
	

}
