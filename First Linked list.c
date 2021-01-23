#include<stdio.h>
#include<stdlib.h>

struct node
{                             ///INSERTION AT END
    int info;
    struct node *link;
};
struct node *START=NULL;
struct node*createNode()
{
 struct node*n;
    n=(struct node*)malloc(sizeof(struct node));
return n;
}
void insertnode()
{
    struct node*temp,*t;

    temp=createNode();
    printf("Enter information\n");
    scanf("%d",temp->info);
temp->link=NULL;
    if(START==NULL)  //if the list is empty
        START=NULL;
     else   //in case if lists is there!!!!
     {  t=START;
     while(t->link)
      {t=t->link;}
     t->link=temp;
     }
}



int main()
{
    insertnode();
     insertnode();
      insertnode();
       insertnode();
        insertnode();

    return 0;

}
