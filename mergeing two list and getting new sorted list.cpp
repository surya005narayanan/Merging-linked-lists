#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node *merge(node *p , node *q , node *s){
	node *head3;
	if(p == NULL)
		return q;
	if(q == NULL)
		return p;
	if(p && q){
		if(p->data <= q->data){
			s = p;
			p = s->next;
		}
		else{
			s= q;
			q= s->next;
		}
	}
	head3= s;
	while(p && q){
		if(p->data <= q->data){
			s->next = p;
			s= p;
			p = s->next;
		}
		else{
			s->next = q;
			s = q;
			q = s->next;
		}
	}
	if(p==NULL){
		s->next = q;
	}
	if(q==NULL){
		s->next = p;
	}
	return head3;	
}
int main(){
	node *p=NULL , *q=NULL , *head1=NULL , *head2=NULL , *s= NULL;
	int n1 , n2 , a , i , n;
	printf("Enter the number of nodes in the First Linked List");
	scanf("%d",&n1);
	printf("Enter the number of nodes in the second Linked List");
	scanf("%d",&n2);
	if(n1 > 0){
	printf("Enter the first Linked List");
	scanf("%d",&a);
	p = (node*)malloc(sizeof(node));
	p->data = a;
	p->next = NULL;
	head1 = p;
	}
	for(i=1;i<n1;i++){
		scanf("%d",&a);
		q = (node*)malloc(sizeof(node));
		q->data = a;
		q->next = NULL;
		p->next = q;
		p = p->next;		
	}
	if(n2 > 0){
	printf("Enter the second Linked List");
	scanf("%d",&a);
	p = (node*)malloc(sizeof(node));
	p->data = a;
	p->next = NULL;
	head2 = p;
	}
	for(i=1;i<n2;i++){
		scanf("%d",&a);
		q = (node*)malloc(sizeof(node));
		q->data = a;
		q->next = NULL;
		p->next = q;
		p = p->next;		
	}
	p = head1;
	q = head2;
	s = merge(p,q,s);
	printf(" Sorted Merged Linked List =");
	while(s!=NULL){
		printf("%d  ",s->data);
		s= s->next;
	}
	return 0;
}