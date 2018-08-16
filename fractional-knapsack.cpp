#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair< pair<double,double>,pair<double,int> > ddd;
int main()
{
    int n;
    cout<<"Enter the number of item "<<endl;
    cin>>n;
    int capacity;
    cout<<"Enter the capacity of knapsack "<<endl;
    cin>>capacity;
    cout<<"Enter profit and weight of each item "<<endl;
    double profit,weight,Ratio;
    vector< ddd >v;
    for(int i=0; i<n; i++)
    {
        cin>>profit>>weight;
        ///me

        Ratio=profit/weight;
        ddd p;
        p=make_pair(make_pair(Ratio,profit),make_pair(weight,i+1));
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    double totalweight=0,totalprofit=0,remaining,fraction_taken;
    int i=n-1;
    while(totalweight<capacity)
    {
        remaining=capacity-totalweight;
        if(remaining/v[i].second.first>=1)
        {
            fraction_taken=1;
            cout<<fraction_taken<<" fraction of Item "<<v[i].second.second<<" is taken "<<endl;
        }
        else
        {
            fraction_taken=remaining/v[i].second.first;
            cout<<remaining<<"/"<<v[i].second.first<<" fraction of Item "<<v[i].second.second<<" is taken "<<endl;
        }

        totalweight+=fraction_taken*v[i].second.first;
        totalprofit+=fraction_taken*v[i].first.second;
        i--;
    }
    cout<<"0 fraction taken from other items"<<endl;
    cout<<"Total profit = "<<totalprofit<<endl;


}
/*
Rakib ISlam
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    float p,w,c,temp,weight = 0,profit = 0,count=0;
    vector< pair <float,float> >v;

    for(int i=0; i<n; i++)
    {
        cin >> p >> w;
        v.push_back(make_pair(p,w));
    }
    float ratio[20];
    for(int i=0;i<n;i++)
        ratio[i]=(v[i].first/v[i].second);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                swap(ratio[i],ratio[j]);
                swap(v[i],v[j]);
            }
        }
    }

    cin >> c;
    temp = c;

    for(int j=0; j<n && temp!=0; j++)
    {
        if(v.at(j).second > temp)
        {
            profit += ((v.at(j).first/v.at(j).second) * temp);

            weight += temp;

            v.at(j).second = temp;

            count++;

            break;
        }

        temp -=v.at(j).second;

        profit +=v.at(j).first;

        weight +=v.at(j).second;

        count++;

    }

    cout<<"\nProfit: "<<profit<<endl;
    cout<<"\nWeight: "<<weight<<endl;

    for(int i=0; i<count; i++)
    {
        cout<<"Item : "<<v.at(i).first<<"weight: "<<v.at(i).second<<endl;
    }


    return 0;
}
5
50 5
36 3.2
12 0.5
45 7
23 2
10.7

5
50 5
36 3.2
12 0.5
45 7
23 2
17.7

5
50 5
36 3.2
12 0.5
45 7
23 2
15

*/
