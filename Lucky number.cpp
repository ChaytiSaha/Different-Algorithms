/**
 Problem link : https://www.devskill.com/CodingProblems/ViewProblem/386
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll SQRT(ll x)
{
    ll res,a = sqrt(x*1.0);
    for(ll i = max(a-2,0LL); i <= a+2; i++)
    {
        if(i*i<=x)
            res = i;
    }
    return res;
}

ll CBRT(ll x)
{
    ll res,a = cbrt(x*1.0);
    for(ll i = max(a-2,0LL); i <= a+2; i++)
    {
        if(i*i*i<=x)
            res = i;
    }
    return res;
}

int main()
{
    int t,T;
    scanf("%d",&T);
    for(t = 1;t<=T;t++)
    {
        ll u,v,sq,cb,cm,ans;
        scanf("%lld %lld",&u,&v);
        sq = SQRT(v)- SQRT(u-1);
        cb = CBRT(v)- CBRT(u-1);
        cm = SQRT(CBRT(v))-SQRT(CBRT(u-1));
        ans = sq+cb-cm;
        printf("%lld\n",(v-u+1)-ans);
    }
    return 0;
}
