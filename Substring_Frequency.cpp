/** http://www.lightoj.com/volume_showproblem.php?problem=1255*/
//Substring Frequency

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<bits/stdc++.h>

using namespace std;

char txt[1000005];
char pat[1000005];
int cnt;

void computeLPSarray(char *pat, int M, int *lps)
{
	int len = 0;	//lenght of previous longest prefix suffix
	int i ;

	lps[0] = 0 ;	//lps[0] is always 0
	i = 1;

	while(i <  M)	//loop calculates lps[i] for i = 1 to M-1
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else	//pat[i] != pat[len]
		{
			if(len != 0)
			{
				//this is tricky
				//consider the example AAACAAAA and i =7
				len = lps[len - 1];
				//we donot increment i here
			}
			else	//if len == 0
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int *lps = (int*)malloc(M*sizeof(int));
	int j = 0;

	computeLPSarray(pat, M, lps);

	int i = 0;
	while(i < N)
	{
		if(pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if(j == M)
		{
			//printf("Found pattern at index %d\n",i - j);
			//if(i-j>=low and i-j<=up and (i-j)+M-1<=up)
			cnt++;
			j = lps[j-1];
		}
		else if(pat[j] != txt[i])
		{
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
	free(lps);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%s",txt);
        scanf("%s",pat);
        KMPSearch(pat, txt);
        printf("Case %d: %d\n",i,cnt);
        cnt=0;
    }
	return 0;
}

