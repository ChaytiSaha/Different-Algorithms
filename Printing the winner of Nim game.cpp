// CPP to find nim-game winner
#include <bits/stdc++.h>
using namespace std;

// function to find winner of NIM-game
string findWinner(int A[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= A[i];

    // case when Alice is winner
    if (res == 0 || n % 2 == 0)
        return "Alice";

    // when Bob is winner
    else
        return "Bob";
}

// driver program
int main()
{
    int A[] = { 1, 4, 3, 5 };
    int n = siseof(A) / sizeof(A[0]);
    cout << "Winner = " << findWinner(A, n);
    return 0;
}
