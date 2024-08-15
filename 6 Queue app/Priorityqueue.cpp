#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<process.h>
//A structure is created for a node
struct node
{
int priority;
int info;
struct node *link;
};
typedef struct node *NODE;
//This function will insert a data and its priority
NODE insert(NODE front)
{
NODE tmp,q;
int added_item,item_priority;
//New node is created
tmp = (NODE)malloc(sizeof(struct node));
printf("\nInput the item value to be added in the queue:");
scanf("%d",&added_item);
printf("\nEnter its priority:");
scanf("%d",&item_priority);
tmp->info = added_item;
tmp->priority = item_priority;
/*Queue is empty or item to be added has priority more than first item*/
if(front == NULL || item_priority < front->priority)
{
tmp->link = front;
front = tmp;
}
else
{
q = front;
while(q->link != NULL && q->link->priority <= item_priority)
q=q->link;
tmp->link = q->link;
q->link = tmp;
}/*End of else*/
return(front);
}/*End of insert()*/
//Following function is to delete a node from the priority queue
NODE del(NODE front)
{
NODE tmp;
if(front == NULL)
printf("\nQueue Underflow\n");
else
{
tmp = front;
printf("\nDeleted item is %d\n",tmp->info);
front = front->link;
free(tmp);
}
return(front);
}/*End of del()*/
void display(NODE front)
{
    NODE ptr;
ptr = front;
if(front == NULL)
printf("\nQueue is empty\n");
else
{ printf("\nQueue is:\n");
printf("\nPriority Item\n");
while(ptr != NULL)
{
printf("%5d %5d\n",ptr->priority,ptr->info);
ptr = ptr->link;
}
}/*End of else */
}/*End of display() */
void main()
{
int choice;
NODE front=NULL;
while(1)
{
clrscr();
printf("\n********* Priority Queue ***********\n");
//Menu options
printf("\n1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Quit\n");
printf("\nEnter your choic");
scanf("%d", &choice);
switch(choice)
{
 case 1:
front=insert(front);
break;
 case 2:
front=del(front);
getch();
break;
 case 3:
display(front);
getch();
break;
 case 4:
exit(1);
 default :
printf("\nWrong choice\n");
}
}
}