#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node *leftAdd; 
    struct Node *rightAdd; 
};

struct Node* insert( int value, struct Node *myroot )
{
    if(myroot == NULL)
    {
        struct Node *newNode = 
            (struct Node*)malloc(sizeof(struct Node)); 
        newNode->val = value; 
        newNode->leftAdd = NULL;
        newNode->rightAdd = NULL; 
        return newNode; 
    }
    
    else if( myroot->val > value)
    {
       myroot->leftAdd = 
         insert(value, myroot->leftAdd); 
    }
    else if(myroot->val < value)
    {
        myroot->rightAdd = 
            insert(value, myroot->rightAdd);
    }
    return myroot; 
}
struct Node* delete( int value, struct Node *myroot )
{
    if( myroot->val > value)
    {
       myroot->leftAdd = 
         delete(value, myroot->leftAdd); 
    }
    else if(myroot->val < value)
    {
        myroot->rightAdd = 
            delete(value, myroot->rightAdd);
    }
    else 
    {
        if(myroot->leftAdd == NULL &&
            myroot->rightAdd == NULL)
            {
                return NULL; 
            }
        else if(myroot->leftAdd == NULL )
        {
            return myroot->rightAdd; 
        }
        else if(myroot->rightAdd == NULL )
        {
            return myroot->leftAdd; 
        }
        else 
        {
            struct Node *subRoot = myroot->rightAdd; 
            struct Node *temp = subRoot;  

            while( temp->leftAdd != NULL )
            {
                temp = temp->leftAdd; 
            }

            int succVal = temp->val; 

            myroot->rightAdd = delete(succVal, subRoot);

            myroot->val = succVal; 

        }
    }


    return myroot; 
}

void inOrder(struct Node *myroot)
{
    if(myroot != NULL)
    {
        inOrder(myroot->leftAdd);
        printf("%d ", myroot->val); 
        inOrder(myroot->rightAdd); 
    }
    return; 
}
void preOrder(struct Node *myroot)
{
    if(myroot != NULL)
    {
        printf("%d ", myroot->val); 
        inOrder(myroot->leftAdd);
        inOrder(myroot->rightAdd); 
    }
    return; 
}
void postOrder(struct Node *myroot)
{
    if(myroot != NULL)
    {
        inOrder(myroot->leftAdd);
        inOrder(myroot->rightAdd); 
        printf("%d ", myroot->val); 
    }
    return; 
}




int main()
{
    struct Node *root = NULL;
    root = insert(10, root); 
    root = insert(5, root);
    root = insert(2, root);
    root = insert(25, root);
    root = insert(7, root);
    root = delete(25, root); 
    inOrder(root); 
}