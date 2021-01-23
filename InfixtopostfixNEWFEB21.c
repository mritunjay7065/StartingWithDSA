#include<stdio.h>
#include<stdlib.h>

struct arraystack
{
   int top;
   int capacity;
   char *array;
};
//typedef struct arraystack stack;

struct arraystack* createstack(int cap)
  {
     struct arraystack *stack;
     stack=(struct arraystack*)malloc(sizeof(struct arraystack));
     stack->top=-1;
     stack->capacity=cap;
     stack->array = (char *)malloc(sizeof(char)*cap);
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
{  printf("\nYOUR STACK \n");
   int top=stack->top;

   while(top!=-1)
    {
       printf("%d ",stack->array[top]);
       top--;
    }
printf("\n");
}

void push(struct arraystack *stack,char data)
{

   if(!isfull(stack))
   {  stack->top++;
      stack->array[stack->top]=data;
   }
  else
   printf("\nSTACK OVERFLOW\n");

 }

void pop(struct arraystack *stack)
{
  if(!isempty(stack))
   {  printf("%d ",stack->array[stack->top]);
      stack->top--;
   }
 else
printf("\nSTACK UNDERFLOW\n");

}


int main()
{   int cap,ch;
    char data;
    struct arraystack *stack;
    printf("\nEnter the size of stack \n");
    scanf("%d",&cap);
    printf("\ncheck");
    stack=createstack(cap);
    while(1)
  {    printf("\n1. PUSH\n2. POP\n3. DISPLAY STACK\n4. Exit\nEnter your choice\n");
       scanf("%d",&ch);
       printf("\ncheck inside while loop");

     switch (ch)
       {
          case 1: printf("\nEnter character : ");
                  scanf("%c",&data);
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
   }


}

