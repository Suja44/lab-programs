#include <stdio.h>
#include <malloc.h>

struct node {
	struct node *left;
	int info;
	struct node *right;
};

typedef struct node *NODE;

NODE insend(NODE first, int item){
	NODE newNode = (NODE)malloc(sizeof (struct node));
	newNode->info = item;
	
	if(first == NULL){
		newNode->left = NULL;
		newNode->right = NULL;
		first = newNode;
		return first;
	}
	
	newNode->right = NULL;
	NODE temp = first;
	
	while(temp->right != NULL){
		temp = temp->right;
	}
	
	temp->right = newNode;
	newNode->left = temp;
	return first;
}

void display(NODE first, int n){
	NODE temp = first;
	int counter = 1;
	
	while(temp != NULL){
		printf("%d\t", temp->info);
		if(counter % n == 0){
			printf("\n");
		}
		temp = temp->right;
		counter++;
	}
}

NODE removeZeros(NODE first, NODE second){
	NODE temp = first;
	while(temp != NULL){
		if(temp->info != 0) {
			second = insend(second, temp->info);
		}
		temp = temp->right;
	}
	
	return second;
}

int main(){
	int m, n, ele;
	NODE first = NULL, second = NULL;
	
	printf("Enter the number of rows and colums\n");
	scanf("%d%d", &m, &n);
	
	printf("Enter %d elements in total\n", m * n);
	for(int i = 1; i<=m; i++){
		for(int j = 1; j<=n; j++){
			scanf("%d", &ele);
			first = insend(first, ele);
		}
	}
	
	printf("The elements entered were\n");
	display(first, n);
	
	printf("Matrix after removing zeros\n");
	second = removeZeros(first, second);
	display(second, n);
	
	return 0;
}

