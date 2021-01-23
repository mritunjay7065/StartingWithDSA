# include <stdio.h>
# include <stdlib.h>
# include <string.h>


typedef struct stack{
   int top;
   unsigned capacity;
   int *array;
}Stack;

Stack *newStack(const unsigned capacity){
        Stack *pstack = (Stack *)malloc(sizeof(Stack));
        pstack->capacity = capacity;
        pstack->top = -1;
        pstack->array = (int *)malloc(capacity*sizeof(int));
       return pstack;
}

char peek(Stack *pstack){
        if(isEmpty(pstack)){
            return 0;//for self understand.
        }
     return pstack->array[pstack->top];
}
char pop(Stack *pstack){
        if(isEmpty(pstack)){
            return 0;//for self understand.
        }
        return pstack->array[(pstack->top)--];
}
void push(Stack *pstack, char ch){
      if(isFull(pstack)){
        return 0;//for self understand.
      }
      pstack->array[++(pstack->top)] = ch;
}

int isEmpty(Stack *pstack){
     return pstack->top == -1;
}

int isFull(Stack *pstack){
   return pstack->top == pstack->capacity-1;

}
int predecessor (char ch){
     if(ch == '-' || ch == '+'){
        return 1;
     }
     else if(ch == '*' || ch == '/'){
        return 2;
     }
     else if(ch == '^'){
        return 3;
     }
     else return -1;
}
int isOperend(char ch){
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'B'){
        return 1;
    }
    return 0;
}

char *infixtopostfix(char *inf){
       Stack *pstack = newStack(strlen(inf));
        char *post = (char *)malloc((strlen(inf))*sizeof(char));
        char c;
        int i = 0, k = 0;
        for(i = 0; inf[i]; i++){
             c = inf[i];
            if(isOperend(c)){
                post[k++] = c;
            }
            else if(c == '('){
                  push(pstack, c);
                    }
            else if(c == ')'){
                while(!isEmpty(pstack) && peek(pstack) != '(')
                    post[k++] = pop(pstack);
                    if (!isEmpty(pstack) && peek(pstack) != '(')
                    {  return -1;
                        } // invalid expression
            else{
                     printf("SDFGH");
                pop(pstack);
                }
            }

            else {
                    while(!isEmpty(pstack) && predecessor (c) <= predecessor (peek(pstack)))
                        post[k++] = pop(pstack);
                        push(pstack, c);
               }
            }
            while(!isEmpty(pstack)){
                post[k++] = pop(pstack);
            }
            post[k] = '\0' ;
            printf("Done!!!\n");
             puts(post);
            return post;

}
/*
void printString(cahr str[]){
        for(int i = 0; str[i]; i++){

        }

}
*/

// output abcd^e-fgh*+^*+i-
void main(){
      char exp[] = "a+b*(c/d)";
       printf("%s\n",exp);

      //infixtopostfix(exp);
      printf(" %s",infixtopostfix(exp));

    return;
}
