/**


Considering an expression with parenthesis, print a message informing if the among of parenthesis is correct or incorrect, without considering the
rest of the expression. Example:

a+(b*c)-2-a        is correct
(a+b*(2-c)-2+a)*2  is correct

when

(a*b-(2+c)         is incorrect
2*(3-a))           is incorrect
)3+b*(2-c)(        is incorrect

Resuming, all closing parenthesis must have an open parenthesis and it's not possible a closing parenthesis without a previous open parenthesis,
and the quantity of closing and open parenthesis must be the same.

Sample input
-----------
a+(b*c)-2-a
(a+b*(2-c)-2+a)*2
(a*b-(2+c)
2*(3-a))
)3+b*(2-c)(

Sample output
------------
correct
correct
incorrect
incorrect
incorrect

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s)){
        int left=0,right=0,c1=0;


        for(int i=0;s[i];i++)
        {
            if(s[i]==')' and left>0){
                left--, right--;
            }
            else if(s[i]==')' and left==0) right++;

            if(s[i]=='('){
                left++, right++;
            }
        }

        if(left==0 && right==0)
            cout<<"correct"<<endl;
        else cout<<"incorrect"<<endl;
    }
    return 0;
}
