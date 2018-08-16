#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
int nn[30005];
int arr[30005],seg[100000];
using namespace std;

vector<pair<int,int> > v;


int ans[200005];
struct node
{
    int k,l,r,qn;
} vv[200005];


int read_int()
{
    char r;
    bool start=false,neg=false;
    int ret=0;
    while(true)
    {
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
        {
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start)
        {
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg)
        return ret;
    else
        return -ret;
}

#define inf 100000001



bool compare(node n1,node n2)
{
    if(n1.k>n2.k) return false;
    else return true;
}




int ups,upe,qs,qe;//qs = query start index , qe= query end index
int val;// ups = update start index , upe =update end index


int qry(int index,int start,int end)
{


    if(start>end || end<qs || start>qe)
    {
        return 0;
    }
    if(start>=qs && end<=qe)
    {
        return  seg[index];

    }
    int q1=qry(2*index,start,(start+end)/2);
    int q2=qry(2*index+1,((start+end)/2)+1,end);
    return q1+q2;

}

void build(int index,int start,int end)
{



    if(start==end)
    {
        seg[index]=1;
        return;
    }


    build(2*index,start,(start+end)/2);
    build(2*index+1,((start+end)/2)+1,end);

    seg[index]=seg[2*index]+seg[2*index+1];
    //  cout<<" index        "<<index<<" val "<<seg[index]<<endl;
}



void update(int index,int start,int end)
{
// cout<<"update "<<start<<" "<<end<<endl;
    if(start>end || start>upe || end<ups) return ;// if(range in complitly out of range sooo need not to update ;;;;)
    if(start==end && start==ups)
    {
        // cout<<" reach "<<index<<endl;
        seg[index]=0;
        return ;
    }
//else if(start==end) return ;

    update(2*index,start,(start+end)/2);
    update(2*index+1,((start+end)/2)+1,end);

    seg[index]=seg[2*index]+seg[2*index+1];

}



int main()
{

    int n,q;
    n=read_int();
    for(int i=0; i<n; i++)
    {
        int a;
        a=read_int();
        v.push_back(make_pair(a,i));
        arr[i]=1;
    }

    //cout<<"build call "<<endl;
    build(1,0,n-1);
    // cout<<"build return "<<endl;

    sort(v.begin(),v.end());


    for(int i=0; i<n; i++) nn[i]=(v[i].first);
    //   cout<<" copy done "<<endl;
    q=read_int();

    for(int i=0; i<q; i++)
    {

        int l,r,k;
        // cin>>l>>r>>k;
        l=read_int();
        r=read_int();
        k=read_int();
        vv[i].l=l;
        vv[i].r=r;
        vv[i].k=k;
        vv[i].qn=i;
    }
    //  cout<<" qinp done "<<endl;
    sort(vv,vv+q,compare);

    // cout<<" after sorting status of the query "<<endl;

    for(int i=0; i<q; i++)
    {
        int l,r,k,qn;
        k=vv[i].k;
        l=vv[i].l;
        r=vv[i].r;
        qn=vv[i].qn;

        //  cout<<" l "<<vv[i].l<<" r "<<vv[i].r<<" k "<<vv[i].k<<" "<<vv[i].qn<<endl;
        // vector<int > :: iterator it;


        int *it=lower_bound(nn,nn+n,k+1);
        if(*it>k) it--;
        int pos=it-nn;
        if(pos==n)pos--;
        //cout<<"pos in sorted array is for "<<k<<" is "<<pos<<endl;
        for(int j=pos; j>=0; j--)
        {
            //      cout<<" updating "<<j<<endl;
            if(nn[j]==0) break;
            else
            {
                int place=v[j].second;
                // v[j].first=0;
                nn[j]=0;
                arr[place]=0;
                ups=place;
                upe=place;
                //  cout<<"index of update "<<place<<endl;
                update(1,0,n-1);

            }
        }
        qs=l-1;
        qe=r-1;
        ans[qn]=qry(1,0,n-1);
    }
    for(int i=0; i<q; i++) printf("%d\n",ans[i]);

    return 0;
}
