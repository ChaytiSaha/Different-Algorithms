/*Problem link : https://www.spoj.com/problems/PRIME1/   */

#include <string.h>
#include<bits/stdc++.h>
#define MAX 100000000//46656
#define LMT 100000//216
#define LEN 10000000//4830
#define RNG 3000000//100032

using namespace std;
unsigned long long base[MAX/64], segment[RNG/64], primes[LEN];

#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

/* Generates all the necessary prime numbers and marks them in base[]*/
void sieve()
{
    unsigned long long i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!chkC(base, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(base, j);
    for(i=3, j=0; i<MAX; i+=2)
        if(!chkC(base, i))
            primes[j++] = i;
}

/* Returns the prime-count within range [a,b] and marks them in segment[] */
int segmented_sieve(unsigned long long a, unsigned long long b)
{
    sieve();
    if(a<=2)
        cout<<2<<endl;
    unsigned long long i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;
    if(b<2) return 0;
    if(a<3) a = 3;
    if(a%2==0) a++;
    mset(segment,0);
    for(i=0; sq(primes[i])<=b; i++)
    {
        j = primes[i] * ( (a+primes[i]-1) / primes[i] );
        if(j%2==0) j += primes[i];
        for(k=primes[i]<<1; j<=b; j+=k)
            if(j!=primes[i])
                setC(segment, (j-a));
    }
    for(i=0; i<=b-a; i+=2)
        if(!chkC(segment, i)){
            //cnt++;
            cout<<a+i<<endl;;
        }
    return cnt;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        unsigned long long a,b;
        cin>>a>>b;
        int cnt=segmented_sieve(a,b);
        cout<<endl;
        //cout<<endl<<cnt<<endl;
    }
    return 0;
}


