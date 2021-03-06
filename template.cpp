#include<bits/stdc++.h>
using namespace std;


#define ull unsigned long long int
#define ll long long int
#define pi 2*acos(0.0)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define ms(a,d) memset(a,d,sizeof(a))
#define popcount(i) __builtin_popcount(i)      //count one. in long long use __builtin_popcountll(i)
#define parity(i)   __builtin_parity(i)       //evenparity 0 and odd parity 1------ parity bit means number of 1     // cout<<parity(0001110001111)<<endl;--->3  //cout<< parity(0011000) ; --->2
#define btz(a)   __builtin_ctz(a)            //count binary trailling zero // cout<<btz(101000)<<endl;---> 3  //btz(001000) ----> 5
#define pii pair < int, int>
#define pll pair < ll, ll>
#define pb(a)  push_back(a)
#define mp make_pair

//upper bound and lower bound
#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())

//File input/output
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

typedef  unsigned long long ull;

//reversing a string
void reverseStr(string &str)
{
    int n = str.size();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

//checking palindrome
bool isPalindrome(string str)
{
    int l = 0;
    int h = str.size() - 1;

    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            cnt=l-1;
            sp=h+2;
            return false;
        }
    }
    return true;
}

//lucky number
//---------------------------
const long long mx = 1e10;
vector <long long> a;
long long DP(long long x)
{
    if (x<=mx)
    {
        a.push_back(x);
        DP(x*10+4);
        DP(x*10+7);
    }
}
//----------------------------

ll SQRT(ll x)
{
    ll res,a = sqrt(x*1.0);
    for(ll i = max(a-2,0LL); i <= a+2; i++)
    {
        if(i*i<=x)
            res = i;
    }
    return res;
}

ll CBRT(ll x)
{
    ll res,a = cbrt(x*1.0);
    for(ll i = max(a-2,0LL); i <= a+2; i++)
    {
        if(i*i*i<=x)
            res = i;
    }
    return res;
}

/*
template <typename T>
string toString( T Number )
{
    stringstream st;
    st << Number;
    return st.str();
}
*/

/*
int stringconvert(string s)
{
    int p; 
    istringstream st(s); 
    st>>p ; 
    return p;
}
*/

/*
  Cheking divisibility of any large number (may be 1000 digits) by a number // 1000000000000000000000000000000 is divisible by 4 or not
----------------------------------------------------------------------------
bool get_result1(string str)// str is the large number which is to be checked
{
    ll n=0;

    for(int i=0;str[i];i++){
        n=( n*10+ (str[i]-'0') )% number_that_divide_str;
    }
    if(n==0)
        return 0;//divisible
    else
        return 1;//not divisible

}
*/

/*
int arr[5000],i;
void stringconvert(string s)
{
    int p;
    istringstream g(s);
    while(g>>p)
        arr[i++]=p;
}

*/

/*
ll Bigmod(ll base, ll power, ll mod)
{
    if(power==0)
        return 1%mod;

    if(power==1)
        return base%mod;

    ll x = Bigmod(base,power/2,mod);

    x = (x*x)%mod;

    if(power%2){
        x = (x*(base%mod))%mod;
    }

    return x;
}
*/

/*
ll modInverse(ll a, ll m)
{
    return bigmod(a,m-2,m);
}
*/

/*

FOR BIGMOD
----------

template <typename T>
T mmul(T a, T b, T m)
{
    a %= m;
    T result = 0;
    while (b)
    {
        if (b % 2) result = (result + a) % m;
        a = (a + a) % m;
        b /= 2;
    }
    return result;
}

template <typename T>
T mpow(T a, T b, T m) // a-->base b--->power  m--->mod
{
    a %= m;
    T result = 1;
    while (b)
    {
        if (b % 2) result = mmul(result, a, m);
        a = mmul(a, a, m);
        b /= 2;
    }
    return result;
}
*/

/*
bool isPrime( ll val )
{
    if( val == 2 )
        return true ;
    if( val % 2 == 0 || val == 1 )
        return false ;
    ll sqrt_N = (ll) ( ( double ) sqrt( val ) ) ;
    for( ll i = 3 ; i <= sqrt_N ; i += 2 ){
        if( val % i == 0 )
            return false ;
    }
    return true ;
}
*/

/*bool cmp(pll a,pll b) //vector<pair<ll,ll>>v; i=0; while(i<n){ cin>>num; v.push_back(make_pair(num,num%M)); i++;} sort(v.begin(),v.end(),cmp);
{
    -----------------
    ----------------
}
*/

/*

GCD
----
int gcd(int a,int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}
*/

/*

Sieve
------
unsigned long long int Prime[300000],nPrime;
unsigned long long mark[1000002];
void sieve(int n)
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    for(i=4;i<=n;i+=2)
        mark[i]=1;
    Prime[nPrime++]=2;
    for(i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            Prime[nPrime++]=i;
            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
*/

/**
Ordered set
------------
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
orderset<int> s ; //orderset<int>::iterator it ;
orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
*/


////============ CONSTANT ===============////
#define inf   1<<30    //infinity value
#define eps   1e-9
#define mx    100009
#define mod   1000000007
////=====================================////


int main()
{

    //DP(0);
    return 0;
}

