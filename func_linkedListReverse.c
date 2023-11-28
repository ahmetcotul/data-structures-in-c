#include<stdio.h>
#include<stdlib.h>
//tek yönlü bağlı listeyi değiştirme
struct node{
	int data;
	struct node *next;

};

void reverse(struct node **head){

	struct node *tmp= (*head);
	struct node *tmp2= NULL,*tmp3;
	while(tmp!=NULL){
		tmp3= tmp2;
		tmp2= tmp;
		tmp= tmp->next;
	 	tmp2->next=tmp3;


	}
	(*head) = tmp2;

}


void printNode(struct node *head){
	struct node *tmp = head;
	if(tmp==NULL){
	printf("eleman bulunamadı");
	return;
	}
	while(tmp!=NULL){
		printf("%d\t",tmp->data);
		tmp= tmp->next;
	}
	printf("\n");



}
/*
void reverse(struct node **head){
	struct node *tmp = (*head);
	struct node *tmp2 = NULL;
	struct node *tmp3 ;

	while(tmp!=NULL){
		tmp3= tmp2;
		tmp2= tmp;
		tmp=tmp->next;
		tmp2->next=tmp3;
	}
	(*head)=tmp2;
}
*/
int main(){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *node1 = (struct node *)malloc(sizeof(struct node));
	struct node *node2 = (struct node *)malloc(sizeof(struct node));
	head->data=5;node1->data=10; node2->data=78;
	head->next = node1;node1->next =node2;node2->next = NULL;
	printNode(head);
	reverse(&head);
	printNode(head);
	return 0;
}
