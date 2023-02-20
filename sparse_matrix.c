#include<stdio.h>
#include<stdlib.h>

//defined the structure of Node
struct Node{
	int row, col, val;
	struct Node *prev, *nxt;
};

typedef struct Node NODE;
NODE *root = NULL;
int m, n;

//function to insert from rear
void insrear(int row, int col, int data){
	NODE *temp, *cur;
	temp = (NODE *)malloc(sizeof(NODE));
	temp->val = data;
	temp->row = row;
	temp->col = col;
	temp->prev = NULL;
	temp->nxt = NULL;
	if(root == NULL)
		root = temp;
	else{
		cur = root;
		while(cur->nxt != NULL)
			cur = cur->nxt;
		cur->nxt = temp;
		temp->prev = cur;
	}
}

//function to display the non-zero elements
void display_list(){
	NODE *temp;
	if(root == NULL)
		printf("List is empty\n");
	else{
		temp = root;
		printf("Row\tCol\tValue\n");
		while(temp != NULL){
			printf("%d\t%d\t%d\n", temp->row, temp->col, temp->val);
			temp = temp->nxt;
		}
	}
}

//function to display the matrix
void display_matrix(){
	
	NODE *temp;
	if(root == NULL)
		printf("List is empty\n");
	else{
		temp = root;
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=n;j++){
				if(temp != NULL && temp->row == i && temp->col == j){
					printf("%d\t", temp->val);
					temp = temp->nxt;
				}
				else{
					printf("0\t");
				}
			}
			printf("\n");
		}
	}
}

int main()
{
	int a[10][10];
	printf("Enter the number of rows: ");
	scanf("%d", &m);
	printf("Enter the number of columns: ");
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			scanf("%d", &a[i][j]);
			if(a[i][j] != 0)
				insrear(i, j, a[i][j]);
		}
	}
	printf("List content display\n");
	display_list();
	printf("Matrix display from list\n");
	display_matrix();
	return 0;
}
			
		
