#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
struct Node* insertAtEnd(struct Node* head, int data)
{
    struct Node* newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
struct Node* insertAtMiddle(struct Node* head, int data, int position)
{
    struct Node* newNode = createNode(data);
    if (position == 0)
    {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    int count = 0;
    while (count < position - 1 && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
    {
        printf("Invalid position for insertion.\n");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}
struct Node* deleteAtBeginning(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
struct Node* deleteAtEnd(struct Node* head)
{
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}
void display(struct Node* head)
{
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node* head = NULL;
    head = insertAtBeginning(head, 1);
    head = insertAtEnd(head, 3);
    head = insertAtMiddle(head, 2, 1);

    printf("Linked List: ");
    display(head);

    head = deleteAtBeginning(head);

    printf("Linked List after deletion: ");
    display(head);
    return 0;
}

	

