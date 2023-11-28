#include<stdio.h>
#include<stdlib.h>

//TEK YONLU BAGLI LISTE

//dugum yapisi
struct node{
	int data;
	struct node *next;
};


//yeni dugum ekleme
struct node *createNode(int data){
	struct node *eklenen = (struct node *)malloc(sizeof(struct node));
	eklenen -> data  = data ;
	eklenen -> next  = NULL;
	return eklenen;
}

//dugumleri yazdirma
void printNode(struct node *head){
	if(head==NULL){
		printf("veri yapisinda veri bulunamadi..\n");
		return;
	}
	struct node *tmp = head;
	while(tmp!=NULL){
		printf("%d\t",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
//basaEkle fonksiyonu
void basaEkle(struct node **head,int data){

	struct node *yeni = createNode(data);
	if((*head)==NULL){
		(*head)=yeni;
		return;
	}

	yeni -> next =(*head);
	(*head) = yeni ;
}
//sona ekleme fonksiyonu
void sonaEkle(struct node **head,int data){
	struct node *yeni = createNode(data);
	yeni->next = NULL;
	if((*head)==NULL)
		(*head)=yeni;
	struct node *tmp = (*head);
	while(tmp->next!=NULL)
		tmp = tmp->next;
	tmp->next = yeni;

}
//araya dataya göre ekleme
void arayaEkle(struct node *head,int aranan,int data){

	struct node *tmp = head;

	while(tmp->data!=aranan)
	{
		tmp = tmp->next;
		if(tmp==NULL){
			printf("aradiginiz eleman bulunamadi.");
			return;
		}
	}
	struct node *yeni = createNode(data);
	yeni->next = tmp->next;
	tmp->next=yeni;


}


//sondan silme
void sondanSil(struct node *head){
	//hiç eleman yoksa
	if(head==NULL){
		return;
	}
	//bir elemanlıysa
	if(head->next==NULL){
		free(head);
		return;
	}
	//ikiden fazla elemanlıysa
	struct node *tmp = head;
	while(tmp->next->next!=NULL)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next= NULL;

}
//bastan silme
void bastanSil(struct node **head){
	//hiç eleman yoksa
	if((*head)==NULL)
	return;
	//diğer durumlar
	struct node *tmp = (*head);
	(*head)=tmp->next;
	free(tmp);

}
//aradanSilme fonksiyonu
void aradanSil(struct node *head,int x){
	//hiç elemanı yoksa
	if(head==NULL)
	return;
	struct node *tmp = head;
	while(tmp->next->data!=x){
		tmp=tmp->next;
		if(tmp->next==NULL){
			printf("silinecek eleman bulunamadi..\n");
			return;
		}
	}
	struct node *silinecek = tmp->next;
	tmp->next = tmp->next->next;
	free(silinecek);


}

//bagli listeyi temizleme
void freeList(struct node **head){
	struct node *tmp;
	while((*head)!=NULL){
		tmp=(*head);
		(*head) = (*head)->next;
		free(tmp);
	}

	printf("bağlı liste temizlendi...\n");
}

//tek yonlu bagli liste yer değiştirme yani baştaki son sondaki  bas olacak simetrik yer degistirecek
void reverse(struct node **head){
	struct node *tmp = (*head);
	while(tmp->next!=NULL)
	tmp=tmp->next; 
//15.11.2023 tarihinde yapılacak.....

}



int main(){
	struct node *dugum1 = createNode(5);
	struct node *dugum2 = createNode(7);
	dugum1->next = dugum2;dugum2->next=NULL;
	printNode(dugum1);
	freeList(&dugum1);
	printNode(dugum1);
	struct node *d1 = createNode(15);
	struct node *d2 = createNode(20);
	struct node *d3 = createNode(25);
	d1->next=d2;d2->next=d3;d3->next=NULL;
	printNode(d1);
	basaEkle(&d1,10);
	printNode(d1);
	sonaEkle(&d1,30);
	printNode(d1);
	arayaEkle(d1,30,35);
	printNode(d1);
	arayaEkle(d1,30,31);
	printNode(d1);
	sondanSil(d1);
	printNode(d1);
	bastanSil(&d1);
	printNode(d1);
	aradanSil(d1,40);
	printNode(d1);
	aradanSil(d1,30);
	printNode(d1);
	return 0;
}
