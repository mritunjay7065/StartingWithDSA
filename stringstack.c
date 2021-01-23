#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void push(struct arraystack* stack,char c)
{ 
   if(!isfull(stack))
  { stack->top++;
    stack->array[stack->top]=c;
    printf("%c ",stack->array[stack->top]);
  }
  else
  printf("\nBHAR GYA STACK \n");

}

char pop(struct arraystack *stack)
{  char c;
   if(!isempty(stack))
    {  
       c=stack->array[stack->top];
       stack->top--;
       return c;
    }
else
printf("\nSTACK UNDERFLOW\n");

}
 
void reverse(char str[])
{
   int l,i;
  char str2[100];
   l=strlen(str);
   struct arraystack*stack;
   stack=createstack(l);
   for(i=0;str[i]!='\0';i++)
   {
      push(stack,str[i]);
   }
  for(i=0;i<l;i++)
   {   str2[i]=pop(stack);
   }
  str[l]='\0';
printf("%s",str2);

}




int main()
{
   char str[]="Guwahati is handsome";
   puts(str);
   reverse(str);

}
	
