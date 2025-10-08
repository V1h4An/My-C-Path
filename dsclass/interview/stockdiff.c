/*an array of stock prices where each element represents price of stock on a given day
find max profit*/

#include<stdio.h>
#include<stdlib.h>

int maxprofit(int price[],int s)
{

int minprice=price[0];
int maxprofit =0;

for(int i=0;i<s;i++)
{
    if(price[i]<minprice)
    {
        minprice = price[i];
    }
    else if(price[i]-minprice>maxprofit)
    {
        maxprofit = price[i]-minprice;
    }
}
return maxprofit;
}

int main()
{
    int price[]={7,1,9,6,2,19};
    int s = sizeof(price)/sizeof(price[0]);
    printf("max profit is %d\n",maxprofit(price,s));
return 0;
}