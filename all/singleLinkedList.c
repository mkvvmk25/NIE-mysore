#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node 
{
    int value; 
    struct Node *nextAddress;
}; 

void insertEnd(int val,  struct Node **head,  struct Node **tail )
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
void insertBeg(int val,  struct Node **head,  struct Node **tail )
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
        newNode->nextAddress = *head; 
        *head = newNode; 
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

void insertBtw(int val, int pos, struct Node **head, struct Node **tail)
{
    struct Node *temp = *head; 
    int len = 0; 
    while( temp != NULL)
    {
        len++; 
        temp = temp->nextAddress; 
    }

    if(pos == 1)
    {
        insertBeg(val, head, tail); 
    }
    else if( pos > len)
    {
        insertEnd(val , head, tail); 
    }
    else 
    {
        // create a node 
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); // 
        newNode->value = val; 
        newNode->nextAddress = NULL; 

        // pos 3
        struct Node *befAddress; // 
        struct Node *posAddress;  //  

        int i = 1; 
        struct Node *tem = *head;  // 
        while(i != pos - 1)  //
        {
            tem = tem->nextAddress;  // 
            ++i;
        }

        befAddress  = tem; 
        posAddress = befAddress->nextAddress;

        // link nn -> posadd 
        newNode->nextAddress = posAddress;
        befAddress->nextAddress = newNode; 
    }

}

void deleteBeg(struct Node **head, struct Node **tail )
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
void deleteEnd(struct Node **head, struct Node **tail )
{
    if( *head == *tail)
    {
        *head = NULL;
        *tail = NULL; 
    }
    else 
    {
        struct Node *tem = *head; 
        while( tem->nextAddress->nextAddress != NULL)
        {
            tem = tem->nextAddress; 
        }
        tem->nextAddress = NULL; 
    }


}


void deleteBtw(int val, int pos, struct Node **head, struct Node **tail)
{
    struct Node *temp = *head; 
    int len = 0; 
    while( temp != NULL)
    {
        len++; 
        temp = temp->nextAddress; 
    }

    if(pos == 1)
    {
        deleteBeg(head, tail); 
    }
    else if( pos == len)
    {
        deleteEnd(head, tail); 
    }
    else 
    {
       
        // pos 3
        struct Node *befAddress; // 
        struct Node *posAddress;  //  
        struct Node *aftAddress;  //  

        int i = 1; 
        struct Node *tem = *head;  // 
        while(i != pos - 1)  //
        {
            tem = tem->nextAddress;  // 
            ++i;
        }

        befAddress  = tem; 
        posAddress = befAddress->nextAddress;
        aftAddress = posAddress->nextAddress; 

        befAddress->nextAddress = aftAddress; 
        posAddress->nextAddress = NULL; 
    }

}

int main()++
{
    struct Node *mainHead = NULL; //  
    struct Node *mainTail = NULL; // 

    insertEnd(10, &mainHead,  &mainTail);
    insertEnd(20, &mainHead,  &mainTail);
    insertEnd(30, &mainHead,  &mainTail); 
    insertEnd(40, &mainHead,  &mainTail); 

    insertBtw(100, 2, &mainHead, &mainTail);
    insertBtw(200, 1, &mainHead, &mainTail);
    insertBtw(300, 7, &mainHead, &mainTail);


    printLL(mainHead); 
   
}