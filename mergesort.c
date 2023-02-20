#include <stdio.h>
#include <malloc.h>

struct node {
	int info;
	struct node *link;
};

typedef struct node *NODE;

NODE insend(NODE first, int item){
	NODE newNode = (NODE)malloc(sizeof (struct node));
	newNode->info = item;
	newNode->link = NULL;
	
	if(first == NULL){
		first = newNode;
		return first;
	}
	
	NODE temp = first;
	while(temp->link != NULL){
		temp = temp->link;
	}
	
	temp->link = newNode;
	return first;
}

NODE merge(NODE f, NODE s, NODE t){
	NODE t1 = f, t2 = s;
	while(t1 != NULL && t2 != NULL){
		if(t1->info < t2->info){
			t = insend(t, t1->info);
			t1 = t1->link;
		}
		else {
			t = insend(t, t2->info);
			t2 = t2->link;
		}
	}
	
	while(t1 != NULL){
		t = insend(t, t1->info);
		t1 = t1->link;
	}
	
	while(t2 != NULL){
		t = insend(t, t2->info);
		t1 = t1->link;
	}
	return t;
}

void display(NODE first){
	NODE temp = first;
	
	while(temp != NULL){
		printf("%d\t", temp->info);
		temp = temp->link;
	}
}

int main(){
	int n, ele;
	NODE f = NULL, s = NULL, t = NULL;
	printf("Enter the number of elements for LL 1\n");
	scanf("%d", &n);
	
	printf("Enter %d elements\n", n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ele);
		f = insend(f, ele);
	}
	printf("Enter the number of elements for LL 2\n");
	scanf("%d", &n);
	
	printf("Enter %d elements\n", n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ele);
		s = insend(s, ele);
	}
	t = merge(f, s, t);
	display(t);
	
	return 0;
}
