#include <stdio.h>
#include<stdlib.h>
long long int cnt=0;
void towers(long long int num, char beg, char aux, char end)
{
    cnt++;
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", beg, end);
        return;
    }
    towers(num - 1, beg, end, aux);
    printf("\n Move disk %lld from peg %c to peg %c", num, beg, end);
    towers(num - 1, aux, beg, end);
}

int main()
{
    long long int num;
    printf("Enter the number of disks : ");
    scanf("%lld", &num);
    printf("The sequence of moves in the Tower of Hanoi are :\n");
    towers(num, 'A', 'B', 'C');
    printf("\n%lld moves needed\n",cnt);
    return 0;
}
