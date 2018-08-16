

// CPP program for the variation
// in nim game
#include <bits/stdc++.h>
using namespace std;

// Function to return final
// grundy Number(G) of game
int solve(int p[], int n)
{
    int G = 0;
    for (int i = 0; i < n; i++) {

        // if pile size is odd
        if (p[i] & 1)

            // We XOR pile size+1
            G ^= (p[i] + 1);

        else // if pile size is even

            // We XOR pile size-1
            G ^= (p[i] - 1);
    }
    return G;
}

// driver program
int main()
{
    // Game with 3 piles
    int n = 3;

    // pile with different sizes
    int p[3] = { 32, 49, 58 };

    // Function to return result of game
    int res = solve(p, n);

    if (res == 0) // if G is zero
        cout << "Player 2 wins";
    else // if G is non zero
        cout << "Player 1 wins";

    return 0;
}
