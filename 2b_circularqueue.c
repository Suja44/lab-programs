#include<stdio.h>
#include <stdlib.h>
#define SIZE 5
int q[SIZE],rear=-1,front=0,item,ch;
int qinsert(int);
int qdelete();
int qdisplay();
int main()
{

while(1)
{
printf("\n 1:INSERT 2:DELETE 3:DISPLAY otherwise EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter the elements\n");
scanf("%d",&item);
qinsert(item);
break;
case 2:qdelete();
break;
case 3 :qdisplay();
break;
default:printf("Invalid operation");
exit(0);
}
}
}
int qinsert(int item)
{
if(rear==SIZE-1)
printf("Queue is full");
else
{
rear=rear+1;
q[rear]=item;
}
return 0;
}
int qdelete()
{
if(front>rear)
printf("Queue is Empty");
else
{
printf("The deleted element id %d",q[front]);
front=front+1;
}
return 0;
}
int qdisplay()
{
int i;
if(front>rear)
printf("Queue is Empty");
else
{
printf("The status of Queue\n");
for(i=front;i<=rear;i++)
printf("Queue[%d]=%d\n",i,q[i]);
}
return 0;
}
