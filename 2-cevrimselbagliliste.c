#include<stdio.h>
#include<stdlib.h>

//cevrimsel bagli liste
struct node{
	int data;
	struct node* next;

};

//create node
struct node * createNode(int data ) {

	struct node*  yeniDugum = (struct node *)malloc(sizeof(struct node));

	yeniDugum-> data = data;

	return(yeniDugum);

}

//display nodes
void printNode(struct node *head){

	if(head==NULL){
		printf("yazılacak node yok..");
		return;
	}
	struct node *tmp = head;

	//1.YOL
	do{
		printf("%d\t",tmp->data);
		tmp = tmp->next;

	}while(tmp!=head);

	printf("\n");
	//2.YOL
	/*
	printf("%d\n",tmp->data);
	tmp = tmp->next;
	while(tmp!=head){
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}*/

	//3.YOL
	/*
	printf("%d\n",tmp->data);

	while(tmp->next!=head){
		tmp = tmp->next ;
		printf("%d \n",tmp->data);

	}
	*/
}
//BASA EKLEMEK
void basaEkle(struct node **head,int x){
	struct node *eklenen = createNode(x);

	if((*head)==NULL){
		eklenen->next = eklenen;
		(*head)= eklenen;
		return;
	}

	eklenen ->next=(*head);
	struct node *tmp = (*head);
	while(tmp->next!=(*head)){
		tmp= tmp->next;
	}
	tmp->next = eklenen;
	(*head)= eklenen;


}

//SONA EKLEMEK
void sonaEkle(struct node **head,int x){
	struct node *eklenen = createNode(x);

	if((*head)==NULL){
		eklenen->next=eklenen;
		(*head) = eklenen;
		return;
	}

	struct node *tmp = (*head);
	while(tmp->next != (*head)){
		tmp = tmp->next;
	}
	tmp->next = eklenen;
	eklenen->next = (*head);


}
//ARAYA EKLE
void arayaEkle(struct node *head,int aranan,int x){

	if(head==NULL)
		return;

	struct node *tmp = head;
	while(tmp->data!=aranan){
		tmp = tmp->next;
		if(tmp==head){
			printf("aradiginiz eleman bulunamadi.\n");
			return;
		}
	}
	struct node *eklenen = createNode(x);
	eklenen->next = tmp ->next ;
	tmp->next = eklenen;


}
//BastanSil
void bastanSil(struct node **head){
	//eleman yoksa
	if((*head)==NULL){
		printf("listenizde veri yok.");
		return;
	}
	struct node *tmp = (*head);
	//tek elemanlıysa
	if((*head)->next == (*head)){
		free(tmp);
		(*head)= NULL;
		return;

	}
	struct node *lastNode = (*head);
	while(lastNode->next != (*head)){
		lastNode = lastNode ->next;
	}
	lastNode->next = (*head)->next ;
	(*head)= (*head)->next;
	free(tmp);

}
//Sondan Sil //cift yildiz olmadı **head olmalı çünkü tek elemanlıyken null oluyor bunu atladım özellikle ....
void sondanSil(struct node *head){
	if(head==NULL){
		printf("dugum yok maalesef.\n");
		return;
	}
 	struct node *tmp = head;
	if(head->next == head){
		free(tmp);
		head = NULL;
		return;
	}

	while(tmp->next->next != head){
		tmp=tmp->next;
	}
	struct node *silinecek = tmp->next;
	tmp->next = tmp->next->next;
	free(silinecek);


}
//Sondan sil kolay 
/*
//Bu doğru mu?
void sondanSil(struct node *head){
	struct node *tmp = head;
	while(tmp->next->next != head)
	tmp=tmp->next;
	free(tmp->next);
	tmp->next = head;

}

*/

int main(){


	struct node *x1 = createNode(4);
	struct node *x2 = createNode(5);
	struct node *x3 = createNode(10);
	x1->next = x2 ;
	x2->next = x3 ;
	x3->next = x1;
//	struct node *y0 =createNode(5);
//	y0->next = y0;
	printNode(x1);
	basaEkle(&x1,28);
	printNode(x1);
	sonaEkle(&x1,1523);
	printNode(x1);
	arayaEkle(x1,28,39);
	printNode(x1);
	bastanSil(&x1);
	printNode(x1);
	sondanSil(x1);
	printNode(x1);
}
