/**
Problem link :https://www.devskill.com/CodingProblems/ViewProblem/418
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ms(a,d) memset(a,d,sizeof(a))

bool  isperfect(int n)
{
    double Sqrt = sqrt(n);
    int int_sqrt = Sqrt;
    if(int_sqrt == Sqrt)
        return true;
    else
        return false;
}

int main()
{
    ll t,n;
    ll ara[101],cnt,p,d;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ms(ara,0);
        cnt=0;

        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&p);
            ara[p]++;
        }

        for(ll i=1;i<=100;i++)
        {
            if(ara[i]!=0){

                d=ara[i]-1;
                cnt+=(d*(d+1))/2;

                for(ll j=i+1;j<=100;j++)
                    if(isperfect(i*j) and ara[j]!=0)
                        cnt=cnt+ara[i]*ara[j];
            }
        }

        printf("%lld\n",cnt);
    }
    return 0;
}
