/** To prefix a expression there are 3 steps
    1.Reverse the infix expression
    2.Obtain the postfix expression of the modified expression
    3.Reverse the postfix expression
**/
#include<bits/stdc++.h>
using namespace std;

int precedence(char a)
{
    if(a == '^') return 3;
    else if(a == '*' || a == '/' || a == '%') return 2;
    else if(a == '+' || a == '-') return 1;
    else return -1;
}

string topostfix(string infix)
{
    stack<char> st;
    st.push('(');
    string result;
    infix = infix +')';
    int len = infix.size();
    for(int i = 0; i<len; i++)
    {
        if(isalnum(infix[i]))///checking if it is operand
            result+=infix[i];
        else if(infix[i] == '(')
            st.push('(');
        else if(infix[i] == ')')
        {
            while(st.top()!= '(')
            {
                result+=st.top();
                st.pop();
            }
            if(st.top() == '(')
                st.pop();
        }
        else ///checking if it is operator
        {
            while(precedence(infix[i])<=precedence(st.top()))
            {
                result+=st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    return result;
}

string toprefix(string infix)
{
    reverse(infix.begin(),infix.end());
    int sz = infix.size();
    for(int i=0; i<sz; i++)
    {
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }
    string result = topostfix(infix);
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
    string infix;
    cin >> infix;
    cout << "The Prefix : " << toprefix(infix) << endl;
    return 0;
}

