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
void insert_in_end(struct node**head,int data){
struct node*newnode=(create node (data);
if(head==NULL){
*head=newnode;
} else{
struct node*current=*head;
while(current
