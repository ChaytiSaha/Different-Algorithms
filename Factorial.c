#include<stdio.h>
int main()
{
    int i,j,dgt=1,rest=0,x,num,ara[100000];
    printf("\n\nPlease, Enter a number less then 25000.\n");
    scanf("%d",&num);            //5
    for(i=1,ara[0]=1;i<=num;i++) //1 - 5 2
    {                            //
        for(j=0;j<dgt;j++)       //0<1 dgt=2
        {                        //
            x=ara[j]*i+rest;     //x=1*1+0 = 1 x=1*2+0 x=1*2*3 x=1*2*3*4 x=24*5 = 120 x=12
            ara[j]=x%10;         //ara[0]=1%10=1  ara[0]=2 ara[0]=6 ara[0]=4 ara[0]=0 ara[1] =2
            rest=x/10;           //rest = 0 rest=0 rest=0 rest=2 rest=12 rest=1
        }                        //
        while(rest>0)            //0>0 2>0 1>0
        {                        //
            ara[dgt]=rest%10;    //ara[1]=2 ara[2]=1
            rest/=10;            //rest= 0 0
            dgt++;               //dgt= 2 3
        }                        //
    }                            //
    for(i=dgt-1;i>=0;i--)        //
        printf("%d",ara[i]);     //
    return 0;
}
