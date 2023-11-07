
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node* createnode(int data)
{
struct node *newnode=(struct node*)malloc(sizeof(newnode));
newnode->data=data;
newnode->next=NULL;
return newnode;
}
void insert_in_middle(struct node*prevnode,int data)
{
if(prevnode==NULL)
{
printf("cannot be NULL\n");
return;
}
struct node *newnode=createnode(data);
newnode->next=prevnode->next;
prevnode->next=newnode;
}

void printlist(struct node *head)
{
struct node* current=head;
while(current!=NULL)
{
printf("%d\n",current->data);
current=current->next;
}
printf("NULL \n");
}
int main()
{
struct node*head=createnode(1);
struct node*second=createnode(2);
struct node*third=createnode(4);
head->next=second;
second->next=third;
printf("initial linked list: ");
printlist(head);
int data_to_insert=3;
insert_in_middle(second, data_to_insert);
printf("linked list after insertion: ");
printlist(head);
return 0;
}
