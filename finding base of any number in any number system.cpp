/**
Question: You will be given an N based integer number R and you are given the guaranty that R is divisible by (N-1). You will have to print the
smallest possible value for N. The range for N is (2 ≤ N ≤ 62) and the digit symbols for 62 based number is (0..9 and A..Z and a..z). Similarly,
the digit symbols for 61 based number system is (0..9 and A..Z and a..y) and so on.

Sample input
-----------
3
5
A
-45678901234567890ABC
-nnnnnnnnnnnnnnnnnnnn
-oooooooooooooooooooooooooooo
ggggggggggggggggggggggggggg


Sample output
-------------
4
6
11
14
50
51
43
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int v[123], m, c, f, x = 0;
    string a;
    for(int i=48;i<58;i++){
        v[i]=x;
        x++;
    }
    for(int i=65;i<91;i++){
        v[i]=x;
        cout<<v[i]<<endl;
        x++;
    }
    for(int i=97;i<123;i++){
        v[i]=x;
        x++;
    }

    while(cin >> a) {
            m = 0, f = 0, c = 0;

            if(a[0] == '-' )
                a = a.substr(1);

            for(int ch: a) {
				c = v[ch];
                f += c;
                m = max(m,c);
            }

            if( f < 3 ){
                cout << "2" << endl;
            } else {
                while(m<62){
                    if(f%m==0){
                        cout << m+1 << endl;
                        break;
                    }
                    m++;
                }
                if(m==62){
                    cout << "such number is impossible!" << endl;
                }
            }
        }

    return 0;
}
