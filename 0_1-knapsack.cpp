#include <bits/stdc++.h>
using namespace std;
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // stores the result of Knapsack
    int res = K[n][W];
    printf("%d\n", res);

    w = W;
    for (i = n; i > 0 && res > 0; i--) {

        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1][w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means the item is included.
        if (res == K[i - 1][w])
            continue;
        else {

            // This item is included.
            printf("%d ", wt[i - 1]);
            // Since this weight is included its value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}

int main()
{
    int W,n;
    cout<<"Enter number of items:"<<endl;
    cin>>n;
    cout<<"Enter highest profit:"<<endl;
    cin>>W;
    int val[n],wt[n];
    cout<<"Enter profit and weight of them respectively:"<<endl;
    for(int l=0;l<n;l++)
        cin>>val[l]>>wt[l];
    printknapSack(W, wt, val, n);
    return 0;
}
