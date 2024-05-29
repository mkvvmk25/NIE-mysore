#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int *qArr; 
    int front;
    int rear;
    int length; 
    int capacity;
};

void enQueue( int val,  struct Queue *q)
{
    if(  q->front == -1 && q->rear == -1 ) // q is empt 
    {
        q->front = 0;
        q->rear = 0;
        *(q->qArr + q->rear) = val; 
        q->length++;
    }
    else if(  (q->rear+1) % q->capacity == q->front )
    {
        printf("%d q is filled\n", q->rear + 1);
    }
    else 
    {
        q->rear = (q->rear + 1) % q->capacity;
        *(q->qArr + q->rear) = val;
        q->length++;
    }
}


int deQueue( struct Queue *q)
{
    if( q->rear == -1 && q->front == -1)
    {
        printf("its empty\n");
        return -1; 
    }
    else if(q->rear == q->front)
    {
        q->length--;
        int t =  q->qArr[q->front]; 
        q->rear = -1; 
        q->front = -1; 
        return t;
    }
    else 
    {
        q->length--;
        int t =  q->qArr[q->front];
        q->front = (q->front + 1 ) % q->capacity;  
        return t; 
    }
}

void printQ(struct Queue *q)
{
    if(q->front == -1)
    {
        printf("nothing to print \n");
        return; 
    }
    for(int i = q->front ;  i != q->rear  ; i=(i+1)%q->capacity)
    {
        printf("%d ", q->qArr[i]);
    }
    printf("%d ", q->qArr[q->rear]);
    
    printf("\n");
}

int main()
{
    struct Queue q1; // 
    q1.front = -1;
    q1.rear = -1;
    q1.length = 0; 
    q1.capacity = 5;
    q1.qArr = (int*)malloc(q1.capacity * 4); 
    enQueue(10, &q1);
    enQueue(20, &q1);
    enQueue(30, &q1);
    enQueue(40, &q1);
    enQueue(50, &q1);
    deQueue(&q1); 
    deQueue(&q1); 
    enQueue(90, &q1);
    enQueue(80, &q1);

    printQ(&q1);

}