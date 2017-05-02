#include <bits/stdc++.h>
using namespace std;

/*******************************************************************\
|                       Md.Mahbubur Rahman                          |
|   	BANGLADESH UNIVERSITY OF BUSINESS & TECHNOLOGY(BUBT)	    |
|		 	    Deptartment of  CSE							        |
|    uva:mahbub07||devskil: mahbub07||codefoces:MAHBUBUR_RAHMAN     |
|                mail:mahbubabid8@gmail.com				            |
\*******************************************************************/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef  vector<int> vi;
typedef  vector<ll> vll;
typedef  vector<string> vs;
typedef  set<int> si;
typedef  set<string> ss;
typedef  map<int,int> mii;
typedef  map<ll,ll> mll;
typedef  map<string,int> msi;
typedef  map<char,int> mci;
//----------------defines-----------------------
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define skip scanf("%*c");
#define ms(s, n) memset(s, n, sizeof(s))
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define For0(i,n) for(int i=0;i<(int)n;i++)
#define For1(i,n) for(int i=1;i<=(int)n;i++)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define Case(no) printf("Case %d: ",++no)
#define pb(b) push_back(b)
#define mp make_pair
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define sortArr(a,n) sort(a,a+n)
#define sortVec(a) sort(all(a))
#define endl '\n'
#define DIST(x1,y1, x2, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
//----------------functions-----------------------
ll multiplyfast(ll a, ll b, ll c){ if(b==0) return 0;ll x = multiplyfast(a , b/2, c)%c; if(!(b&1)){ return (x%c+x%c)%c;}else return ((a%c + (x+x)%c))%c; }
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=multiplyfast(res,a,mod)%mod;a=multiplyfast(res,a,mod)%mod;}return res;}
ll modInverse(ll a, ll m){return powmod(a,m-2,m);}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
//----------------constants-----------------------
const int MOD = (int) 1e9 + 7;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;

const long long MAX =10000000;

vector <long long>primes;
vector <long long>segment;
vector <long long>segmentPrime;
vector < bool > isprime(MAX,false);

void sieve()
{
	isprime[1] = true;

	for(long long i = 4;i<= MAX ;i+=2 )
		isprime[i] = true;

	for(long long i=3;i<= sqrt(MAX) ;i += 2){

		if( !isprime[i]){
			for(long long j = i*i ; j<= MAX ;j = j*i){
				isprime[j] = true;
			}

		}
	}
	primes.pb(2);
	for(int i = 3; i <= MAX; i+=2){
		if(!isprime[i])
			primes.pb(i);
	}

}
void segmented_sieve(ll l,ll u)
{
	ll root;
	segment.clear();
	root=sqrt(u)+1;



	for(ll i=l;i<=u;i++)
	{
		segment.push_back(i);
	}


	if(l==0){
		segment[1]=0;
	}
	else if(l==1)
	{
		segment[0]=0;
	}



	for(ll i=0;primes[i]<=root;i++)
	{
		ll si=primes[i];

		ll start=si*si; // every prime*prime = composite

		if(start<l)
		{
			start=((l+si-1)/si)*si; // starting composite number
		}


		for(ll j=start;j<=u;j=j+si)
		{
			segment[j-l]=0;  // marking as zero every composite number

		}
	}

}

int main() 
{
	sieve();
	ll lower,upper;
	cin >> lower >> upper;
	
	segmented_sieve(lower, upper);
	
	for(ll i = lower; i <= upper ;i++){
		if(segment[i-lower] != 0){
			segmentPrime.pb(segment[i-lower]); // storing all the prime not marked as composite in range.
		}
	}
	cout<<"Size of seg: "<<segmentPrime.size()<<endl;
	for(ll i = 0; i < segmentPrime.size();i++){
		cout << segmentPrime[i]<<endl;
	}
	return 0;
}