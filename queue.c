#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int size =5;
int front = 0, rear = -1, c=0;
char q[5], item;
void insert(){
	if(c==size)
		printf("Queue full\n");
	else{
		printf("Enter the element : ");
		scanf("%s", &item);
		rear = (rear+1)%size;
		q[rear] = item;
		c=c+1;
	}
}

void delete(){
	if(c==0)
		printf("Queue is empty\n");
	else{
		int temp = front;
		front = (front+1)%size;
		printf("Deleted element : %c", q[temp]);
		c=c-1;
	}
}

void display(){
	int i;
	if(c==0)
		printf("Queue is empty");
	else{
		int temp = front;
		for(i=0; i<c; i++){
			printf("%c\n", q[temp]);
			temp = (temp+1)%size;
		}
	}
}

int main()
{
	int ch;
	while(1){
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert(); break;
			case 2: delete(); break;
			case 3: display(); break;
			case 4: exit(0); break;
			default: printf("Invalid"); break;
		}
	}
	return 0;
}
