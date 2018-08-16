// CPP program for Game of Replacement
#include <bits/stdc++.h>
using namespace std;

// Function return which player win the game
int playGame(int arr[], int n)
{
    // Create hash that will stores
    // all distinct element
    unordered_set<int> hash;

    // Traverse an array element
    for (int i = 0; i < n; i++)
        hash.insert(arr[i]);

    return (hash.size() % 2 == 0 ? 1 : 2);
}

// Driver Function
int main()
{
    int arr[] = { 1, 1, 2, 2, 2, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Player " << playGame(arr, n) << " Wins" << endl;
    return 0;
}
