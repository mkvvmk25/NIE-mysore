#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int *stackArr; 
    int top;
    int length; 
    int capacity;
};

int peek(struct stack *st)
{
    if(st->top == -1)
    {
            printf("stack is empty no peek ele\n");
            return -1; 
    }
    else 
    {
        return st->stackArr[st->top]; 
    }
}

void push( int val,  struct stack *st)
{
    if(st->top == st->capacity - 1)
    {
        printf("stack over flow\n"); 
    }
    else
    {
        st->length++;
        st->top = st->top + 1; 
        st->stackArr[st->top] = val; 
    }
}

int pop( struct stack *st)
{
   if(st->top == -1)
   {
        printf("stack is empty\n");
        return -1; 
   }
   else 
   {
        st->length--;
        int t = st->stackArr[   st->top   ]; // 50
        st->top = st->top - 1; 
        return t;
   }
}

void printStack(struct stack *st)
{
    if(st->top == -1 )
    {
        printf("nothing to print\n");
    }
    else 
    {
        for(int i = 0; i <= st->top; i++)
        {
            printf("%d ",st->stackArr[i]); 
        }
        printf("\n");
    }
}

int main()
{
    struct stack s1; 
    s1.capacity = 5;
    s1.length = 0; 
    s1.top = -1; 
    s1.stackArr = (int*)malloc(s1.capacity * 4); 

    push(10,&s1);
    push(20,&s1);
    push(30,&s1);
    push(40,&s1);
    push(50,&s1);
    push(60,&s1);
    push(70,&s1);
    pop(&s1); 
    pop(&s1); 
    pop(&s1); 

    printStack(&s1);

}