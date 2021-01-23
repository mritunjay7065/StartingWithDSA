#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct arraystack   ///Reversing string with stack using array!!!!!!
 {
    int top;
    int capacity;
    char *array;
 };
typedef struct arraystack stack;
stack *createstack(int cap)
{
    stack *Stack;
    Stack =(stack *)malloc(sizeof(stack));
    Stack->top=-1;
    Stack->capacity=cap;
    Stack->array=(char *)malloc(sizeof(char)*cap);

    return Stack;
}
int isempty(stack *stack)
{

    return (stack->top==-1);
}
int isfull(stack *stack)
{
  if(stack->top==stack->capacity-1)
     return 1;
  return 0;
}

void push(stack *stack,char c)
{
    if(isfull(stack))
        printf("\nStack Overflow\n");
    else
    { stack->top++;
      stack->array[stack->top]=c;
    }

}

char pop(stack*stack)
{  char s;
    if(isempty(stack))
       {
           printf("\nunderflow");
       } //return '\0';
    else
    {
        s=stack->array[stack->top];
        stack->top--;
    }
   return s;
}

void reversestring(stack *stack,char str[])
{
  int i,l,m,c=0;
  char str2[100],str3[100];
  l=strlen(str);
  for(i=0;str[i]!='\0';i++)
  {
      push(stack,str[i]);
  }
  for(i=0;i<l;i++)
  {
      str2[i]=pop(stack);
    /// printf("%c ",str2[i]);
  }
  str2[i]='\0';
puts(str2);

}


int main()
{
    stack *stack;
    char str[100];
  //  char str[]="computer is  a great device";


    printf("\nEnter a string\n");
    scanf("%[^\n]",str);
   // puts(str);
    stack=createstack(strlen(str));
  //printf("%d",strlen(str));
  reversestring(stack,str);

}
