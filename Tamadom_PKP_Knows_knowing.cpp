/**https://www.spoj.com/problems/TAMADOM/*/
//nCr%m for bog 1<=N<=100000, 0<=R<=100000




#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ull             unsigned long long int
#define pii             pair < int, int>
#define pll             pair < ll, ll>
#define sc              scanf
#define scin(x)         sc("%d",&(x))
#define scln(x)         sc("%lld",&(x))
#define pf              printf
#define ms(a,b)         memset(a,b,sizeof(a))
#define pb(a)           push_back(a)
#define mp              make_pair
#define db              double
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define vi              vector< int >
#define vl              vector< ll >
#define vii             vector<vector< int > >
#define vll             vector<vector< ll > >
#define DBG             pf("HI\n")
#define MOD             1000000007
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RUN_CASE(t,T)   for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)         printf("Case %d: ",t)
#define CASEL(t)        printf("Case %d:\n",t)
#define intlimit        2147483648
#define longlimit       9223372036854775808
#define infinity        (1<<28)
#define gcd(a, b)       __gcd(a,b)
#define lcm(a, b)       ((a)*(b)/gcd(a,b))
#define mx              1234567899
#define PI              2*acos(0.0)
#define rep(i,a,b)      for(__typeof(i) i=a; i<=b; i++)
#define rev(i,a,b)      for(__typeof(i) i=a; i>=b; i--)
ll M;
long long BigMod(long long int a, long long int b)   /// a function to determine a^b(mod M)
{
    long long remainder, answer = 1ll;                            /// set two variables for remainder and answer
    remainder = a%M;                                         /// setting remainder as
    while(b!=0ll)                                                     ///  loop occurs until b is not equal to 0
    {
        if(b%2ll==1ll) answer = (answer*remainder)%M;                  /// checking if b is odd
        /// taking the present remainder in the answer if b is odd
        remainder = (remainder*remainder)%M;    /// making remainder double on each turn of the loop
        b/=2ll;                                  /// reducing b by dividing it by 2 in every turn,
    }
    return answer;
}

#define SIZE 10000007
vector<int> prime; /*Stores generated primes*/
char sieve[SIZE]; /*0 means prime*/
void primeSieve ( int n )
{
    sieve[0] = sieve[1] = 1; /*0 and 1 are not prime*/

    prime.push_back(2); /*Only Even Prime*/
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = 1; /*Remove multiples of 2*/

    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 )
    {
        if ( sieve[i] == 0 )
        {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }

    for ( int i = 3; i <= n; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
}

int factors[100005];
void factorize1( int n )
{
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ )
    {
        if ( sieve[n] == 0 ) break; ///*Checks if n is prime or not*/
        if ( n % prime[i] == 0 )
        {
            while ( n % prime[i] == 0 )
            {
                n /= prime[i];
                factors[prime[i]]++;
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        factors[n]++;
    }
}

void factorize2( int n )
{
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ )
    {
        if ( sieve[n] == 0 ) break; ///*Checks if n is prime or not*/
        if ( n % prime[i] == 0 )
        {
            while ( n % prime[i] == 0 )
            {
                n /= prime[i];
                factors[prime[i]]--;
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        factors[n]--;
    }
}

int main()
{
    primeSieve(SIZE);
    int tst;
    cin >>tst;
    while(tst--)
    {
        ms(factors,0);
        ll n,nn, r;
        scanf("%lld %lld %lld", &n,&r,&M);
        if(n<r)
        {
            pf("0\n");
            continue;
        }
        int mn = min(r,n-r);
        nn = n;
        for(int i=1; i<=mn; i++,n--)
        {
            factorize1(n);
            factorize2(i);
        }
        ll ans =1ll;

        for(int i=2; i<=nn; i++)
        {
            //cout <<" Case ->"<<i << "  " <<factors[i] << endl;
            if(factors[i])
                ans =((ans%M)*(BigMod(i,factors[i])%M)%M);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

