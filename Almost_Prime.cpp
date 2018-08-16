/**https://algo.codemarshal.org/problems/556b56d1fc5f0103000a0aed*/
//Sieve +Binary search



#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll prime[3000000],nPrime;
ll status[10000002];
vector<ll>v;
vector<ll>::iterator low_limit,up_limit;

void sieve()
{
    ll i,j,limit=sqrt(1e7);
    status[1]=1;
    for(i=4; i<1e7; i+=2)
        status[i]=1;
    prime[nPrime++]=2;
    for(i=3; i<=1e7; i+=2)
        if(status[i]==0)
        {
            prime[nPrime++]=i;
            if(i<=limit)
                for(j=i*i; j<=1e7; j+=i*2)
                    status[j]=1;
        }
}

void almost_prime()
{
    sieve();
    //cout<<nPrime<<endl;
    for(ll i=0; i<nPrime; i++)
    {
        ll mul=prime[i]*prime[i];
        while(mul<1e12)
        {
            v.push_back(mul);
            //if(prime[i]==2)cout<<mul<<endl;
            mul=mul*prime[i];
        }
    }
    sort(v.begin(),v.end());
}

int main()
{
    almost_prime();
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,y,ans=0ll;
        cin>>x>>y;

        low_limit=lower_bound (v.begin(), v.end(), x);
        up_limit =upper_bound (v.begin(), v.end(), y);

        ans = (up_limit-v.begin())-(low_limit-v.begin());

        cout<<ans<<endl;
    }
    return 0;
}




/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>num;
vector<ll>update;
ll l,r;
int binarysearch(ll item,int flag);
ll prime[3000000],nPrime;
ll status[10000002];
vector<ll>v;
void seive()
{
    ll i,j,limit=sqrt(1e7);
    status[1]=1;
    for(i=4; i<1e7; i+=2)
        status[i]=1;
    prime[nPrime++]=2;
    for(i=3; i<=1e7; i+=2)
        if(status[i]==0)
        {
            prime[nPrime++]=i;
            if(i<=limit)
                for(j=i*i; j<=1e7; j+=i*2)
                    status[j]=1;
        }
}
int main()
{
    seive();
    for(ll i=0; i<nPrime; i++)
    {
        ll x=prime[i];
        while(x<=1e12)
        {
            x=x*prime[i];
            num.push_back(x);
        }
    }
    sort(num.begin(),num.end());
    ll t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>l>>r;
        ll fp=binarysearch(l,-1);
        ll lp=binarysearch(r,1);
        if(lp==-1)
        {

             cout<<0<<endl;
            continue;
        }

        cout<<lp-fp+1<<endl;
    }
}
int binarysearch(ll item,int flag)
{
    ll mid,beg,end;
    beg=0;
    end=num.size()-1;
    ll index=0;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(num[mid]==item)
        {
            index=mid;
            return index;
        }
        else if(num[mid]>item)
        {
            end=mid-1;
            if(flag==1)
                index=end;
        }
        else
        {
            beg=mid+1;
            if(flag==-1)
                index=beg;
        }

    }
    return index;
}
*/
