//stack pushla ilgili compute fonksiyonu 
void compute(struct stack* yeni){
	int length = yeni -> top +1;
	if(length%2==0)
		push(yeni,length);
	else
		printf("alinan=%d\n",pop(yeni));
}
push(yeni,5);
push(yeni,10);
push(yeni,15);
compute(yeni);
printf("alinan=%d\n",top);
