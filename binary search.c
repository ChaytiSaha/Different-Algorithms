#include<stdio.h>
int main()
{
    int n,item,beg,end,mid;
    printf("How many elements :");
    scanf("%d",&n);
    int i,data[n];
    for(i=0;i<n;i++)
        scanf("%d",&data[i]);

    printf("Enter the item u want to search :");
    scanf("%d",&item);

    beg=0;end=n-1;
    mid=(beg+end)/2;
    while(beg<=end && data[mid]!=item)
    {
        if(item<data[mid])
            end=mid-1;
        else
            beg=mid+1;
        mid=(beg+end)/2;
    }

    if(data[mid]==item)
        printf("%d is the location of the item\n",mid);
    else
        printf("Item is not found\n");
    return 0;
}

