#include<bits/stdc++.h>

#define ll                      long long int
#define scln(x)                 scanf("%lld",&(x))

using namespace std;

#define Size 1000005
ll arr[Size];
ll tree[Size*3];

void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node]=arr[b];
        return;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

ll query(ll node,ll b,ll e,ll x,ll y)
{
    if(b>y || e<x)
        return 0;

    if(b>=x && e<=y)
        return tree[node];

    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    ll q1=query(left,b,mid,x,y);
    ll q2=query(right,mid+1,e,x,y);
    return q1+q2;
}

void update(ll node,ll b,ll e,ll x,ll value)
{
    if(x<b || x>e)
        return;

    if(b>=x && e<=x){
        tree[node]=value;
        return;
    }

    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    update(left,b,mid,x,value);
    update(right,mid+1,e,x,value);
    tree[node]=tree[left]+tree[right];
}


int main()
{
    ll n,q,i,j,k,co,value,cmd,t=1,Tc,pp,qq;
    scln(Tc);
    while(t<=Tc){
        scln(n);
        scln(q);
        for(i=1; i<=n; i++)
            scln(arr[i]);
        init(1,1,n);
        printf("Case %lld:\n",t);
        while(q--)
        {
            scln(cmd);
            if(cmd == 1){
                scln(pp);
                printf("%lld\n",arr[pp+1]);
                update(1,1,n,pp+1,0);
                arr[pp+1] = 0;
            }
            else if(cmd == 2){
                scln(pp);
                scln(qq);
                pp++;
                update(1,1,n,pp,arr[pp]+qq);
                arr[pp]=arr[pp]+qq;
            }
            else if(cmd==3){
                scln(pp);
                scln(qq);
                co=query(1,1,n,pp+1,qq+1);
                printf("%lld\n",co);
            }
        }
        t++;
    }
    return 0;
}

