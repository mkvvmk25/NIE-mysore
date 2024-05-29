#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node 
{
    int value; 
    struct Node *nextAddress;
}; 

void enQueue(int val,  struct Node **head,  struct Node **tail )
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); // 
    newNode->value = val; 
    newNode->nextAddress = NULL; 

    if(*head == NULL)
    {
        *tail = newNode; // 
        *head = newNode; //
    }
    else 
    {
        (*tail)->nextAddress = newNode;
        *tail = newNode;
    }
}   

void printLL(struct Node *temp)
{
    while( temp != NULL)
    {
        printf("%d ",temp->value); 
        temp = temp->nextAddress; 
    }
    printf("\n");
}


void deQueue(struct Node **head, struct Node **tail )
{
    if( *head == *tail)
    {
        *head = NULL;
        *tail = NULL; 
    }
    else 
    {
        struct Node *temp = *head; // 1001 
        *head = (*head)->nextAddress; 
        temp->nextAddress = NULL; 
    }
}

struct singleLinkedList
{
    struct Node *mainHead; //  
    struct Node *mainTail; // 
};

int main()
{
    struct singleLinkedList link1; 

    link1.mainHead = NULL; 
    link1.mainTail = NULL; 

    enQueue(10,&link1.mainHead, &link1.mainTail);
    enQueue(20,&link1.mainHead, &link1.mainTail);
    enQueue(30,&link1.mainHead, &link1.mainTail);
    enQueue(40,&link1.mainHead, &link1.mainTail);
    enQueue(50,&link1.mainHead, &link1.mainTail);

    deQueue(&link1.mainHead, &link1.mainTail);
    deQueue(&link1.mainHead, &link1.mainTail);

    enQueue(100,&link1.mainHead, &link1.mainTail);
    printLL(link1.mainHead); 
   
}