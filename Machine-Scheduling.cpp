#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,x;
    printf("Please enter the number of task and number of machines: ");
    cin>>n>>x;
    int task[n+1];
    cout<<"Please enter the starting time for "<<n<<" works:\n";
    int start[n+1];
    for(int i = 0; i < n; i++) task[i] = i;
    for(int i = 0; i < n; i++) cin>>start[i];
    int finish[n+1];
    cout<<"Please enter the finishing time for "<<n<<" works:\n";
    for(int i = 0; i < n; i++) cin>>finish[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(finish[i]>finish[j])
            {
                swap(task[i],task[j]);
                swap(start[i],start[j]);
                swap(finish[i],finish[j]);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(finish[i]==finish[j]){
                if(start[i]>start[j])
                {
                    swap(task[i],task[j]);
                    swap(start[i],start[j]);
                    swap(finish[i],finish[j]);
                }
            }
        }
    }
    int machine[x][n], m[x], state[n], cnt = 0, mfns;
    for(int i = 0; i < x; i++) m[i] = 0;
    for(int i = 0; i < n; i++) state[i] = 0;
    for(int i = 0; i < x; i++)
    {
        mfns = 0;
        for(int j = 0; j < n; j++)
        {
            if(state[j]==0&&mfns<=start[j])
            {
                machine[i][m[i]++] = task[j];
                state[j] = 1;
                mfns = finish[j];
                cnt++;
            }
        }
        if(cnt==n) break;
    }
    cout<<"Solution:\n";
    for(int i = 0; i < x; i++)
    {
        cout<<"Machine "<<i+1<<": ";
        for(int j = 0; j < m[i]; j++)
            printf("%c ",machine[i][j]+'a');
        printf("\n");
    }
    return 0;
}
