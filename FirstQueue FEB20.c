///Queue using array
#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int rear,front;
    int capacity;
    int *array;
};
typedef struct queue queue;

queue *create(int capacity)
{
queue* q;
q=(queue*)malloc(sizeof(queue));
q->capacity=capacity;
q->front=q->rear=-1;
q->array=(int *)malloc(sizeof(int)*q->capacity);
return q;

}
int isempty(queue *q)
{
    return(q->front==-1);

}
int isfull(queue *q)
{
    return((q->rear+1)%q->capacity==q->front);

}
void enqueue(queue *q,int data)
{
    if(isfull(q))
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        q->rear=(q->rear+1)%q->capacity;
        q->array[q->rear]=data;
        if(q->front==-1)
            q->front=q->rear;
       printf("\nFront is [%d] \t",q->front);
       printf("\nRear  is [%d] \n",q->rear);
    }
}
void display(queue *q)
{  int f=q->front;
   int r=q->rear;
    if(isempty(q))
    {
      printf("\nQueue is Empty(Inside Display)\n");
      return;
    }
   else
   {  printf("\nYour Queue elements are : ");
       while(f<=r)
       {
           printf("%d ",q->array[f]);
           f++;
       }
   }
}

void dequeue(queue *q)
{

   if(isempty(q))
   {
       printf("\nQueue is Empty(Inside Dequeue)\n");
       //return;
   }
   else
   {
       printf("\nDequeued element is : %d \n",q->array[q->front]);
       if(q->front==q->rear)
          q->front=q->rear=-1;
       else
        q->front=(q->front+1) % q->capacity;

   }
}
void sizeofqueue(queue *q)
{

    printf("\nThe Size of the queue is : %d",(q->capacity)-(q->front)+(q->rear+1)%q->capacity);

}
int main()
{
    int capacity;
    queue*q;
    printf("\nEnter the size of Queue : ");
    scanf("%d",&capacity);
   q = create(capacity);
   display(q);
   enqueue(q,2);
   enqueue(q,-1);
   enqueue(q,5);
   enqueue(q,6);
   enqueue(q,7);
   display(q);
  sizeofqueue(q);
  dequeue(q);
  //dequeue(q);
 enqueue(q,67);
 sizeofqueue(q);
 // display(q);
  display(q);
  //display(q);
    //enqueue(q,77);



}
