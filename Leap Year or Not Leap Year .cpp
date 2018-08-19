/**

The ancient race of Gulamatu is very advanced in their year calculation scheme. They understand what leap year is (A year that is divisible by 4
and not divisible by 100 with the exception that years that are divisible by 400 are also leap year.) and they have also similar festival years.
One is the Huluculu festival (happens on years divisible by 15) and the Bulukulu festival (Happens on years divisible by 55 provided that is also a
leap year). Given an year you will have to state what properties these years have. If the year is not leap year nor festival year, then print the
line 'This is an ordinary year.' The order of printing (if present) the properties is leap year-->huluculu-->bulukulu.

Input
Input will contain several years as input. Each year will be in separate lines. Input is terminated by end of file. All the years will not be less
than 2000 (to avoid the earlier different rules for leap years) but can have more than 1000 digits.

Output
For each input, output the different properties of the years in different lines according to previous description and sample output. A blank line
should separate the output for each line of input. Note that there are four different properties.

*/


#include<bits/stdc++.h>
using namespace std;

int sum(string str,int year)
{
    int tot=0;
    for(int i=0;str[i];i++)
        tot = (tot*10+str[i]-'0')%year;
    if(tot==0)
        return 0;
    else return 1;
}

int main()
{
    string s;
    int l=0;
    while(cin>>s)
    {

        int cnt=0,flag=0;

        if(l>0)cout<<endl;

        if((sum(s,4)==0 and sum(s,100)!=0) or (sum(s,400)==0))
        {
            cout<<"This is leap year."<<endl;
            cnt=1;
            flag=1;
        }
        if(sum(s,15)==0)
        {
            cout<<"This is huluculu festival year."<<endl;
            cnt=1;
        }
        if(sum(s,55)==0 and flag==1)
        {
            cout<<"This is bulukulu festival year."<<endl;
            cnt=1;
        }
        if(cnt==0)
            cout<<"This is an ordinary year."<<endl;
        l++;
    }
    return 0;
}

