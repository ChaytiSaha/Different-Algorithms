/** https://www.spoj.com/problems/HORRIBLE/*/
// segment tree lazy propagation

#include<bits/stdc++.h>

#define ll                      long long int
#define ull                     unsigned long long int
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scln(x)                 sc("%lld",&(x))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define db                      double
#define EPS                     10E-10
#define sqr(x)                  (x)*(x)
#define MOD                     1000000007
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)

using namespace std;

#define Size 100005
ll arr[Size];

struct info
{
    ll prop,sum;
}tree[Size*3];

void init(ll node,ll b,ll e)
{
    if(b == e)
    {
        tree[node].sum=arr[b];
        return;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

void update(ll node,ll b,ll e,ll x,ll y,ll value)
{
    if(x>e || y<b)
        return;

    if(b>=x && e<=y)
    {
        tree[node].prop+=value;
        tree[node].sum += (e - b + 1) *value;
        return;
    }

    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    update(left,b,mid,x,y,value);
    update(right,mid+1,e,x,y,value);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

ll query(ll node,ll b,ll e,ll x,ll y,ll carry =0 )
{
    if(x>e || y<b)
        return 0;

    if(b>=x && e<=y)
        return tree[node].sum+carry*(e-b+1);

    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,x,y,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,x,y,carry+tree[node].prop);
    return p1+p2;
}

int main()
{
    ll n,i,j,k,x,q,y,co,value,cmd,t=1,tc;
    scln(tc);
    while(t<=tc){
        //printf("Case %lld:\n",t);
        scln(n);
        scln(q);
        ms(arr,0);
        ms(tree,0);
        init(1,1,n);
        while(q--)
        {
            scln(cmd);
            if(cmd == 1)
            {
                scanf("%lld %lld",&x,&y);
                co=query(1,1,n,x,y,0);
                printf("%lld\n",co);
            }
            else if(cmd == 0)
            {
                scanf("%lld %lld",&x,&y);
                scln(value);
                update(1,1,n,x,y,value);
            }
        }
        t++;
    }
    return 0;
}


