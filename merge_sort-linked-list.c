#include<stdio.h>
#include<stdlib.h>

//defining the structure of node
typedef struct node{
	int data;
	struct node *next;
}node;

//function to merge two sorted linked list
node *merge(node *p, node *q, node *sorting){
	node *head3;
	if(p == NULL)
		return q;
	if(q == NULL)
		return p;
	if(p && q){
		if(p->data <= q->data){
			sorting = p;
			p = sorting->next;
		}
		else{
			sorting = q;
			q = sorting->next;
		}
	}
	
	head3 = sorting;
	
	while(p && q){
		if(p->data <= q->data){
			sorting->next = p;
			sorting = p;
			p = sorting->next;
		}
		else{
			sorting->next = q;
			sorting = q;
			q = sorting->next;
		}
	}
	if(p == NULL)
		sorting->next = q;
	if(q == NULL)
		sorting->next = p;
		
	return head3;
}

int main()
{
	node *p = NULL, *q = NULL, *head1 = NULL, *head2 = NULL, *sorting = NULL;
	int n1, n2, a, i;
	printf("Enter the number of nodes in first linked list: ");
	scanf("%d", &n1);
	printf("Enter the number of nodes in second linked list: ");
	scanf("%d", &n2);
	
	if(n1 > 0){
		printf("Enter the first linked list: ");
		scanf("%d", &a);
		p = (node *)malloc(sizeof(node));
		p->data = a;
		p->next = NULL;
		head1 = p;
	}
	for(i = 1;i<n1;i++){
		scanf("%d", &a);
		q = (node *)malloc(sizeof(node));
		q->data = a;
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
	
	if(n2 > 0){
		printf("Enter the second linked list: ");
		scanf("%d", &a);
		p = (node *)malloc(sizeof(node));
		p->data = a;
		p->next = NULL;
		head2 = p;
	}
	for(i = 1;i<n2;i++){
		scanf("%d", &a);
		q = (node *)malloc(sizeof(node));
		q->data = a;
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
	
	p = head1;
	q = head2;
	
	printf("First linked list: ");
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	
	printf("Second linked list: ");
	while(q != NULL){
		printf("%d ", q->data);
		q = q->next;
	}
	
	printf("\n");
	
	p = head1;
	q = head2;
	
	sorting = merge(p, q, sorting);
	
	printf("Sorted merged linked list: ");
	while(sorting != NULL){
		printf("%d ", sorting->data);
		sorting = sorting->next;
	}
	
	return 0;
}
