/**


Diana is going to write a list of all positive integers between A and B, inclusive, in base 10 and without any leading zeros. She wants to know how
many times each digit is going to be used.

Input
------
Each test case is given in a single line that contains two integers A and B (1 ≤ A ≤ B ≤ 108). The last test case is followed by a line containing
two zeros.

Output
------
For each test case print a single line with 10 integers representing the number of times each digit is used when writing all integers between A and
B, inclusive, in base 10 and without leading zeros. Write the counter for each digit in increasing order from 0 to 9.

Input Sample
-----------
1 9
12 321
5987 6123
12345678 12345679
0 0

Output Sample
-------------
0 1 1 1 1 1 1 1 1 1
61 169 163 83 61 61 61 61 61 61
134 58 28 24 23 36 147 24 27 47
0 2 2 2 2 2 2 2 1 1
*/


#include <bits/stdc++.h>

using namespace std;

inline int mpow(int n, int m)
{
	int ret = 1;
	for(int i = 1; i <= m; ++i)
		ret *= n;
	return ret;
}
void calc(int n, int cnt[])
{
	if(n <= 0)
		return;

	char buf[105];
	sprintf(buf, "%d", n);
	int len = strlen(buf);
	int prev = 0, suffix;

	calc(mpow(10, len - 1) - 1, cnt);

	int prev10 = 1;
	for(int i = 0; i < len; ++i)
	{
		int d = buf[i] - '0';
		sscanf(buf + i + 1, "%d", &suffix);

		if(i != len-1)
			cnt[d] += suffix + 1;
		else
			cnt[d]++;
		if(i != 0)
			cnt[d] += (prev - prev10 / 10) * mpow(10, len - i - 1);
		for(int j = (i == 0); j < 10; ++j)
		{
			if(j == d)	continue;
			if(j < d)
			{
				if(prev > 0)
					cnt[j] += (prev - prev10/10 + 1) * mpow(10, len - i - 1);
				else
					cnt[j] += mpow(10, len-i-1);

			}
			else
			{
				if(prev > 0 && prev - prev10 / 10 > 0)
					cnt[j] += (prev - prev10 / 10) * mpow(10, len - i - 1);
			}
		}
		prev10 *= 10;
		prev = prev * 10 + d;
	}
}
int main()
{
	int l, r;

	ios_base :: sync_with_stdio(0); cin.tie(0);
	while(cin >> l >> r)
	{
		if(l == 0 && r == 0)
			break;
		int A[10] = {}, B[10] = {};
		calc(l - 1, A);
		calc(r, B);
		for(int i = 0; i < 10; i++)
		{
			if (i) cout << ' ';
			cout << (B[i] - A[i]);
		}
		cout << '\n';
	}
	return 0;
}
