#include <stdio.h> 
//creates a linked list node 
#include <stdlib.h> 

struct Node
{
    int data; 
    struct Node* next; 
};


void push(struct Node** head, int newNum)
{
    //allocates the memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = newNum;
    new_node->next = *head; 
    *head = new_node; 
}

void delete(struct Node** head, int key)
{
    struct Node* temp = *head; 
    struct Node* prev = NULL; 

    if(temp != NULL && temp->data == key)
    {
        prev = temp; 
        temp = temp->next; 
    }

    while(temp != NULL && temp->data != key)
    {
        prev = temp; 
        temp = temp->next; 
    }

    if(temp == NULL)
    {
        return; 
    }

    prev->next = temp->next; 
}


void printList(struct Node* node)
{
    while(node != NULL)
    {
        printf("%d", node->data); 
        node = node->next; 
    }
    printf("\n"); 
}


int main() {
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printf("Created Linked list is:\n");
    printList(head);

    delete(&head, 1);

    printf("Linked List after Deletion of 1:\n");
    printList(head);

    return 0;
}