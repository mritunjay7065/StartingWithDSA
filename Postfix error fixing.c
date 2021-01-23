#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct arraystack
{
    int top;
    int capacity;
    int *array;
};
typedef struct arraystack stack;
stack *createstack(int cap)
{
    struct arraystack *Stack;
    Stack=(stack*)malloc(sizeof(stack));
    Stack->top=-1;
    Stack->capacity=cap;
    Stack->array=(int *)malloc(sizeof(int)*cap);
    return Stack;
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
void push(struct arraystack *stack,char data)
{

   if(!isfull(stack))
   {  stack->top++;
      stack->array[stack->top]=data;
   }
 ///else
   ///printf("\nSTACK OVERFLOW\n");

 }

char pop(struct arraystack *stack)
{
  if(!isempty(stack))
    return (stack->array[(stack->top)--]);
return '$';
}
/*
int sign(char c,int a,int b)
{

    if(c=='+')
        return (b+a);
    if(c=='-')
        return (b-a);
     if(c=='*')
        return (b*a);
     if(c=='/')
        return (b/a);
}
*/
int postfix(char str[])
 {   int l,i,A,B;
     stack *stack;
     l=strlen(str);
     printf("\nlengths is %d \n",l);
     stack=createstack(l);///Creates stack of size strlen(str)
     for(i=0;str[i]!='\0';i++)
     {
         if(str[i]>='0'&&str[i]<='9')
         {
             push(stack,str[i]-'0');
         }
         else // if (str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
         {
            B= pop(stack);
            printf("B is %d\n",B);
            A=pop(stack);
            printf("A is %d\n",A);
            switch(str[i])
            {
                case '+' : push(stack,B+A);
                           break;
                case '-' : push(stack,A-B);
                           break;
                case '*' : push(stack,B*A);
                           break;
                case '/' : push(stack,B/A);
                           break;
            }
           // C=sign(str[i],A,B);
           // printf("C is %d",C);
           // push(stack,C);

         }
     }

     return pop(stack);
}

int main()
{

    char str[]="437+*7-";

    printf("The Postfix Evaluation is : %d ",postfix(str));

}
