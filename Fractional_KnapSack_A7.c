#include<stdio.h>
struct knapSack
{
    float itemPrice ;
    float itemWeight;
};

float KnapSack(struct knapSack a[],int n,float SackCapacity)
{
    int i ,j;
    float ratio[n],temp,capacity = 0,temp2,temp3,profit=0;
    for(i=0;i<n;i++)
        ratio[i] = (a[i].itemPrice/a[i].itemWeight);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp = ratio[i];
                temp2 = a[i].itemPrice;
                temp3 = a[i].itemWeight;
                ratio[i] = ratio[j];
                a[i].itemPrice = a[j].itemPrice;
                a[i].itemWeight = a[j].itemWeight;
                ratio[j] = temp;
                a[j].itemPrice = temp2;
                a[j].itemWeight = temp3;
            }
        }
    }

for(i=0;i<n;i++)
  {
      printf("\nRatio of %d is %f",i,ratio[i]);
      printf("\nItem price %f, item wight %f ",a[i].itemPrice,a[i].itemWeight);
  }

for(i=0;i<n;i++)
{   while(capacity!=SackCapacity)
     {
         capacity = capacity + a[i].itemWeight;
         profit = profit + a[i].itemPrice;
     }
}

}
int main()
{
    int n,i;
    float profit,Q;
    printf("\nEnter the number of items present in the shop : ");
    scanf("%d",&n);
    printf("Enter the capacity of SACK : ");
    scanf("%f",&Q);
    struct knapSack obj[n];

    for(i=0;i<n;i++)
    {
        printf("\nEnter the price of %d item  ",i);
        scanf("%f",&obj[i].itemPrice);
        printf("\nEnter the weight  of %d item ",i);
        scanf("%f",&obj[i].itemWeight);
    }
        for(i=0;i<n;i++)
    {
        printf("\n Price of %d item  : ",i);
        printf("%f",obj[i].itemPrice);
        printf("\n Weight of %d item : ",i);
        printf("%f",obj[i].itemWeight);
    }

  profit = KnapSack(obj,n,Q);
  printf("\nProfit is %d ",profit);

return 0;
}
