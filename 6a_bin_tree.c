
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
	int info;
	struct node* left;
	struct node* right;
};typedef struct node* NODE;

 NODE create(NODE root)
 {
	 NODE pres,prev,newnode;
	 newnode = (NODE) malloc(sizeof(struct node));
	 printf("Enter info\n");
	 scanf("%d",&newnode->info);
	 newnode->left = newnode->right = NULL;
	 if(root==NULL)
	 {
		 root = newnode;
		 return root;
	 }
	 pres = root;
	 while(pres!=NULL)
	 {
		 if(newnode->info < pres->info)
		 {
			 prev = pres;
			 pres = pres->left;
		 }
		 else
		 {
			 prev = pres; 
			 pres = pres->right;
		 }
	 }
	 if(newnode->info < prev->info)
	 prev->left = newnode;
	 else
	 prev->right = newnode;
	 return root;
 }
 
 void preorder(NODE root)
 {
	 if(root!=NULL)
	 {
		 printf("%d\t",root->info);
		 preorder(root->left);
		 preorder(root->right);
	 }
 }
 void inorder(NODE root)
 {
	 if(root!=NULL)
	 {
		 preorder(root->left);
		 printf("%d\t",root->info);
		 preorder(root->right);
	 }
 }
 void postorder(NODE root)
 {
	 if(root!=NULL)
	 {
		 postorder(root->left);
		 postorder(root->right);
		 printf("%d\t",root->info);
	 }
 }
	 
 int main()
 {
	 NODE root = NULL;
	 int ch;
	 for(;;)
	 {
		 printf("1. Create 2.Preorder 3.Inorder 4.PostOrder\n");
		 scanf("%d",&ch);
		 switch(ch)
		 {
			 case 1:root = create(root);
			 break;
			 case 2: if(root==NULL) printf("Tree is empty\n");
					 else preorder(root);
			 break;
			 case 3: if(root==NULL) printf("Tree is empty\n");
					 else inorder(root);
			 break;
			 case 4: if(root==NULL) printf("Tree is empty\n");
					 else postorder(root);
			 break;
			 default : exit(0);
		 }
	 }
 }
	 
	 
	 
	 
	 
