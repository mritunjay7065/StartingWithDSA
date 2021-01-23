#include<stdio.h>
#include<stdlib.h>

struct arraystack
{
   int top;
   int capacity;
   int *array;
};
//typedef struct arraystack stack;

struct arraystack* createstack(int cap)
  {
     struct arraystack *stack;
     stack=(struct arraystack*)malloc(sizeof(struct arraystack));
     stack->top=-1;
     stack->capacity=cap;
     stack->array = (int *)malloc(sizeof(int)*cap);
     return stack;
  }

int isfull(struct arraystack *stack)
{
  if(stack->top==stack->capacity-1)
  {
    return 1;
  }
 return 0;
}

int isempty(struct arraystack *stack)
{
  if(stack->top==-1)
  {
     return 1;
  }
return 0;
}
void displaystack(struct arraystack *stack)
{   int top=stack->top;
    if(isempty(stack))
        printf("\nSTACK IS EMPTY\n\n");
        else
        { printf("YOUR STACK : ");
   while(top!=-1)
    {
       printf("%d ",stack->array[top]);
       top--;
    }
        }
printf("\n");
}

void push(struct arraystack *stack,int data)
{

   if(!isfull(stack))
   {  stack->top++;
      stack->array[stack->top]=data;
   }
  else
   printf("\n\n---STACK OVERFLOW---\n\n");

 }

void pop(struct arraystack *stack)
{
  if(!isempty(stack))
   {  printf("%d ",stack->array[stack->top]);
      stack->top--;
   }
 else
printf("\n---STACK UNDERFLOW---\n");

}

int main()
{   int cap,ch,data;
    struct arraystack *stack;
    printf("\nEnter the size of stack \n");
    scanf("%d",&cap);
    stack=createstack(cap);
    while(1)
  {    printf("1. PUSH\n2. POP\n3. DISPLAY STACK\n4. Exit\nEnter your choice\n");
       scanf("%d",&ch);

     switch (ch)
       {
          case 1: printf("\nEnter data : ");
                  scanf("%d",&data);
                  push(stack,data);
                  break;
          case 2: printf("\nPopped Element is : ");
                  pop(stack);
                  printf("\n");
                  break;
          case 3: displaystack(stack);
                  break;
          case 4: exit(0);
                  break;
          default: printf("\nWrong choice entered try again\n");
         }
   }//while loop


}
