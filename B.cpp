/**
In Euclidean geometry, a regular convex polygon is a polygon that is equiangular (all interior angles are equal in measure), equilateral (all
sides have the same length) and all interior angles are less than 180 degrees. Let's define an N-gon as a regular convex polygon which has N
sides and N interior angles, where N is a positive integer.

Given a non-negative integer X, your task is to find whether a valid N-gon can be formed whose summation of all the interior angles is equal
to X. If it's possible, then also find the value of N and the interior angle of the N-gon.


Input Specification
-------------------
The first line of input contains a positive integer T which denotes the number of test cases. The next T lines will contain a single
non-negative integer X.


Output Specification
--------------------
For each test casei, output a single line starting with the case number in the format “Case i: ” without the quotes.

Then if it is possible to form a valid N-gon, output two space separated integers N and Ain the format “N A” without quotes,which are the values
of N as mentioned in the problem description and the value of the interior angle of the N-gon respectively. Otherwise output “Impossible” instead
without the quotes.The value of A should be rounded to its nearest integer.

See the sample input/output for more details.

Constraints:

Small Subtask: T <= 100, 0 <= X <= 10^5, for 30 points

Large Subtask: T <= 10^5, 0 <= X <= 10^18, for 70 points


Input
3
120
180
360

Output
Case 1: Impossible
Case 2: 3 60
Case 3: 4 90

*/


#include<bits/stdc++.h>
using namespace std;

typedef  long long ll;

int main()
{
    ll T,i=1ll,x,n;
    cin>>T;
    while(i<=T){
        cin>>x;
        n=(x/180)+2;

        if(x%180==0 and x!=0)
            printf("Case %lld: %lld %lld\n",i,n,(ll)((round)(double(x)/n)));
        else
            printf("Case %lld: Impossible\n",i);
        i++;
    }
    return 0;
}
