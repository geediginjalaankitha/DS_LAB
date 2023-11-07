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
void insert_at_beginning(struct node**head, int data)
{
struct node*newnode=createnode(data);
newnode->next=*head;
*head=newnode;
}
void dispalylist(struct node *head)
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
struct node*head=NULL;

insert_at_beginning(&head,3);
insert_at_beginning(&head,2);
insert_at_beginning(&head,1);
printf("linked list: ");
dispalylist(head);
return 0;
}


