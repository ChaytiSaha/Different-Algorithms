#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int n;
void printSolution(int dist[][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == 99999)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall (int graph[][100])
{
    int dist[100][100], i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];
    cout<<"The given adjacency matrix is :"<<endl;
    printSolution(dist);

    for (k = 0; k < n; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++)
        {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < n; j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
        cout<<endl<<"[A"<<k+1<<"]  :::::"<<endl;
        printSolution(dist);
    }
}

int main()
{
    cout<<"Enter size of adjacency matrix of graph:"<<endl;
    cin>>n;
    /*
    int graph[V][V] = { {0,   3,  INF, 7},
                        {8, 0,   2, INF},
                        {5, INF, 0,   1},
                        {2, INF, INF, 0}
                      };
                */
    int graph[100][100];
    cout<<"Enter the adjacency matrix of size "<<n<<" :"<<endl;
    cout<<"Enter 99999 for denoting infinity:"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    floydWarshall(graph);
    return 0;
}
